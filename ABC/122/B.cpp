#include <iostream>
#include <string>
using namespace std;

bool check(string str){
  for(auto c : str){
    if(!(c=='A' || c =='T' || c=='C' || c=='G')){
      return false;
    }
  }
  return true;
}

int main(void){
  string S;
  cin >> S;

  int length = S.length();
  int max = 0;

  for (int i = 0; i < length; i++){
    for (int j = i; j <length ;j++){
      string str = S.substr(i, length - j);
      if(check(str)==true){
        if(str.length()>max){
          max = str.length();
        }
      }
    }
  }
  cout << max << endl;
}
