#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0, num;  // N <= 100

	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> num;
		double root = sqrt(num);

		int p = 2, p_next;
		list<int> sieve;
		for(int j=2; j<=num; j++){
			sieve.push_back(j);
		}
		while(p <= root){
			int flag = 1;
			for(auto it=sieve.begin(); it!=sieve.end(); it++)
			{
				if(*it%p == 0 && *it!=p){
					it = sieve.erase(it);
				}
				else if(flag && *it>p){
					flag = 0;
					p_next = *it;
				}
			}
			p = p_next;
		}
		auto res = find(sieve.begin(), sieve.end(), num);
		if(res != sieve.end())
			cnt++;
	}

	cout << cnt << "\n";
	
	return 0;
}