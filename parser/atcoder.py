from .base import BaseParser

class Atcoder(BaseParser):
    
    @property
    def code_path(self) -> str:
        return "code/AtCoder"

    @property
    def request_cookie(self): # 有时候比赛剩下不会做，想写题解，但由于比赛还没结束，需要登录才能看题，可以F12获取登录cookie
        return {
            "REVEL_SESSION": ""
        }

    @property
    def name(self) -> str:
        return "atcoder"

    def _title_method(self) -> str:
        return self.soup.head.title.get_text().strip("Tasks - ")

    @property
    def problem_table(self) -> str:
        return "table"

    @property
    def contest_id(self) -> str:
        return self.url.split('/')[-2]

