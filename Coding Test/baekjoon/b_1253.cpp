#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 1 ≤ N ≤ 2,000
	int i;
	int cnt = 0;

	cin >> N;

	vector<int> A(N, 0);  // |Ai| ≤ 1,000,000,000, Ai는 정수 -> 중복된 수, 음수도 나올 수 있음 !! 

	for(i=0; i<N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	for(i=0; i<N; i++){
		int s = 0, e = N-1;

		if(i==0)
			s = 1;
		else if(i==N-1)
			e = N-2;
		
		while(s < e){
			
			if(A[s]+A[e] == A[i]){
				cnt++;
				break;
			}
			else if(A[s]+A[e] < A[i]){
				s++;
			}
			else{
				e--;
			}

			if(s == i)
				s++;
			if(e == i)
				e--;
		}
		
	}

	cout << cnt << "\n";
	

	return 0;
}

/*
N = 3
0, 3, 3


-3 4 7
*/