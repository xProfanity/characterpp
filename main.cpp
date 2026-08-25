#include <iostream>

class Character {
	private:
		std::string name;
		int age;
		int hp = 100;
		std::string weapon;
	
	public:
		
		Character(std::string name_val, int age_val) : name(name_val), age(age_val) {}
		
		Character() {
			name = "Traveller";
			age = 0;
		}
		
		void showHealth() {
			std::cout << name << ": ";
			std::cout << hp << "HP" << std::endl;
		}
		
		void equipWeapon(std::string weapon_val) {
			weapon = weapon_val;
			
			std::cout << weapon << " Equiped!" << std::endl;
		}
	
};

int main() {
	Character c1("afk", 139);
	Character c2;
	
	c2.showHealth();
	c2.equipWeapon("A Cool Stick that look like a gun nobody knows what it does");
	
	return 0;
}
