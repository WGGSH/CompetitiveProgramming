# [B - K-th Common Divisor](https://atcoder.jp/contests/abc120/tasks/abc120_b)
実行時間制限: 2sec / メモリ制限: 1024MB
配点: 200点

## 問題文
正整数*A*,*B* が与えられます．
*A* も *B* も割り切る正整数のうち， *K* 番目に大きい物を求めてください．
なお，与えられる入力では， *A* も *B* も割り切る正整数のうち *K* 番目に大きいものが存在することが保証されます．

## 制約
* 入力は全て整数である．
* 1 &le; *A* , *B* &le; 100
* *A* も *B* も割り切る正整数のうち， *K* 番目に大きいものが存在する
* *K* &ge; 1

## 入力
入力は以下の形式で標準入力から与えられる．
`
A B K
`

## 解答
```cpp
#include <iostream>
using namespace std;

int main(void){
  int A, B, K;
  cin >> A >> B >> K;

  int max = A > B ? A : B;
  int count = 0;
  for (int i = max; i > 0; i--){
    if(A%i == 0 && B%i ==0){
      count++;
      if(count==K){
        cout << i << endl;
        return 0;
      }
    }
  }
}

```

## 解説
*A* も*B* も割り切れる数のうち，最も大きい可能性があるのは *A* と *B* のうち小さい方である．
その数を最大値として，1つずつ値を減らし割り切れる値であるか確認をしていく
