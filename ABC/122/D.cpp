#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin >> N;

  unsigned long long max = 1;
  for (int i = 0; i < N;i++){
    max *= 4;
  }

  cout << max << endl;
}
