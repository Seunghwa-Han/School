#include <iostream>
#include <vector>

using namespace std;

// 고유한 번호는 100,000보다 작거나 같은 자연수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 1 ≤ N ≤ 15,000
	int M; // 1 ≤ M ≤ 10,000,000
	int i, j, cnt = 0;

	cin >> N >> M;

	vector<int> v(N, 0);

	for(i=0; i<N; i++){
		cin >> v[i];
	}

	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(v[i]+v[j] == M)
				cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}