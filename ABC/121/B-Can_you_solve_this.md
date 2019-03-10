# [B - Can you solve this?](https://beta.atcoder.jp/contests/abc121/tasks/abc121_b)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
*N*個のソースコードがあり*i*個目のソースコードの特徴は*A<sub>i1</sub>* , *A<sub>i2</sub>* , ... , *A<sub>iM</sub>*の*M*個の整数で表されます．
また，整数*B<sub>1</sub>*, *B<sub>2</sub>*, ... , *B<sub>M</sub>* と整数*C*が与えられます．
*A<sub>i1</sub>* *B<sub>1</sub>* + *A<sub>i2</sub>* *B<sub>2</sub>* + ... + *A<sub>iM</sub>* *B<sub>M</sub>* + *C* > 0 のときに限り，*i*個目のソースコードはこの問題に正答するソースコードです．
*N*個のソースコードのうち，この問題に正答するソースコードの個数を求めてください．

## 制約
* 入力は全て整数である．
* 1 &le; *N* , *M* &le; 20
* -100 &le; *A<sub>ij</sub>* &le; 100
* -100 &le; *B<sub>ij</sub>* &le; 100
* -100 &le; *C* &le; 100

## 入力
入力は以下の形式で標準入力から与えられる
```
N   M   C
B1  B2  ...  BM
A11 A12 ...  A1M
A21 A22 ...  A2M
.
.
.
AN1 AN2 ...  ANM
```

## 出力
*N*個のソースコードのうち，この問題に正答するソースコードの個数を出力せよ

## 解答
```cpp
#include <iostream>
#include <vector>
using namespace std;


int main(void){
  int N,M,C;
  cin >> N >> M >> C;
  vector<int> B;
  vector<vector<int>> A;

  B.resize(M);
  for(int i=0;i<M;i++){
    cin>>B[i];
  }

  A.resize(N);
  for(int i=0;i<N;i++){
    A[i].resize(M);
    for(int j=0;j<M;j++){
      cin>>A[i][j];
    }
  }

  int answer=0;
  for(auto index : A){
    int valueLeft=C;
    for(int j=0;j<M;j++){
      valueLeft+=index[j]*B[j];
    }
    if(valueLeft>0){
      answer++;
    }
  }

  cout<<answer<<endl;
}

```

## 解説
全てのソースコードに対して，計算結果を求め，正しいソースコードの数を数える
