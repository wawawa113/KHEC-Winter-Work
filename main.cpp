using namespace std;
#include <iostream>
#include <vector>
#include <utility>

using map=vector<vector<int>>;
using coordinate=pair<int,int>;

map maze = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
             {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
             {1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
             {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
             {1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
             {1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
             {1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
             {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
             {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void DFS(map maze,coordinate now,coordinate goal,map visited,int depth,int& answer){
    if(now==goal){
        answer=depth;
    }
    vector<coordinate> visitable;
    int x=now.first;
    int y=now.second;

    visited[y][x]=1;

    if(maze[y][x-1]==0){
        visitable.push_back(make_pair(x-1,y));
    }
    if(maze[y][x+1]==0){
        visitable.push_back(make_pair(x+1,y));
    }
    if(maze[y-1][x]==0){
        visitable.push_back(make_pair(x,y-1));
    }
    if(maze[y+1][x]==0){
        visitable.push_back(make_pair(x,y+1));
    }
    for(int i=0;i<visitable.size();i++){
        int tx=visitable[i].first;
        int ty=visitable[i].second;
        if(visited[ty][tx]==1){

        }else{
            DFS(maze,visitable[i],goal,visited,depth+1,answer);
        }
    }
}

int main(){
    map visited=maze; //visitedを定義する
    int answer; //答えを受け取る変数を定義する
    coordinate start(10,1);
    coordinate goal(19,9);
    DFS(maze,start,goal,visited,0,answer);
    cout << answer << endl; //答えを出力する
}