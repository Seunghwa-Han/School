#include <iostream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string str, char c){
    istringstream iss(str);
    string tmp;
    vector<string> res;
    res.clear();
    while(getline(iss, tmp, c)){
        res.push_back(tmp);
    }
    return res;
}

int main(){
    int T; 
    string str, back;
    vector<string> word;  
    
    scanf("%d\n", &T);

    for(int i=0; i<T; i++){
        getline(cin, str);
        word = split(str, ' ');
        back = word.back();
        reverse(back.begin(), back.end());
        for(auto w: word){
            reverse(w.begin(), w.end());
            if(w == back){
                cout << w << endl;
            }
            else
                cout << w << " ";
        }
    }
    return 0;
}