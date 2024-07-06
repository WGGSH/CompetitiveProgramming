#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

bool check_2(ll N) {
  string str = to_string(N);
  string reverse_str = str;
  reverse(reverse_str.begin(), reverse_str.end());

  return str == reverse_str;
}

ll cube(ll N) {
  return N * N * N;
}

int main() {
  ll N;
  cin >> N;


  // 対象の値の3乗根を求め，その値から1ずつ減らしていき，その値の3乗が回文数かどうかを調べる
  ll cbrt_N = int(cbrtl(N));
  for(ll i = cbrt_N; i > 0; i--) {
    ll cube_i = cube(i);
    if (check_2(cube_i)) {
      cout << cube_i << endl;
      return 0;
    }
  }
}
