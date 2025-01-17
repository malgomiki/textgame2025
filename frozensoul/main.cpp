#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include "Windows.h"
#include "e_acGen.h"
#include "e_aircraft.h"

std::string P1name = ""; //your name, set to nothing initially

//defines the fun stuff
void baseInit();
void hangarCheck();
void baseMain();
void engageEAC();
void engageRibbon();
void engageZOEAC();
void endingSeq();

//your health/damage values, defaults to the typhoon's values at beginning
int pacHealth = 1750, pacMaxHP = 1750; //max hp is for when you return to base
int gDamage = 100;
int mDamage = 300;

int downedEAC = 0; //how many of these guys did you blow up

bool ribbonFound = false; //was this specific guy found yet or not
bool pacTyphoon = true; //are you in this bird? (default: true)
bool pacFlankerF = false; //are you in this bird? (default: false)
bool pacFirebird = false; //are you in this bird? (default: false)

int main() {
	std::cout << "A voice rings out from the void. 'You there. State your callsign.'\nYour callsign? - ";
	std::cin >> P1name;
	std::cout << "'" << P1name << ", we'll be needing you to assist with shooting down any enemy aircraft that'll try to weaken our numbers, in addition to being on high alert for the enemy's superweapon.\nRemain on standby until further notice.'" << std::endl;
	std::cout << "You make your way to the one place you know you'll have be on standby for.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
	_getch();
	
	baseInit();

	return 0;
}

void baseInit() {
	system("cls");
	system("color 8F");
	int actTakenInit; //value for action taken
	bool baseLoopInit = false; //while in baseInit, this is false

	std::cout << "'Oh, Captain " << P1name << "! I've been waiting for you. I believe the General's already told you about keeping the enemy at bay and that superweapon they've got, so I won't repeat what he's said.'\n'Though, can I also ask that you try and locate a certain pilot we've lost contact with?'\n'All that I remember is that he had a ribbon emblem on his aircraft's vertical stabilizers.'" << std::endl;
	std::cout << "'But I'm sure you'll manage, right?\nBy the way, call me 'Elanor' if you have to.'\n\n[ - PRESS ENTER TO CONTINUE - ]\n" << std::endl;
	_getch();

	std::cout << "'Anyways, what do you want to do, captain?'\n[1] - Take off for the skies\n[2] - Look at aircraft\n" << std::endl;
	std::cin >> actTakenInit;

	while (baseLoopInit != true) {
		if (actTakenInit == 1) {
			engageEAC();
			baseLoopInit = true;
		}
		else if (actTakenInit == 2) {
			hangarCheck();
			baseLoopInit = true;
		}
		else {
			std::cout << "'Uh, captain... I don't think I understood that.'\n[1] - Take off for the skies\n[2] - Look at aircraft\n" << std::endl;
			std::cin >> actTakenInit;
		}
	}

}

