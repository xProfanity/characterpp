#include "Character.hpp"

#include <iostream>
#include <string>

Character::Character(std::string name_val, int age_val) : name(name_val), age(age_val) {
	std::cout << name << " aged " << age << " spawned!" << std::endl;
}
		
Character::Character() {
	name = "Traveller";
	age = 0;
}

Character::~Character() {
	std::cout << "Character suddenly exploded and died! Haha fucking crazy!" << std::endl;
}

int Character::abs(int n) {
	if (n < 0) return n * -1;
	
	return n;
}

void Character::showHealth() const {
	std::cout << name << ": ";
	std::cout << hp << "HP" << std::endl;
}

void Character::equipWeapon(std::string weapon_val) {
	if (!weapons[weapon_val]) {
		std::cout << "Unknown weapon, You remain unarmed!" << std::endl;
		return;
	}
	
	weapon = weapon_val;
	damage = weapons[weapon];
	
	std::cout << weapon << " Equiped!" << std::endl;

	gainExperience(10);
}

std::string Character::getWeapon() {
	return weapon;
}

int Character::getHp() {
	return hp;
}

void Character::setHp(int hp_val) {
	if (hp_val > 100) {
		hp = 100;
		return;
	} else if (hp_val < 0) {
		hp = 0;
		return;
	}
	
	hp = hp_val;
}

void Character::takeDamage(int amount) {
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

void Character::heal(int amount) {
	amount = abs(amount);
	
	setHp(hp + amount);
	
	std::cout << name << " took a healing potion! +" << amount << "HP" << std::endl;
	
	gainExperience(5);
}

void Character::attack() {
	int damage_dealt = damage;
	
	std::cout << "Blowwww! You attack! Deals " << damage_dealt << "HP damage to your enemy!" << std::endl;
	
	gainExperience(15);
}

bool Character::isAlive() const {
	return hp > 0;
}

void Character::setXp(int amount) {
	amount = abs(amount);
	
	xp += amount;
}

int Character::getLevel() const {
	return lvl;
}

void Character::gainExperience(int amount) {
	int old_lvl = lvl;
	
	setXp(amount);
	
	lvl = xp / 50;
	
	std::cout << "+" << amount << "XP gained!" << std::endl;
	
	if (lvl > old_lvl) {
		std::cout << "Leveled up! Your now LEVEL " << lvl << std::endl;
		std::cout << xp << "XP points!" << std::endl;
	}
}
