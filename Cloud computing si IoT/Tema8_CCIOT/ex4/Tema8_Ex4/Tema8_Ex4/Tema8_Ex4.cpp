// Tema8_Ex4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>
#include <set>

using namespace std;

ostream& operator << (ostream& out,const vector<string>& obj) {
	for ( string i : obj ) {
		out << i << ";";
	}
	return out;
}

class Animal
{
protected:
	string race = "";
	string name = "";
	unsigned int age = -1;
	vector<string> shots;
public:
	virtual ~Animal() {}
	virtual string getRace() { return race; }
	virtual string getName() { return name; }
	virtual unsigned int getAge() { return age; }
	virtual vector<string> getShots() { return this->shots; }
	
	friend ostream& operator << (ostream& out, Animal& obj) {
		return out << "race: " << obj.getRace() << endl << "Name: " << obj.getName() << endl << "Age: " << obj.getAge() << endl << "Shots: " << obj.getShots() << endl;
	}

};

bool operator < (const shared_ptr<Animal>& obj1,const shared_ptr<Animal>& obj2) { return (obj1.get()->getName()).compare(obj2.get()->getName()) > 0; }

class Dog :public Animal {
private:
	string breed;
public:
	string getBreed() { return breed; }
	Dog( string breed, string name, unsigned int age, vector<string> shots) {
		this->breed = breed;
		this->race = "dog";
		this->name = name;
		this->age = age;
		this->shots = shots;
	}
	Dog(string breed, string name, unsigned int age) {
		this->breed = breed;
		this->race = race;
		this->name = name;
		this->age = age;
	}
	~Dog() {}

	friend ostream& operator << (ostream& out, Dog& obj) {
		return out << "race: " << obj.getRace() << endl << "Breed: " << obj.getBreed() << endl << "Name: " << obj.getName() << endl << "Age: " << obj.getAge() <<endl << "Shots: " << obj.getShots() << endl;
	}

};
class Cat :public Animal {
private:
	string breed;
public:
	string getBreed() { return breed; }
	Cat(string breed, string name, unsigned int age, vector<string> shots) {
		this->breed = breed;
		this->race = "cat";
		this->name = name;
		this->age = age;
		this->shots = shots;
	}
	Cat(string breed, string name, unsigned int age) {
		this->breed = breed;
		this->race = race;
		this->name = name;
		this->age = age;
	}
	~Cat() {}

	friend ostream& operator << (ostream& out, Cat& obj) {
		return out << "race: " << obj.getRace() << endl << "Breed: " << obj.getBreed() << endl << "Name: " << obj.getName() << endl << "Age: " << obj.getAge() << endl << "Shots: " << obj.getShots() << endl;
	}
};
class ExoticAnimal :public Animal {
private:
	bool venomous;
	bool bites;
public:
	ExoticAnimal(string race, string breed, string name, unsigned int age,bool venomous,bool bites ,vector<string> shots) {
		this->race = race;
		this->name = name;
		this->age = age;
		this->shots = shots;
		this->venomous = venomous;
		this->bites = bites;
	}
	ExoticAnimal(string race, string breed, string name, unsigned int age, bool venomous, bool bites) {
		this->race = race;
		this->name = name;
		this->age = age;
		this->venomous = venomous;
		this->bites = bites;
	}
	virtual ~ExoticAnimal() {}

	bool isVenomous() { return this->venomous; }
	bool doesBite() { return this->bites; }

	friend ostream& operator << (ostream& out, ExoticAnimal& obj) {
		return out << "race: " << obj.getRace() << endl << "Name: " << obj.getName() << endl << "Age: " << obj.getAge() << endl << "Bites: " << obj.doesBite() << endl << "Venomous: " << obj.isVenomous() << endl << "Shots: " << obj.getShots() << endl;
	}

};


