#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

ll get_palindrome_number_count(int digit) {
  if (digit == 1) {
    return 9;
  }
  if (digit % 2 == 0) {
    return 9 * pow(10, digit / 2 - 1);
  } else {
    return 9 * pow(10, (digit + 1) / 2 - 1);
  }
}

// X番目のN桁の回文数を取得する関数
string getNthPalindrome(ll N, ll X) {
  // 桁数が1の場合の処理
  if (N == 1) {
    if (X <= 9) {
      return to_string(X - 1); // 0から9の回文数
    }
  }

  // 偶数桁数の場合
  if (N % 2 == 0) {
    ll halfLength = N / 2;
    ll start = pow(10, halfLength - 1);
    ll end = pow(10, halfLength);

    // if (X > (end - start)) {
    //   return "Index out of range.";
    // }

    ll halfNumber = start + X - 1;
    string halfStr = to_string(halfNumber);
    string rev = halfStr;
    reverse(rev.begin(), rev.end());
    return halfStr + rev;
  } else { // 奇数桁数の場合
    ll halfLength = N / 2;
    ll start = pow(10, halfLength);
    ll end = pow(10, halfLength + 1);

    // if (X > (end - start) * 10) {
    //   return "Index out of range.";
    // }

    ll index = (X - 1) / 10;
    ll middleDigit = (X - 1) % 10;

    ll halfNumber = start / 10 + index;
    string halfStr = to_string(halfNumber);
    string rev = halfStr;
    reverse(rev.begin(), rev.end());
    return halfStr + to_string(middleDigit) + rev;
  }
}

int main() {
  ll N;
  cin >> N;

  // K桁以下の回文数の個数が，Nを超えるまでのKを求める
  ll digit = 1;
  ll count = 0;
  while (true) {
    ll palindrome_number_count = get_palindrome_number_count(digit);
    // cout << digit << " " << palindrome_number_count << endl;
    if (count + palindrome_number_count >= N) {
      break;
    }
    count += palindrome_number_count;
    digit++;
  }


  ll diff = N - count;
  // if (digit >= 3) {
  //   diff--;
  // }
  if (N >= 10) {
    diff--;
  }
  if (diff == 0) {
    digit--;
    diff = get_palindrome_number_count(digit);
  }
  // cout << digit << endl;
  // cout << diff << endl;
  cout << getNthPalindrome(digit, diff) << endl;
}
