#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
void back(int p, int len);
bool is_prime(int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 1 ≤ N ≤ 8  1000 0000
    cin >> N;

    // int max = pow(10, N)-1;
    // vector<bool> check(max+1, true);
    // int root = sqrt(max);
    // int i;
    // int p = 2;
    // check[0] = false;
    // check[1] = false;
    // while(p<=root)
    // {
    //     int flag = 1;
    //     int p_next;
    //     for(i=p+1; i<=max; i++)
    //     {
    //         if(check[i] && i!=p)
    //         {
    //             if(i%p == 0)
    //                 check[i] = false;
    //             else if(flag){
    //                 p_next = i;
    //                 flag = 0;
    //             }
    //         }
    //     }
    //     p = p_next;
    // }

    back(2, N);
    back(3, N);
    back(5, N);
    back(7, N);
    
    return 0;
}

bool is_prime(int num){
    for(int i = 2; i<=num/2; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void back(int p, int len){

    int pre = p*10, num, i;
    int res = p / pow(10, len-1);

    if(res > 0)
        cout <<p << "\n";

    res = pre / pow(10, len-1);
    if(res >= 10)
        return ;

    for(i=1; i<10; i+=2){
        num = pre + i;
        if(is_prime(num)){
            back(num, len);
        }
    }
}