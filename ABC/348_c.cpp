#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> AC(N);
  rep(i, 0, N) {
    ll a, b;
    cin >> a >> b;
    AC[i] = make_pair(a, b);
  }

  map<ll, ll> s;
  rep(i, 0, N) {
    if (s.count(AC[i].second) == 0) {
      s[AC[i].second] = AC[i].first;
    } else if (s[AC[i].second] > AC[i].first) {
      s[AC[i].second] = AC[i].first;
    }
  }

  // s の中から最大値を調べる
  auto ans = max_element(s.begin(), s.end(), [](auto a, auto b) { return a.second < b.second; });

  cout << ans->second << endl;
}
