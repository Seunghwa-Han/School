#include <iostream>
#include <stdio.h>
#include <string>
#include <list> 
using namespace std;

/*
a->b->c->d->
it = lst.begin() : |a 

*/

int main(){
    string input, command;  // 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.
    int M; // 1 ≤ M ≤ 500,000
    int size;
    list<char> list;

    getline(cin, input);
    size = input.length();
    
    scanf("%d\n", &M);

    for(int i=0; i<size; i++){
        list.push_back(input[i]);
    }

    auto iter = list.end();

    for(int i=0; i<M; i++){
        getline(cin, command);

        if(command == "L"){
            if(iter != list.begin()){
                iter--;
            }
        }
        else if(command == "D"){
            if(iter != list.end()){
                iter++;
            }
        }
        else if(command == "B"){
            if(iter != list.begin()){
                iter = list.erase(--iter);
            }
        }
        else{  // P $
            char ch = command[2];
            list.insert(iter, ch);
        }
    }

    for(iter = list.begin(); iter!=list.end(); iter++){
        cout << *iter;
    }
    printf("\n");

    return 0;
}

/*

시간초과 
int main(){
    string input, command;  // 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.
    int M; // 1 ≤ M ≤ 500,000
    int cursor, size;
    getline(cin, input);
    size = cursor = input.length();
    
    scanf("%d\n", &M);

    for(int i=0; i<M; i++){
        getline(cin, command);

        if(command == "L"){
            if(cursor > 0)
                cursor--;
        }
        else if(command == "D"){
            if(cursor < size)
                cursor++;
        }
        else if(command == "B"){
            if(cursor > 0){
                input.erase(--cursor, 1);
            }
        }
        else{  // P $
            string ch = command.substr(2);
            input.insert(cursor++, ch);
            size = input.length();
        }
    }

    cout << input <<endl;

    return 0;
}
*/