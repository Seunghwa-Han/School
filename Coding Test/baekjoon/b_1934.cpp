#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int A,B;
	int lcm;

	cin >> T;

	for(int i=0; i<T; i++){
		cin >> A;
		cin >> B;

		int a = A, b = B, r;
		if (a > b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		while(1){
			r = a%b;
			if (r == 0)
				break;
			a = b;
			b = r;
		}
		lcm = A*B/b;
		cout << lcm <<"\n";
	}
	return 0;
}