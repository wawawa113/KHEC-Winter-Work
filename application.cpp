#include "DFS.cpp"

class Application{
    private:
    long long ANSWER_DEPTH_;
    std::vector<map> data_;
    void DoDFS(map maze, coordinate now, coordinate goal, map &visited, long long depth, long long &ANSWER_DEPTH, std::vector<map> &data){
        domain::DFS(maze, now, goal, visited, depth, ANSWER_DEPTH, data);
    }
    
    public:
    std::pair<std::vector<map>,long long> work(map maze, coordinate now, coordinate goal, map &visited, long long depth){
        DoDFS(maze,now,goal,visited,depth,ANSWER_DEPTH_,data_);
        return make_pair(data_,ANSWER_DEPTH_);
    }
};