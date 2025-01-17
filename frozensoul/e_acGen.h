#pragma once
#include <vector>
#include "e_aircraft.h"

class eacGen {
public:
	rndAircraft getRndEAC(); //gets a random aircraft for the enemy fighter

private:
	std::vector<std::string> acType = { "Nosferatu", "Darkstar", "Fulcrum", "Flanker-S" }; //names for whatever aircraft they can have
};