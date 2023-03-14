#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,K; // (1 ≤ K ≤ N ≤ 5,000)
    queue<int> myq;

    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++){
        myq.push(i);
    }

    printf("<");
    while(1){

        if(myq.size() == 1){
            printf("%d>\n", myq.front());
            break;
        }
        else{
            for(int i=0; i<K-1; i++){
                myq.push(myq.front());
                myq.pop();
            }
            printf("%d, ", myq.front());
            myq.pop();
        }
    }
    return 0;
}