#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int getMax(int X, int count, int value) {
  return min(X / value, count);
}

int main() {
  int A,B,C,X;
  cin >> A >> B >> C >> X;

  // 可能なAの枚数でループ
  int count = 0;
  int maxA = getMax(X, A, 500);
  rep(a, maxA + 1) {
    // 可能なBの枚数でループ
    int maxB = getMax(X - 500 * a, B, 100);
    rep(b, maxB + 1) {
      // 可能なCの枚数でループ
      int maxC = getMax(X - 500 * a - 100 * b, C, 50);
      rep(c, maxC + 1) {
        if (500 * a + 100 * b + 50 * c == X) {
          count++;
          // cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
        }
      }
    }
  }

  cout << count << endl;
}
