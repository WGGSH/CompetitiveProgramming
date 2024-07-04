#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<string> WORDS = { "maerd", "remaerd", "esare", "resare" };

int main() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  bool result = false;
  while(true) {

    bool is_success = false;
    // 対象の文字それぞれを先頭から含むか確認
    for(auto w: WORDS) {
      if (s.find(w) == 0) {
        s = s.substr(w.size());
        is_success = true;
        break;
      }
    }

    // 対象の文字が１つも見つからなければ失敗
    if (!is_success) {
      result = false;
      break;
    }


    // 反復して文字列が空になっていたら成功
    if (s.empty()) {
      result = true;
      break;
    }
  }

  cout << (result ? "YES" : "NO") << endl;
}
