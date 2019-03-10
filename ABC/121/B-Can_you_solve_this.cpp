#include <iostream>
#include <vector>
using namespace std;


int main(void){
  int N,M,C;
  cin >> N >> M >> C;
  vector<int> B;
  vector<vector<int>> A;

  B.resize(M);
  for(int i=0;i<M;i++){
    cin>>B[i];
  }

  A.resize(N);
  for(int i=0;i<N;i++){
    A[i].resize(M);
    for(int j=0;j<M;j++){
      cin>>A[i][j];
    }
  }

  int answer=0;
  for(auto index : A){
    int valueLeft=C;
    for(int j=0;j<M;j++){
      valueLeft+=index[j]*B[j];
    }
    if(valueLeft>0){
      answer++;
    }
  }

  cout<<answer<<endl;
}
