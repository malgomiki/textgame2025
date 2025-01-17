#include "e_aircraft.h"

rndAircraft::rndAircraft(const std::string& eacModel, int eacHealth, int eac_gDamage, int eac_mDamage)//initialises enemy aircraft
	: eacModel(eacModel), eacHealth(eacHealth), eac_gDamage(eac_gDamage), eac_mDamage(eac_mDamage) {}

//function for getting enemy aircraft name
std::string rndAircraft::getEACName() const
{
	return eacModel;
}

//for getting enemy health
int rndAircraft::getEACHealth() const
{
	return eacHealth;
}

//for getting enemy gun damage
int rndAircraft::getEAC_gDamage() const
{
	return eac_gDamage;
}

//for getting enemy missile damage
int rndAircraft::getEAC_mDamage() const
{
	return eac_mDamage;
}