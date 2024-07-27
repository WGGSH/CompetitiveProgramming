#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

using ll = long long;

const ll INF = LLONG_MAX;

struct Edge {
  ll to, weight;
};

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];
  vector<ll> U(M), V(M), B(M);
  rep(i, 0, M) cin >> U[i] >> V[i] >> B[i];

  // index と合わせる
  rep(i, 0, M) {
    U[i]--;
    V[i]--;
  }

  vector<vector<Edge>> G(N);
  rep(i, 0, M) {
    G[U[i]].push_back({V[i], B[i]});
    G[V[i]].push_back({U[i], B[i]});
  }

  vector<ll> minWeight(N, INF);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  minWeight[0] = A[0];
  pq.push({A[0], 0});

  while (!pq.empty()) {
    auto [currentWeight, u] = pq.top();
    pq.pop();

    if (currentWeight > minWeight[u]) continue;

    for (const auto& edge : G[u]) {
      ll v = edge.to;
      ll newWeight = currentWeight + edge.weight + A[v];

      if (newWeight < minWeight[v]) {
        minWeight[v] = newWeight;
        pq.push({newWeight, v});
      }
    }
  }

  rep(i, 1, N) {
    cout << minWeight[i] << " ";
  }
  cout << endl;

}
