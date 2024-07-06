#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];

  A.insert(A.begin() + K, X);

  rep(i, 0, N + 1) {
    cout << A[i];
    if (i < N) cout << " ";
  }
  cout << endl;

}
