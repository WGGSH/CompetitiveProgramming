#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int getDigitSum(int n) {
  int result = 0;
  while(n!=0) {
    result += n % 10;
    n /= 10;
  }
  return result;
}

int main() {
  int N,A,B;
  cin >> N >> A >> B;

  int result = 0;
  rep(i, N + 1) {
    int Sum = getDigitSum(i);
    if (A <= Sum && Sum <= B) {
      result += i;
    }
    // cout << "i: " << i << " Sum:" << getDigitSum(i) << endl;
  }
  cout << result << endl;
}
