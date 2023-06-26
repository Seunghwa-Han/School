#include <iostream>
#include <string>
#define HSIZE 100
using namespace std;

class element {
   public:
    string name;
    double score;
    void set_data(string n, double s);
};
void element::set_data(string n, double s){
    name =n;
    score =s;
}

class my_heap {
    element h[HSIZE];
    int csize;  //현재 힙 사이즈 
   public:
    my_heap();
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};
my_heap::my_heap(){
    csize = 0;
}
bool my_heap::heap_empty(){
    return (csize == 0);
}
bool my_heap::heap_full(){
    return (csize >= HSIZE-1);
}
int my_heap::h_size(){
    return csize;
}
void my_heap::insert_heap(element t){
    csize++;
    h[csize] = t;
    int k = csize;
    while(k!=1 && t.score > h[k/2].score){
        h[k] = h[k/2];
        k = k/2;
    }
    h[k] = t;
}
element my_heap::delete_heap(){
    element t = h[1];   //리턴할 원소 
    element tmp = h[csize]; 
    csize--;

    int child = 2;
    while(child <= csize){   //루트 부터 시작해서 밑으로 내려가는 반복문 
        if(child<csize && h[child].score<h[child+1].score)  //오른쪽이 있고, 오른쪽 key값이 더 크면 오른쪽 선택 
            child++; 
        if(tmp.score >= h[child].score)  //tmp가 더 크면 반복문 스탑 
            break; 
        h[child/2] = h[child];
        child = child*2;
    }
    h[child/2] = tmp;
    return t;
}

int main(){
    my_heap h1;

    element temp;
    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);
    
    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}