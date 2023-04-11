#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; 
    int i, j, x1, x2, y1, y2, tmp;

    cin>> N;
    cin>> M;

    vector<vector<int>> S(N+1, vector<int>(N+1, 0));

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            cin>> tmp;
            S[i][j] = S[i-1][j] + S[i][j-1] + tmp - S[i-1][j-1];
        }
    }

    for(i=0; i<M; i++){
        cin>> x1;
        cin>> y1;
        cin>> x2;
        cin>> y2;

        tmp = S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1];
        cout << tmp << "\n";
    }

    return 0;
}