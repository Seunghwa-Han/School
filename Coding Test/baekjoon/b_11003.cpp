#include <iostream>
#include <deque>
#include <vector>
using namespace std;

typedef pair<int, int> Node;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L; // 1 ≤ L ≤ N ≤ 5,000,000
	cin >> N >> L;

	deque<Node> mydeque;  // -10^9 ≤ Ai ≤ 10^9
	// pair : index, number 

	int i, num;

	for(i=1; i<=N; i++){
		cin >> num;

		while(mydeque.size()!= 0 && mydeque.back().second > num){
			mydeque.pop_back();
		}
		mydeque.push_back(make_pair(i, num));

		if(mydeque.back().first - L >= mydeque.front().first)
			mydeque.pop_front();
		
		cout << mydeque.front().second << " ";
	}
	cout << "\n";

	return 0;
}