#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> T(N);
  rep(i, N) cin >> T[i];

  int currentTime = 0;
  vector<int> completedTimes;

  rep(i, N) {
    if (currentTime <= T[i]) {
      currentTime = T[i] + A;
    } else {
      currentTime += A;
    }
    completedTimes.push_back(currentTime);
  }

  rep(i, N) {
    cout << completedTimes.at(i) << ' ';
  }
  cout << endl;
}
