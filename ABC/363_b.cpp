#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  ll N, T, P;
  cin >> N >> T >> P;
  vector<ll> L(N);
  rep(i, 0, N) cin >> L[i];

  sort(L.begin(), L.end(), greater<ll>());
  ll target = L[P-1];
  if (target >= T) {
    cout << 0 << endl;
    return 0;
  }

  cout << T - target << endl;
}
