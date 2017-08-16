#ifndef HEURISTIC_H_
#define HEURISTIC_H_

#include <vector>
#include "hybrid_breadth_first.h"

class Heuristic
{
public:
  Heuristic(const HBF::maze_s& state, const vector<int>& goal)
    : state(state),
      goal(goal),
      distance(0)
  {
    distance = calc_distance(state, goal);
  }

  const HBF::maze_s& get_state() const
  {
    return state;
  }

  bool operator<(const Heuristic& other) const
  {
    // priority_queue prioritizes the largest value, but our search should prioritize nodes with the smallest value, so flip the comparison.
    return (heuristic() > other.heuristic());
  }

private:
  static double calc_distance(const HBF::maze_s& state, const vector<int>& goal)
  {
    double xd = state.x - goal[0];
    double yd = state.y - goal[1];
    return sqrt(xd * xd + yd * yd);
  }

  double get_distance() const
  {
    return distance;
  }

  double heuristic() const
  {
    return get_distance();
  }

  HBF::maze_s state;
  vector<int> goal;

  double distance;
};

#endif
