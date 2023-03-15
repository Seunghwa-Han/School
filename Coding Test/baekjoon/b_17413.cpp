#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string S; // S의 길이는 100,000 이하이다 
	stack<char> my_stack;
	int index = 0;
	int length;

	getline(cin, S);

	length = S.length();

	while(index < length){
		// printf("[%d,%c]", index,S[index]);
		if(S[index] == '<'){
			while(!my_stack.empty()){
				printf("%c", my_stack.top());
				my_stack.pop();
			}
			
			int tmp = S.find(">", index);
			cout << S.substr(index, tmp-index+1);
			index = tmp;
		}
		else if(S[index] == ' '){
			while(!my_stack.empty()){
				printf("%c", my_stack.top());
				my_stack.pop();
			}
			printf(" ");
		}
		else{
			my_stack.push(S[index]);
		}
		index++;
	}

	while(!my_stack.empty()){
		printf("%c", my_stack.top());
		my_stack.pop();
	}

	printf("\n");
	
	return 0;
}