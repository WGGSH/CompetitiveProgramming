# [A - Multiple of 2 and N](https://abc102.contest.atcoder.jp/tasks/abc102_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
正整数*N*が与えられます.2と*N*のどちらでも割り切れる最小の正整数を求めてください.

## 制約
* 1 <= *M* <= 10<sup>9</sup>
* 入力は全て整数である.

## 入力
入力は以下の形式で標準入力から与えられる.

`
N
`

## 出力
2と*N*のどちらでも割り切れる最小の正整数を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin >> N;

  int result;
  if(N%2==0){
    result = N;
  }else{
    result = N * 2;
  }

  cout << result << endl;
}

```

## 解説
入力値*N*が2で割り切れる（=偶数）場合,最小値は*N*になる.
入力値*N*が2で割り切れない（=奇数）場合,最小値は2*N*になる.
