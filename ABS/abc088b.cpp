#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  // a を大きい順に並び替える
  sort(a.begin(), a.end(), [](auto a, auto b){ return a > b; });

  int index = 0;
  int result = 0;
  for_each(a.begin(), a.end(), [&index, &result](auto v) {
    // 奇数回なら加算・偶数回なら減算
    if (index % 2) {
      result -= v;
    } else {
      result += v;
    }
    index++;
  });

  cout << result << endl;
}
