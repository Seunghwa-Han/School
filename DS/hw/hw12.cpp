//binary search tree
#include <iostream>
#include <string>
using namespace std;

class bst_node {
public:
    string s_id;
    string name;
    double score;
    bst_node * left, *right;
    bst_node();
    bst_node(string id, string n, double s);
    void set_data(string id, string n, double s);
};
bst_node::bst_node(){
    score = 0;
}
bst_node::bst_node(string id, string n, double s){
    s_id = id;
    name = n;
    score = s;
}
void bst_node::set_data(string id, string n, double s){
    s_id = id;
    name = n;
    score = s;
}

class bst_tree{
    bst_node * root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
    int size();
};
bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}

bst_node search_node(bst_node * root, string tid){
    if(root == NULL){   //없는 경우 
        bst_node t("0000000000", "None", -1);
        return t;
    }
    if(root->s_id == tid){  //키값이 일치하는 경우 
        bst_node t;
        t = *root;
        return t;
    }
    else if(root->s_id < tid)   //키값이 더 큰경우 오른쪽 서브트리에서 찾기 
        return search_node(root->right, tid);
    return search_node(root->left, tid);  //키값이 작은 경우 왼쪽 서브트리에서 찾기 
}
bst_node bst_tree::search(string tid){
    return search_node(root, tid);
} 

void bst_tree::insert_node(bst_node t){
    bst_node * p;  //루트부터 시작해서 반복문 돌릴 노드 포인터 
    p = root;

    string tid = t.s_id;  
    bst_node * tmp = new bst_node;  //insert할 노드 포인터 
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(p == NULL){  //트리가 empty이면 루트에 노드 저장 
        root = tmp;
        csize++;
        return;
    }

    while(1){
        if(p->s_id == tid){  //key값이 이미 존재하는 경우 
            cout<< "Insertion Failed: the Key "<<tid<<" already exists.\n";
            delete tmp;
            return;
        }
        if(p->s_id < tid){ // key 보다 작은 경우 
            if(p->right == NULL){
                p->right = tmp;
                csize++;
                return;
            }
            p = p->right;
        }
        else{ // key 보다 큰 경우 
            if(p->left == NULL){
                p->left = tmp;
                csize++;
                return;
            }
            p = p->left;
        }
    }
}
void inorder_traverse(bst_node * p){
    if(p == NULL) return;
    inorder_traverse(p->left);
    cout<< p->s_id<< " : "<<p->name<<" : "<<p->score <<"\n";
    inorder_traverse(p->right);
}
void bst_tree::show_inorder(){
    //inorder면 왼쪽 서브트리 먼저 그다음 노드 그다음 오른쪽 서브트리 
    inorder_traverse(root);
}
int bst_tree::size(){
    return csize;
}

int main()
{
	bst_node temp;
	bst_tree t1;	
	temp.set_data("21900013", "Kim", 6.5);	
	t1.insert_node(temp);	
	temp.set_data("21900136", "Lee", 8.8);
	t1.insert_node(temp);
	temp.set_data("21900333", "Park", 9.2);
	t1.insert_node(temp);
	temp.set_data("21800442", "Choi", 7.1);
	t1.insert_node(temp);
	temp.set_data("21900375", "Ryu", 5.4);
	t1.insert_node(temp);
	temp.set_data("21700248", "Cho", 6.3);
	t1.insert_node(temp);

    cout << "\n\nNode List : inorder sequence \n";

	t1.show_inorder();

	string s_key = "21800442";
	temp = t1.search(s_key);

	cout << "\n -- " << s_key << "'s record ---" << endl;
	cout << " Student ID   : "<< temp.s_id << endl;
	cout << " Student Name : "<< temp.name << endl;
	cout << " Score        : " << temp.score << endl;
	
	return 0;
}

/*
<  예상 출력 결과 >
Node List : inorder sequence
21700248 : Cho : 6.3
21800442 : Choi : 7.1
21900013 : Kim : 6.5
21900136 : Lee : 8.8
21900333 : Park : 9.2
21900375 : Ryu : 5.4

 -- 21800442's record ---
 Student ID   : 21800442
 Student Name : Choi
 Score        : 7.1
*/