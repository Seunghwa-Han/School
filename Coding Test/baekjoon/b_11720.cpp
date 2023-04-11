#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N; // (1 ≤ N ≤ 100)
    string input;
    int sum = 0;

    cin >> N;
    cin >> input;

    int len = input.length();

    // for(auto i : input){
    //     sum += i - '0';
    // }
    for(int i=0; i<len; i++)
        sum += input[i]-'0';
    cout << sum <<"\n";


    return 0;
}