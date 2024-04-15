#include <iostream>

class Building {
private:
    int id;
    int maxAge;
    int initialCost;
    int currentCost;

    // Private function for destroing the building
    void Destroy() {
        std::cout << "Building with id " << id << " has been destroyed." << std::endl;
    }

public:
    // Constructor
    Building(int id, int maxAge, int initialCost) : id(id), maxAge(maxAge), initialCost(initialCost), currentCost(initialCost) {}

    // Function to get the current cost of the building
    int GetCost() {
        return currentCost;
    }

    // Function for aging the building
    void ToAge(int years) {
        if (years >= maxAge) {
            Destroy();
            currentCost = 0;
        }
        else {
            currentCost = initialCost - initialCost * years / (2 * maxAge);
        }
    }
};

int main() {
    // Building class using example
    Building building1(1, 50, 10000); // Building with id 1, maximum age 50 years, initial cost $10,000

    std::cout << "Initial cost of building: $" << building1.GetCost() << std::endl;

    building1.ToAge(10); // Age the building by 10 years
    std::cout << "Cost of building after 10 years: $" << building1.GetCost() << std::endl;

    building1.ToAge(60); // Age the building by 60 years (more than max age)
    std::cout << "Cost of building after 60 years: $" << building1.GetCost() << std::endl;

    return 0;
}
