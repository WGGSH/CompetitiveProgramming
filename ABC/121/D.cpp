#include <iostream>
#include <vector>
using namespace std;

int main(void){
  unsigned long A,B;
  cin >> A >> B;
  
  unsigned long diff = B-A+1;

  int maxBit=0;
  unsigned long maxValue=1;
  for(int i=0;i<64;i++){
    maxBit++;
    if(B<=maxValue){
      break;
    }else{
      maxValue*=2;
    }
  }
  // cout<<maxBit<<','<<maxValue<<endl;
  vector<int> bitList;
  bitList.resize(maxBit);
  unsigned long rootNum=1;
  unsigned int value=1;
  unsigned long answer=0;
  for(int i=0;i<maxBit;i++){
    rootNum*=2;
    long mod = diff%rootNum;
    unsigned long count=(diff/rootNum)*(rootNum/2);
    unsigned long currentPos = (rootNum-1)&A;
    unsigned long center = rootNum/2;
    // cout << mod<<','<<count<<','<<currentPos<<','<<center;
    // スタート地点が中点より先
    if(currentPos>center){
      // ループしない場合
      if(mod<center){
        // 4
        count+=mod;
      }else{
        // スタートに戻る場合
        // count+=mod-center;
        count+=(center*2-currentPos);
        mod-=(center*2-currentPos);
        //まだcenterを通過できるか
        if(mod>=center){
          // 6
          // count+=mod-center;
          mod-=center;
          count+=mod;
        }else{
          // 中点を通過できない:5
        }
      }
    }else{
      // スタート地点が中点より手前
      // まずcenterまで移動
      mod-=(center-currentPos);
      if(mod<=0){
        // 加算無しで終了: 1
      }else{
        if(mod<center){
          count+=mod;
          // 終了:2
        }else{
          // スタートに戻る:3
          count+=center;
          // mod-=center;
          // if(mod>center){
          //   count+=mod-center;
          // }
        }
      }
    }
    // cout<<':'<<count<<endl;
    if(count%2==0){

    }else{
      answer+=value;
    }
    value*=2;

    // mod,A,iを元に加算する値を決定
    
  }

  cout<<answer<<endl;

  // unsigned long result=A;
  // for(unsigned long i=A+1;i<=B;i++){
  //   result=result^i;
  // }
  // cout<<result<<endl;
}
