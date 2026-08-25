#include <iostream>

class Character {
	public:
		std::string name;
		int age;
		
	Character(std::string name_val, int age_val) : name(name_val), age(age_val) {
		
		std::cout << "Hi " << name << " aged " << age << "!" << std::endl;
	}
	
	Character() {
		name = "Traveller";
		age = 0;
		
		std::cout << "Hello " << name << "!" << std::endl;
	}
	
};

int main() {
	Character c1("afk", 139);
	Character c2("profanity", 679);
	
	return 0;
}
