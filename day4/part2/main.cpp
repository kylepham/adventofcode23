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

  auto trim = [&](string s) -> string
  {
    int i = 0;
    while (s[i] == ' ')
      i++;
    while (s.back() == ' ')
      s.pop_back();

    return s.substr(i, s.length());
  };

  auto split = [&](string s, char delimiter) -> vector<string>
  {
    stringstream ss(trim(s));
    string substr;
    vector<string> ans;

    while (getline(ss, substr, delimiter))
    {
      substr = trim(substr);
      if (substr.length())
        ans.push_back(substr);
    }

    return ans;
  };

  string s;
  ll ans = 0, id = 0;
  vector<int> num_cards(maxN, 1);

  while (getline(cin, s))
  {
    ans += num_cards[++id];
    ll cnt = 0;

    string card = split(s, ':')[1];
    vector<string> winning_numbers = split(split(card, '|')[0], ' ');
    vector<string> numbers_you_have = split(split(card, '|')[1], ' ');
    map<string, bool> m;
    for (auto &x : winning_numbers)
      m[x] = true;

    for (auto &x : numbers_you_have)
      cnt += m.count(x) > 0;

    for (int i = id + 1; i <= id + cnt; i++)
      num_cards[i] += num_cards[id];
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcases = 1;
  // cin >> testcases;
  while (testcases--)
    solve();
}