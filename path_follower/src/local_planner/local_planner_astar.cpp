/// HEADER
#include <path_follower/local_planner/local_planner_astar.h>

/// PROJECT
#include <path_follower/pathfollower.h>

LocalPlannerAStar::LocalPlannerAStar(PathFollower &controller, tf::Transformer &transformer,
                                     const ros::Duration &update_interval)
    :LocalPlannerStar(controller,transformer,update_interval)
{

}

double LocalPlannerAStar::G(HNode*& current, std::size_t& index, std::vector<HNode*>& successors,
                            const std::vector<Scorer::Ptr>& scorer, const std::vector<double>& wscorer,
                            double& score){
    double tentative_gScore = current->gScore_ ;
    if(successors[index]->twin_ != nullptr){
        tentative_gScore += Cost(*(successors[index]->twin_), scorer, wscorer, score);
    }else{
        tentative_gScore += Cost(*(successors[index]), scorer, wscorer, score);
    }
    return tentative_gScore;
}
