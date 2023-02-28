#include <iostream>
#include <stdio.h>
#include <string>
#include <stack> 
#include <sstream>
using namespace std;

void print_reverse(string str){
    stack<char> my_stack;
    for(auto c: str){
        my_stack.push(c);
    }
    while(!my_stack.empty()){
        printf("%c", my_stack.top());
        my_stack.pop();
    }
    printf(" ");
}

int main(){
    int T; 
    string str, token;
    
    scanf("%d\n", &T);

    for(int i=0; i<T; i++){
        getline(cin, str);
        istringstream iss(str);
        while(iss >> token){
            print_reverse(token);    
        }
        printf("\n");
    }
    return 0;
}