void adopt(set< shared_ptr<Animal>,less<shared_ptr<Animal>> >& shelter, string breed, string race, int adopterAge) {
	for ( shared_ptr<Animal> i : shelter ) {
		if (race.compare("cat")==0) {
			Cat* cat = NULL;
			cat = dynamic_cast<Cat*>(i.get());
			if ( cat != NULL ) {
				if ( cat->getBreed().compare(breed) == 0 ) {
					cout << " --> Was adopted!"<<endl << *i.get() << "-------" << endl << endl;
					shelter.erase(i);
					break;
				}
			}
		}
		else if(race.compare("dog")==0) {
			Dog* dog = NULL;
			dog = dynamic_cast<Dog*>(i.get());
			if ( dog != NULL ) {
				if ( dog->getBreed().compare(breed) == 0 ) {
					cout << " --> Was adopted!" << endl << *i.get() << "-------" << endl << endl;
					shelter.erase(i);
					break;
				}
			}
		}
		else {
			if ( adopterAge >= 18 ) {
				ExoticAnimal* exoticAnimal = NULL;
				exoticAnimal = dynamic_cast<ExoticAnimal*>(i.get());
				if ( exoticAnimal != NULL ) {
					cout << " --> Was adopted!" << endl << *i.get() << "-------" << endl << endl;
					shelter.erase(i);
					break;
				}
			}
			else {
				cout << "You need to be at least 18 years old to adopt an exotic animal!" << endl << endl;
				break;
			}	
		}
	}
}

void displayVector(set< shared_ptr<Animal>, less<shared_ptr<Animal> >>& arr) {

	for ( shared_ptr<Animal> i : arr ) {

		Cat* cat = NULL;
		Dog* dog = NULL;
		ExoticAnimal* exoticAnimal = NULL;
		Animal* animal = NULL;

		cat = dynamic_cast<Cat*>(i.get());
		dog = dynamic_cast<Dog*>(i.get());
		exoticAnimal = dynamic_cast<ExoticAnimal*>(i.get());
		animal = dynamic_cast<Animal*>(i.get());

		if ( cat != NULL ) {
			cout << *cat << endl;
		}
		else if ( dog != NULL ) {
			cout << *dog << endl;
		}
		else if ( exoticAnimal != NULL ) {
			cout << *exoticAnimal << endl;
		}
		else {
			cout << *animal << endl;
		}
		
	}
}
void displayDogs(set< shared_ptr<Animal>, less<shared_ptr<Animal> >>& arr) {

	for ( shared_ptr<Animal> i : arr ) {
		Dog* dog = NULL;
		dog = dynamic_cast<Dog*>(i.get());
		if ( dog != NULL ) {
			cout << *dog << endl;
		}
	}
}

int main()
{
	set < shared_ptr<Animal>,less<shared_ptr<Animal>> > shelter;
	shelter.insert(make_shared<Cat>(Cat("siamese", "Mr Petter", 5, vector<string>{"covid","hiv","astrazeneca","frisbee"})));
	shelter.insert(make_shared<Cat>(Cat("british shorthair", "Bolder", 2, vector<string>{"hiv", "astrazeneca", "frisbee"})));
	shelter.insert(make_shared<Cat>(Cat("persian", "Tom", 5, vector<string>{"frisbee"})));
	shelter.insert(make_shared<Cat>(Cat("sphinx", "Anubis", 3, vector<string>{"hiv"})));
	shelter.insert(make_shared<Dog>(Dog("Doberman", "Barki", 1, vector<string>{"covid", "hiv", "astrazeneca", "frisbee"})));
	shelter.insert(make_shared<Dog>(Dog("Husky", "Norby", 5, vector<string>{"covid"})));
	shelter.insert(make_shared<Dog>(Dog("Labrador", "Max", 4, vector<string>{"astrazeneca", "frisbee"})));
	shelter.insert(make_shared<Dog>(Dog("Poodle", "Moxy", 2, vector<string>{"covid", "hiv", "astrazeneca"})));
	shelter.insert(make_shared<ExoticAnimal>(ExoticAnimal("arachnoid","tarantula", "Mr. Juve", 1, true, true, vector<string>{})));
	shelter.insert(make_shared<ExoticAnimal>(ExoticAnimal("reptile","python", "Piky", 2, false, true, vector<string>{})));


	cout << "Toate animalele" << endl;
	displayVector(shelter);

	cout << endl << "All dogs" << endl;
	displayDogs(shelter);

	cout << endl << "After adoption" << endl;
	adopt(shelter, "british shorthair","cat",16);
	displayVector(shelter);

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
