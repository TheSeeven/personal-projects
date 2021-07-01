// Tema7_Ex4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int profit;
    int productionYear;
public:
    Car(string brand, string model, int profit, int productionYear) {
        this->brand = brand;
        this->model = model;
        this->profit = profit;
        this -> productionYear = productionYear;
    }
    Car() {}
    ~Car() {}

    string getBrand() { return this->brand; }
    string getModel() { return this->model; }
    int getProfit() { return this->profit; }
    int getProductionYear() { return this->productionYear; }
    bool operator < (const Car& obj) const { return (this->model).compare(obj.model) > 0; }
};

bool greaterYear (Car& obj1,Car& obj2) {
    return obj1.getProductionYear() > obj2.getProductionYear();
}

ostream& operator << (ostream& out, Car& obj) {
    return out << "Brand: " << obj.getBrand() << " Model: " << obj.getModel() << " Profit: " << obj.getProfit() << " Production year: " << obj.getProductionYear();
}

void isExistBMW(set<Car>& cars) {
    int counter = 0;
    for ( auto i : cars ) {
        if ( (i.getBrand()).compare("BMW") == 0  ) {
            counter++;
        }
    }
    if ( counter != 0 ) {
        cout << counter << " -> BMW models have been sold!" << endl;
        return;
    }
    cout << "0 -> BMW models haven't been sold!" << endl;


}

template<typename T>
void printSet(set<Car, T> theSet) {
    for ( Car i : theSet ) {
        cout << i << endl;
    }
}

void printVector(vector<Car> &vect) {
    for ( Car i : vect ) {
        cout << i << endl;
    }
}

void printMostProfitableYear(vector<Car>& vect) {
    Car* temp = nullptr;
    for ( Car &i : vect ) {
        if ( temp == nullptr ) {
            temp = &i;
        }
        else {
            if ( temp->getProfit() < i.getProfit() ) {
                temp = &i;
            }
        }
    }
    cout << "MOST PROFITABLE YEAR IS -> " << temp->getProductionYear() << endl;
}

int main()
{
    set<Car,less<Car>> cars;
    cars.insert(Car("Mercedes","c-class",200000,2008));
    cars.insert(Car("Mercedes", "3300", 250000, 2004));
    cars.insert(Car("Mercedes", "e-class", 150000, 2010));
    cars.insert(Car("Dacia", "Logan", 20000, 2002));
    cars.insert(Car("Dacia", "Solenza", 15000, 1998));
    cars.insert(Car("Dacia", "1310", 500000, 1980));
    cars.insert(Car("BMW", "Series 3", 650000, 2004));
    cars.insert(Car("BMW", "Series 7", 550000, 2012));
    cars.insert(Car("BMW", "Series 5", 350000, 2008));
    cars.insert(Car("BMW", "X6", 500000, 2018));
    cars.insert(Car("Renault", "c-class", 200000, 2008));

    cout << "ORIGINAL SET" << endl;
    printSet(cars);
    cout << endl;


    cout << "EXERCITIUL 4" << endl;
    isExistBMW(cars);
    cout << endl;

    vector<Car> YearOrdered;
    for ( auto i : cars ) {
        YearOrdered.push_back(i);
    }
    sort(YearOrdered.begin(), YearOrdered.end(), greaterYear);
    cout << "YEAR ORDERED VECTOR" << endl;
    printVector(YearOrdered);
    cout << endl;

    printMostProfitableYear(YearOrdered);


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
