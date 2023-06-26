#include <iostream>
#include <string>
#include <fstream>
#define SIZE 100
using namespace std;
class node{
  public:
    string name;
    double score;
    node * link;
    void set_data(string n, double s);
};
void node::set_data(std::string n, double s){
  name = n;
  score = s;
}

class my_list{
  node * head, * tail;
  public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string tname);
    int remove_a_node(string tname);
    void invert();
    friend bool list_equal(my_list a, my_list b);
};
my_list::my_list(){
  head = NULL;
  tail = NULL;
}
void my_list::add_to_head(node t){
  //헤드 쪽에 집어 넣을라면 일단 새로운 공간 생성 
  node * tmp = new node;
  *tmp = t;  //내용 복사 
  tmp->link = head;  //기존에 있는 원소랑 연결 
  head = tmp;  //헤드 위치 조정 
  if(tail == NULL) tail = tmp; //empty면 테일도 조정 
}
void my_list::add_to_tail(node t){
  //테일에 집어넣을라면 일단 새로운 공간 생성 
  node * tmp = new node;
  *tmp = t;
  tmp->link = NULL; //끝이니까 링크값 조정 
  if(tail!=NULL)  //주의 !!
    tail->link = tmp;
  else //empty이면 헤드도 변경 
    head = tmp; 
  tail = tmp;
}
node my_list::delete_from_head(){
  node t;
  t = *head; //리턴할 노드에 데이터복사 
  node * tmp = head; 
  head = head->link;
  delete tmp;
  if(head == NULL) tail = NULL;  //주의 !! 삭제 후에 empty될 때 
  return t;
}
int my_list::num_nodes(){
  int count = 0;
  for(node * t = head; t!=NULL; t=t->link){
    count++;
  }
  return count;
}
bool my_list::list_empty(){
  return (head==NULL);
}
double my_list::score_sum(){
  double sum = 0;
  for(node * t=head; t!=NULL; t=t->link){
    sum += t->score;
  }
  return sum;
}
double my_list::get_score(string tname){
  for(node * t=head; t!=NULL; t=t->link){
    if(t->name == tname){
      return t->score;
    }
  }
  return -1;
}
int my_list::remove_a_node(string tname){
  /*
  헤드 지우는 경우
    head = head->link;
    delete t;
    if(head == NULL) tail = NULL; 지우고나서 empty면 테일 조정 
  중간 노드 지우는 경우 
    prev->link = t->link  전에거 그 다음다음거로 연결 
    delete t
  근데 테일이면
    추가로 tail = prev 테일값 조정 
  
  */
  node * prev = NULL;
  node * t = head;
  while(t!=NULL && t->name!=tname){
    prev = t;
    t = t->link;
  }
  if(t== NULL) return 0;
  if(prev)
    prev->link = t->link;
  else 
    head = head->link;
  if(head == NULL) tail = NULL;
  if(t == tail) tail = prev;
  delete t;
  return 1;
}
void my_list::invert(){
  node * newhead = NULL;
  node * oldhead = head;
  while(1){
    if(oldhead == NULL) break;
    node * tmp = newhead;
    newhead = oldhead;
    oldhead = oldhead->link;
    newhead->link = tmp;
  }
  tail = head;
  head = newhead;
}
bool is_equal(node * a, node * b){
  if(a==NULL && b== NULL) return true;
  if(a==NULL || b==NULL) return false;
  if(a->name==b->name && a->score==b->score)
    return is_equal(a->link, b->link);
  return false;
}
bool list_equal(my_list a, my_list b){
  return is_equal(a.head, b.head);
}

int main( )
{
  my_list a,b;
  node tmp;
  tmp.set_data("Kim", 83.5);
  a.add_to_head(tmp);
  tmp.set_data("Lee", 78.2);
  a.add_to_head(tmp);
  tmp.set_data("Park", 91.3);
  a.add_to_head(tmp);
  tmp.set_data("Choi", 85.1);
  a.add_to_head(tmp);
  tmp.set_data("Choi", 85.1);
  b.add_to_head(tmp);
  tmp.set_data("Park", 91.3);
  b.add_to_head(tmp);
  tmp.set_data("Lee", 78.2);
  b.add_to_head(tmp);
  tmp.set_data("Kim", 83.5);
  b.add_to_head(tmp);     

  b.invert();
  if (list_equal(a, b))
    cout << "Yes, the two lists are identical. \n";
  else
    cout << "No, They are not identical.\n";
  
  tmp= b.delete_from_head();
  cout << tmp.name << " : " << tmp.score<< "\n";
  return 0; 
}
/*
2 : 161.7
3 : 253
Lee is deleted.
4 : 354.2
Park’s score : 91.3
Kim is deleted from the list.
3 : 270.7
*/

/*
Yes, the two lists are identical.
Choi : 85.1
*/