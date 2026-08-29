#include <iostream>
#include <map>

class Character {
	private:
		std::string name;
		int age;
		int hp = 100;
		std::string weapon;
		int damage = 5;
		
		int lvl = 1;
		long xp = 50;
	
		std::map<std::string, int> weapons = {
			{ "sword", 25 },
			{ "axe", 35 },
			{ "bow", 20 }
		};
	
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
			if (!weapons[weapon_val]) {
				std::cout << "Unknown weapon, You remain unarmed!" << std::endl;
				return;
			}
			
			weapon = weapon_val;
			damage = weapons[weapon];
			
			std::cout << weapon << " Equiped!" << std::endl;
		
			gainExperience(10);
		}
		
		std::string getWeapon() {
			return weapon;
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
			
			gainExperience(5);
		}
		
		void attack() {
			int damage_dealt = damage;
			
			std::cout << "Blowwww! You attack! Deals " << damage_dealt << "HP damage to your enemy!" << std::endl;
			
			gainExperience(15);
		}
		
		bool isAlive() {
			return hp > 0;
		}
		
		void setXp(int amount) {
			amount = abs(amount);
			
			xp += amount;
		}
		
		int getLevel() {
			return lvl;
		}
		
		void gainExperience(int amount) {
			int old_lvl = lvl;
			
			setXp(amount);
			
			lvl = xp / 50;
			
			std::cout << "+" << amount << "XP gained!" << std::endl;
			
			if (lvl > old_lvl) {
				std::cout << "Leveled up! Your now LEVEL " << lvl << std::endl;
				std::cout << xp << "XP points!" << std::endl;
			}
		}
	
};

int main() {
	Character c1("afk", 139);
	
	c1.equipWeapon("axe");
	c1.showHealth();
	c1.takeDamage(-39);
	c1.showHealth();
	c1.heal(-55);
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.attack();
	c1.showHealth();
	
	if (c1.isAlive()) {
		std::cout << "Bro you is living" << std::endl;
	} else {
		std::cout << "Unlucky mf" << std::endl;
	}
	
	return 0;
}
