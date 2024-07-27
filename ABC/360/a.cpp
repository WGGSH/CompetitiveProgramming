#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main(void) {
  string S;
  cin >> S;

  int R_index = S.find("R");
  int M_index = S.find("M");
  if (R_index < M_index) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
