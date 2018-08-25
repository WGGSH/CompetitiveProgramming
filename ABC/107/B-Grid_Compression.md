# [B - Grid Compression](https://abc107.contest.atcoder.jp/tasks/abc107_b)
* 時間制限: 2sec / メモリ制限: 1024MB

## 問題文
縦 *H* 行,横 *W* 列のマス目があります.上から *i* 行目, 左から *j* 列目のマスを (*i* , *j*) とします.各マスは白または黒です.マス目の配色は, *H* 行 *W* 列の行列(*a<sub>i,j</sub>*) によって与えられます.
*a<sub>i,j</sub>* が '<font color=red> . </font> 'ならばマス (*i* , *j*) は白であり, (*a<sub>i,j</sub>*) が '<font color=red> # </font>'ならばマス (*i* , *j*) は黒です.
すぬけ君はこのマス目を圧縮しようとしています.そのために,白いマスのみからなる行または列が存在する間,次の操作を繰り返し行います.

* 操作: 白いマスのみからなる行または列をひとつ任意に選び,その行または列を取り除いて空白を詰める.

各操作でどの行または列を選ぶかによらず,最終的なマス目は一位に定まることが示せます.最終的なマス目を求めてください

## 制約
* 1 <= *H* , *W* <= 100
* *a<sub>i,j</sub>* は '<font color=red> . </font> ' または '<font color=red> # </font> ' である.
* マス目全体で少なくとも1つは黒いマスが存在する.

## 入力
入力は以下の形式で標準入力から与えられる

```
H W
a1,1  ...  a1,W
.
.
.
aH,1  ...  aH,W
```

## 出力
最終的なマス目を,入力と同様のフォーマットで出力せよ.ただし,行数及び列数は省くこと.

## 回答
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int H, W;
  int **a;
  cin >> H >> W;
  a = new int*[H];
  for (int i = 0; i < H;i++){
    a[i] = new int[W];
  }
  for (int y = 0; y < H;y++){
    for (int x = 0; x < W;x++){
      char c;
      cin >> c;
      if(c=='.'){
        a[y][x] = 0;
      }else if(c=='#'){
        a[y][x] = 1;
      }
    }
  }

  vector<int> passH, passW;
  
  // 縦探索
  for (int y = 0; y < H;y++){
    bool flag = true;

    for (int x = 0; x < W;x++){
      if(a[y][x]==1){
        flag = false;
      }
    }

    if(flag==true){
      passH.push_back(y);
    }
  }

  // 横探索
  for (int x = 0; x < W; x ++){
    bool flag = true;

    for (int y = 0; y < H; y++){
      if (a[y][x] == 1){
        flag = false;
      }
    }

    if (flag == true){
      passW.push_back(x);
    }
  }



  // 無視する行以外を出力する
  for (int y = 0; y < H;y++){
    bool passY = false;
    
    for(auto index : passH){
      if(y==index){
        passY = true;
        break;
      }
    }

    if(passY==true){
      continue;
    }

    for (int x = 0; x < W;x++){
      bool passX = false;

      for(auto index : passW){
        if(x==index){
          passX = true;
          break;
        }
      }

      if(passX==true){
        continue;
      }

      cout << (a[y][x] == 0 ? '.' : '#');
    }
    cout << endl;
  }
}

```

## 解説
問題分より,どの順番で操作を行っても最終的なマス目は一意に定まるという点から,各操作が,それ以降の操作に影響を与えないことがわかる.
よって,実際に操作を行いマス目のデータを加工せずに,どの行,列に操作を行う必要があるかを知ることができれば最終的なマス目が得られる.
予め全て白の行,列を列挙し,その行,列のみ無視して出力することで最終的なマス目になる.
