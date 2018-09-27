#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
  int N;
  vector<string> W;

  cin >> N;
  W.resize(N);
  for(auto& w : W){
    cin >> w;
  }

  char lastCharacter;
  bool isFirst=true;
  bool isFailed = false;

  for (int i = 0; i < N; i++){
    if(isFirst==true){
      isFirst = false;
      lastCharacter = W[i][W[i].size() - 1];
    }
    else{
      if(W[i][0]!=lastCharacter){
        isFailed = true;
      }

      lastCharacter = W[i][W[i].size() - 1];
      for (int j = 0; j < i;j++){
        if(W[i]==W[j]){
          isFailed = true;
        }
      }
    }

    if(isFailed==true){
      cout << "No" << endl;
      return 0 ;
    }
  }

  cout << "Yes" << endl;

}
