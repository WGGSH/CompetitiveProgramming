#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  // sum(A) + max(Bi - Ai)
  vector<ll> diff(N);
  rep(i, N) diff[i] = B[i] - A[i];
  ll max_diff = *max_element(diff.begin(), diff.end());

  ll sum_a = accumulate(A.begin(), A.end(), 0LL);
  cout << sum_a + max_diff << endl;
}
