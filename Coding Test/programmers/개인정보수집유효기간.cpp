#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> date_split(const string& str){
    istringstream ss(str);
    string buf;
    vector<int> v; // year, month, day
    v.clear();
    while(getline(ss, buf, '.')){
        v.push_back(stoi(buf));
    }
    return v;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> v_today = date_split(today); 
    
    unordered_map<string, int> terms_map;
    for(const auto&term : terms){
        stringstream ss(term);
        string type, period;
        ss >> type >> period;
        terms_map[type] = stoi(period);
    }
    
    int len = privacies.size();
    for(int i=0; i<len; i++){
        stringstream ss(privacies[i]);
        string date, type;
        ss >> date >> type;
        vector<int> v_collect = date_split(date);
        
        int period = terms_map[type];
        
        int expired_year = v_collect[0] + period/12;
        int expired_month = v_collect[1] + period%12;
        if(expired_month > 12){
            expired_year += expired_month/12;
            expired_month = expired_month%12;
        }
        int expired_day = v_collect[2];
        
        if(expired_year < v_today[0] ||
          expired_year == v_today[0] && expired_month < v_today[1] ||
          expired_year==v_today[0] && expired_month == v_today[1] &&
            expired_day <= v_today[2])
            answer.push_back(i+1);
    }
    
    return answer;
}