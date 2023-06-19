from parser.parser import Parser
import sys

# url1 = "https://atcoder.jp/contests/abc306/tasks"
# url2 = "https://codeforces.com/contest/1834"
# url3 = "https://codeforces.com/gym/104010"
# url4 = "https://ac.nowcoder.com/acm/contest/5157"

if len(sys.argv) < 2:
    print(f"python3 {sys.argv[0]} <url>")
    exit(-1)
url = sys.argv[1]

parser = Parser()
parser.start(url)
