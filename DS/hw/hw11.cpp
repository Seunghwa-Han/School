#include <iostream>
#include <string>
#define HSIZE 100
using namespace std;

class element{
   public:
    string name;
    double score;
    void set_data(string n, double s);
};
void element::set_data(string n, double s){
    name = n;
    score = s;
}

class my_heap{
    element h[HSIZE];
    int csize;
    void adjust(int troot);
   public:
    my_heap();
    my_heap(element a[], int n);
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double score_average();
    int node_delete_by_name(string tname);
};
my_heap::my_heap(){
    csize = 0;
}
void my_heap::adjust(int troot){
    element tmp = h[troot];
    int child = troot*2;
    while(child<=csize){
        if(child<csize && h[child].score<h[child+1].score)
            child++;
        if(tmp.score >= h[child].score) break;
        h[child/2] = h[child];
        child = child*2;
    }
    h[child/2] = tmp;
}
my_heap::my_heap(element a[], int n){
    for(int i = 1; i<=n; i++){
        h[i] = a[i-1];
    }
    csize = n;
    for(int i = n/2; i>=1 ; i--){
        adjust(i);
    }
}
int my_heap::h_size(){
    return csize;
}
bool my_heap::heap_full(){
    return (csize >= HSIZE-1);
}
bool my_heap::heap_empty(){
    return (csize == 0);
}
void my_heap::insert_heap(element t){
    csize++;
    h[csize] = t;
    int k = csize;
    while(k!=1 && t.score>h[k/2].score){
        h[k] = h[k/2];
        k = k/2;
    }
    h[k] = t;
}
element my_heap::delete_heap(){
    element t = h[1];
    element tmp = h[csize];
    csize--;

    int child = 2;
    while(child <= csize){
        if(child<csize && h[child].score<h[child+1].score)
            child++;
        if(tmp.score >= h[child].score)
            break;
        h[child/2] = h[child];
        child = child*2;
    }
    h[child/2] = tmp;
    return t;
}
double summation(element a[], int troot, int n){
    if(troot > n) return 0;
    return a[troot].score + summation(a, troot*2, n)+ summation(a, troot*2+1, n);
}
double my_heap::score_sum(){
    return summation(h, 1, csize);
}
double my_heap::score_average(){
    return score_sum()/csize;
}
void heap_adjust(element a[], int troot, int n){
    element tmp = a[troot];
    int child = troot*2;
    while(child<=n){
        if(child<n && a[child].score<a[child+1].score)
            child++;
        if(tmp.score >= a[child].score)
            break;
        a[child/2] = a[child];
        child = child*2;
    }
    a[child/2] = tmp;
}
int delete_node(element a[], int troot, string tname, int n){
    if(troot>n) return 0;
    if(a[troot].name == tname){
        a[troot] = a[n];
        heap_adjust(a, troot, n);
        return 1;
    }
    if(delete_node(a, troot*2, tname, n)) return 1;
    return delete_node(a, troot*2+1, tname,n);
}
int my_heap::node_delete_by_name(string tname){
    if(csize == 0) return 0;
    if(delete_node(h, 1, tname, csize)){
        csize --;
        return 1;
    }
    return 0;
}

int main(){
    element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}  };
    my_heap h1(a, 6);
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;
    h1.node_delete_by_name("Kim");
    cout << "\n-- After the deletion operation. --\n\n";
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;

    while (h1.h_size() > 0) {
        element temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}