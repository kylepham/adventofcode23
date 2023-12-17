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
    stringstream ss(s);
    string substr;
    vector<string> ans;

    while (getline(ss, substr, delimiter))
      ans.push_back(trim(substr));

    return ans;
  };

  string s;
  ll ans = 0;

  while (getline(cin, s))
  {
    vector<string> result;

    result = split(s, ':');
    ll id = stoi(split(result[0], ' ')[1]);

    result = split(result[1], ';');
    int mR = 0, mG = 0, mB = 0;
    for (string set : result)
    {
      int r = oo, g = oo, b = oo;
      vector<string> rounds = split(set, ',');
      for (string round : rounds)
      {
        vector<string> temp = split(round, ' ');
        int cnt = stoi(temp[0]);
        string color = temp[1];
        if (color == "red")
          r = min(r, cnt);
        else if (color == "green")
          g = min(g, cnt);
        else
          b = min(b, cnt);
      }
      mR = max(mR, r == oo ? 0 : r);
      mG = max(mG, g == oo ? 0 : g);
      mB = max(mB, b == oo ? 0 : b);
    }

    ans += 1ll * mR * mG * mB;
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