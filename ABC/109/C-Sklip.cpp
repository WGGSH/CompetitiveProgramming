#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  int N, X;
  vector<int> x;

  cin >> N >> X;
  x.resize(N);
  for(auto& val : x){
    cin >> val;
  }

  int D;

  // 初期地点をリストに追加する
  x.push_back(X);

  // 最も差の小さい2地点間の距離を,探索する最大数とする
  sort(x.begin(), x.end());
  vector<int> distanceList;
  for (int i = 0; i < N ;i++){
    distanceList.push_back(x[i + 1] - x[i]);
  }

  // 2点間の距離の最小値を求める
  int min = -1;
  for (auto val : distanceList){
    if(min==-1 || val <min){
      min = val;
    }
  }

  // 最小値をDの上限として,ループ開始
  for (int i = min; i >= 1; i--){
    // 点xの全てに対して,mod i の値が X にmod iをした場合と一致すれば解
    int mem = X % i;
    bool success = true;
    for (auto val : x){
      if (val % i != mem){
        success = false;
      }
    }
    if(success == true){
      cout << i << endl;
      return 0;
    }
  }
}
