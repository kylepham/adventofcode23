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

  vector<string> a;
  while (cin >> s)
    a.push_back(s);

  int n = a.size();
  int m = a[0].size();

  const vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
  const vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};

  auto ok = [&](int x, int y) -> bool
  {
    return x >= 0 && x < n && y >= 0 && y < m && isdigit(a[x][y]);
  };

  vector<vector<bool>> vis(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (!isdigit(a[i][j]) && a[i][j] != '.')
      {
        for (int k = 0; k < dx.size(); k++)
        {
          int u = i + dx[k];
          int v = j + dy[k];
          if (ok(u, v))
          {
            int v1 = v, v2 = v;
            while (ok(u, v1 - 1))
              v1--;
            while (ok(u, v2 + 1))
              v2++;

            for (int l = v1; l <= v2; l++)
              vis[u][l] = true;
          }
        }
      }
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] && (j == 0 || !vis[i][j - 1]))
      {
        ll num = 0;
        for (int k = j; k < m && vis[i][k]; k++)
          num = num * 10 + (a[i][k] - '0');
        ans += num;
      }
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