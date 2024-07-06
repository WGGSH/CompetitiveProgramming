#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

using namespace std;

// ハッシュ関数の定義
struct hash_function {
  size_t operator()(const string& s) const {
    return hash<string>{}(s);
  }
};

int bfs(int N, const string& S, const string& T) {
  string start = S + "..";
  string goal = T + "..";

  if (start == goal) return 0;

  queue<pair<string, int>> q;
  q.push({start, 0});
  unordered_set<string, hash_function> visited;

  while (!q.empty()) {
    auto [current_state, step_count] = q.front();
    // cout << "q.front(): " << current_state << "," << step_count << endl;
    q.pop();

    // if (step_count > 2) {
    //   return -1;
    // }
    rep(i, 0, N + 2) {
      if (current_state[i] != '.'  && current_state[i + 1] != '.') {
        // 任意の2連続の文字と入れ替えて queue に追加
        rep(j, 0, N+2) {
          if(current_state[j] == '.' && current_state[j + 1] == '.') {
            string new_state = current_state;
            new_state[j] = current_state[i];
            new_state[j + 1] = current_state[i + 1];
            new_state[i] = '.';
            new_state[i + 1] = '.';

            if (new_state == goal) {
              // cout << "goal: " << goal << endl;
              return step_count + 1;
            }

            if (visited.find(new_state) == visited.end()) {
              // cout << new_state << "," << step_count + 1 << endl;
              visited.insert(new_state);
              q.push({new_state, step_count + 1});
            }
          }
        }
      }
    }
  }

  return -1;
}

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;

  int result = bfs(N, S, T);
  cout << result << endl;

  return 0;
}
