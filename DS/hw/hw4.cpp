#include <iostream>
#include <string>
#define SIZE 10
#define EOS '$'
using namespace std;

class mystack{  //문자원소 operator를 저장할 수 있는 스택 클래스 
    int top;  //새로운 원소가 들어갈 위치
    char s[SIZE];
    public:
        mystack();
        void push(char x);
        char pop();
        bool empty();
        char top_element();
};
mystack::mystack(){
    top = 0;
};
void mystack::push(char x){
    s[top++] = x;
};
char mystack::pop(){
    top--;
    return s[top];
};
bool mystack::empty(){
    return (top == 0);
}
char mystack::top_element(){
    return s[top-1];
};

bool is_operand(char ch){
    if(ch == '('|| ch==')'||ch=='$'|| ch=='+'|| ch=='-'|| ch=='*'|| ch=='%'|| ch=='/') return false;
    else return true;
}
int get_precedence(char ch){
    if(ch == '/'|| ch=='*'|| ch=='%') return 2;
    else if(ch == '+'|| ch =='-') return 1;
    else return 0;
}

int main(){
    mystack stack;
    stack.push(EOS);

    string input, output;
    cout<<"Input an infix expression to convert : ";
    cin>>input;
    input += '$';

    for(int i=0; i<input.size(); i++){
       if(is_operand(input[i])) output += input[i];  //피연산자는 그대로 출력 
       else{
           if(input[i] == '(') stack.push(input[i]);  //여는 괄호 
           else if(input[i] == ')'){  //닫는 괄호 
               while(1){
                   if(stack.top_element()=='('){  //여는 괄호 나오면 꺼내기 스탑 
                       stack.pop();
                       break;
                   } 
                   output += stack.pop();
               }
           }
           else{
               while(1){
                   int n = get_precedence(stack.top_element());
                   if(n < get_precedence(input[i])){  //자기보다 우선순위 낮으면 꺼내기 스탑 
                       stack.push(input[i]);
                       break;
                   }
                   if(stack.top_element()==EOS) break;   //꺼낼때 스택 끝이면 멈추기 
                   output += stack.pop();
               }
           }
       }
    }
    cout<<output<<endl;

    return 0;
}