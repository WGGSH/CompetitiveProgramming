#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  ll Q;
  cin >> Q;

  vector<pair<char, char>> cd(Q);
  rep(i, 0, Q) {
    cin >> cd[i].first >> cd[i].second;
  }

  // 各文字が何に変換されるかのテーブルを作る
  map<char, char> table;
  rep(i, 0, 26) {
    table['a' + i] = 'a' + i;
  }

  rep(i, 0, Q) {
    char c = cd[i].first;
    char d = cd[i].second;

    // table の全文字に対して，末尾が c のものに d を付与する
    rep(j, 0, 26) {
      if (table['a' + j] == c) {
        table['a' + j] = d;
      }
    }
  }

  // S の各文字を変換する
  for (char &c : S) {
    c = table[c];
  }

  cout << S << endl;
}
