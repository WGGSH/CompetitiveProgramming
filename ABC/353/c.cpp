#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

const int MOD = 100000000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(A.begin(), A.end());

  // rep(i, N) {
  //   cout << A[i] << " ";
  // }
  // cout << endl;

  ll result = 0;

  ll sum = 0;
  ll mod_count = 0;
  rep(i, N) {
    sum += A[i] * (N - 1);

    // 残りの要素から，A[i] + A[j] >= MOD となる範囲を求める
    int j = A.end() - lower_bound(A.begin() + i + 1, A.end(), MOD - A[i]);
    mod_count += j;
  }
  sum -= mod_count * MOD;
  cout << sum << endl;

}