void hangarCheck() { //plane changer
	system("cls");
	system("color 0F");

	int birdSel = 0;
	bool birdTaken = false;

	if (downedEAC == 3) { //if you've got this value (3), this happens
		std::cout << "'You've got access to the Flanker-F, as well as your previous Typhoon. I heard you might get access to a special aircraft if you get 5 or more downed enemy planes.\n'Which aircraft do you want to fly?'\n[1] - Typhoon\n[2] - Flanker-F\n" << std::endl;
		std::cin >> birdSel;

		while (birdTaken != true) {
			if (birdSel == 1 && pacTyphoon == false) {
				pacHealth = 1750, pacMaxHP = 1750, gDamage = 100, mDamage = 300;
				std::cout << "\nYou choose to get into the Typhoon.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
				pacTyphoon = true, pacFlankerF = false;
				birdTaken = true;
				_getch();
				baseMain();
			}
			else if (birdSel == 2 && pacFlankerF == false) {
				pacHealth = 2750, pacMaxHP = 2750, gDamage = 200, mDamage = 400;
				pacFlankerF = true, pacTyphoon = false;
				std::cout << "\nYou choose to get into the Flanker-F.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
				birdTaken = true;
				_getch();
				baseMain();
			}
			else {
				std::cout << "'...Do you want to try that one again?'\n[1] - Typhoon\n[2] - Flanker-F\n" << std::endl;
				std::cin >> birdSel;
			}
		}
	}
	else if (downedEAC >= 5) { //if you've got this value (5) or more, this happens
		std::cout << "'You've got access to the best of the best, the Firebird, as well as the other two aircraft at your disposal.'\n'Which aircraft do you want to fly?'\n[1] - Typhoon\n[2] - Flanker-F\n[3] - Firebird\n" << std::endl;
		std::cin >> birdSel;

		while (birdTaken != true) {
			if (birdSel == 1 && pacTyphoon == false) {
				pacHealth = 1750, pacMaxHP = 1750, gDamage = 100, mDamage = 300;
				std::cout << "\nYou choose to get into the Typhoon.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
				pacTyphoon = true, pacFlankerF = false, pacFirebird = false;
				birdTaken = true;
				_getch();
				baseMain();
			}
			else if (birdSel == 2 && pacFlankerF == false) {
				pacHealth = 2750, pacMaxHP = 2750, gDamage = 200, mDamage = 400;
				pacFlankerF = true, pacTyphoon = false, pacFirebird = false;
				std::cout << "\nYou choose to get into the Flanker-F.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
				birdTaken = true;
				_getch();
				baseMain();
			}
			else if (birdSel == 3 && pacFirebird == false) {
				pacHealth = 3500, pacMaxHP = 3500, gDamage = 250, mDamage = 500;
				pacFirebird = true, pacTyphoon = false, pacFlankerF = false;
				std::cout << "\nYou choose to get into the Firebird.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
				birdTaken = true;
				_getch();
				baseMain();
			}
			else {
				std::cout << "\n'...Do you want to try that one again?'\n[1] - Typhoon\n[2] - Flanker-F\n[3] - Firebird\n" << std::endl;
				std::cin >> birdSel;
			}
		}
	}
	else { //if you didn't have any of those values this happens
		std::cout << "'You've only got access to the Typhoon for now, but if you get 3 or more downed enemy planes, you might get something better." << std::endl;
		std::cout << "You don't have anything else to do here, so you and Elanor turn around to head back to the main base.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
		_getch();
		baseMain();
	}

}

void baseMain() {
	system("cls");
	system("color 8F");
	int actTaken; 
	bool baseLoop = false; //while in baseMain, this is false
	pacHealth = pacMaxHP;

	if (downedEAC >= 5) {
		std::cout << "'You're back, captain!\nThey've spotted the superweapon around a location, so I'd suggest you check the hangar and take off for the location immediately.'" << std::endl;
		std::cout << "'What do you want to do next, now that you're back?\n'Also, you've shot down " << downedEAC << " enemy aircraft so far.'\n[1] - Take off to chase afer the superweapon\n[2] - Take off for the skies once again\n[3] - Look at aircraft\n" << std::endl;
	}
	else {
		std::cout << "'Back at the base again, captain? " << std::endl;
		std::cout << "'What do you want to do next, now that you're back?'\n'Also, you've shot down " << downedEAC << " enemy aircraft so far.'\n[1] - Take off for the skies once again\n[2] - Look at aircraft\n" << std::endl;
	}

	std::cin >> actTaken;

	while (baseLoop != true && downedEAC <= 4) {
		if (actTaken == 1) {
			int ribbonSearch = rand() % 109 + 1;
			if (ribbonSearch >= 90 && ribbonFound != true) {
				engageRibbon();
				baseLoop = true;
			}
			else {
				engageEAC();
				baseLoop = true;
			}
		}
		else if (actTaken == 2) {
			hangarCheck();
			baseLoop = true;
		}
		else {
			std::cout << "\n'Uh, captain... I don't think I understood that.'\n[1] - Take off for the skies\n[2] - Look at aircraft\n" << std::endl;
			std::cin >> actTaken;
		}
	}
	while (baseLoop != true && downedEAC >= 5) {
		if (actTaken == 1) {
			engageZOEAC();
		}
		if (actTaken == 2) {
			int ribbonSearch = rand() % 109 + 1;
			if (ribbonSearch >= 90 && ribbonFound != true) {
				engageRibbon();
				baseLoop = true;
			}
			else {
				engageEAC();
				baseLoop = true;
			}
		}
		else if (actTaken == 3) {
			hangarCheck();
			baseLoop = true;
		}
		else {
			std::cout << "\n'Uh, captain... I don't think I understood that.'\n[1] - Take off to chase afer the superweapon\n[2] - Take off for the skies once again\n[3] - Look at aircraft\n" << std::endl;
			std::cin >> actTaken;
		}
	}
	
}

