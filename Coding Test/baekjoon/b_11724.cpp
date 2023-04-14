#include <iostream>
#include <vector>

using namespace std;

void DFS(int i, vector<vector<int>> &A, vector<bool> &visited);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; // 1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2
    int i, u, v;
    
    cin >> N >> M;

    vector<bool> visited(N+1, false);
    vector<vector<int>> A(N+1);
    int cnt = 0;

    for(i=0 ; i<M; i++)
    {
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    for(i=1; i<=N; i++)
    {
        if(!visited[i])
        {
            cnt++;
            DFS(i, A, visited);
        }
    }

    cout << cnt << "\n";

    return 0;
}

void DFS(int i, vector<vector<int>> &A, vector<bool> &visited)
{
    if(visited[i])
        return;
    visited[i] = true;

    for(auto &node : A[i]){
        if(!visited[node])
            DFS(node, A, visited);
    }
}