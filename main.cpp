#include <iostream>

class Character {
	private:
		std::string name;
		int age;
		int hp = 100;
		std::string weapon;
	
	public:
		
		Character(std::string name_val, int age_val) : name(name_val), age(age_val) {
			std::cout << name << " aged " << age << " spawned!" << std::endl;
		}
		
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
		
		int getHp() {
			return hp;
		}
		
		int setHp(int hp_val) {
			hp = hp_val;
		}
		
		void takeDamage(int amount) {
			if (amount > hp) {
				setHp(0);
				
				std::cout << name << " died! :(" << std::endl;
				return;
			}
			
			hp -= amount;
			
			std::cout << name << " took " << amount << " of HP damage!" << std::endl;
			std::cout << name << " now have " << hp << " HP left" << std::endl; 
		}
	
};

int main() {
	Character c1("afk", 139);
	
	c1.equipWeapon("A Cool Stick");
	c1.showHealth();
	c1.takeDamage(39);
	c1.showHealth();
	
	return 0;
}
