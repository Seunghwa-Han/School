#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int height = park.size();
    int width = park[0].size();
    
    int x, y;  // 세로 위치, 가로 위치 
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(park[i][j]=='S'){
                x = i; 
                y = j;
            }
        }
    }
    
    for(auto route : routes){
        stringstream ss(route);
        string op, n_str;
        ss >> op >> n_str;
        int n = stoi(n_str);
        
        if(op == "E"){
            if(y+n < width){
                if(park[x].substr(y, n+1).find("X") == string::npos)
                    y += n;
            }
	}
	else if(op == "W"){
            if(y-n >= 0){
                if(park[x].substr(y-n, n+1).find("X")==string::npos)
                    y -= n;
            }
	}
	else if(op == "S"){
            if(x+n < height){
                int flag = 1;
                for(int k = x; k<=x+n; k++){
                    if(park[k][y]=='X'){
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    x += n;
            }
	}
	else{ // N
            if(x-n >= 0){
                int flag = 1;
                for(int k = x-n; k<=x; k++){
                    if(park[k][y]=='X'){
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    x -= n;
            }
	}
    }
           
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}

int main()
{	
	vector<string> p1 = {"SOO","OXX","OOO"};
	vector<string> p2 = {"E 2","S 2","W 1"};
	vector<int> ans = solution(p1, p2);

	for(auto item : ans)
		cout<<item<<"\n";
	return 0;
}