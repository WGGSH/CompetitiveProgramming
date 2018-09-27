#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N,K;
  cin >> N >> K;

  unsigned long count = 0;

  for (int a = 1; a <= N;a++){
    // aの値から,当てはまるb,cを列挙する
    // (K-a)*2 == K
    int next;
    if(a%K==0){
      next = a;
    }else if(a - (a / K) * K > K / 2){
      next = ((a / K) * 2 + 2) * K - a;
    }else{
      next = ((a / K) * 2 + 1) * K - a;
    }

    for (int b = next; b <= N; b++){
      if((a+b)%K==0){
        if((b*2)%K==0){
          // ここで値加算
          vector<int> list;
          int targetNum = (N - a) / K + 1;
          // targetNum! 通り存在
          // そのうち1つは 全ての値が同じ
          // そのうち targetNum-1つは2つの値が同じ
          // 残りは3つの値が別
          int pattern = targetNum * (targetNum + 1) / 2;
          // for (int i = 1; i <= targetNum;i++){
          //   pattern += i;
          // }
          // TYPEA: aとbが一致: targetNum通り
          // TYPEB: bとcが一致: targetNum通り
          // TYPEC: TYPEAとTYPEBの複合: 1通り
          count += 1;
          pattern--;
          count += 3 * (targetNum - 1) * 2;
          pattern -= (targetNum - 1) * 2;
          count += 6 * (pattern);
          break;
        }else{
          // bをループする必要性なし
          break;
        }
      }
    }
  }
  cout << count << endl;
}
