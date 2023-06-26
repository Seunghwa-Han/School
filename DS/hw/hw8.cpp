#include <iostream>
#include <string>
using namespace std;
class node{
   public:
    string name;
    double score;
    node * link;
    node();
    void set_data(string n, float s);
};
node::node(){
    link = NULL;
}
void node::set_data(string n, float s){
    name = n;
    score = s;
}

class my_list{
    node * head; //첫 원소 위치 
    node * tail; //끝 원소 위치 
   public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list::add_to_head(node t){ //헤드 쪽에 추가하기 
    node * p = new node;  //새로운 노드 공간 잡기 
    *p = t;  //data복사 
    p->link = head; //새로운 노드 공간이 헤드(원래 첫 원소 위치)를 가리켜야 함 
    head = p; //헤드를 새로운 노드 공간으로 바꿔주기 
    if(tail==NULL) tail = p;  //만약 empty였다면 테일도 새로운 노드 공간(첫원소)으로 바꿔주기 
}
void my_list::add_to_tail(node t){  //테일 쪽에 추가하기 
    node * p = new node; //새로운 노드 공간 잡기 
    *p = t; //data 복사 
    p->link = NULL;
    if(tail!=NULL) //이전 상태가 empty가 아니라면 
        tail->link = p;  //테일(원래 끝 원소)이 새로운 노드 공간을 가리켜야 함 
    else   //이전 상태가 empty였다면 
        head = p;  //헤드도 새로운 노드 공간으로 바꿔주기 
    tail = p; //테일을 새로운 노드 공간으로 바꿔주기 
}
node my_list::delete_from_head(){
    node temp; //리턴할 노드 
    node * t; 
    t = head; //첫 원소 위치 복사하기 
    temp = *head; //첫 원소 data 복사하기 
    head = head->link; //첫 원소(헤드)를 그 다음 원소로 바꾸기 
    delete t;
    if(head == NULL) 
        tail = NULL; //헤드 삭제하고 나서 empty가 되면 tail도 NULL로 바꾸기 
    return temp;
}
int my_list::num_nodes(){
    node * t;
    int count = 0;
    for(t = head; t!=NULL; t=t->link){
        count++;
    }
    return count;
}
bool my_list::list_empty(){
    return (head == NULL);
}
double my_list::score_sum(){
    double sum = 0;
    node * t;
    for(t=head ; t!=NULL; t= t->link){
        sum += t->score;
    }
    return sum;
}
double my_list::get_score(string t_name){
    node * t;
    for(t=head; t!=NULL; t=t->link){
        if(t->name == t_name){
            return t->score;
        }
    }
    return -1; //해당하는 이름이 없으면 -1 리턴 
}
int my_list::remove_a_node(string t_name){  
/*
첫 노드(헤드) 삭제하는 경우 
    헤드 위치 딴 곳에 복사하고 삭제하기 
    헤드를 다음 노드로 바꿔주기 
    - 헤드 삭제하고 나서 empty가 되면(head==NULL) tail도 NULL로 바꿔주기 
마지막 노드(테일) 삭제하는 경우
    테일 위치 딴 곳에 복사하고 삭제하기 
    테일을 그 전 노드로 바꿔주기 
    테일의 링크를 NULL로 바꿔주기 
    - 테일 삭제하고 empty되는 경우는(tail==NULL) head도 NULL로 바꿔주기 ...-> 근데 이건 위에서 걸러질듯 
중간 노드 삭제하는 경우 
*/
    node * t;  
    node * a = NULL; //전에거 저장할 노드 공간 
    for(t=head; t!=NULL; t=t->link){
        if(t->name == t_name){
            node * tmp;
            if(t==head){ //첫번째 노드(헤드) 삭제하는 경우 
                tmp = t;
                head = t->link;  //헤드를 
                delete tmp;
                if(head == NULL) tail = NULL; //헤드 삭제하고 나서 empty되면 tail 바꾸기 
            }else if(t==tail){ //마지막 노드(테일) 삭제하는 경우
                tmp = t;
                tail = a;
                delete tmp;
                tail->link = NULL;
            }else{ //중간 노드 삭제하는 경우 
                tmp = t;
                a->link = t->link; //전에거가 t 다음거를 가리키도록 
                delete tmp;
            }
            return 1;
        }
        a = t;
    }
    return 0; //해당 노드가 없으면 0 리턴 
}

int main(){
    my_list a;
    node tmp;

	tmp.set_data("Kim", 83.5);
   	a.add_to_head(tmp);

   	tmp.set_data("Lee", 78.2);
   	a.add_to_head(tmp);           // head 위치로 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검

   	tmp.set_data("Park", 91.3);   
   	a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검

    tmp = a.delete_from_head();

    cout  << tmp.name << " is deleted.\n";   // 3단계 점검 

    tmp.set_data("Choi", 85.1);   
   	a.add_to_tail(tmp);           

	tmp.set_data("Ryu", 94.3);   
   	a.add_to_head(tmp);             // 2개의 원소 추가

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";

    cout << "Park’s score : " << a.get_score("Park")<< "\n";  // 4단계 점검

    if ( a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5단계 점검
/*
    if ( a.remove_a_node("Ryu") == 1)
        cout << "Ryu is deleted from the list. \n";     // 5단계 점검
    if ( a.remove_a_node("Choi") == 1)
        cout << "Choi is deleted from the list. \n";     // 5단계 점검
        */
    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";  // 최종 점검    

    return 0;
}