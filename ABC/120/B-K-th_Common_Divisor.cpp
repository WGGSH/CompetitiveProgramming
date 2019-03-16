#include <iostream>
using namespace std;

int main(void){
  int A, B, K;
  cin >> A >> B >> K;

  int max = A > B ? A : B;
  int count = 0;
  for (int i = max; i > 0; i--){
    if(A%i == 0 && B%i ==0){
      count++;
      if(count==K){
        cout << i << endl;
        return 0;
      }
    }
  }
}
