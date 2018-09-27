#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
  int A, B;

  cin >> A >> B;
  if(A%2==0 || B%2==0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
