#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int getMax(int X, int count, int value) {
  return min(X / value, count);
}

int main() {
  int N, Y;
  cin >> N >> Y;

  int maxX = getMax(Y, N, 10000);
  rep(x, maxX + 1) {
    int maxY = getMax(Y - x * 10000, N - x, 5000);
    rep(y, maxY + 1) {
      int maxZ = getMax(Y - x * 10000 - y * 5000, N - x - y, 1000);
      rep(z, maxZ + 1) {
        if (Y - x * 10000 - y * 5000 - z * 1000 == 0 && x + y + z == N) {
          cout << x << " " << y << " " << z << endl;
          return 0;
        }
        // cout << "[x, y, z] = [" << x << "," << y << "," << z << "]" << endl;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
}
