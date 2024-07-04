#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct Plan {
  int t;
  int x;
  int y;
};

// (xi, yi) → (xi+1, yi+1) に移動できるか確認
// bool can_move(int t, const int x1, int y1, int x2, int y2) {
bool can_move(Plan from, Plan to) {
  // 最短の移動時間を探す
  int min_time = abs(to.x - from.x) + abs(to.y - from.y);
  int distance_time = to.t - from.t;
  if (min_time > distance_time) return false;

  // 目的地に到着後時間が余った場合，往復して時間を潰す
  // 残り時間が偶数なら到達可能
  return (distance_time - min_time) % 2 == 0;
}

int main() {
  int N;
  cin >> N;
  vector<Plan> plans(N);
  rep(i, N) {
    cin >> plans[i].t >> plans[i].x >> plans[i].y;
  }

  plans.insert(plans.begin(), { 0, 0, 0});

  bool result = true;
  rep(i, N) {
    if (!can_move(plans[i], plans[i + 1])) {
      result = false;
      break;
    }
  }

  cout << (result ? "Yes" : "No") << endl;

}
