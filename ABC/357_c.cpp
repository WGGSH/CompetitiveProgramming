#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

using namespace std;

int pow(int x, int n) {
  int res = 1;
  rep(i, 0, n) {
    res *= x;
  }
  return res;
}

void recursive(vector<vector<bool>>& field, int N, int x, int y) {
  if (N == 0) {
    return;
  }

  // 1セルのサイズ
  int next = N - 1;
  int size = pow(3, next);

  // 中央のセル内の要素はすべて true
  rep(i, 0, size) {
    rep(j, 0, size) {
      field[x + size + i][y + size + j] = true;
    }
  }

  recursive(field, next, x, y);
  recursive(field, next, x + size, y);
  recursive(field, next, x + size * 2, y);
  recursive(field, next, x, y + size);
  recursive(field, next, x + size * 2, y + size);
  recursive(field, next, x, y + size * 2);
  recursive(field, next, x + size, y + size * 2);
  recursive(field, next, x + size * 2, y + size * 2);
}

int main() {
  int N;
  cin >> N;

  int size = pow(3, N);
  // cout << size << endl;
  vector<vector<bool>> field(size, vector<bool>(size, false));

  recursive(field, N, 0, 0);

  rep(i, 0, size) {
    rep(j, 0, size) {
      cout << (field[i][j] ? '.' : '#');
    }
    cout << endl;
  }
}
