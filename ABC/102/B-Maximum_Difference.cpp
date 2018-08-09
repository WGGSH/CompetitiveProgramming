#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  vector<int> A;

  cin >> N;
  A.resize(N);
  for (auto &val : A){
    cin >> val;
  }

  int max = 0, min = 0;
  for(auto val : A){
    if(max==0 || max<val){
      max = val;
    }
    if(min==0 || min>val){
      min = val;
    }
  }

  cout << max - min << endl;
}
