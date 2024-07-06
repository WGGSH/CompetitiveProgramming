#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  int N;
  ll K;
  cin >> N >> K;

  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];

  // 1 以上K以下の整数のうち， A に含まれないものの総和を求める
  // 1~Kまでの整数の総和 - Aに含まれる整数の総和

  ll sum = K * (K + 1) / 2;

  sort(A.begin(), A.end());

  A.erase(unique(A.begin(), A.end()), A.end());
  for(auto a : A) {
    if (a <= K) {
      sum -= a;
    } else {
      break;
    }
  }

  cout << sum << endl;
}
