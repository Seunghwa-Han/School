#include <iostream>
#include <string> 
#include <stack> 
using namespace std;

/*
stack size -> 막대기 depth 

괄호 쌍 : 스택 사이즈만큼 cnt 증가
여는 괄호 : stack push 
닫는 괄호 : stack pop, cnt++
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    stack<char> my_stack; 
    int cnt=0, l_cnt=0, len;


    getline(cin, str);  // 괄호 문자의 개수는 최대 100,000
    len = str.length();

    for(int i=0; i < len; i++){
        if(i<len-1 && str[i]=='(' && str[i+1]==')'){
            i++;
            if(my_stack.empty())
                continue;
            cnt += my_stack.size();
            
        }
        else if (str[i]=='(')
        {
            my_stack.push('(');
        }
        else if (str[i]==')')
        {
            my_stack.pop();
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}