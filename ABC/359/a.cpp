#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }
  int count = 0;
  rep(i, N) {
    if (S[i] == "Takahashi") {
      count++;
    }
  }
  cout << count << endl;
}

