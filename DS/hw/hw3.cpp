#include <iostream>
#define SIZE 5
using namespace std;

class mystack{
    int s[SIZE];
    int top;  //top은 새로운 원소가 들어갈 위치 
    public:
        void init();
        void push(int x);
        int pop();
        bool stack_empty();
        bool stack_full();
        
};
void mystack::init(){
    top = 0;
};
void mystack::push(int x){
    s[top++] = x;
};
int mystack::pop(){
    top--;
    return s[top];
}
bool mystack::stack_empty(){
    if(top == 0) return true;
    else return false;
}
bool mystack::stack_full(){
    if(top >= SIZE) return true;
    else return false;
}

int main()
{
    mystack  s1;
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;
    s1.init();
    for (i = 0; i < 5; i++ )
        if (list[i]> 100)
            s1.push(list[i]);
    while ( ! s1.stack_empty( ) )
    {
        x = s1.pop( );
        cout << x << endl ; 
    }
    return 0;
}