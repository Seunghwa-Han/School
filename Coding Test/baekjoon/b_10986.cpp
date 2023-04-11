#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 1 ≤ N ≤ 106, 2 ≤ M ≤ 103
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
1 3 6 7 9

N = 5
1,5 2,5 3,5 4,5 5,5
1,4 2,4 3,4 4,4
1,3 2,3 3,3
1,2 2,2
1,1

*/