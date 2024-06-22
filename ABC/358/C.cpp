#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int getBitCount(int n) {
  int count = 0;
  while (n > 0) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}

vector<int> getBitPositions(int n, int max) {
  vector<int> positions;
  rep(i, max) {
    if (n & (1 << i)) {
      positions.push_back(i);
    }
  }
  return positions;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> S(N);
  rep(i, N) cin >> S[i];

  vector<int> dataList;
  for(auto s : S) {
    int data = 0;
    for(auto c : s) {
      data <<= 1;
      if (c == 'o') {
        data |= 1;
      }
    }
    dataList.push_back(data);
  }


  int max = 1 <<N;
  int min = N;

  int answer = (1 << M) - 1;

  auto bitwise_or = [](int a, int b) {
    return a | b;
  };

  rep(bitCase, max) {
    int bitCount = getBitCount(bitCase);
    if (bitCount >= min) {
      continue;
    }
    vector<int> bitPositions = getBitPositions(bitCase, N);
    vector<int> filteredDataList(bitPositions.size());
    transform(bitPositions.begin(), bitPositions.end(), filteredDataList.begin(), [&](int i) {
      return dataList.at(i);
    });

    int result = accumulate(filteredDataList.begin(), filteredDataList.end(), 0, bitwise_or);

    if (result == answer && bitCount < min) {
      min = bitCount;
    }
  }

  cout << min << endl;


};
