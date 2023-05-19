#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& v, vector<bool>& visited, int now, vector<int>& dfs){
    visited[now] = true;
    dfs.push_back(now);

    for(const auto& next : v[now]){
        if(!visited[next])
            DFS(v, visited, next, dfs);
    }
}

void BFS(vector<vector<int>>& v, vector<bool>& visited, int V, vector<int>& bfs){
    queue<int> q;
    q.push(V); 

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(visited[now])
            continue;
        bfs.push_back(now);
        visited[now] = true;

        for(const auto& next: v[now]){
            if(!visited[next]){
                q.push(next);
            }
        }
    }
}

int main(){
    
    int N, M, V;

    cin >> N >> M >> V;

    vector<vector<int>> v(N+1);
    vector<bool> visited(N+1, false);
    vector<int> dfs;
    vector<int> bfs;

    for(int i=0; i<M; i++){
        int s,e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for(int i=1; i<=N; i++)
        sort(v[i].begin(), v[i].end());

    DFS(v, visited, V, dfs);

    fill(visited.begin(), visited.end(), false);

    BFS(v, visited, V, bfs);

    for(const auto& i : dfs)
        cout << i <<" ";
    cout <<"\n";
    for(const auto& i : bfs)
        cout << i <<" ";
    cout <<"\n";

    return 0;
}