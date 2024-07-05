#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> B(N);
  rep(i, 0, N) B[A[i]] = i;

  vector<pair<int, int>> moves;

  rep(i, 0, N ) {
    int target = B[i];
    if (i == target) {
      continue;
    }
    B[i] = i;
    B[A[i]] = target;
    swap(A[i], A[target]);
    moves.push_back({i, target});
  }

  cout << moves.size() << endl;
  for (auto move : moves) {
    cout << move.first + 1 << " " << move.second + 1 << endl;
  }
}
