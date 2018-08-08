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
