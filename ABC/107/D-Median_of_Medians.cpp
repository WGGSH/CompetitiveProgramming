#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int N;
  vector<int> a;
  cin >> N;
  a.resize(N);

  for (int i = 0; i < N;i++){
    cin >> a[i];
  }

  vector<vector<int>> m;
  // 全てのmを生成する
  for (int l=0;l<N;l++){

    for (int r = l; r < N; r++){
      m.push_back(*new vector<int>);

      for (int i = l; i <= r; i++){
        m.back().push_back(a[i]);
      }
    }
  }

  vector<int> m2;
  // 各部分行列の中央値を求める
  for(auto &line : m){
    std::sort(line.begin(), line.end());
    m2.push_back(line[line.size() / 2]);
  }

  // 中央値の集合を再度ソート
  std::sort(m2.begin(), m2.end());
  cout << m2[m2.size() / 2] << endl;

  // for (auto line : m){
  //   cout << '{';

  //   for (auto val : line)
  //   {
  //     cout << val << ',';
  //   }
  //   cout << '}' << endl;
  // }

  // cout << "-----" << endl;
  for(auto median : m2){
    cout << median << ',';
  }
  cout << endl;
}
