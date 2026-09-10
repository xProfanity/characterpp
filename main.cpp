#include "Character.hpp"

int main() {
	Character protagonist("profanity", 209);
	Character enemy("boots", 916);
	
	enemy.equipWeapon("axe");
	protagonist.equipWeapon("sword");
	
	enemy.attack(protagonist);
	
	
	protagonist.showHealth();
}
