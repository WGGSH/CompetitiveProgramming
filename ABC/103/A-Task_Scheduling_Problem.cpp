#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int A[3];
  cin >> A[0] >> A[1] >> A[2];

  int minScore = -1;

  // 3!パターン存在する
  for (int i = 0; i < 6;i++){
    int score = 0;
    int preIndex;
    for (int j = 0; j < 3; j++)
    {
      int index = ((i / 2) + j * ((i % 2) * 2 - 1) + 3) % 3;

      if (j == 0){
        preIndex = index;
        continue;
      }

      score += A[index] - A[preIndex] > 0 ? A[index] - A[preIndex] : A[preIndex] - A[index];

      preIndex = index;
    }
    if(minScore==-1 || minScore>score){
      minScore = score;
    }
  }

  cout << minScore << endl;
}
