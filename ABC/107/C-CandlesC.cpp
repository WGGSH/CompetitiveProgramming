#include <iostream>
#include <vector>
using namespace std;

int getTime(int left,int right){
  // 両者正の場合
  if(left>=0 && right>=0){
    return right;
  }

  // 両者負の場合
  if(left<=0 && right<=0){
    return -left;
  }

  // 正負混合の場合
  return (-left > right) ? (-left + right * 2) : (-left * 2 + right);
}

int main(void){
  int N, K;
  vector<int> x;
  cin >> N >> K;
  x.resize(N);

  for (int i = 0; i < N;i++){
    cin >> x[i];
  }

  int min = -1;

  for (int i = 0; i < N - K + 1; i++){
    int left = x[i];
    int right = x[i + K - 1];
    int time = getTime(left, right);
    if(min==-1 || min>time){
      min = time;
    }
  }
  cout << min << endl;
}
