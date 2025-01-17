to compile the game, use visual studio with c++ which should open up a window to let you play the game
for those without visual studio/don't want to bother with the hassle: open the "x64" folder, then open "Release", inside should be an .exe file that should run the game

--

flight shooting text game except there's this weird bird that needs to be shot down
shoot down a specific number of enemy aircraft to get access to 2 other planes and the chance to shoot said weird bird down

only need to enter in a "callsign" of sorts (can be anything) at the beginning of the game, other than that you're free to do anything

what ending you get depends on the following:
	- did you get shot down?
	- did you shoot that weird bird down?
	- did you do the above but also found that other fighter pilot?

--

arrays used for names of enemy aircraft, and a randomizer for any stats it might have (for health, gun damage [gDamage] and missile damage [mDamage])
a seperate randomizer was also used to determine if you'll encounter a certain fighter pilot the person at the beginning of the game mentions once and never again or not

also bool statements were used to determine what aircraft you're in (as inconvenient as that is...)
and ints for all the fun stuff you have (health + max health, gun damage, missile damage)