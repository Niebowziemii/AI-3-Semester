#include <iostream>
#include <string>
#include <queue>
#include <memory>

class Human {
    std::string firstName;
    std::string lastName;
public:
    Human(std::string a, std::string b) :firstName(a), lastName(b) {}
    virtual void drink() {};
    virtual void introduceYourself() { std::cout << "Hello! I am " << firstName << " " << lastName << "!\n"; };
};

class Student : public Human {
    int studentID;
public:
    Student(std::string a, std::string b, int c): Human(a,b),studentID(c) {}
    void drink() { std::cout << "*Happy drinking noices*\n\n"; }
    void introduceYourself() {
        Human::introduceYourself();
        std::cout << "My studentID is " << studentID << ".\n";
    }
};

class Lecturer : public Human {
public:
    Lecturer(std::string a, std::string b): Human(a,b) {}
    void drink() { std::cout << "*Sad drinking noices*\n\n"; }
};

int main()
{
    std::cout << "Welcome to the pub!\nEnter number of customers...\n";
    std::queue<std::unique_ptr<Human>> beerQueue;
    int numberOfCustomers,ixNum;
    char choice;
    std::string fstN,lstN;
    std::cin >> numberOfCustomers;
    for (int i = 0; i < numberOfCustomers; i++) {
        std::cout << "Is it a Lecturer or a Student? L/S\n";
        do {
            std::cin >> choice;
            if (choice == 'L') {
                std::cout << "Enter data in format: FirstName [enter] LastName [enter]\n";
                std::cin >> fstN >> lstN;
                beerQueue.push(std::make_unique<Lecturer>(fstN, lstN));
            }
            else if (choice == 'S') {
                std::cout << "Enter data in format: FirstName [enter] LastName [enter] IndexNumber [enter]\n";
                std::cin >> fstN >> lstN >> ixNum;
                beerQueue.push(std::make_unique<Student>(fstN, lstN,ixNum));
            }
            else {
                std::cout << "Try again\n";
            }
        } while (choice != 'L' && choice != 'S');
    }
    system("cls");
    for (int i = 0; i < numberOfCustomers; i++) {
        beerQueue.front()->introduceYourself();
        beerQueue.front()->drink();
        beerQueue.pop();
    }
}
