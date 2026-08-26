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
		
		int abs(int n) {
			if (n < 0) return n * -1;
			
			return n;
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
		
		void setHp(int hp_val) {
			if (hp_val > 100) {
				hp = 100;
				return;
			} else if (hp_val < 0) {
				hp = 0;
				return;
			}
			
			hp = hp_val;
		}
		
		void takeDamage(int amount) {
			amount = abs(amount);
			
			if (amount > hp) {
				setHp(hp - amount);
				
				std::cout << name << " died! :(" << std::endl;
				return;
			}
			
			setHp(hp - amount);
			
			std::cout << name << " took " << "damage! -" << amount << "HP" << std::endl;
			std::cout << name << " now have " << hp << " HP left" << std::endl; 
		}
		
		void heal(int amount) {
			amount = abs(amount);
			
			setHp(hp + amount);
			
			std::cout << name << " took a healing potion! +" << amount << "HP" << std::endl;
		}
	
};

int main() {
	Character c1("afk", 139);
	
	c1.equipWeapon("A Cool Stick");
	c1.showHealth();
	c1.takeDamage(-39);
	c1.showHealth();
	c1.heal(-55);
	c1.showHealth();
	
	return 0;
}
