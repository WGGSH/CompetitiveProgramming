# [B - Skip](https://beta.atcoder.jp/contests/abc109/tasks/abc109_c)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 300点

## 問題文
数直線状に *N* 個の都市があり, *i* 番目の都市は座標 *x<sub>i</sub>* にあります.
あなたの目的は,これら全ての都市を1度以上訪れることです.
あなたは,はじめに正整数 *D* を設定します.
その後,あなたは座標 *X* から出発し,以下の移動1,移動2を好きなだけ行います.

* 移動1: 座標 *y* から座標 *y* + *D* に移動する
* 移動2: 座標 *y* から 座標 *y* - D に移動する

全ての都市を1度以上訪れることのできる *D* の最大値を求めてください.

## 制約
* 入力は全て整数である.
* 1 <= *M* <= 10<sup>5</sup>
* 1 <= *X* <= 10<sup>9</sup>
* 1 <= *x<sub>i</sub>* <= 10<sup>9</sup>
* *x* は全て異なる
* x<sub>1</sub> , x<sub>2</sub> , ... , x<sub>n</sub> ≠ *X*


## 入力
入力は以下の形式で標準入力から与えられる.

```
N X
x1 x2 ... xN
```

## 出力
全ての都市を1度以上訪れることのできる *D* の最大値を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  int N, X;
  vector<int> x;

  cin >> N >> X;
  x.resize(N);
  for(auto& val : x){
    cin >> val;
  }

  int D;

  // 初期地点をリストに追加する
  x.push_back(X);

  // 最も差の小さい2地点間の距離を,探索する最大数とする
  sort(x.begin(), x.end());
  vector<int> distanceList;
  for (int i = 0; i < N ;i++){
    distanceList.push_back(x[i + 1] - x[i]);
  }

  // 2点間の距離の最小値を求める
  int min = -1;
  for (auto val : distanceList){
    if(min==-1 || val <min){
      min = val;
    }
  }

  // 最小値をDの上限として,ループ開始
  for (int i = min; i >= 1; i--){
    // 点xの全てに対して,mod i の値が X にmod iをした場合と一致すれば解
    int mem = X % i;
    bool success = true;
    for (auto val : x){
      if (val % i != mem){
        success = false;
      }
    }
    if(success == true){
      cout << i << endl;
      return 0;
    }
  }
}

```

## 解説
剰余演算(mod)を利用する.例えば,初期座標 *X* が7で,移動する幅 *D* が4の時,移動先は3か11となる.
この時,移動前後の座標 7,3,11 全てに対して mod 4 (4は移動幅) を行うと,いずれも結果は3となる.つまり,移動の前後で移動幅に対する余剰演算を行った結果は変わらない.
そのため,目的地の座標全てと,初期座標に対して特定の値で余剰演算を行ったときに,その結果が全て同一であれば全ての都市を1度以上訪れることが可能だとわかる.

ただし,全ての都市を1度以上訪れることができる移動幅は複数存在し,問題の解として必要なものは,移動幅の最大値であるため,最も大きな移動幅*D* を求める必要がある.

そこで,まず最大値 *D* に成り得る可能性のある最も大きな値を求めて,それ以下の値から全ての都市を訪れることのできる移動幅を見つける.

例えば,都市の座標リストが( 2, 10, 4, 16 )の場合,10-4, 10-16はそれぞれ移動幅6で移動することができるが,2-4への移動は移動幅2または1でなければならない.
隣接する都市間の距離がその2都市間の移動に使用できる最大の幅となるので,年の座標に初期座標を加えたリストをソートし,隣接する都市間の距離リストを作成する.距離リストの中で最も値の小さいものを探索する最大値とする.

入力例1であれば 座標リストは( 1, 7, 11, 3)で,これをソートすると(1, 3, 7, 11) となる.
ここから距離リストを作成すると(2, 4, 4)となりその最小値2が,探索する最大値になる.2以下の正整数で全ての都市を訪れることのできる最も大きな値は2となりこれが解になる.
