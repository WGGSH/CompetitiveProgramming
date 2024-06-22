#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main(void) {
  int N,M;
  cin >> N >> M;
  vector<int> AList(N);
  rep(i, N) {
    cin >> AList[i];
  }

  vector<int> BList(M);
  rep(i, M) {
    cin >> BList[i];
  }

  sort(AList.begin(), AList.end());
  sort(BList.begin(), BList.end());

  long long answer = 0;
  bool isBreak = false;

  multiset<int> st;
  for(auto a : AList) st.insert(a);


  for(auto b : BList) {
    auto iter = st.lower_bound(b);
    if (iter == st.end()) {
      isBreak = true;
      break;
    }

    answer += *iter;
    st.erase(iter);
  }

  // for(auto b : BList) {
  //   auto iter = find_if(AList.begin(), AList.end(), [b](int a) {
  //     return a >= b;
  //   });
  //   int index = distance(AList.begin(), iter);
  //   if (index == AList.size()) {
  //     isBreak = true;
  //     break;
  //   }
  //
  //   answer += AList.at(index);
  //   AList.erase(AList.begin(), AList.begin() + index + 1);
  //   for(auto a: AList) {
  //     cout << a;
  //   }
  //   cout << endl;
  // }

  if (isBreak) {
    cout << -1 << endl;
    return 0;
  }

  cout << answer << endl;
  return 0;
}
