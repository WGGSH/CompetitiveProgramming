#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;

  transform(S.begin(), S.end(), S.begin(), ::toupper);

  // T が3文字の場合
  int count = (T.size() == 3 && T[2] != 'X') ? 3 : 2;
  bool result = true;
  rep(i, 0, count) {
    auto find_index = S.find(T[i]);
    if (find_index != string::npos) {
      S.erase(0, find_index + 1);
    } else {
      result = false;
      break;
    }
  }
  cout << (result ? "Yes" : "No") << endl;
}
