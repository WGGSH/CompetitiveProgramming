# [B - Shiritori](https://beta.atcoder.jp/contests/abc109/tasks/abc109_b)
* 時間制限: 2sec / メモリ制限: 1024MB
* 配点: 200点

## 問題文
高橋くんは今日も1人でしりとりの練習をしています.

しりとりは以下のルールで遊ばれるゲームです.

* はじめ,好きな単語を発言する
* 以降,次の条件を満たす単語を発言することを繰り返す
  * その単語はまだ発言していない単語である
  * その単語の先頭の文字は直前に発言した単語の末尾の文字と一致する

高橋くんは,10秒間にできるだけ多くの単語を発言する練習をしています.
高橋くんが発言した単語の個数 *N* と *i* 番目に発言した単語 *W<sub>i</sub>* が与えられるので,どの発言もしりとりのルールを守っていたかを判定してください

## 制約
* *M* は 2 <= *M* < 100 を満たす整数である
* *W<sub>i</sub>* は英子文字からなる長さ1以上10以下の文字列である

## 入力
入力は以下の形式で標準入力から与えられる.

```
N
W1
W2
.
.
WN
```

## 出力
高橋くんのどの発言もしりとりのルールを守っていたなら ' <font color = red>Yes</font> ' , そうでなければ ' <font color = red>No</font> ' を出力せよ.

## 回答
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
  int N;
  vector<string> W;

  cin >> N;
  W.resize(N);
  for(auto& w : W){
    cin >> w;
  }

  char lastCharacter;
  bool isFirst=true;
  bool isFailed = false;

  for (int i = 0; i < N; i++){
    if(isFirst==true){
      isFirst = false;
      lastCharacter = W[i][W[i].size() - 1];
    }
    else{
      if(W[i][0]!=lastCharacter){
        isFailed = true;
      }

      lastCharacter = W[i][W[i].size() - 1];
      for (int j = 0; j < i;j++){
        if(W[i]==W[j]){
          isFailed = true;
        }
      }
    }

    if(isFailed==true){
      cout << "No" << endl;
      return 0 ;
    }
  }

  cout << "Yes" << endl;

}

```

## 解説
2つめ以降の単語全てについて,先頭文字が直前の単語の末尾と一致しているか,それまでに登場した全ての単語と重複していないかを調べる
