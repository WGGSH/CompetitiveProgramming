#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> pos(N);

  rep(i, N) {
    cin >> pos[i].first >> pos[i].second;
  }

  sort(pos.begin(), pos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
  });

  vector<int> lefts(N);
  rep(i, N) {
    lefts[i] = pos[i].first;
  }

  unsigned long long count = 0;
  rep(i, N) {
    // cout << "i: " << i << " pos[i].first: " << pos[i].first << " pos[i].second: " << pos[i].second << endl;
    int j = upper_bound(lefts.begin(), lefts.end(), pos[i].second) - lefts.begin() - 1;
    // cout << "j: " << j << endl;
    count += j - i;
  }

  cout << count << endl;
}

