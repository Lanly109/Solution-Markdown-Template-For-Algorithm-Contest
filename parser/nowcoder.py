from .base import BaseParser

class Nowcoder(BaseParser):
    
    @property
    def code_path(self) -> str:
        return "/Users/lanly/Documents/Code/OJ/nowcoder/contests"

    @property
    def name(self) -> str:
        return "nowcoder"

    @property
    def abbr(self) -> str:
        return "Nowcoder"

    def _title_method(self) -> str:
        return self.soup.head.title.get_text().split('_')[0]

    @property
    def problem_table(self) -> str:
        return "table-hover"

    @property
    def contest_id(self) -> str:
        return self.url.split('/')[-1]

    def get_problem(self):
        res = self.request(f"https://ac.nowcoder.com/acm/contest/problem-list?id={self.contest_id}").json()
        problems = []
        for problem in res['data']['data']:
            problem_id = problem['index']
            problem_name = problem_id + " - " + problem['title']
            problem_url = self.url + "/" + problem_id
            problems.append((problem_id, problem_name, problem_url))
           
        return problems
