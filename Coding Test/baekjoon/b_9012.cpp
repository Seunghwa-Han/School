#include <iostream>
#include <stdio.h>
#include <stack>
#include <string> 
using namespace std;

int main(){
    int T, flag = 0;
    string str;

    scanf("%d\n", &T);
    
    for(int i=0; i<T; i++){
        stack<char> my_stack;
        flag = 0;
        getline(cin, str);

        for(auto c: str){
            if(c == '('){
                my_stack.push(c);
            }
            else if(c == ')'){
                if(my_stack.empty() || my_stack.top() != '('){
                    flag = 1;
                    break;
                }
                else{
                    my_stack.pop();
                }
            }
        }
        if(!my_stack.empty())
            flag = 1;
        if(flag == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}