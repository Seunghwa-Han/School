//세가지 유형의 괄호,  (  ), {  }, [  ]를 사용하는 수식 표현에서, 괄호 사용의 오류를 점검하는 프로그램을 작성하시오.

#include <iostream>
#include <string>
#define SIZE 100
#define NORMAL 1
#define ERROR 0
using namespace std;

class mystack
{
    int top;
    char s[SIZE];
    public:
      mystack();
      void push(char ch);
      char pop();
      bool empty();
};
mystack::mystack(){
    top = 0;
};
void mystack::push(char ch){
    s[top++] = ch;
};
char mystack::pop(){
    top --;
    return s[top];
};
bool mystack::empty(){
    return (top == 0);
};

bool is_open(char ch){
    return (ch=='('|| ch=='{'|| ch=='[');
};
bool is_close(char ch){
    return (ch==')'|| ch=='}'|| ch==']');
};
char match(char ch){
    if(ch=='(') return ')';
    if(ch==')') return '(';
    if(ch=='{') return '}';
    if(ch=='}') return '{';
    if(ch=='[') return ']';
    if(ch==']') return '[';
    return '\0';
};
bool matched(char ch1, char ch2){
    if(ch1=='('&& ch2==')'||ch1=='{'&&ch2=='}'||ch1=='['&&ch2==']') return true;
    else return false;
}
//{a-(a+b 

int main(){
    mystack stack1;
    string input;
    char buff[100];
    int result = NORMAL;

    cin.getline(buff,100);
    input = buff;
    int length = input.size();

    for(int i=0; i<length; i++){
        if(is_open(input[i])) //여는 괄호이면 스택에 푸시 
            stack1.push(input[i]);
        else if(is_close(input[i])){  //닫는 괄호이면 
            if(stack1.empty()){  //중간에 팝할 원소가 없으면 여는 괄호 부족 

                //cout<<"Error: short of parenthesis, \'"<<match(input[i])<<"\' is expected.\n";
                cout<<"-Error: An extra prenthesis, \'"<<input[i]<<"\' is found.\n";
                result = ERROR;
                break;
            }
            else {
                char ch = stack1.pop();
                if(input[i]!=match(ch)){ //스택 팝해서 닫는 괄호랑 비교 
                    cout<<"Error: mis-matched parenthesis, \'"<<match(ch)<<"\' is expected.\n";
                    result = ERROR;
                    break;
                }
            }
        }
        else continue;
    }
    if(result == NORMAL){
       while(!stack1.empty()){
          //cout<<"Error: short of parenthesis, \'"<<match(stack1.pop())<<"\' is expected.\n";
          cout<<"Error: An extra prenthesis, \'"<<stack1.pop()<<"\' is found.\n";
          result = ERROR;
          break;
       }
    }

    if(result == NORMAL) cout<<"It's a normal expression.\n";
    return 0;
}


/*
세가지 유형의 괄호,  (  ), {  }, [  ]를 사용하는 수식 표현에서, 괄호 사용의 오류를 점검하는 프로그램을 작성하시오.
괄호 타입이 맞지 않음 , 정상 (끝까지 불일치 발생 안하고 최종 스택 상태 empty), 여는 괄호 부족(중간에 pop할때 괄호가 없음), 
닫는 괄호 부족(최종 스택에 내용 남아있음)

{a-(a+b  --> 괄호 부족 
{a-(a*b)  --> 
[b+{a-(a/b) -->괄호 부족 
{a-(a+b)}]  --> extra 괄호 
{a-(a+b)}(  --> extra 괄호 
a-(a+b)}  --> 
([{a-n}*b] --> extra 괄호 

끝나고 스택에 남아있는거 
-> 스택에 여는 괄호가 남아있으면 

일단 여는 괄호는 스택에 푸시. 

*/