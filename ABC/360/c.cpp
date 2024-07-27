#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main(void) {
  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> W(N);
  rep(i, N) {
    cin >> A.at(i);
  }
  rep(i, N) {
    cin >> W.at(i);
  }

  vector<int> max(N);
  int sum = 0;
  rep(i, N) {
    // cout << "i: " << i << ',' << A[i] << ',' << W[i] << endl;
    if (max[A[i]] != 0) {
      if (max[A[i]] < W[i]) {
        // cout << "add sum: " << W[i] << endl;
        sum += max[A[i]];
        max[A[i]] = W[i];
      } else {
        // cout << "add sum: " << max[A[i]] << endl;
        sum += W[i];
      }
    } else {
      max[A[i]] = W[i];
    }
    // if (max[A[i]] != 0 && max[A[i]] <= W[i]) {
    //   cout << "add sum: " << W[i] << endl;
    //   sum += max[A[i]];
    // }
  }
  // for(auto &m : max) {
  //   cout << m << endl;
  // }
  cout << sum << endl;
}
