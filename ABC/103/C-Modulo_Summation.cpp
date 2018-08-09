#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  vector<int> a;

  cin >> N;
  a.resize(N);

  for (int i = 0; i < N; i++){
    cin >> a[i];
  }

  int ans = 0;

  for(auto val : a){
    ans += val;
  }
  ans -= N;

  cout << ans << endl;
}
