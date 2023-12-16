//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//            Phật phù hộ, không bao giờ BUG
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <locale>
#include <math.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <random>
#include <utility>
#include <vector>

#define ll long long
#define ii pair<int, int>
#define endl "\n"
#define watch(x) cerr << (#x) << " : " << (x) << endl

using namespace std;

template <class F>
struct y_combinator_result
{
  F f; // the lambda will be stored here
  // a forwarding operator():
  template <class... Args>
  decltype(auto) operator()(Args &&...args) const
  {
    // we pass ourselves to f, then the arguments.
    // the lambda should take the first argument as `auto&& recurse` or similar.
    return f(*this, forward<Args>(args)...);
  }
};
// helper function that deduces the type of the lambda:
template <class F>
y_combinator_result<decay_t<F>> y_combinator(F &&f)
{
  return {forward<F>(f)};
}
const int maxN = 1 << 19;
const int oo = 1e9 + 7;

void solve()
{
  // main function goes here
  // check testcases?
  // check bounds (0- or 1-indexed?)

  string s;
  ll ans = 0;

  const vector<string> nums_word{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  map<string, int> w2n;

  for (int i = 1; i <= 9; i++)
    w2n[nums_word[i - 1]] = i;

  while (getline(cin, s))
  {
    vector<int> nums;
    for (int i = 0; i < s.length(); i++)
      if (isdigit(s[i]))
        nums.push_back(s[i] - '0');
      else
      {
        for (int j = 3; j <= 5; j++)
        {
          string w = s.substr(i, j);
          if (w.length() == j && w2n.count(w))
          {
            nums.push_back(w2n[w]);
            // i += j;
            break;
          }
        }
      }
    // cout << nums << endl;
    ans += nums[0] * 10 + nums.back();
  }

  cout << ans << endl;
}

int main()
{
  // freopen("/Users/hoangpham/Documents/adventofcode/day1/part2/input.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcases = 1;
  // cin >> testcases;
  while (testcases--)
    solve();
}