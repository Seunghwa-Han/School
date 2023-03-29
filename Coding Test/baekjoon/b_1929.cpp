#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;  // 1 ≤ M ≤ N ≤ 1,000,000
	cin >>M;
	cin >>N;

	int p=2, p_next =3;
	list<int> sieve;

	for(int i=2; i<=N; i++)
		sieve.push_back(i);
	
	double root = sqrt(N);
	while(p<=root){
		int flag = 1;
		for(auto it=sieve.begin(); it!=sieve.end(); it++)
		{
			if(*it!=p && *it%p==0)
			{
				it = sieve.erase(it);
			}
			else if(*it>p && flag)
			{
				flag = 0;
				p_next = *it;
			}
		}
		p = p_next;
	}
	for(auto it=sieve.begin(); it!=sieve.end(); it++)
	{
		if (*it>=M)
			cout << *it << "\n";
	}



	return 0;
}