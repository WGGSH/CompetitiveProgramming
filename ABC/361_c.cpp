#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

ll INF = 1e18;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];

  sort(A.begin(), A.end());

  // rep(i, 0, N) {
  //   cout << A[i] << " ";
  // }
  // cout << endl;

  ll sum = 0;
  rep(i, 0, K) {
    sum += A[i];
  }

  // A + B = K
  // 左端から A 個, 右端から B 個取る
  // 取ったあとの A の最大値 - 最小値が最も小さいケースを調べる

  ll min = INF;
  rep(i, 0, K + 1) {
    ll left = A[i];
    ll right = A[N - K + i - 1];
    // ll ans = min(abs(left), abs(right));
    ll ans = right - left;
    if (ans < min) {
      min = ans;
    }
    // cout << "A: " << left << " B: " << right << " ans: " << ans << endl;
  }

  cout << min << endl;

}
