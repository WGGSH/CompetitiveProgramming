#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

map<ll, ll> memo;
ll calc(ll N) {
  if (N == 1) {
    return 0;
  }
  if (memo.count(N)) {
    return memo[N];
  }

  ll result = calc(N / 2) + calc((N + 1) / 2) + N;
  memo[N] = result;
  return result;
}

int main() {
  ll N;
  cin >> N;

  vector<ll> A;
  A.push_back(N);

  ll result = 0;
  result = calc(N);

  cout << result << endl;
}
