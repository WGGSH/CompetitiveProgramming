## [B - Maximum Difference](https://abc102.contest.atcoder.jp/tasks/abc102_b)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 200点

## 問題文
長さ*N*の整数列*A*が与えられます.*A*の（添字の）異なる2要素の差の絶対値の最大値を求めてください.

## 制約
* 2 <= *N* <= 100
* 1 <= *A<sub>i</sub> <= 10<sup>9</sup>
* 入力は全て整数である.

## 入力
入力は以下の形式で標準入力から与えられる.

```
N
A1 A2 ... AN
```

## 出力
Aの（添字の）異なる2要素の差の絶対値の最大値を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  vector<int> A;

  cin >> N;
  A.resize(N);
  for (auto &val : A){
    cin >> val;
  }

  int max = 0, min = 0;
  for(auto val : A){
    if(max==0 || max<val){
      max = val;
    }
    if(min==0 || min>val){
      min = val;
    }
  }

  cout << max - min << endl;
}
```

## 解説
最大値 - 最小値 が任意の2要素の差の絶対値の最大値となる.
