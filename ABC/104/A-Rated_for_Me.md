# [A - Rated for Me](https://abc104.contest.atcoder.jp/tasks/abc104_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
プログラミングコンペティションサイト*AtCode*は,プログラミングコンテストを定期的に開催しています.
*AtCode*で次に開催されるコンテストはABCと呼ばれ,レーティングが1200未満の参加者のレーティングが変動します.
その次に開催されるコンテストはARCと呼ばれ,レーティングが2800未満の参加者のレーティングが変動します.
そのさらに次に開催されるコンテストはAGCと呼ばれ,全ての参加者のレーティングが変動します.
高橋くんの*AtCode*でのレーティングは *R* です.彼のレーティングが変動する次のコンテストは何でしょうか?

## 制約
* 0 <= *R* <= 4208
* *R* は整数である.

## 入力
入力は以下の形式で標準入力から与えられる.

`R`

## 出力
高橋くんのレーティングが変動する次のコンテストの名称（'<font color=red>ABC</font>', '<font color=red>ARC</font>', '<font color=red>AGC</font>' のいずれか）を出力せよ.

## 回答
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(void){
  int S;
  cin >> S;

  if(S<1200){
    cout << "ABC";
  }else if(S<2800){
    cout << "ARC";
  }else{
    cout << "AGC";
  }
  cout << endl;
}

```

## 解説
入力値に対して,1200,2800を条件として3通りの分岐を行う
