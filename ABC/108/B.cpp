#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x3, y3, x4, y4;

  int vec1_2x, vec1_2y, vecRotx, vecRoty;

  vec1_2x = x2 - x1;
  vec1_2y = y2 - y1;

  vecRotx = -vec1_2y;
  vecRoty = vec1_2x;

  x3 = x2 + vecRotx;
  y3 = y2 + vecRoty;
  x4 = x1 + vecRotx;
  y4 = y1 + vecRoty;

  cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
}
