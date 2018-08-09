# [C - Modulo Summation](https://abc103.contest.atcoder.jp/tasks/abc103_c)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 300点

## 問題文
*N*個の正整数*a<sub>1</sub>*,*a<sub>2</sub>*,...,*a<sub>N</sub>* が与えられます.
非負整数*m*に対して, *f*(m) = (*m mod a<sub>1</sub>*) + (*m mod a<sub>2</sub>*) + ... + (*m mod a<sub>N</sub>*) とします.
ここで,*X mod Y* は,*X*を*Y*で割った余りを表します.
*f*の最大値を求めてください

## 制約
* 入力は全て整数である
* 2 <= *N* <= 3000
* 2 <= *a<sub>i</sub>* <= 10<sup>5</sup>

## 入力
入力は以下の形式で標準入力から与えられる
```
N
a1 a2 ... aN
```

## 出力
*f*の最大値を出力せよ

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  vector<int> a;

  cin >> N;
  a.resize(N);

  for (int i = 0; i < N; i++){
    cin >> a[i];
  }

  int ans = 0;

  for(auto val : a){
    ans += val;
  }
  ans -= N;

  cout << ans << endl;
}
```
