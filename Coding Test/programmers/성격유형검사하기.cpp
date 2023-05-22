#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size = survey.size();
    map<char, int> score;
    
    for(int i=0; i<size; i++){
        char type_no = survey[i][0];
        char type_yes = survey[i][1];
        
        if(choices[i]<4){
            if(score.find(type_no) == score.end())
                score[type_no] = 0;
            score[type_no] += 4-choices[i];
        }
        if(choices[i]>4){
            if(score.find(type_yes) == score.end())
                score[type_yes] = 0;
            score[type_yes] += choices[i]-4;
        }
    }
    
    if(score['R']>=score['T'])
        answer += 'R';
    else
        answer += 'T';
    
    if(score['C']>=score['F'])
        answer += 'C';
    else
        answer += 'F';

    if(score['J']>=score['M'])
        answer += 'J';
    else
        answer += 'M';
    
    if(score['A']>=score['N'])
        answer += 'A';
    else
        answer += 'N';
    return answer;
}