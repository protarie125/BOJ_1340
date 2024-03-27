#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

map<string, ll> M{{"January", 1},  {"February", 2},  {"March", 3},
                  {"April", 4},    {"May", 5},       {"June", 6},
                  {"July", 7},     {"August", 8},    {"September", 9},
                  {"October", 10}, {"November", 11}, {"December", 12}};
vl D{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll yy;
  string x, y, z;
  cin >> x >> y >> yy >> z;

  const auto& month = M[x];
  ll dd;
  {
    auto iss = istringstream{y.substr(0, y.length() - 1)};
    iss >> dd;
  }
  auto is_uruu = false;
  is_uruu = (0 == yy % 400) || ((0 == yy % 4 && 0 != yy % 100));

  auto total = double{365};
  if (is_uruu) {
    total += 1;
  }
  total *= 24;
  total *= 60;  // total minute

  ll hh;
  {
    auto iss = istringstream{z.substr(0, 2)};
    iss >> hh;
  }
  ll mm;
  {
    auto iss = istringstream{z.substr(3)};
    iss >> mm;
  }

  auto now = 0LL;
  for (auto i = 0LL; i < month - 1; ++i) {
    now += D[i];
    if (1 == i && is_uruu) {
      now += 1;
    }
  }
  now *= 24;
  now *= 60;

  for (auto i = 0; i < dd - 1; ++i) {
    now += 24 * 60;
  }

  for (auto i = 0; i < hh; ++i) {
    now += 60;
  }

  now += mm;

  cout << fixed << setprecision(12) << (100 * now) / total;

  return 0;
}