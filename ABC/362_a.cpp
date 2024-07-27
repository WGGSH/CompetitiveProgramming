#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  vector<int> V(3);
  rep(i, 0, 3) cin >> V[i];
  string C;
  cin >> C;

  if (C == "Red") V.erase(V.begin());
  else if (C == "Green") V.erase(V.begin() + 1);
  else if (C == "Blue") V.erase(V.begin() + 2);

  sort(V.begin(), V.end());

  cout << V[0] << endl;
}
