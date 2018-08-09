# [B - AcCepted](https://abc104.contest.atcoder.jp/tasks/abc104_b)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 200点

## 問題文
文字列 *S* が与えられます. *S* のそれぞれの文字は英大文字または英小文字です. *S* が次の条件全て満たすかを判定してください.

* *S* の先頭の文字は大文字の '<font color=red> A </font>' である.
* *S* の先頭から3文字目と末尾から2文字めの間（両端含む）に大文字の '<font color=red> C </font>' がちょうど1個含まれる.
* 以上の ' <font color=red>A</font> ' ,  ' <font color=red>C</font> ' を除く *S* の全ての文字は小文字である.

## 制約
* 4<=|*S*|<=10
* *S*のそれぞれの文字は英大文字または英小文字である.

## 入力
入力は以下の形式で標準入力から与えられる.

`S`

## 出力
*S* が問題文中の条件全てを満たすなら ' <font color=red>AC</font> ' , そうでなければ ' <font color=red>WC</font> '  と出力せよ

## 回答
```cpp
#include <iostream>
#include <string>
using namespace std;

bool check(string s){
  //  文字数を確認
  if(s.size()<4 || s.size()>10){
    return false;
  }
  
  // 全ての文字を走査
  int index = 0;
  int uppercaseCount = 0;
  int cCount = 0;

  for (auto c : s){
    // 先頭文字が'A'か調べる
    if(index==0 && !(c=='A')){
      return false;
    }

    // 'C'を調べる
    if(index>=2 && index <=s.size()-2){
      if(c=='C'){
        cCount++;
      }
    }

    // 大文字の個数を調べる
    if(c>='A' &&c<='Z'){
      uppercaseCount++;
    }

    index++;
  }

  if(cCount!=1 || uppercaseCount!=2){
    return false;
  }

  return true;
}

int main(void){
  string S;
  cin >> S;
  bool result = check(S);
  if(result){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
}

```

## 解説
先頭文字から順に走査し,問題の条件を満たしているか書くにする
