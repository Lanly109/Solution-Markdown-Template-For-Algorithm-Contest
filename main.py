from parser.parser import Parser
import sys

url = ""

# url = "https://atcoder.jp/contests/abc371/tasks"
# url = "https://codeforces.com/contest/1857"
# url = "https://codeforces.com/gym/101522"
# url = "https://ac.nowcoder.com/acm/contest/49259"

if not url and len(sys.argv) < 2:
    print(f"python3 {sys.argv[0]} <url>")
    exit(-1)
elif not url:
    url = sys.argv[1]

parser = Parser()
parser.start(url)
