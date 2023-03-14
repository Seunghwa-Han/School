#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
/*
1 2 3 4 5 6 7 
(7,3)

3
1 2 4 5 6 7 
*/
int main(){
    int N,K; // (1 ≤ K ≤ N ≤ 5,000)
    int cnt = 1;
    list<int> list;

    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++){
        list.push_back(i);
    }

    printf("<");
    auto iter = list.begin();
    
    while(1){

        if(list.size() == 1){
            printf("%d>\n", *iter);
            break;
        }

        if(cnt % K == 0){
            printf("%d, ", *iter);

            iter = list.erase(iter);
            if(iter == list.end()){
                iter = list.begin();
            }
        }
        else{
            if(++iter == list.end()){
                iter = list.begin();
            }
        }
        
        cnt++;
    }


    return 0;
}