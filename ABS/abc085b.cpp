#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) cin >> d[i];

  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  cout << d.size() << endl;

}
