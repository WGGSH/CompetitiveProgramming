#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> l, r;
  l.resize(Q);
  r.resize(Q);
  for (int i = 0; i < Q;i++){
    cin >> l[i] >> r[i];
  }

  vector<int> answerList;
  answerList.resize(Q);

  vector<int> acPosList;
  acPosList.resize(N);

  // ACのAを持つ箇所のリストを作成する
  int acCount = 0;
  for (int i = 0; i < N - 1;i++){
    
    if(S[i]=='A'){
      if(S[i+1]=='C'){
        acPosList[i] = ++acCount;
      }else if(S[i+1]!='A'){
        i++;
      }
    }
  }

  // for(auto val : acPosList){
  //   cout << val << ',';
  // }
  // cout << endl;

  for (int q = 0; q < Q;q++){
    int left = -1, right = -1;

    for (int i = l[q] - 1; i < r[q] - 1; i++){
      if(acPosList[i]!=0){
        left = acPosList[i];
        break;
      }
    }
    for (int i = r[q] - 1; i >= l[q] - 1; i--){
      if(acPosList[i]!=0){
        right = acPosList[i];
        break;
      }
    }

    // cout << left << ',' << right << ',';
    
    if(left==-1 && right==-1){
      cout << 0 << endl;
    }else if(left == -1 && right != -1){
      cout << 0 << endl;
    }else if(left!=-1 && right == -1){
      cout << 0 << endl;
    }else{
      cout << right - left +1<< endl;
    }
  }

  cout << endl;


}
