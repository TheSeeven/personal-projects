// Tema8_Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;



class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() {
        struct tm newtime;
        time_t now = time(0);
        localtime_s(&newtime, &now);

        year = newtime.tm_year + 1900;
        month = newtime.tm_mon + 1;
        day = newtime.tm_mday;
    }

    Date(unsigned int year, unsigned int month, unsigned int day) {
        if ( month > 12 || year < 0 ) {
            throw "Month < 12 & year > 0 ";
        }
        if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
            if ( day > 31 ) {
                throw "Months 1,3,5,7,8,10,12 have only 31 days!";
            }
        }
        else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
            if ( day > 30 ) {
                throw "Months 4,6,9,11 have only 30 days!";
            }
        }
        else {
            if ( day > 28 ) {
                throw "Month 2 have only 28 days!";
            }
        }

        this->year = year;
        this->month = month;
        this->day = day;
    }
    ~Date() {}

    int getYear() {
        return this->year;
    }
    int getMonth() {
        return this->month;
    }
    int getDay() {
        return this->day;
    }

    bool operator < (const Date& second) const {
        if ( this->year < second.year ) {
            return 1;
        }
        else if ( this->year > second.year ) {
            return 0;
        }

        if ( this->month < second.month ) {
            return 1;
        }
        else if ( this->month > second.month ) {
            return 0;
        }

        if ( this->day < second.day ) {
            return 1;
        }
        else if ( this->day > second.day ) {
            return 0;
        }
        return 0;
    }
};


class Pot {
private:
    string type = "";
    unsigned int capacity = 0;
    unsigned int price = 0 ;
    Date* deliveryDate = nullptr;
public:
    Pot() {}
    Pot(string type, unsigned int capacity, unsigned int price,unsigned int day, unsigned int month, unsigned int year) {
        this->type = type;
        this->capacity = capacity;
        this->price = price;
        this->deliveryDate =new Date(year,month,day);
    }

    ~Pot() {}

    string getType() { return this->type; }
    unsigned int getCapacity() { return this->capacity; }
    unsigned int getPrice() { return this->price; }
    Date* getDeliveryDate() { return this->deliveryDate; }
    bool operator < (const Pot& obj) const { return (this->type).compare(obj.type) > 0; }
};

ostream& operator << (ostream& out, Pot& obj)  {
    return out << "Type: " << obj.getType() << " Capacity: " << obj.getCapacity() << " Price: " << obj.getPrice();
}

void priceAboveFive(set<Pot>& pots) {
    int counter = 0;
    for (Pot i : pots ) {
        if ( i.getCapacity() > 5) {
            counter++;
        }
    }
    if ( counter != 0 ) {
        cout << counter << " -> Number of pots above 5$" << endl;
        return;
    }
    cout << "0 -> Pots with price above 5" << endl;
}

bool deliveryDateComparator(Pot& obj1, Pot& obj2) {
    return obj1.getDeliveryDate() < obj2.getDeliveryDate();
}

int getWeek(int day, int month, int year) {
    int week = month * 4;
    week += day / 7;
    return week;
}

typedef tuple<int, int> WeekProfit;
void AddToWeek(int value, int week, vector<WeekProfit>& arr) {
    bool found = false;
    for ( WeekProfit &i : arr ) {
        if ( get<0>(i) == week ) {
            get<1>(i) += value;
            found = true;
            break;
        }
        
    }
    if ( !found ) {
        arr.push_back(make_tuple(week, value));
    }
}


typedef tuple<int, int> WeekProfit;
void printWeeksByProfit(vector<Pot> DeliveryOrdered) {
    vector<WeekProfit> result;
    for ( Pot i : DeliveryOrdered ) {
        AddToWeek(i.getPrice(), getWeek(i.getDeliveryDate()->getDay(), i.getDeliveryDate()->getMonth(), i.getDeliveryDate()->getYear()), result);
    }
    int max = 0;
    int week = 0;
    for ( WeekProfit i : result ) {
        if ( get<1>(i) > max ) {
            max = get<1>(i);
            week = get<0>(i);
        }

    }
    cout << "The most profitable week: " << week << " profit: " << max << endl;
}


int main() {
    set<Pot,less<Pot>> pots;
    pots.insert(Pot("palm", 50, 100,5,2,2020));
    pots.insert(Pot("small flowers", 2, 5,8,9,2021));
    pots.insert(Pot("bonsai", 1, 20,7,9,2021));
    pots.insert(Pot("ornament", 1, 10,1,3,2020));
    pots.insert(Pot("big flowers", 6, 25,6,6,2020));
    pots.insert(Pot("medium flowers", 4, 15,4,2,2021));
    pots.insert(Pot("small tree", 20, 40,6,2,2020));
    pots.insert(Pot("small cactus", 1, 10,2,6,2021));
    pots.insert(Pot("medium cactus", 3, 30,2,4,2020));
    pots.insert(Pot("big cactus", 5, 50,6,4,2021));
    pots.insert(Pot("extra cactus", 8, 70,28,10,2021));

    priceAboveFive(pots);

    vector<Pot> DeliveryOrdered;
    for ( Pot i : pots ) {
        DeliveryOrdered.push_back(i);
    }
    sort(DeliveryOrdered.begin(), DeliveryOrdered.end(), deliveryDateComparator);
    printWeeksByProfit(DeliveryOrdered);

   
    

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
