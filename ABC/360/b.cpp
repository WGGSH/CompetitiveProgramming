#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

vector<string> splitString(const string &str, int n) {
  vector<string> result;
  int length = str.length();

  rep(i, length) {
    if (i % n == 0) {
      result.push_back(str.substr(i, n));
    }
  }

  return result;
}

int main(void) {
  string S, T;
  cin >> S >> T;
  int length = S.length() - 1;

  cout << S << ',' << T << endl;

  bool result = false;
  for(int i = 1; i <= length; i++) {
    cout << "----------" << endl;
    vector<string> s = splitString(S, i);
    for(auto &str : s) {
      cout << str << endl;
    }
    cout << i << endl;
    string lastCat = "";
    // 各文字列の中で最後の文字列を取得
    for(auto &str : s) {
      if (str.length() >= i) {
        lastCat.push_back(str[i - 1]);
      }
    }
    cout << lastCat << endl;
    if (lastCat == T) {
      result = true;
      break;
    }
  }

  if (result) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}


// #include <bits/stdc++.h>
// #define rep(i, n) for(int i = 0; i < (n); i++)
//
// using namespace std;
//
// vector<string> splitString(const string &str, int w) {
//     vector<string> result;
//     int length = str.length();
//     for (int i = 0; i < length; i += w) {
//         result.push_back(str.substr(i, w));
//     }
//     return result;
// }
//
// int main(void) {
//     string S, T;
//     cin >> S >> T;
//     int lenS = S.length();
//     int lenT = T.length();
//
//     bool result = false;
//
//     for (int w = 1; w < lenS; ++w) {
//         for (int c = 1; c <= w; ++c) {
//             string constructed = "";
//             for (int i = 0; i + w <= lenS; i += w) {
//                 if (i + c - 1 < lenS) {
//                     constructed.push_back(S[i + c - 1]);
//                 }
//             }
//             if (constructed.substr(0, lenT) == T) {
//                 result = true;
//                 break;
//             }
//         }
//         if (result) break;
//     }
//
//     if (result) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }
//     return 0;
// }
