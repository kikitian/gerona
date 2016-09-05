#ifndef LOCAL_PLANNER_ASTAR_H
#define LOCAL_PLANNER_ASTAR_H

/// PROJECT
#include <path_follower/local_planner/local_planner_star.h>

class LocalPlannerAStar : virtual public LocalPlannerStar
{
public:
    LocalPlannerAStar(PathFollower& controller, tf::Transformer &transformer,
                      const ros::Duration& update_interval);
private:
    virtual double G(HNode*& current, std::size_t& index, std::vector<HNode*>& successors,
             const std::vector<Scorer::Ptr>& scorer, const std::vector<double>& wscorer,
             double& score) override;
};

#endif // LOCAL_PLANNER_ASTAR_H
