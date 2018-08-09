# [A - Task Scheduling Problem](https://abc103.contest.atcoder.jp/tasks/abc103_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
3個のタスクがあり,あなたは全てのタスクを完了させなければなりません.
はじめ,任意の1このタスクをコスト0で完了できます.
また,***i*** 番目のタスクを完了した直後にコスト|*A<sub>j</sub>* - *A<sub>i</sub>*|で *j* 番目のタスクを完了できます.
ここで|***x***| は ***x*** の絶対値を表します.
全てのタスクを完了するのに要する合計コストの最小値を求めてください.

## 制約
* 入力は全て整数である.
* 1 <= *A<sub>1</sub>* , *A<sub>2</sub>* , *A<sub>3</sub>* <= 100

## 入力
入力は以下の形式で標準入力から与えられる.

` A1 A2 A3`

# 出力
全てのタスクを完了するのに要する合計コストの最小値を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int A[3];
  cin >> A[0] >> A[1] >> A[2];

  int minScore = -1;

  // 3!パターン存在する
  for (int i = 0; i < 6;i++){
    int score = 0;
    int preIndex;
    for (int j = 0; j < 3; j++)
    {
      int index = ((i / 2) + j * ((i % 2) * 2 - 1) + 3) % 3;

      if (j == 0){
        preIndex = index;
        continue;
      }

      score += A[index] - A[preIndex] > 0 ? A[index] - A[preIndex] : A[preIndex] - A[index];

      preIndex = index;
    }
    if(minScore==-1 || minScore>score){
      minScore = score;
    }
  }

  cout << minScore << endl;
}

```

## 解説
タスクの選択する順序によってコストが変わるため,その全てを調べることで最小値が得られる.
タスクの数は3つなので,*3! = 6*通りについて実際にコストを求める
