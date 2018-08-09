# [B - String Rotation](https://abc103.contest.atcoder.jp/tasks/abc103_b)
* 制限時間: 2sec / メモリ制限:1024MB
* 配点: 200点

## 問題文
英小文字からなる文字列*S*, *T* が与えられます.
*S* を回転させて*T* に一致させられるか判定してください.
すなわち, 以下の走査を任意の回数繰り返して*S*を*T*に一致させられるか判定してください.
操作: *S*=*S<sub>1</sub>S<sub>2</sub>...S<sub>|S|</sub>* のとき, *S*を*S<sub>|S|</sub>S<sub>1</sub>S<sub>2</sub>...S<sub>|S|-1*に変更する
ここで,|*X*|は文字列*X*の長さを表します.

## 制約
* 2 <= |*S*| <= 100
* |*S*| = |*T*|
* *S*, *T*は英小文字からなる

## 入力
入力は以下の形式で標準入力から与えられる.
```
S
T
```

## 出力
*S*を回転させて*T*に一致させられる場合は,'<font color= red>Yes</font>', 一致させられない場合は'<font color=red>No</font>'を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  string S, T;
  cin >> S >> T;

  bool success = false;

  int len = S.size();
  for (int i = 0; i < len;i++){
    char lastChar = S[len - 1];

    for (int j = len - 1; j >= 1; j--){
      S[j] = S[j - 1];
    }
    S[0] = lastChar;

    if(S==T){
      success = true;
      break;
    }
  }

  if(success){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

```
