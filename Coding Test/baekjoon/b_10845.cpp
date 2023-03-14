#include <stdio.h>
#include <iostream>
#include <string> 
#include <deque>
using namespace std;

int main(){
    int N; //1 ≤ N ≤ 10,000
    int num;
    string str; 
    deque<int> dq;

    scanf("%d\n", &N);

    for(int i=0; i<N; i++){
        getline(cin, str);

        if(str == "size"){
            printf("%d\n", dq.size());
        }
        else if(str == "empty"){
            if(dq.empty()){
                printf("1\n");
            }
            else   
                printf("0\n");
        }
        else if(str == "front"){
            if(dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", dq.front());
            }
        }
        else if(str == "back"){
            if(dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", dq.back());
            }
        }
        else if(str == "pop"){
            if(dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else{
            num = stoi(str.substr(5));
            dq.push_back(num);
        }
    }

    return 0;
}