#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, tmp;
    
    cin>>N;
    cin>>M;

    vector<int> S(N+1, 0);

    for(i=0; i<N; i++){
        cin>> tmp;
        S[i] = S[i-1]+tmp;
    }


    return 0;
}

/*
1 2 3 1 2
1 3 6 7 

*/