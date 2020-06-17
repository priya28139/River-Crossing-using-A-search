#include <iostream>
#include <vector>
#include "State.h"

using namespace std;

// constructor
State::State() {
	farmer = 1;
	goat = 1;
	tiger = 1;
	plant = 1;
	g_value = 0;
	h_value = 4;
	a_star_value = g_value + h_value;
	previous = nullptr;
}

// parameterised constructor
State::State(int farmer, int goat, int tiger, int plant) {
	this->farmer = farmer;
	this->goat = goat;
	this->tiger = tiger;
	this->plant = plant;
	this->a_star_value = 0;
	this->g_value = 0;
	this->h_value = 0;
	this->previous = nullptr;
}

// destructor
State::~State() {
}

//movement functions
StatePtr State::farmer_left() {
	if (farmer == 1) //if farmer is already on left side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(1, this->goat, this->tiger, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_right() {
	if (farmer == 0) //if farmer is already on right side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(0, this->goat, this->tiger, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_plant_left() {
	if (farmer == 1 || plant == 1) //if farmer or plant or both are already on left side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(1, this->goat, this->tiger, 1); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_plant_right() {
	if (farmer == 0 || plant == 0) //if farmer or plant or both are already on right side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(0, this->goat, this->tiger, 0); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_goat_left() {
	if (farmer == 1 || goat == 1) //if farmer or goat or both are already on left side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(1, 1, this->tiger, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_goat_right() {
	if (farmer == 0 || goat == 0) //if farmer or goat or both are already on right side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(0, 0, this->tiger, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_tiger_left() {
	if (farmer == 1 || tiger == 1) //if farmer or tiger or both are already on left side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(1, this->goat, 1, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

StatePtr State::farmer_tiger_right() {
	if (farmer == 0 || tiger == 0) //if farmer or tiger or both are already on right side then return next state as NULL
			{
		return nullptr;
	}

	StatePtr next_state = new State(0, this->goat, 0, this->plant); //creating a new state based on the movement function
	if (state_validator(next_state)) //if this state is valid then DO the movement
			{
		next_state->previous = this;
		return next_state;
	} else // if not then return next state as NULL
	{
		delete next_state;
		return nullptr;
	}
}

// function to check the validity of a particular state
bool State::state_validator(StatePtr next_state) {
	// if goat and tiger on left bank together and farmer on right bank
	if (next_state->farmer == 0 && next_state->plant == 0
			&& next_state->goat == 1 && next_state->tiger == 1)
		return false;
	// if goat and tiger on right bank together and farmer on left bank
	if (next_state->farmer == 1 && next_state->plant == 1
			&& next_state->goat == 0 && next_state->tiger == 0)
		return false;
	// if goat and plant on left bank together and farmer on right bank
	if (next_state->farmer == 0 && next_state->plant == 1
			&& next_state->goat == 1 && next_state->tiger == 0)
		return false;
	// if goat and tiger on right bank together and farmer on left bank
	if (next_state->farmer == 1 && next_state->plant == 0
			&& next_state->goat == 0 && next_state->tiger == 1)
		return false;
	// if goat, tiger and plant together on left bank and farmer on right bank
	if (next_state->farmer == 1 && next_state->plant == 0
			&& next_state->goat == 0 && next_state->tiger == 0)
		return false;
	// if goat, tiger and plant together on right bank and farmer on left bank
	if (next_state->farmer == 0 && next_state->plant == 1
			&& next_state->goat == 1 && next_state->tiger == 1)
		return false;

	return true;
}

// operator function for checking state equality
bool State::operator==(const State another_state) const {
	return this->farmer == another_state.farmer
			&& this->goat == another_state.goat
			&& this->tiger == another_state.tiger
			&& this->plant == another_state.plant;
}

// accessor and mutator methods for the class' instance variables
int State::get_a_star_value() const {
	return a_star_value;
}

void State::set_a_star_value(int a_star_value) {
	this->a_star_value = a_star_value;
}

int State::get_farmer() const {
	return farmer;
}

void State::set_farmer(int farmer) {
	this->farmer = farmer;
}

int State::get_g_value() const {
	return g_value;
}

void State::set_g_value(int value) {
	g_value = value;
}

int State::get_goat() const {
	return goat;
}

void State::set_goat(int goat) {
	this->goat = goat;
}

int State::get_h_value() const {
	return h_value;
}

void State::set_h_value(int value) {
	h_value = value;
}

int State::get_plant() const {
	return plant;
}

void State::set_plant(int plant) {
	this->plant = plant;
}

State* State::get_previous() const {
	return previous;
}

void State::set_previous(State* previous) {
	this->previous = previous;
}

int State::get_tiger() const {
	return tiger;
}

void State::set_tiger(int tiger) {
	this->tiger = tiger;
}

// overloaded << operator function for printing the states as output
ostream& operator<<(ostream& os, State& state) {
	vector<char> left;
	vector<char> right;

	if (state.farmer == 1) {
		left.push_back('F');
	} else {
		right.push_back('F');
	}

	if (state.goat == 1) {
		left.push_back('G');
	} else {
		right.push_back('G');
	}

	if (state.plant == 1) {
		left.push_back('P');
	} else {
		right.push_back('P');
	}

	if (state.tiger == 1) {
		left.push_back('T');
	} else {
		right.push_back('T');
	}

	for (auto l : left) {
		os << l << flush;
	}

	cout << " || " << flush;
	for (auto r : right) {
		os << r << flush;
	}

	return os;
}
