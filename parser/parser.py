from .atcoder import Atcoder
from .codeforces import Codeforces
from .nowcoder import Nowcoder

class Parser():

    rules = {
            "atcoder" : Atcoder,
            "codeforces" : Codeforces,
            "nowcoder" : Nowcoder
            }

    def start(self, url: str):
        instance = None
        for key, value in self.rules.items():
            if key in url:
                instance = value()
        if instance is None:
            print("Unsupported url!")
            return

        instance.start(url)
