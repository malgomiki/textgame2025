#include "e_acGen.h"
#include <ctime>

rndAircraft eacGen::getRndEAC()
{
    int randIndx = rand() % acType.size();
    std::string eacModel = acType[randIndx]; //gets a random name from the name array
    int eacHealth = 1200 + (rand() % 2001 - 1200 + 1); //assigns a random health value between 1200-2000
    int eac_gDamage = 90 + (rand() % 171 - 90 + 1); //like above but for gun damage values between 90-170
    int eac_mDamage = 200 + (rand() % 351 - 200 + 1); //like above but for missile damage values between 200-350
    return rndAircraft(eacModel, eacHealth, eac_gDamage, eac_mDamage);
}
