from .base import BaseParser

class Codeforces(BaseParser):
    
    @property
    def code_path(self) -> str:
        return "/Users/lanly/Documents/Code/OJ/cf/" + ("contest" if len(self.contest_id) <= 4 else "gym")

    @property
    def request_cookie(self): # 有时候有cloudflare，可以F12里的cookie获取这个字段绕过
        return {
            "RCPC": "32209d40519fff5e97617e41000f0e48"
        }

    @property
    def name(self) -> str:
        return "codeforces"

    @property
    def abbr(self) -> str:
        return "CF"

    @property
    def problem_table(self) -> str:
        return "problems"

    def _title_method(self) -> str:
        return self.soup.find(attrs="rtable").find(attrs="left").get_text().strip()

    @property
    def contest_id(self) -> str:
        return self.url.split('/')[-1]

