#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

bool is_cross(int a, int b, int c, int d) {
  return max(a, c) < min(b, d);
}

int main() {
  vector<int> A(6);
  vector<int> B(6);
  rep(i, 0, 6) cin >> A[i];
  rep(i, 0, 6) cin >> B[i];

  bool result = false;
  result = is_cross(A[0], A[3], B[0], B[3]) && is_cross(A[1], A[4], B[1], B[4]) && is_cross(A[2], A[5], B[2], B[5]);


  cout << (result ? "Yes" : "No") << endl;
}
