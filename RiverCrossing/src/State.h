#ifndef STATE_H_
#define STATE_H_

#include <iostream>
using namespace std;

class State {
private:

	//state variables
	int farmer;
	int goat;
	int tiger;
	int plant;
	int g_value; //value to store the cost of going from the initial state to this specific state -- g(n)
	int h_value; //value to store the number of elements remaining to go to the right side -- h(n)
	int a_star_value; //value to store the sum of g(n) and h(n)
	State* previous; //data member that connects current movement state to the previous movement state

public:

	//constructor
	State();
	//parameterised constructor
	State(int farmer, int goat, int tiger, int plant);
	//destructor
	~State();

	//movement functions
	State* farmer_left();
	State* farmer_right();
	State* farmer_plant_left();
	State* farmer_plant_right();
	State* farmer_goat_left();
	State* farmer_goat_right();
	State* farmer_tiger_left();
	State* farmer_tiger_right();

	//validator function
	static bool state_validator(State* next_state);

	//overloaded operators
	bool operator==(const State another_state) const;
	friend ostream& operator<<(ostream& os, State& state);

	//accessor and mutator methods
	int get_a_star_value() const;
	void set_a_star_value(int starValue);
	int get_farmer() const;
	void set_farmer(int farmer);
	int get_g_value() const;
	void set_g_value(int value);
	int get_goat() const;
	void set_goat(int goat);
	int get_h_value() const;
	void set_h_value(int value);
	int get_plant() const;
	void set_plant(int plant);
	State* get_previous() const;
	void set_previous(State* previous);
	int get_tiger() const;
	void set_tiger(int tiger);
};

typedef State* StatePtr;

#endif
