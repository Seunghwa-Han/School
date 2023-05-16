#include <iostream>
using namespace std;

class weight{
    int kg, g;
    public:
        void set_weight(int a, int b);
        int get_weight();
};
void weight::set_weight(int a, int b){
    kg = a;
    g = b;
};
int weight::get_weight(){
    return kg*1000 + g;
};

weight add_weight(weight a, weight b){
    weight tmp;
    int n = a.get_weight() + b.get_weight();
    tmp.set_weight(n/1000, n%1000);
    return tmp;
};
bool less_than(weight a, weight b){  
    if(a.get_weight() < b.get_weight()) return true;
    else return false;
};

int main( )
{
    weight  w1, w2, w3;  // weight라는 class object 3개 생성
    w1.set_weight(3, 400);  // w1을 3kg 400 g으로 
    w2.set_weight(2, 700);  // w2을 2kg 700 g으로 
    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g
    cout<< w3.get_weight() << "grams\n"; // w3의 값 ‘6100 grams’ 출력
    if (less_than(w1, w2) ) // w1이 w2보다 작은 값인가 판단
        cout<< "yes. \n"; 
    else
        cout<< "no. \n";   // 작지 않으므로 ‘no’ 출력
}