#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, tmp, sum = 0; 
    int i,j,k;
    vector<int> S;

    cin>> N;
    cin>> M;

    for(i=0; i<N; i++){
        cin>> tmp;
        sum += tmp;
        S.push_back(sum);
    }

    for(i=0; i<M; i++){
        cin>>j;
        cin>>k;
        if(j==1)
            tmp = S[k-1];
        else
            tmp = S[k-1]-S[j-2];
        cout << tmp << "\n";
    }


    return 0;
}