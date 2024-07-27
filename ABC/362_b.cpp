#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  vector<int> X(3);
  vector<int> Y(3);
  rep(i, 0, 3) cin >> X[i] >> Y[i];

  vector<int> d(3);
  rep(i, 0, 3) {
    int dx = X[(i + 1) % 3] - X[i];
    int dy = Y[(i + 1) % 3] - Y[i];
    d[i] = dx * dx + dy * dy;
  }
  sort(d.begin(), d.end());


  cout << (d[0] + d[1] == d[2] ? "Yes" : "No") << endl;
}
