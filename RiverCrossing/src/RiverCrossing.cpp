#include <iostream>
#include "State_manager.h"
#include "State.h"
using namespace std;

int main() {
	// create object of State_manager that contains a head - initial state
	State_manager s;
	// apply the A* search Algorithm on the initial state to generate actions to reach the goal state
	s.path_generator();
	return 0;
}
