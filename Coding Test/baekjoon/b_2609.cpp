#include <iostream>
#include <algorithm>
using namespace std;
/*
uclid algorithm 
Theorem 2.8 : gcd * lcm = a*b

*/

int get_gcd(int a, int b){
	int r;
	if (b > a) swap(a,b);

	while(1){
		r = a % b;

		if (r == 0){
			break;
		}
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num1, num2;
	int gcd, lcm;
	cin >> num1;
	cin >> num2;

	gcd = get_gcd(num1, num2);
	lcm = num1*num2/gcd;

	cout << gcd << "\n";
	cout << lcm << "\n";

	return 0;
}