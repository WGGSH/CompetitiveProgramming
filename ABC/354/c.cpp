#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;
using ll = long long;

struct Card {
  ll a;
  ll c;
  int index;
};

int main() {
  int N;
  cin >> N;
  vector<Card> cards(N);
  rep(i, N) {
    cin >> cards[i].a >> cards[i].c;
    cards[i].index = i;
  }

  sort(cards.begin(), cards.end(), [](auto a, auto b) {
    return a.c < b.c;
  });

  vector<int> answer_index;
  int target_a = 0;
  for(auto card : cards) {
    if (card.a > target_a) {
      target_a = card.a;
      answer_index.push_back(card.index);
    }
  }
  sort(answer_index.begin(), answer_index.end());

  cout << answer_index.size() << endl;
  for(auto index : answer_index) {
    cout << index + 1;
    if (index != answer_index.back()) {
      cout << " ";
    }
  }
  cout << endl;
}
