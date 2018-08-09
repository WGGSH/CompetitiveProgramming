# [C - All Green](https://abc104.contest.atcoder.jp/tasks/abc104_c)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 300点

## 問題文
プログラミングコンペティションサイト*AtCode*は,アルゴリズムの問題集を提供しています.それぞれの問題には,難易度に応じて点数がつけられています.
現在,1以上 ***D*** 以下のそれぞれの整数 ***i*** に対して,100 ***i*** 点をつけられた問題が ***p<sub>i</sub>*** 問存在します.これらの ***p<sub>i</sub>*** + ... + ***p<sub>D</sub>*** 問が*AtCode*に収録された問題の全てです.
*AtCode*のユーザーは総合スコアと呼ばれる値を持ちます.ユーザーの総合スコアは,以下の2つの要素の和です.
* 基本スコア: ユーザーが解いた問題全ての配点の合計です.
* コンプリートボーナス: 100 ***i*** 点を着けられた ***p<sub>i</sub>*** 問の問題全てを解いたユーザーは,基本スコアと別にコンプリートボーナス ***c<sub>i</sub>*** 点を獲得します (1<=***i***<=***D***).
*AtCode*の新たなユーザーとなった高橋くんは,まだ問題を1問も解いていません.彼の目標は,総合スコアを ***G*** 点以上にすることです.このためには,少なくとも難問の問題を解く必要があるでしょうか?

## 制約
* 1<= ***D*** <=10
* 1<= ***P<sub>i</sub>*** <=100
* 100 <= ***c<sub>i</sub>*** <= 10<sup>6</sup>
* 100 <= ***G***
* 入力中の全ての値は整数である.
* ***C<sub>i</sub>*** , ***G*** は全て100の倍数である.
* 総合スコアを ***G*** 点以上にすることは可能である.

## 入力
入力は以下の形式で標準入力から与えられる.
```
D  G
p1 c1
.
.
pD cD
```

## 出力
総合スコアを ***G*** 点以上にするために得必要のある最小の問題数を出力せよ.なお,この目標は必ず達成可能である（制約を参照のこと）.

## 回答
```cpp
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
```
