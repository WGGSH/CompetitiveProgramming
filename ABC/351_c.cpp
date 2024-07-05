#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];


  vector<ll> balls;
  rep(i, N) {
    balls.push_back(A[i]);
    if (balls.size() <= 1) continue;
    for(int j = balls.size() - 1; j > 0; j--) {
      if (balls.at(j) == balls.at(j - 1)) {
        balls.at(j - 1)++;
        balls.erase(balls.begin() + j);
      } else {
        break;
      }
    }
  }

  cout << balls.size() << endl;
}
