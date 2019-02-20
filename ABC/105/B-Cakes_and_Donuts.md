# [B - Cakes and Donuts](https://beta.atcoder.jp/contests/abc105/tasks/abc105_b)
* 実行時間制限: 2sec / メモリ制限: 1000MB
* 配点: 100点

##  問題文
ABC洋菓子店では，1個4ドルのケーキと1個7ドルのドーナツが売られている．
このとき，合計金額が*N*ドルとなる買い方はあるか，判定せよ．ただし，同じ商品を2個以上買ってもよく，買わない商品があっても良いものとする．

## 制約
* *N*は1以上100以下の整数

## 入力
入力は以下の形式で標準入力から与えられる．

`
N
`

## 出力
合計が*N*ドルとなる買い方がある場合，'<font color=red>Yes</font>' , そうでない場合，'<font color=red>No</font>' と出力せよ

## 回答
```cpp
#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int max_4=N/4;
    for(int i=0;i<=max_4;i++){
        int max_7 = (N-i*4)/7;
        for(int j=0;j<=max_7;j++){
            if(i*4+j*7==N){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout << "No"<< endl;
    return 0;
}
```

## 解説
入力*N*に対して，4の倍数と，7の倍数の和で表すことができるか全て探索する．
