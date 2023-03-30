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
    stack<int> my_stack;

    cin >> N;
    cin.ignore();
    getline(cin, A);

    istringstream iss(A);
    string tmp;
    int num;
    while(iss >> tmp){
        num = stoi(tmp);
        my_stack.push(num);
    }
    stack<int> st;
    while(!my_stack.empty()){
        num = my_stack.top();
        st.push(num);
        my_stack.pop();
    }

    while(1){
        num = st.top();
        st.pop();
        if(num < st.top())
            cout << num <<" ";
        else
            st.pop();
    }




    return 0;
}