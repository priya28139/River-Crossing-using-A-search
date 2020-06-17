#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "State_manager.h"

using namespace std;

// constructor
State_manager::State_manager() {
	HEAD = new State();
	CURRENT = HEAD;
}

//destructor to destroy the memory contained in the set and the vector
State_manager::~State_manager() {
	while (!leaf_nodes.empty()) {
		delete *leaf_nodes.begin();
		leaf_nodes.erase(leaf_nodes.begin());
	}

	while (!parent_nodes.empty()) {
		delete *parent_nodes.begin();
		parent_nodes.erase(parent_nodes.begin());
	}

}

//function to generate the optimal path from the initial to the goal state using the A* search algorithm
void State_manager::path_generator() {
	//keep looping until the goal state is reached
	while (!goal_checker(CURRENT)) {
		//for each current state all possible next movements are made
		vector<StatePtr> temp_container;
		temp_container.push_back(CURRENT->farmer_goat_left());
		temp_container.push_back(CURRENT->farmer_goat_right());
		temp_container.push_back(CURRENT->farmer_left());
		temp_container.push_back(CURRENT->farmer_plant_left());
		temp_container.push_back(CURRENT->farmer_plant_right());
		temp_container.push_back(CURRENT->farmer_right());
		temp_container.push_back(CURRENT->farmer_tiger_left());
		temp_container.push_back(CURRENT->farmer_tiger_right());

		//from the valid states that result from the movements, the a_star_value is generated for each
		for (auto temp : temp_container) {
			if (temp != nullptr) {
				temp->set_g_value(actual_cost(temp)); // g(n)
				temp->set_h_value(heuristic(temp)); // h(n)
				temp->set_a_star_value(
						temp->get_g_value() + temp->get_h_value()); // g(n) + h(n)
				leaf_nodes.insert(temp);
			}
		}

		CURRENT = *(leaf_nodes.begin()); //the next state to be explored is the first one in the leaf_nodes set -- minimal a_star_value
		leaf_nodes.erase(leaf_nodes.begin()); //this node is removed from the leaf_nodes set, as it will now be explored further
		parent_nodes.push_back(CURRENT); // this state then become a parent node as it will be explored next
	}

	// prints the solution as a series of successive states in the optimal path from the initial state to the goal state
	solution_printer();
}

//function to calculate the number of elements remaining to reach the right side -- h(n)
int State_manager::heuristic(StatePtr next_state) {
	int heuristic_value = 0;

	// h(n) is incremented for every element present on the left side of the bank
	if (next_state->get_farmer() == 1) {
		heuristic_value++;
	}
	if (next_state->get_goat() == 1) {
		heuristic_value++;
	}
	if (next_state->get_tiger() == 1) {
		heuristic_value++;
	}
	if (next_state->get_plant() == 1) {
		heuristic_value++;
	}

	return heuristic_value;
}

//returns number of trips to be made from the start state to reach this state -- g(n)
int State_manager::actual_cost(StatePtr next_state) {
	return next_state->get_previous()->get_g_value() + 1;
}

//checks if all the elements have reached the right side
bool State_manager::goal_checker(StatePtr next_state) {
	return next_state->get_farmer() == 0 && next_state->get_goat() == 0
			&& next_state->get_tiger() == 0 && next_state->get_plant() == 0;
}

//prints the solution to the river-crossing problem -- series of states in the optimal path from the initial to the goal state
void State_manager::solution_printer() {
	cout
			<< "The following represent successive states for the optimal way to solve the river crossing puzzle* >> "
			<< endl << endl;
	deque<StatePtr> solution;
	while (CURRENT != nullptr) {
		solution.push_front(CURRENT);
		CURRENT = CURRENT->get_previous();
	}

	for (auto s : solution) {
		cout << (*s) << endl;
	}

	cout
			<< "\n\n*Symbols have meaning as indicated here >>\nF-Farmer\nG-Goat\nT-Tiger\nP-Plant\n||-River"
			<< endl;

	for (auto s : solution) {
		delete s;
	}
	solution.clear();
}

