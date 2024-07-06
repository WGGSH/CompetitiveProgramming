#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  ll N, M, L, Q;
  cin >> N;

  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];

  cin >> M;
  vector<ll> B(M);
  rep(i, 0, M) cin >> B[i];

  cin >> L;
  vector<ll> C(L);
  rep(i, 0, L) cin >> C[i];

  cin >> Q;
  vector<ll> x(Q);
  rep(i, 0, Q) cin >> x[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  A.erase(unique(A.begin(), A.end()), A.end());
  B.erase(unique(B.begin(), B.end()), B.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  set <ll> sum_set;
  rep(i, 0, N) {
    rep(j, 0, M) {
      rep(k, 0, L) {
        sum_set.insert(A[i] + B[j] + C[k]);
      }
    }
  }

  rep(i, 0, Q) {
    bool result = sum_set.find(x[i]) != sum_set.end();
    cout << (result ? "Yes" : "No") << endl;
  }
}
