#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  string s;
  cin >> s;

  vector<char> v(s.begin(), s.end());
  int sum = accumulate(v.begin(), v.end(), 0, [](int acc, char c) {
    return acc + int(c == '1');
  });
  cout << sum << endl;
}
