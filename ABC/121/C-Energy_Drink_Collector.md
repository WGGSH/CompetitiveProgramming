# [C - Energy Dorink Collector](https://beta.atcoder.jp/contests/abc121/tasks/abc121_c)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 100点

## 問題文
栄養ドリンクにレーティング上昇効果があると聞いた高橋くんは，*M*本の栄養ドリンクを買い集めることにしました．
栄養ドリンクが売られている店は*N*軒あり，*i*軒目の店では1本  *A<sub>i</sub>* 円の栄養ドリンクを *B<sub>i</sub>* 本まで買うことができます．
最小で何円あれば *M* 本の栄養ドリンクを買い集めることができるでしょうか．
なお，与えられる入力では，十分なお金があれば *M* 本の栄養ドリンクを買い集められることが保証されます．

## 制約
* 入力は全て整数である．
* 1 &le; *N* , *M* &le; 10<sup>5</sup>
* 1 &le; *A<sub>i</sub>* &le; 10<sup>9</sup>
* 1 &le; *B<sub>i</sub>* &le; 10<sup>5</sup>
* *B<sub>1</sub>* + ... + *B<sub>N</sub>* &ge; *M*

## 入力
入力は以下の形式で標準入力から与えられる．
```
N  M
A1 B1
A2 B2
.
.
.
AN BN
```

## 解答
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  unsigned long N,M;
  cin >> N >> M;
  vector<unsigned long> A,B;
  vector<pair<unsigned long,unsigned long>> AB;
  AB.resize(N);
  for(unsigned long i=0;i<N;i++){
    cin>>AB[i].first>>AB[i].second;
  }

  sort(AB.begin(),AB.end());


  unsigned long money=0;
  unsigned long num = M;
  unsigned long min=-1;
  unsigned long minIndex=-1;
  for(auto pair:AB){
    if(pair.second>=num){
      money+=pair.first*num;
      break;
    }else{
      money+=pair.first*pair.second;
      num-=pair.second;
    }
  }

  cout<<money<<endl;
}

```

## 解説
出力や，途中計算に用いた数が*int型*の上限を超える可能性があるため，変数は *unsigned long型* を用いた．

最も安い店から順番に買い占めていくことで最小の金額で必要な本数を買い集めることができる．
