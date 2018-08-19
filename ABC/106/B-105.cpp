#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int num = 0;

  for (int i = 1; i <= N; i += 2){
    int count = 0;
    for (int j = 1; j <= i; j++){
      if(i%j==0){
        count++;
      }
    }
    if(count==8){
      num++;
    }
  }
  cout << num << endl;
}
