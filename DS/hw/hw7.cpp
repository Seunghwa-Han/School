#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

class element{
    public: 
        string s_title;
        int npages;
        int price;
        void set_data(string n, int pg, int pr);
};
void element::set_data(string n, int pg, int pr){
       s_title = n;
       npages = pg;
       price = pr;
}

class my_queue{
    element arr[SIZE];
    int rear;  //새로 들어갈 원소 위치 
    int front; //빠져나올 원소 위치 
    public:
        my_queue();
        void insert_q(element E);
        element delete_q();
        bool empty();
        bool full();
};
my_queue::my_queue(){
    rear = 0; 
    front = 0;
}
void my_queue::insert_q(element E){
    if(!full()){
        arr[rear] = E;
        rear = (rear+1)%SIZE;
    }
    else cout<<"queue is full.\n";
}
element my_queue::delete_q(){
    if(!empty()){
        int f = front;
        front = (front+1)%SIZE;
        return arr[f];
    }
    else cout<< "queue is empty.\n";
}
bool my_queue::empty(){
    return (rear == front);
}
bool my_queue::full(){
    return ((rear+1)%SIZE == front);
}

int main(){
    my_queue a;
    element tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while(!a.empty()){
        tmp = a.delete_q();
        cout << tmp.s_title <<" : "<< tmp.npages <<" : "<< tmp.price<<"\n";
    }
    return 0;
}