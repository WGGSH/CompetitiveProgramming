#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int D, G;
  vector<int> p, c;
  cin >> D >> G;
  p.resize(D);
  c.resize(D);

  for (int i = 0; i < D;i++){
    cin >> p[i] >> c[i];
  }

  // アプローチ
  // 最も点数の高い問題から順に解いた場合の問題数を取得し,
  // そこにそれぞれのコンプリートボーナスがあった場合と比較する
  // 2^D
  int score = 0;
  int min = -1;
  int maxApproach = 1;
  for (int i = 0; i < D;i++){
    maxApproach *= 2;
  }

  for (int i = 0; i < maxApproach;i++){
    int score = G;
    int count = 0;
    vector<int> completeIndexList;
    int pow = 1;
    for (int j = 0; j < D;j++){
      pow *= 2;
      if(i%pow>=pow/2){
        completeIndexList.push_back(j);
      }
    }
    // for (auto val: completeIndex){
    //   cout << val << ",";
    // }
    // cout << endl;

    // コンプリートを前提とした箇所のスコアと問題数を加算する
    for(auto index : completeIndexList){
      score -= (p[index] * (index + 1) * 100 + c[index]);
      count += p[index];
    }
    // コンプリートしていない得点の問題を,点数が高い順に解いていく
    for (int j = D - 1; j >= 0;j--){
      // 既に目標スコアを満たしていれば終了
      if(score<0){
        break;
      }

      bool isCompleted = false;
      for(auto index : completeIndexList){
        if(j==index){
          isCompleted = true;
        }
      }
      if(isCompleted==true){
        continue;
      }

      int solveCount = score / (100 * (j + 1));
      if(solveCount>p[j]){
        solveCount = p[j];
      }
      score -= solveCount * (100 * (j + 1));
      count += solveCount;
      if (solveCount == p[j]){
        // コンプリートボーナスを加算
        score -= c[j];
      }
    }
    // 現在の施行における回答数
    // cout << count << endl;
    if(min==-1 || min>count){
      min = count;
    }
  }

  // 結果を表示
  cout << min << endl;
}
