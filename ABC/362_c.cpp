#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> L(N), R(N);
  rep(i, 0, N) cin >> L[i] >> R[i];

  vector<ll> answer(N);
  // 一旦中央値を入れておく
  rep(i, 0, N) answer[i] = (R[i] + L[i]) / 2;

  // rep(i, 0, N) {
  //   cout << median[i] << endl;
  // }

  ll sum = 0;
  sum = accumulate(answer.begin(), answer.end(), sum);
  rep(i, 0, N) {
    // すでに0になっていれば，調整不要
    if (sum == 0) {
      break;
    }

    // sum が0より大きければ，可能な限り増やす
    // 0 より小さければ，可能な限り減らす
    if (sum > 0) {
      ll diff = min(answer[i] - L[i], sum);
      answer[i] -= diff;
      sum -= diff;
    } else {
      ll diff = min(R[i] - answer[i], -sum);
      answer[i] += diff;
      sum += diff;
    }
  }
  // cout << sum << endl;
  // 全要素見て sum が0なら，調整不可能
  if (sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
    return 0;
  }
  rep(i, 0, N) {
    cout << answer[i] << " ";;
  }
  cout << endl;
}
