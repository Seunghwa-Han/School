#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int S, P; // 1 ≤ |P| ≤ |S| ≤ 1,000,000
	string dna;
	vector<int> acgt(4, 0);
	vector<int> check(4, 0);
	int i, j;
	int cnt = 0;

	cin>> S >> P;
	cin>> dna;
	cin>> acgt[0] >> acgt[1] >> acgt[2] >> acgt[3];

	if(P > 0 & S > 0){

		for(i=0; i<P; i++){
			if(dna[i] == 'A')
				check[0]++;
			else if(dna[i] == 'C')
				check[1]++;
			else if(dna[i] == 'G')
				check[2]++;
			else if(dna[i] == 'T')
				check[3]++;
		}

		for(i=0, j=i+P; i<=S-P; i++, j++){

			if(acgt[0]<= check[0] & acgt[1]<=check[1] & acgt[2]<=check[2] & acgt[3] <= check[3])
				cnt++;

			if(dna[i] == 'A')
				check[0]--;
			else if(dna[i] == 'C')
				check[1]--;
			else if(dna[i] == 'G')
				check[2]--;
			else if(dna[i] == 'T')
				check[3]--;

			if(dna[j] == 'A')
				check[0]++;
			else if(dna[j] == 'C')
				check[1]++;
			else if(dna[j] == 'G')
				check[2]++;
			else if(dna[j] == 'T')
				check[3]++; 
		}
	}

	cout << cnt << "\n";

	return 0;
}