#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class stack{
    vector<int> v;
public:
    void push(int x);
    void pop();
    void size();
    void empty();
    void top();
};

void stack::size(){
    printf("%d\n", v.size());
}
void stack::empty(){
    if(v.empty()){
        printf("1\n");
    }
    else
        printf("0\n");
}
void stack::top(){
    if(v.empty()){
        printf("-1\n");
    }
    else{
        printf("%d\n", v.back());
    }
}
void stack::push(int x){
    v.push_back(x);
}
void stack::pop(){
    if(v.empty()){
        printf("-1\n");
    }
    else{
        printf("%d\n", v.back());
        v.pop_back();
    }
}


int main(){
    int n; // (1 ≤ N ≤ 10,000)
    string str; 
    stack my_stack;

    scanf("%d\n", &n);

    for(int i=0; i<n; i++){
        getline(cin, str);
        
        if(str.find("push") == 0){
            int x = stoi(str.substr(5));
            my_stack.push(x);
        }
        else if(str == "pop"){
            my_stack.pop();
        }
        else if(str == "size"){
            my_stack.size();
        }
        else if(str == "empty"){
            my_stack.empty();
        }
        else{ 
            my_stack.top();
        }
    }

    return 0;
}