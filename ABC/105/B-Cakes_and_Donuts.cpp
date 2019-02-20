#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int max_4=N/4;
    for(int i=0;i<=max_4;i++){
        int max_7 = (N-i*4)/7;
        for(int j=0;j<=max_7;j++){
            if(i*4+j*7==N){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout << "No"<< endl;
    return 0;
}
