#include "UI.cpp"
#include "application.cpp"
#include <chrono>
#include <thread>

int main()
{
    Application app;
    map isVisited;
    map t;
    auto [data, goal_depth] = app.work(maze_, std::make_pair(10, 1), std::make_pair(19, 9), t, 0);
    
    std::cout << std::endl;
    std::cout << "<maze data>" << std::endl;
    for(int h=0;h<maze_.size();h++){
        for(int w=0;w<maze_.at(h).size();w++){
            std::cout << maze_.at(h).at(w) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "shortest path cost : " << goal_depth << std::endl;
}