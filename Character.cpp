#include "Character.hpp"

#include <iostream>
#include <string>

Character::Character(std::string name_val, int age_val) : name(name_val), age(age_val) {
	std::cout << name << " aged " << age << " spawned!" << std::endl;
}

Character::Character(std::string name_val) : name(name_val) {
	age = 100;
	std::cout << name << " aged " << age << " spawned!" << std::endl;
}

Character::Character() {
	name = "NPC";
	age = 0;
	
	std::cout << "Bronem a npc!" << std::endl;
}

Character::Character(const Character& character) {
	name = character.name + " clone";
	age = character.age;
	weapon = character.weapon;
	
	std::cout << character.name << ": " << "Shadow clone jutsu! @*@**" << std::endl;
}

Character::~Character() {
	std::cout << name << ": " << "Character suddenly exploded and died! Haha fucking crazy!" << std::endl;
}

void Character::addItem(std::string item) {
    inventory.push_back(item);
}

void Character::removeItem(std::string item) {
    inventory.pop_back();
}

void Character::showInventory() {

    std::cout << name << " inventory" << std::endl;

    std::cout << "[ ";

    for(std::string item : inventory) {
        std::cout << item << ",";
    }

    std::cout << " ]" << std::endl;
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
		std::cout << name << ": " << "Unknown weapon, You remain unarmed!" << std::endl;
		return;
	}
	
	weapon = weapon_val;
	damage = weapons[weapon];
	
	std::cout << name << ": " << weapon << " Equiped!" << std::endl;

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

void Character::attack(Character& character) {
	int damage_dealt = damage;
	
	std::cout << "Blowwww! " << name << " attacks " << character.getName() <<  " Deals " << damage_dealt << "HP damage to the enemy!" << std::endl;
	
	character.takeDamage(damage_dealt);
	
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
	
	std::cout << name << ": " << "+" << amount << "XP gained!" << std::endl;
	
	if (lvl > old_lvl) {
		std::cout << name << ": " << "Leveled up! Your now LEVEL " << lvl << std::endl;
		std::cout << name << ": " << xp << "XP points!" << std::endl;
	}
}
