# [A - Train](https://abc107.contest.atcoder.jp/tasks/abc107_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
*N*両編成の列車があります.この列車の前から*i*両目は,後ろから何両目でしょうか?

## 制約
* 1 < *N* < 100
* 1 <= *i* <= *N*

## 入力
入力は以下の形式で標準入力から与えられる.

`
N i
`


## 出力
答えを出力せよ.

## 回答
```cpp
#include <iostream>
using namespace std;

int main(void){
  int N,i;
  cin >> N >> i;
  cout << N + 1 - i;
}

```

## 解説
*N*+1-*i*が解
