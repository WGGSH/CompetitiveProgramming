#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];

  ll result = 0;
  // cout << result << " ";
  for(auto a : A) {
    result += a;
    // cout << result << " ";
    if (result < 0) {
      result = 0;
    }
  }
  // cout << endl;

  cout << result << endl;
}
