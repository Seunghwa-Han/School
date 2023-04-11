#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 1 ≤ N ≤ 10,000,000

	cin >> N;

	int s = 1, e = 1;
	int sum = 1;
	int cnt = 0;

	while(e <= N){

		if(sum < N){
			e++;
			sum += e;
		}
		else if(sum > N){
			sum -= s;
			s++;
		}
		else if(sum == N){
			cnt++;
			e++;
			sum += e;
		}
	}

	cout << cnt << "\n";

	return 0;
}