#include <iostream>
using namespace std;

int main(void){
  int H,W,h,w;
  cin >> H >> W >> h >> w ;

  int answer = H*W - h*W - w*H +h*w;
  cout << answer<<endl;
}
