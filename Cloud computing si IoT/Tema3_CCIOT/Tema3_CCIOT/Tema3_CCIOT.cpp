// Tema3_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <set>
#include <forward_list>
#include <vector>
#include <memory>

class Person {
private:
    std::string name;
    std::string nickname;
    std::string job;
    unsigned int age;

public:
    Person(std::string name, std::string nickname, std::string job, unsigned int age) {
        this->name = name;
        this->nickname = nickname;
        this->job = job;
        this->age = age;
    }
    ~Person() {}

    std::string getName() const {
        return name;
    }
    std::string getNickname() const {
        return nickname;
    }
    std::string getJob() const {
        return job;
    }
    unsigned int getAge() const {
        return age;
    }

    unsigned int ageClass() const {
        if (age < 15) {
            return 1;
        }
        if (age >= 15 && age < 25) {
            return 2;
        }
        if (age >= 25 && age < 55) {
            return 3;
        }
        return 4;
    }
   
    bool operator < (const Person& p) const {
        return p.getAge() < this->getAge();
    }

};

std::ostream& operator << (std::ostream& out,const Person& obj)
{
    return out << "Name: " << obj.getName() << std::endl << "Nickname: " << obj.getNickname() << std::endl << "Job: " << obj.getJob() << std::endl << "Age: " << obj.getAge() << std::endl << "Age class: " << obj.ageClass() << std::endl << std::endl;
}

bool isInFirstNotInThird(Person& first, std::forward_list<Person> second) {
    std::cout <<"first: "<< &first << std::endl;
    for (Person& i : second) {
        std::cout << std::addressof(i) << std::endl;
        if (&first==std::addressof(i)) {
            return true;
        }
    }
    return false;
}

int main()
{
    // exercitiul 1
    std::cout << "EXERCITIUL 1" << std::endl << std::endl;
    std::list<Person> list;
    list.push_back(Person("Alex", "Mica", "Programmer", 20));
    list.push_back(Person("Biga", "Amino", "Constructor", 18));
    list.push_back(Person("Banino", "Alberto", "Manager", 35));
    list.push_back(Person("Johan", "Liebert", "Profesor", 45));
    list.push_back(Person("Violet", "Evergarden", "Clown", 40));
    list.push_back(Person("All", "Mighty", "Crane operator", 22));
    list.push_back(Person("Midoria", "Izuku", "Mechanic", 18));
    list.push_back(Person("George", "Cosbuc", "Inspector", 35));
    list.push_back(Person("Mihai", "Eminem", "Basketball player", 30));
    list.push_back(Person("Tenma", "Kenzo", "Doctor", 27));

    for (const auto i : list) {
        std::cout << i;
    }

    // exercitiul 2
    std::cout << "EXERCITIUL 2" << std::endl << std::endl;
    std::set<Person> set1;
    unsigned int counter = 0;
    for (const auto& i : list) {
        counter++;
        if (counter > 5) break;
        set1.insert(i);
    }

    for (const auto i : set1) {
        std::cout << i;
    }

    // exercitiul 3
    std::cout << "EXERCITIUL 3" << std::endl << std::endl;
    std::forward_list<Person> linkedList;

    for (auto& i : set1) {
        linkedList.push_front(i);
    }
    for (auto& i : linkedList) {
        std::cout << i << std::endl;
    }

    // exercitiul 4
    std::cout << "EXERCITIUL 4" << std::endl << std::endl;
    std::vector<Person> vector1;
    for (auto& i : list) {
        if (!isInFirstNotInThird(i, linkedList)) {
            vector1.push_back(i);
        }
    }

    for (auto i : vector1) {
        std::cout << i;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
