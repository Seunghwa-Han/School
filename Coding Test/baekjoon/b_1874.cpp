#include <iostream>
#include <stdio.h>
#include <string>
#include <stack> 
using namespace std;
/*
작은거부터 스택에 푸시.
임의의 수열 -> 스택을 이용해서 그 수열을 만들 수 있는지 없는지 
어떤 순서로 push랑 pop을 해야하는지 

seq: 4, 3, 6, 8, 7, 5, 2, 1
seq: 1 2 5 3 4

stack.top == seq : pop
stack.top < seq
    1. if cur > seq : 불가능한 경우
    2. else : stack.top == seq까지 push 
stack.top > seq : 불가능한 경우 

*/

void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;
 
// Extract top of the stack
    int x = s.top();
 
    // Pop the top element
    s.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';
 
    // Proceed to print
// remaining stack
    PrintStack(s);
 
    // Push the element back
    s.push(x);
}

int main(){
    int n, seq, cur = 1; // 1 ≤ n ≤ 100,000
    string res =""; 
    stack<int> my_stack;
    my_stack.push(0);

    scanf("%d\n", &n);
    
    for(int i=0; i<n-1; i++){
        scanf("%d\n", &seq);

        if(my_stack.top() == seq){
            my_stack.pop();
            res += "-\n";
        }
        else if(my_stack.top() < seq){
            if(cur > seq){
                res = "NO\n";
            }
            else{
                while(my_stack.top() < seq){
                    my_stack.push(cur++);
                    res += "+\n";
                }
                my_stack.pop();
                res += "-\n";
            }
        }
        else { // my_stack.top() > seq 
            res = "NO\n";
        }
        
        printf(">>%d: ", seq);
        PrintStack(my_stack);
        printf("\n");
    }

    cout << res; 

    return 0;
}