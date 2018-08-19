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
