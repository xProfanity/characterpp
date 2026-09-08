#pragma once

#include <string>
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
		
		Character(std::string name_val, int age_val);
		
		Character();
		
		~Character();
		
		int abs(int n);
		
		void showHealth() const;
		
		void equipWeapon(std::string weapon_val);
		
		std::string getWeapon();
		
		int getHp();
		
		void setHp(int hp_val);
		
		void takeDamage(int amount);
		
		void heal(int amount);
		
		void attack();
		
		bool isAlive() const;
		
		void setXp(int amount);
		
		int getLevel() const;
		
		void gainExperience(int amount);
	
};
