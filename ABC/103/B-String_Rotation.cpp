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
