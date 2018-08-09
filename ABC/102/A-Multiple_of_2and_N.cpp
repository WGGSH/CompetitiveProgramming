#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin >> N;

  int result;
  if(N%2==0){
    result = N;
  }else{
    result = N * 2;
  }

  cout << result << endl;
}
