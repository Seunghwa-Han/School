#include <iostream>
#include <string>
using namespace std;
#define YES 1;
#define NO 0;

class node{
   public:
    char c;
    node * link;
    node();
    void set_data(char ch);
};
node::node(){
    link = NULL;
}
void node::set_data(char ch){
    c = ch;
}

class my_list{
    node * top; //첫 원소 위치 
   public:
    my_list();
    void add_to_top(node t);
    node delete_from_top();
    void show();
};
my_list::my_list(){
    top = NULL;
}
void my_list::add_to_top(node t){
    node * tmp; //새로운 노드 공간 잡기 
    tmp = new node;
    *tmp = t;  //내용 복사하기
    tmp->link = top; //원래 첫번째 원소를 가리키게 한다
    top = tmp;  //첫번째 원소를 새로 들어온 원소로 update
}
node my_list::delete_from_top(){
    node * tmp;
    tmp = top; //새로운 노드공간 만들어서 첫번째 원소 위치 붙잡고 있기 
    top = top->link; //top은 그 다음 원소 위치로 바꾸기 
    node t; //리턴할 노드 
    t = *tmp; //원래 첫원소 내용 복사하기 
    delete tmp;
    return t;
}
void my_list::show(){
    int i =0;
    for(node * t = top; t!=NULL; t = t->link){
        printf("[%d] %c\n", i, t->c);
        i++;
    }
}

int main(){
    my_list a;
    string input;
    char buff[80];
    int i, len;
    int result = YES;

    cin.getline(buff,80);
    input = buff;

    len = input.size(); //문자열 길이 

    for( i=0; i<len/2; i++){
        node tmp;
        tmp.set_data(input[i]);
        a.add_to_top(tmp);
    }

    while(i<len){
        if(len%2!=0 && i==len/2){
            i++;
            continue;
        }
        char t = a.delete_from_top().c;
        if(input[i]!=t){
            result = NO;
            break;
        }
        i++;
    }

    if(result==1) cout<<"Yes, it's a palindrome.\n";  
    else cout<<"No, it's not a palindrome.\n";

    return 0;
}