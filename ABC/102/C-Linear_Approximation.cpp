#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int abs(int val){
  return val > 0 ? val : -val;
}

int main(void){
  int N;
  vector<int> A;
  cin >> N;
  A.resize(N);

  for(auto &val : A){
    cin >> val;
  }

  vector<int> B;
  B.resize(N);
  for (int i = 0; i < N;i++){
    B[i] = A[i] - (i + 1);
  }

  // 中央値を求める
  // 配列Bをソートする
  sort(B.begin(), B.end());

  int b;
  if(N%2==1){
    b = B[N / 2];
  }else{
    // N が偶数の場合は,中央値の前後の値のうち,より中央値に近い方を取る
    b = B[N / 2 ];
  }
  // cout << "b:" << b << endl;

  for(auto &val : B){
    // cout << abs(val) << endl;
    val -= b;
  }

  int ans = 0;

  for (auto val : B){
    ans += abs(val);
  }

  cout << ans << endl;
}