void engageEAC() {
	srand(static_cast<unsigned int>(time(nullptr)));
	system("cls");
	system("color 3F"); //sets color to light blue with bright white text

	eacGen findEAC; //initialises randomizer

	rndAircraft rndEAC = findEAC.getRndEAC(); //gets a random guy
	std::string tmpEACmodel = rndEAC.getEACName(); //gets name for guy, i might actually be dumb when i forgot strings also needed the std prefix
	int tmpEAChp = rndEAC.getEACHealth(); //health value for the guy
	int tmpEACgdmg = rndEAC.getEAC_gDamage(); //damage value 1 for the guy
	int tmpEACmdmg = rndEAC.getEAC_mDamage(); //damage value 2 for the guy

	int actionEAC; //value for action taken
	int actionATK; //value for enemy action taken
	int EACmiss; //value for if the enemy misses you or not

	std::cout << "You take off for the skies, scavenging for anything flying about alongside Mars Eye." << std::endl;
	Sleep(1500);
	std::cout << "..." << std::endl;
	Sleep(2000);
	std::cout << "Whoa! An enemy " << tmpEACmodel << " began to engage you!\n" << std::endl;
	std::cout << "'" << P1name << ", cleared to engage.'\n" << std::endl;

	std::cout << tmpEACmodel << "\n| " << tmpEACmodel << " Health - " << tmpEAChp << "\n| Your Health - " << pacHealth << std::endl;
	std::cout << "[1] - Shoot gun\n[2] - Fire missile\n" << std::endl;
	std::cin >> actionEAC;

	while (pacHealth > 0 && tmpEAChp > 0) {
		if (actionEAC == 1) {
			std::cout << "You fired off several bullets at the enemy, dealing " << gDamage << " damage in total.\n" << std::endl;
			tmpEAChp -= gDamage;
		}
		else if (actionEAC == 2) {
			std::cout << "'Fox 2, Fox 2!'\nYou fired off a missile at the enemy, dealing " << mDamage << " damage.\n" << std::endl;
			tmpEAChp -= mDamage;
		}
		else { //misinput handler presumably
			std::cout << P1name << ", make your mind up.\n" << std::endl;
		}
		actionATK = rand() % 49 + 1; //should generate a random enemy between 1 and 50
		EACmiss = rand() % 99 + 1; //should generate a random chance for the enemy to miss between 1 and 100 (note: for this it's 2/5 to miss?)
		while (actionEAC != 0 && tmpEAChp > 0) {
			if (actionATK <= 24) { //if enemy gets this value, they go guns blazing on you
				if (EACmiss <= 60) {
					std::cout << "The enemy fires several bullets at you, dealing " << tmpEACgdmg << " damage in total.\n" << std::endl;
					pacHealth -= tmpEACgdmg;
				}
				else if (EACmiss >= 61) { //enemy misses if they get any value that is this or above this value
					std::cout << "The enemy fires several bullets at you, but they completely miss you.\n" << std::endl;
				}
				actionATK = 0; //resets enemy action to "none"
				actionEAC = 0; //resets your action to "none"
			}
			else if (actionATK >= 25) { //if enemy gets this value, missile alert
				if (EACmiss <= 60) {
					std::cout << "The enemy fires a missile at you, dealing " << tmpEACmdmg << " damage.\n" << std::endl;
					pacHealth -= tmpEACmdmg;
				}
				else if (EACmiss >= 61) { //enemy misses if they get any value that is this or above this value
					std::cout << "The enemy fires a missile at you, but you manage to shake it off.\n" << std::endl;
				}
				actionATK = 0;
				actionEAC = 0;
			}
		}
		std::cout << tmpEACmodel << "\n| " << tmpEACmodel << " Health - " << tmpEAChp << "\n| Your Health - " << pacHealth << std::endl;
		std::cout << "[1] - Shoot gun\n[2] - Fire missile\n" << std::endl;
		std::cin >> actionEAC;
	}

	if (tmpEAChp <= 0) {
		std::cout << "'" << P1name << "'s shot down a bandit, nice work!'\nYou head back to base, awaiting what to do next." << std::endl;
		downedEAC += 1;
		_getch();
		baseMain();
	}
	else if (pacHealth <= 0) {
		std::cout << "'" << P1name << "'s been shot down!!' Mars Eye cries out, seeing your aircraft drop out of the sky.\nYou eject from your aircraft in a frenzy, but at what cost?\n\n[ GAME OVER - Got shot down ]\n\n[ - PRESS ENTER TO EXIT - ]" << std::endl;
		_getch();
		exit(0);
	}
}

