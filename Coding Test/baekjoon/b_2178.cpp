#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int> > v;
vector<vector<bool> > visited;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;

void BFS(){
	queue<pair<int,int> > q;
	q.push(make_pair(1, 1));

	while(!q.empty()){
		pair<int,int> now = q.front();
		q.pop();
		int i = now.first;
		int j = now.second;

		if(visited[i][j]) // already visited
			continue;
		
		visited[i][j] = true;

		if(i == N && j== M)
			break;

		for(int k=0; k<4; k++){
			int x = i + dx[k];
			int y = j + dy[k];
			if(v[x][y]!=0 && !visited[x][y])
			{
				q.push(make_pair(x, y));
				v[x][y] = v[i][j] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	v.resize(N+2, vector<int>(M+2));
	visited.resize(N+2, vector<bool>(M+2));

	fill(v[0].begin(), v[0].end(), 0);
	fill(v[N+1].begin(), v[N+1].end(), 0);
	
	for(int i=0; i<N+1; i++)
		fill(visited[i].begin(), visited[i].end(), false);

	for(int i=1; i<=N; i++){
		string line;
		cin >> line;

		v[i][0] = 0;
		for(int j=1; j<=M; j++){
			v[i][j] = line[j-1] - '0';
		}
		v[i][M+1] = 0;
	}

	BFS();

	cout << v[N][M] << "\n";

	return 0;
}