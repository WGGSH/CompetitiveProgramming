#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int getBitCout(int bit) {
  int count = 0;
  while (bit) {
    count += bit & 1;
    bit >>= 1;
  }
  return count;
}

int main(void) {
  int N,M,K;

  cin >> N >> M >> K;

  vector<int> C(M);
  vector<vector<int>> A(M);
  vector<bool> R(M);
  rep(i, M) {
    cin >> C[i];
    A[i].resize(C[i]);
    rep(j, C[i]) {
      cin >> A[i][j];
    }
    string r;
    cin >> r;
    if (r == "o") {
      R[i] = true;
    } else {
      R[i] = false;
    }
  }
  vector<int> bitA(M);

  rep(i, M) {
    // 使っている鍵の番号に応じた bit を建てる
    // 1 → 0 / 1
    // 2 → 0 / 2
    // 3 → 0 / 4
    rep(j, C[i]) {
      bitA[i] |= 1 << (A[i][j] - 1);
    }
    // cout << bitset<3>(bitA[i]) << ":" << bitA[i] << endl;
  }

  int max = 1 << N;
  int result = 0;
  rep(i, max) {
    bool success = true;
    // cout << "-----" << endl;
    // cout << bitset<4>(i) << ":" << i << endl;
    rep(j, M) {
      int bitCount = getBitCout(i & bitA[j]);
      // cout << R[j] << ":" << bitA[j] << "→" << bitset<4>(bitA[j]) << ":" << bitCount << endl;
      if ((bitCount < K) == R[j]) {
        success = false;
        break;
      }
    }
    if (success) {
      // cout << bitset<4>(i) << ":" << i << endl;
      result++;
    }
  }

  cout << result << endl;
}
