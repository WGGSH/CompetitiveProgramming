#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main(void){
  int N, M, Q;
  vector<int> p, q;

  cin >> N >> M >> Q;
  p.resize(Q);
  q.resize(Q);

  array<int, 2> LR[M];

  for (int i = 0; i < M;i++){
    cin >> LR[i][0] >> LR[i][1];
  }

  for (int i = 0; i < Q;i++){
    cin >> p[i] >> q[i];
  }

  //LRをソートする
  std::sort(&LR[0], &LR[M], [](auto &x, auto &y) { return x[0] < y[0]; });

  // 左端の新しい数字が始まる箇所を記したテーブルを作成
  vector<int> tableIndex;
  vector<int> tableNum;
  int lastNum = -1;
  for (int i = 0; i < M; i++){
    if(LR[i][0]!=lastNum){
      tableIndex.push_back(i);
      tableNum.push_back(LR[i][0]);
    }
    lastNum = LR[i][0];
  }

  // テーブルを元に,第二要素を再度ソートする
  int tableSize = tableIndex.size();
  for (int i = 0; i < tableSize;i++){
    std::sort(&LR[tableIndex[i]], &LR[(i==tableSize-1) ? M : tableIndex[i+1]], [](auto &x, auto &y) { return x[1] < y[1]; });
  }

  // ソートされた右側要素を元に,再度テーブルを作成する
  vector<vector<int>> rightTableIndex;
  vector<vector<int>> rightTableNum;

  rightTableIndex.resize(tableSize);
  rightTableNum.resize(tableSize);

  for (int i = 0; i < tableSize; i++){
    int lastNum = -1;
    rightTableIndex[i].clear();
    rightTableNum[i].clear();

    for (int j = tableIndex[i]; j < ((i == tableSize - 1) ? M : tableIndex[i + 1]); j++){
      if(LR[j][1]!=lastNum){
        rightTableIndex[i].push_back(j);
        rightTableNum[i].push_back(LR[j][1]);
      }
    }
  }

  // for (int i = 0; i < tableSize;i++){
  //   cout << tableNum[i] << ',' << tableIndex[i];
  //   for (int j = 0; j < rightTableIndex[i].size();j++){
  //     cout << "(" << rightTableIndex[i][j] << ":" << rightTableNum[i][j] << "), ";
  //   }
  //   cout << endl;
  // }

  // for (auto val : LR){
  //     cout << val[0] << ',' << val[1] << endl;
  // }

  // for (int i = 0; i < tableIndex.size();i++){
  //   cout << tableIndex[i] << ',' << tableNum[i] << endl;
  // }

  // 質問数だけループ
  for (int i = 0; i < Q; i++)
  {
    int count = 0;

    // テーブルの走査
    // pi 以上同じ値が出るまで探す
    int size = tableIndex.size();
    int index = -1;

    int j;

    for (j = 0; j < size; j++){
      if (p[i] <= tableNum[j]){
        index = tableIndex[j];
        break;
      }
    }

    for (int j = index; j < M;j++){
      // 右端テーブルの走査
      // qi以下の数が出るまで探す
      int size2 = rightTableIndex[tableNum[j]].size();
      int index2 = -1;

      for (int k = size2 - 1; k >= 0; k--)
      {
        if (rightTableNum[i][k] <= q[i])
        {
          index2 = rightTableIndex[i][k];
          break;
        }
      }
    }

      

    // if(index == -1 || index2 == -1){
    //   cout << 0 << endl;
    //   continue;
    // }




      // index ~ M だけの走査で個数がわかる
      for (int j = index; j < rightTableIndex[i][index2]; j++)
      {
        // if (LR[j][1] <= q[i])
        // {
        //   count++;
        // }
        count++;
    }
    cout << count << endl;
  }
}
