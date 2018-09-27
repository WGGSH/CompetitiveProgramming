# [A - ABC333](https://beta.atcoder.jp/contests/abc109/tasks/abc109_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
1以上3以下の整数 *A* , *B* が与えられます.
*A* × *B* × *C* が奇数となるような1以上3以下の整数 *C* が存在するか判定してください

## 制約
* 入力は全て整数である
* 1 <= *A* , *B* <= 3

## 入力
入力は以下の形式で標準入力から与えられる.

`
A B
`


## 出力
条件を満たすような*C*が存在するなら ' <font color = red>Yes</font> ' , そうでないなら ' <font color = red>No</font> 'を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
  int A, B;

  cin >> A >> B;
  if(A%2==0 || B%2==0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
```

## 解説
*A* と *B* の両方が奇数ならYes, 一方でも偶数が含まれていればNoになる