void engageRibbon() {
	system("cls");
	system("color 3F");

	std::cout << "You take off for the skies, scavenging for anything flying about alongside Mars Eye." << std::endl;
	Sleep(1500);
	std::cout << "..." << std::endl;
	Sleep(2000);
	std::cout << "Whoa! A Berkut began to engage you!\n\n| Berkut Health - 4000 \n| Your Health - " << pacHealth << "\n\n[1] - Shoot gun... ? \n[2] - Fire missile... ? " << std::endl;
	_getch();
	std::cout << "'DO NOT ENGAGE! I REPEAT, DO NOT ENGAGE!'  Mars Eye's voice rings out, which was picked up by your radio. Was it meant for the other pilot?\nHold on... You spot a ribbon insignia on the Berkut's vertical stabilizers. It's the pilot that - back at the base was talking about!\n" << std::endl;
	
	std::cout << "After some time, you fly back to base with the other pilot in tow.\n\n[ - PRESS ENTER TO CONTINUE - ]" << std::endl;
	ribbonFound = true;
	_getch();

	baseMain();
}

void engageZOEAC() {
	srand(static_cast<unsigned int>(time(nullptr))); 
	system("cls");
	system("color 4F");
	
	std::cout << "You take off for the skies, flying towards the area the superweapon was last located at, alongside Mars Eye." << std::endl;
	Sleep(1500);
	std::cout << "..." << std::endl;
	Sleep(2000);
	std::cout << "..." << std::endl;
	Sleep(2000);
	std::cout << "There it is! The enemy's superweapon!\n" << std::endl;
	std::cout << "'That's the enemy superweapon, SOKOL! " << P1name << ", cleared to destroy the superweapon!'\n" << std::endl;

	int healthZOEAC = 4500;
	int lDamageZOEAC = 400;
	int mDamageZOEAC = 500;

	int actionZOEAC;
	int ZOEACatk;
	int ZOEACmiss; 

	std::cout << "ADF-13 SOKOL\n | SOKOL Health - " << healthZOEAC << "\n | Your Health - " << pacHealth << std::endl;
	std::cout << "[1] - Shoot gun\n[2] - Fire missile\n" << std::endl;
	std::cin >> actionZOEAC;

	while (pacHealth > 0 && healthZOEAC > 0) {
		if (actionZOEAC == 1) {
			std::cout << "You fired off several bullets at the enemy, dealing " << gDamage << " damage in total.\n" << std::endl;
			healthZOEAC -= gDamage;
		}
		else if (actionZOEAC == 2) {
			std::cout << "'Fox 2, Fox 2!'\nYou fired off a missile at the enemy, dealing " << mDamage << " damage.\n" << std::endl;
			healthZOEAC -= mDamage;
		}
		else { //misinput handler presumably
			std::cout << P1name << ", make your mind up.\n" << std::endl;
		}
		ZOEACatk = rand() % 49 + 1; //should generate a random enemy between 1 and 50
		ZOEACmiss = rand() % 99 + 1; //should generate a random chance for the enemy to miss between 1 and 100 (80/100 for sokol)
		while (actionZOEAC != 0 && healthZOEAC > 0) {
			if (ZOEACatk <= 24) { //if enemy gets this value, they go guns blazing on you
				if (ZOEACmiss <= 70) {
					std::cout << "The SOKOL fires a laser beam towards your aircraft, dealing " << lDamageZOEAC << " damage.\n" << std::endl;
					pacHealth -= lDamageZOEAC;
				}
				else if (ZOEACmiss >= 71) { //enemy misses if they get any value that is this or above this value
					std::cout << "The SOKOL fires a laser beam towards your aircraft, but it somehow misses the mark.\n" << std::endl;
				}
				ZOEACatk = 0; //resets enemy action to "none"
				actionZOEAC = 0; //resets your action to "none"
			}
			else if (ZOEACatk >= 25) { //if enemy gets this value, missile alert
				if (ZOEACmiss <= 71) {
					std::cout << "The SOKOL fires a missile at you, dealing " << mDamageZOEAC << " damage.\n" << std::endl;
					pacHealth -= mDamageZOEAC;
				}
				else if (ZOEACmiss >= 71) { //enemy misses if they get any value that is this or above this value
					std::cout << "The SOKOL fires a missile at you, but you manage to shake it off.\n" << std::endl;
				}
				ZOEACatk = 0;
				actionZOEAC = 0;
			}
		}
		std::cout << "ADF-13X SOKOL\n| SOKOL Health - " << healthZOEAC << "\n| Your Health - " << pacHealth << std::endl;
		std::cout << "[1] - Shoot gun\n[2] - Fire missile\n" << std::endl;
		std::cin >> actionZOEAC;
	}
	
	if (healthZOEAC <= 0) {
		std::cout << "'" << P1name << "' shot down the superweapon!! They've done it, they've done it!!'\nYou fly about in a holding pattern as you watch the SOKOL become engulfed in flames, exploding into a fireball rivalling that of a firework display.\nYou feel a little proud.\n" << std::endl;
		std::cout << "'" << P1name << ", return to base, everyone's gonna treat you like a king for this!'\nYou fly back to base, where everyone else's anticipating your arrival back.\n" << std::endl;
		_getch();
		endingSeq();
	}
	else if (pacHealth <= 0) {
		std::cout << "'The SOKOL's shot " << P1name << "'s aircraft down!!'  Mars Eye cries out hopelessly, seeing your aircraft drop out of the sky.\nWithout even a chance to eject, your aircraft explodes into a raging fireball, taking you down with it.\n\n[ GAME OVER - SOKOL shot you down ]\n\n[ - PRESS ENTER TO EXIT - ]" << std::endl;
		_getch();
		exit(0);
	}
}

void endingSeq() {

	if (ribbonFound == true) {
		std::cout << "Once back at base, the pilot of the ribbon-clad aircraft you'd managed to locate earlier walks up to you.\nDespite him towering over you, he pets your head in a way to say 'congratulations'.\n...Feels nice to be recognised by an ace pilot like him.\n" << std::endl;
		std::cout << "[ GAME END - Shot down the SOKOL and found the ribbon fighter ]\n[ - PRESS ENTER TO EXIT - ]" << std::endl;
		_getch();
		exit(0);
	}
	else {
		std::cout << "[ GAME END - Shot down the SOKOL ]\n[ - PRESS ENTER TO EXIT - ]" << std::endl;
		_getch();
		exit(0);
	}
}