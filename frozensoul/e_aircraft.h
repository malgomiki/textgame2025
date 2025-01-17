#pragma once
#include <iostream>
#include <string>
#include <vector>

class rndAircraft {
public:
	//defines value for enemy aircraft
	int eacHealth, eac_gDamage, eac_mDamage;
	rndAircraft(const std::string& eacModel, int eacHealth, int eac_gDamage, int eac_mDamage);

	std::string getEACName() const;
	int getEACHealth() const;
	int getEAC_gDamage() const;
	int getEAC_mDamage() const;

private:
	std::string eacModel;
	//initialises the fun stuff
};