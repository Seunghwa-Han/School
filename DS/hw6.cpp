//어떤 주어진 string이 Palindrome(좌우 대칭인 string)인지 여부를 판단하는 프로그램을 작성하시오.
#include <iostream>
#define SIZE 100
#define YES 1;
#define NO 0;
using namespace std;

class mystack{
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
}

int main(){
    mystack stack1;
    string input; 
    char buff[80];
    int check = 0;
    int result = YES;
    int len, i;

    cin.getline(buff,80);
    input = buff;

    len = input.size();

    for(i=0; i<len/2; i++){  // 입력받은 문자열 절반을 스택에 푸시 
        stack1.push(input[i]);
    }

    while(i<len){  // 문자열 길이만큼 반복 
        if(len%2!=0 && i==len/2){  // 문자열 길이가 짝수이고, 문자열의 절반인 지점이라면 그냥 넘어가기 
            i++;   
            continue;
        }  
        if(input[i]!=stack1.pop()){  // 문자와 스택 탑의 문자가 같지 않다면 비대칭으로 판단하고 break
            result = NO;
            break;
        }
        i++;
    }

    if(result==1) cout<<"Yes, it's a palindrome.\n";  
    else cout<<"No, it's not a palindrome.\n";
    return 0;
}