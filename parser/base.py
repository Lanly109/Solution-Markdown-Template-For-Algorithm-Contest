from abc import abstractmethod, abstractproperty
import os
import random
from datetime import datetime
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

class BaseParser():
    
    def __init__(self) -> None:
        self._log = []
        self._title = ""
        self.problem_num = 0

    @abstractproperty
    def name(self) -> str: ...
    @abstractmethod
    def _title_method(self) -> str: ...
    @abstractmethod
    def problem_url(self, problem_id: str) -> str: ...

    @abstractproperty
    def contest_id(self) -> str: ...
    @abstractproperty
    def code_path(self) -> str: ...
    @abstractproperty
    def problem_table(self) -> str:
        return ""

    @property
    def request_header(self):
        return {}

    @property
    def request_cookie(self):
        return {}

    @property
    def abbr(self) -> str: 
        return ""

    @property
    def template(self) -> str:
        return '''## [{} ({}{} {})]({})
### 题目大意

<++>

### 解题思路

<++>

<details>
  <summary>神奇的代码</summary>
  
```cpp
{}
```
</details>
<br>

***
'''

    @property
    def header(self) -> str:
        return f'''---
title: {self.title()} 
categories: 算法题解
description: 我好菜啊
tags:
  - {self.name}
cover: /img/chino/vec/chino{random.randint(1,60)}.jpg
katex: true
date: {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}
---

'''

    def brief(self, problem_num: int) -> str:
        head = '''<details>
  <summary>省流版</summary>

'''
        tail = '''

</details>
<br>
'''

        mid = '\n'.join([f"- {chr(65+i)}. <++>" for i in range(problem_num)])
        
        return head + mid + tail

    def get_problem(self) -> list:
        table_node = self.soup.find_all("table", class_=self.problem_table)
        trs = table_node[0].find_all("tr")
        self.problem_num = len(trs) - 1
        problems = []
        for i in range(self.problem_num):
            tr = trs[i + 1]
            tds = tr.find_all("td")
            a_tag = tds[1].find('a')

            problem_id = tds[0].get_text().strip()
            problem_name = problem_id + " - " + a_tag.get_text().strip()
            problem_url = urljoin(self.url, a_tag['href'])

            problems.append((problem_id, problem_name, problem_url))

        return problems

    def start(self, url: str):
        self.url = url
        res = self.request(self.url)
        res.raise_for_status()
        self.soup = BeautifulSoup(res.text, features="html.parser")
        self.log(self.header)

        problems = self.get_problem()
        self.problem_num = len(problems)
        self.log(self.brief(self.problem_num))

        print(f"find {self.problem_num} problem")

        for problem_id, problem_name, problem_url in problems:
            print(f"find [{problem_name}]")
            self.log(self.make_problem(problem_id, problem_name, problem_url))
        self.write()

    def request(self, url: str) -> requests.Response:
        return requests.get(url, headers=self.request_header, cookies=self.request_cookie)

    def title(self) -> str:
        if not self._title:
            self._title = self._title_method()
            print(f"title: {self._title}")
        return self._title

    def get_code(self, problem_id: str) -> str:
        p = problem_id.lower()
        fp = os.path.join(self.code_path, self.contest_id, p, f"{p}.cpp")
        if not os.path.exists(fp):
            print(f"{fp} not found!")
            return ""
        with open(fp, "r") as f:
            return f.read()

    def make_problem(self, problem_id: str, problem_name: str, problem_url: str) -> str:
        code = self.get_code(problem_id)
        return self.template.format(problem_name, self.abbr, self.contest_id, problem_id, problem_url, code)

    def write(self):
        with open(f"{self.title()}.md", "w") as f:
            f.write('\n'.join(self._log))
        print(f"Save in {self.title()}.md")

    def log(self, text:str):
        self._log.append(text)
