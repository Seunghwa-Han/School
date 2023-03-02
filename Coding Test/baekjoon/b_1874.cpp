#include <iostream>
#include <stdio.h>
#include <string>
#include <stack> 
using namespace std;
/*
작은거부터 스택에 푸시.
임의의 수열 -> 스택을 이용해서 그 수열을 만들 수 있는지 없는지 
어떤 순서로 push랑 pop을 해야하는지 

4, 3, 6, 8, 7, 5, 2, 1

1 2 3 4 

*/
int main(){
    int n, num, cur = 1; // 1 ≤ n ≤ 100,000
    string res =""; 
    stack<int> my_stack;

    scanf("%d\n", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d\n", num);

        if(my_stack.empty()){
            while(cur <= num){
                my_stack.push(cur++);
                res += "+\n";
            }
        }
        else if(my_stack.top() == num){
            my_stack.pop();
            res += '-\n';
        }
        else if(my_stack.top() < num){
            while(cur <= num){
                my_stack.push(cur++);
                res += "+\n";
            }
        }
        else { // my_stack.top() > num 
            while(1){
                
            }
        }
    }

    return 0;
}