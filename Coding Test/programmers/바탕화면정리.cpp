#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int height = wallpaper.size();
    int width = wallpaper[0].size();

    // 가장 왼쪽 위, 가장 오른쪽 아래 
    int lux = height, luy = width;
    int rdx = -1, rdy = -1;

    for(int i = 0; i<height; i++){
        for(int j =0; j<width; j++){
            if(wallpaper[i][j] == '#')
            {
                if(lux > i)
                    lux = i;
                if(luy > j)
                    luy = j;
                if(rdx < i+1)
                    rdx = i+1;
                if(rdy < j+1)
                    rdy = j+1;
            }
        }
    }
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    return answer;
}