#include <iostream>
#include <sstream>
#include <string> 
#include <stack>
using namespace std;

/*
3 5 2 7 -> 5 7 7 -1
1초 
N (1 ≤ N ≤ 1,000,000)
A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    string A;
    stack<int> st1;
    stack<int> st2;

    cin >> N;
    cin.ignore();
    getline(cin, A);

    istringstream iss(A);
    string tmp;
    int num;
    while(iss >> tmp){
        num = stoi(tmp);
        st1.push(num);
    }



    return 0;
}

