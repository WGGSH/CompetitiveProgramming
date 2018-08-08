#include <iostream>
#include <string>
using namespace std;

int main(void){
  int S;
  cin >> S;

  if(S<1200){
    cout << "ABC";
  }else if(S<2800){
    cout << "ARC";
  }else{
    cout << "AGC";
  }
  cout << endl;
}
