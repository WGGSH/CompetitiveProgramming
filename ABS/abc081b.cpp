#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  const int MAX_BIT = 32;
  int min = MAX_BIT;
  rep(i, N) {
    // cout << "-----" << endl;
    // cout << bitset<8>(A[i]) << endl;
    int shift_num = 0;
    rep(j, MAX_BIT) {
      if ((A[i] >> j) & 1) {
        shift_num = j;
        break;
      }
      // cout << bitset<8>(shifted) << endl;
    }
    // cout << "shift_num: " << shift_num << endl;
    if (shift_num < min) {
      min = shift_num;
    }
  }
  cout << min << endl;
}
