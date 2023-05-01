#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int> > &v, vector<int> &visited, int node, int cnt);
bool exist;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M; // 5 ≤ N ≤ 2000,  1 ≤ M ≤ 2000
	cin >> N >> M;

	int a, b; // 0 ≤ a, b ≤ N-1, a ≠ b
	vector<vector<int> > v(N);
	vector<int> visited(N, false);

	for(int i=0; i<M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	exist = false;
	for(int i=0; i<N; i++)
	{ 
		DFS(v, visited, i, 1);
		if(exist)
			break;
	}

	if(exist){
		cout << "1\n";
	}
	else
		cout << "0\n";

	return 0;
}

void DFS(vector<vector<int> > &v, vector<int> &visited, int node, int cnt)
{
	if(cnt >= 5){
		exist = true;
		return;
	}

	visited[node] = true;

	for(int i : v[node])
	{
		if(!visited[i]){
			DFS(v, visited, i, cnt+1);
		}
	}

	visited[node] = false;
}