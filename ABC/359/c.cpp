#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;
using ll = long long;


int main(void) {
  ll Sx, Sy, Tx, Ty;
  cin >> Sx >> Sy >> Tx >> Ty;

  // 最大の移動回数を確認
  ll maxX = abs(Tx-Sx);
  ll maxY = abs(Ty-Sy);


  // 対象の座標
  ll hoge = max(maxX, maxY);

  if ((Sx+Sy+Tx+Ty) % 4 == 1) {
    hoge--;
  }


  cout << hoge << endl;

}
