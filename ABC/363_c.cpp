#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

bool check(string s, ll K) {
  // 長さKの回文が含まれているかチェックする
  ll N = s.size() - K + 1;
  rep(i, 0, N) {
    bool is_palindrome = true;
    rep(j, 0, K / 2) {
      if (s[i + j] != s[i + K - 1 - j]) {
        is_palindrome = false;
        break;
      }
    }
    if (is_palindrome) {
      return true;
    }
  }

  return false;
}

int main() {
  ll N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  // S の文字を並び替えてできる全パターンを調べる
  sort(S.begin(), S.end());
  ll answer = 0;

  do {
    if (!check(S, K)) {
      answer++;
    }
  } while (next_permutation(S.begin(), S.end()));

  cout << answer << endl;

}
