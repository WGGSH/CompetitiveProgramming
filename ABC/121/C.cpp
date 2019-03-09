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
    // この店で買いきれるか
    if(pair.second>=num){
      // 買いきれるなら，必要量買い，ループ終了
      money+=pair.first*num;
      break;
    }else{
      // 買いきれないなら，全て買い，ループ継続
      money+=pair.first*pair.second;
      num-=pair.second;
    }
  }

  cout<<money<<endl;
}
