#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, int> get_index;
    unordered_map<string, int> report_num;

    int i = 0;
    for(auto id : id_list){
        answer.push_back(0); // initialize 
        report_num[id] = 0; // initialize 
        get_index[id] = i++;
    }

    vector<unordered_set<string>> report_list(i);

    for(auto item : report){
        stringstream ss(item);
        string id, report_id;
        ss >> id >> report_id;

        int index = get_index[id];

        auto res = report_list[index].insert(report_id);
        if(res.second == 1) // no duplicate 
        {
            report_num[report_id] += 1;
        }
    }


    for(i=0; i<report_list.size(); i++){
        for(string id : report_list[i])
            if (report_num[id] >= k)
                answer[i] ++;
    }

    return answer;
}