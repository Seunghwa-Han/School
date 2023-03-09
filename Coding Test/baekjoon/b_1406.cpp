#include <iostream>
#include <stdio.h>
#include <string>
#include <list> 
#include <functional>
using namespace std;

/*
abcdefg 
size: 7 
0 a 1 b 2 c 3 d 4 e 5 f 6 g 7
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

    for(int i=0; i<M; i++){
        getline(cin, command);

        if(command == "L"){
        }
        else if(command == "D"){
        }
        else if(command == "B"){
        }
        else{  // P $
            string ch = command.substr(2);
        }
    }

    cout << input <<endl;

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