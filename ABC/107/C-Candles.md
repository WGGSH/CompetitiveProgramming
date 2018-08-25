# [C - Candles](https://abc107.contest.atcoder.jp/tasks/arc101_a)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 300点

## 問題文
数直線状に *N* 本のろうそくが置かれています.左から *i* 番目のろうそくは座標 *x<sub>i</sub>* に置かれています. ただし, *x<sub>1</sub>* < *x<sub>2</sub>* < ... *x<sub>N</sub>* が成り立ちます.
最初,どのろうそくにも火が付いていません.すぬけ君は, *N* 本のうち *K* 本のろうそくに火を付けることにしました.
今,すぬけ君は座標 *0* にいます.すぬけ君は,数直線状を左右に速度 *1* で移動することができます.また,自分と同じ座標のろうそくに火を付けることができます.この時,火を付けるのにかかる時間は無視できます.
*K* 本の老僧に火を付けるのに必要な最小の時間を求めてください.

## 制約
* 1 <= *N* <= 10<sup>5</sup>
* 1 <= *K* <= *N*
* *x<sub>i</sub>* は整数である
* | *x<sub>i</sub>* | <= 10<sup>8</sup>
* *x<sub>1</sub>* < *x<sub>2</sub>* < ... < *x<sub>N</sub>*

## 入力
入力は以下の形式で標準入力から与えられる
```
N K
x1 x2 ... xN
```

## 出力
*K* 本のろうそくに火を付けるのに必要な最小の時間を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int getTime(int left,int right){
  // 両者正の場合
  if(left>=0 && right>=0){
    return right;
  }

  // 両者負の場合
  if(left<=0 && right<=0){
    return -left;
  }

  // 正負混合の場合
  return (-left > right) ? (-left + right * 2) : (-left * 2 + right);
}

int main(void){
  int N, K;
  vector<int> x;
  cin >> N >> K;
  x.resize(N);

  for (int i = 0; i < N;i++){
    cin >> x[i];
  }

  int min = -1;

  for (int i = 0; i < N - K + 1; i++){
    int left = x[i];
    int right = x[i + K - 1];
    int time = getTime(left, right);
    if(min==-1 || min>time){
      min = time;
    }
  }
  cout << min << endl;
}
```

## 解説
最小になりうる,火を付けるろうそくの組み合わせは,より原点に近い,連続した *K* 本となる.
そこで,連続した *K* 本のろうそくに火を付ける場合のパターン全てに対して,必要な時間を計算し,その最小値を求めた.
パターン数は *N-K* 通りとなる.
必要な時間は,*K* 本のろうそくのうち,両端の2本の位置と原点の位置関係によって導出方法が異なる.
全てのろうそくが原点より正側,または全て原点より負側にある場合,原点から最も遠いろうそくの座標が必要な時間と同値になる.
左端のろうそくが負,右端のろうそくが正の場合,一度片側のろうそくに火をつけ原点に戻ってくる時間が必要になる.
そのため,左端と右端のうち近い方の距離に2倍した値と,もう一方の端の距離との和が必要な時間となる.
