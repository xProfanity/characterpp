#include "Character.hpp"

int main() {
	Character protagonist("profanity", 209);
	Character enemy("boots", 916);

	Character npc;
	
	enemy.equipWeapon("axe");
	protagonist.equipWeapon("sword");
	
	enemy.attack(protagonist);
	
	Character clone(protagonist);

    clone.addItem("dildo");
    clone.addItem("basketball");
    clone.addItem("healing potion");

    clone.showInventory();
	
	protagonist.showHealth();
}
