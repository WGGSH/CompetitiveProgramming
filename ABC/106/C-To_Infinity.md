# [C - To Infinity](https://beta.atcoder.jp/contests/abc106/tasks/abc106_c)
* 時間制限: 2sec / メモリ制限 1000MB
* 配点: 300点

## 問題文
Mr.Infinityは'<font color=red>1</font>'から'<font color=red>9</font>'までの数字からなる文字列*S*を持っている．この文字列は，日付が変わるたびに次のように変化する．

* 文字列*S*に含まれるそれぞれの
'<font color=red>2</font>'が'<font color=red>22</font>'に，
'<font color=red>3</font>'が'<font color=red>333</font>'に，
'<font color=red>4</font>'が'<font color=red>4444</font>'に，
'<font color=red>5</font>'が'<font color=red>55555</font>'に，
'<font color=red>6</font>'が'<font color=red>666666</font>'に，
'<font color=red>7</font>'が'<font color=red>7777777</font>'に，
'<font color=red>8</font>'が'<font color=red>88888888</font>'に，
'<font color=red>9</font>'が'<font color=red>999999999</font>'に置き換わる．
'<font color=red>1</font>'は'<font color=red>1</font>'のまま残る．

例えば，*S*が'<font color=red>1324</font>の場合，翌日には'<font color=red>1333224444</font>'になり，翌々日には'<font color=red>133333333322224444444444444444</font>'になる．
あなたは5000兆日後に文字列がどのようになっているか知りたい．5000兆日後の文字列の左から*K*文字目は何か?

## 制約
* *S*は1文字以上100文字以下の文字列
* *K*は1以上10<sup>18</sup>以下の整数
* 5000兆日後の文字列の長さは，*K*文字以上である．

## 入力
入力は以下の形式で標準入力から与えられる．

```
S
K
```

## 出力
5000兆日後にMr.Infinityが持っている文字列の*K*文字目の数字を出力しなさい．

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  string S;
  unsigned long K;
  cin >> S >> K;

  int count1 = 0;
  int i;
  for (i = 0; i < S.size(); i++){
    if(S[i] =='1'){
      count1++;
    }else{
      break;
    }
  }

  if(count1>=K){
    cout << 1<<endl;
  }else{
    cout << S[i] << endl;
  }
}
```

## 解説
1日毎に行われる文字の置換により，それぞれの文字を*n*とすると，5000兆日後には，各文字が*n<sup>5x10<sup>15</sup></sup>* 個連続で並んだものをつなげた文字列に置き換わる
先頭文字が2の場合，*2<sup>5x10<sup>15</sup></sup>* > *10<sup>18* となるので，左から*K*番目の文字は入力文字列*S*の先頭文字になる．同様に，先頭文字が2から9の場合は全て左から*K*番目の文字は入力文字列*S*の先頭文字になる．
先頭文字が1の場合，．*1<sup>5x10<sup>15</sup></sup>* = *1* となり，先頭文字から連続した1の数だけ，置換後の文字列の先頭に1がつくことになる．よって，先頭から連続する1の個数と*K*を比較することで，出力文字が1か，1以外で初めて現れる文字かを判定できる．

### 入力例
```
111134
2
```
の場合，置換された文字列は，'<font color=red>111133333333333...</font>'となり，左から2番目の文字は1になる．
