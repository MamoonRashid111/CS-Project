#include <iostream>
#include <string>

class Pet {
public:
    Pet(const std::string& name) : name(name), hunger(50) {}

    void feed(int amount) {
        hunger += amount;
        if (hunger > 100) {
            hunger = 100;
        }
        std::cout << "You fed " << name << ". Hunger level is now " << hunger << "." << std::endl;
    }

    void play(int duration) {
        hunger -= duration;
        if (hunger < 0) {
            hunger = 0;
        }
        std::cout << "You played with " << name << ". Hunger level is now " << hunger << "." << std::endl;
    }

private:
    std::string name;
    int hunger;
};

int main() {
    std::string petName;
    std::cout << "Enter your pet's name: ";
    std::cin >> petName;

    Pet myPet(petName);

    int choice;
    int value;

    while (true) {
        std::cout << "Choose an action (1: Feed, 2: Play, 3: Quit): ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter the amount of food: ";
            std::cin >> value;
            myPet.feed(value);
        } else if (choice == 2) {
            std::cout << "Enter the duration of playtime: ";
            std::cin >> value;
            myPet.play(value);
        } else if (choice == 3) {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}