#include <stdio.h>
#include <string>
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N; //  (1 ≤ N ≤ 10,000)
    string str;
    int num;
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
            else
                printf("%d\n", dq.front());
        }
        else if(str == "back"){
            if(dq.empty()){
                printf("-1\n");
            }
            else
                printf("%d\n", dq.back());
        }
        else if(str == "pop_front"){
            if(dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else if(str == "pop_back"){
            if(dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }
        else if(str.find("push_front") != -1){
            num = stoi(str.substr(11));
            dq.push_front(num);
        }
        else{ // push_back 
            num = stoi(str.substr(10));
            dq.push_back(num);
        }
    }
    return 0;
}