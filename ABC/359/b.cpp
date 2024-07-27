#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N * 2);
  rep(i, N * 2) {
    cin >> A[i];
  }

  int count = 0;

  rep(i, N * 2 - 2) {
    if (A[i] == A[i + 2]) {
      count++;
    }
  }
  cout << count << endl;
}
