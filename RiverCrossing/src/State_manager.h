#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include <iostream>
#include <set>
#include <vector>
#include "State.h"
using namespace std;

//object comparator for comparing two State pointers
struct State_comparator {
	bool operator()(const StatePtr s1, const StatePtr s2) {
		return s1->get_a_star_value() <= s2->get_a_star_value();
	}
};

class State_manager {

private:
	//set of nodes that have not yet been explored (no next states have been generated therefrom)
	set<StatePtr, State_comparator> leaf_nodes;
	//vector of nodes that have been explored (next states have been generated therefrom)
	vector<StatePtr> parent_nodes;

	//represents the initial state -- all elements on the left side
	StatePtr HEAD;
	//represents the current state under exploration
	StatePtr CURRENT;

public:

	//constructor
	State_manager();
	//destructor
	~State_manager();

	//generates solution to the river crossing problem using the A* search algorithm
	void path_generator();
	//returns estimate cost of going from the specified state to the goal state
	int heuristic(StatePtr next_state);
	//returns the actual cost (number of trips) of going from the initial state to the specified state
	int actual_cost(StatePtr next_state);
	//checks if all the elements are on the right bank for the specified state, i.e., the goal state is reached
	bool goal_checker(StatePtr next_state);
	//prints solution to the river crossing problem as a series of successive states in the optimal path from the initial to the goal state
	void solution_printer();

};

#endif
