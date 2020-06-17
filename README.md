# River-Crossing-using-A-search

As the traditional river crossing problem goes, there is a farmer and he has a tiger, a goat and a plant. He is standing on one side of the river with a very weak boat that can hold only of his belongings at a time. The farmer wants to take all three of his possessions to the other side of the river using the boat. He can make as many trips he likes across the river but cannot ever leave the tiger with the goat, or the goat with the plant unattended, as one will eat the other. Your task is to help the farmer find out a series of moves to perform to get his belongings to the other side of the river in the minimum number of trips possible.


The project models the river crossing problem as a search problem and then uses the famed A* search to identify the successive states in an optimal path from the initial state (farmer and all his belongings on one side of the river) to the goal state (farmer and all his belongings on the other side of the river).


Each state has certain properties - positions of the plant, farmer, goat and tiger, a pointer to the predecessor state, values of the cost - g(n), and heuristic - h(n) functions, and the A* value of the state. There is a StateManager that leverages the State instances to generate a state space tree of all valid states, which it then explores using the A* algorithm to identify an optimal solution to the problem.


The key contents of this repository are:
1. State.h: Header file that models the problem as a series of states 
2. State.cpp: C++ Source code file that implements constructors and functions per the headers defined in the State.h header file
3. StateManager.h: Header file that leverages abstraction and functionality offered by the State class in generating a state space tree for the problem to be later explored using the A* search algorithm for finding an optimal solution
4. StateManger.cpp: C++ Source code file that implements constructors and functions per the headers defined in the StateManager.h header file
5. RiverCrossing.cpp: The client C++ Source code file containing the main() function - it creates an instance of the StateManager class and invokes relevant functionality to solve the river crossing problem
