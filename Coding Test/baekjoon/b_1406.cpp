#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    string input, command;  // 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.
    int M; // 1 ≤ M ≤ 500,000
    getline(cin, input);
    
    scanf("%d", &M);

    for(int i=0; i<M; i++){
        getline(cin, command);
    }

    return 0;
}