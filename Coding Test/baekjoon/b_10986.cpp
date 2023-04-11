#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N; 
    int M; // 1 ≤ N ≤ 10^6, 2 ≤ M ≤ 10^3
    int i;
    long cnt = 0;
    
    cin>>N;
    cin>>M;

    vector<long> S(N+1, 0);
    vector<long> remainder(M, 0);

    for(i=1; i<=N; i++){
        long tmp;
        cin>> tmp;  //0 ≤ Ai ≤ 10^9 
        S[i] = (S[i-1]+tmp) % M;
        if(S[i] == 0)
            cnt++;
        remainder[S[i]]++;
    }


    for(i=0; i<M; i++){
        if(remainder[i]>=2){
            cnt += remainder[i]*(remainder[i]-1)/2;   //remainder[i]_C_2 (combination)
        }
    }

    cout<< cnt << "\n";

    return 0;
}