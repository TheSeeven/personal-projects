// Tema8_Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



class Date {
private:
    int year;
    int month;
    int day;

    int getNumberOfDays() {
        if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
            return 31;
        }
        else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
            return 30;
        }
        return 28;
    }


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

    bool isEligible(Date fromDate) {
        int result;
        if ( (fromDate.getDay() - this->getDay() > 0) && this->getYear() == fromDate.getYear() && this->getMonth() == fromDate.getMonth()) {
            result = fromDate.getDay() - this->getDay();
            if ( result <= 7 ) return true;
            return false;
        }
        else if ( (fromDate.getDay() - this->getDay() <= 0 ) && this->getMonth() != fromDate.getMonth() && this->getYear() == fromDate.getYear() && fromDate.getMonth()-this->getMonth()==1 ) {
            result = fromDate.getDay()+ this->getNumberOfDays() - this->getDay();
            if ( result <= 7 ) return true;
            return false;
        }
        else if ( (fromDate.getDay() - this->getDay() <= 0) && this->getMonth() != fromDate.getMonth() && this->getYear() != fromDate.getYear() && fromDate.getMonth() - this->getMonth() == 1 ) {
            int monthCompare = 12 - this->getMonth() + fromDate.getMonth();
            if ( monthCompare == 1 ) {
                result = fromDate.getDay() + this->getNumberOfDays() - this->getDay();
                if ( result <= 7 ) return true;
                return false;
            }
            return false;
        }
        return false;

    }

};
class Client {
private:
    Date* placed = nullptr;
    string fullName = "";
public:
    Client() {}
    Client(string fullName,int year, int month, int day) {
        this->placed = new Date(year, month, day);
        this->fullName = fullName;
    }
    ~Client() {}
    Date* getPlaced() { return this->placed; }
    string getFullName() { return this->fullName; }

};
class Order {
private:
    int amount = -1;
    int age = -1;
public:
    Order() {}
    Order(int amount, int age) {
        this->amount = amount;
        this->age = age;
    }
    ~Order() {}
    int getAmount() { return this->amount; }
    int getAge() { return this->age; }

};
typedef pair<Client, Order> Data;

ostream& operator << (ostream& out, Date* obj) {
    return out << to_string(obj->getYear()) << "/" << to_string(obj->getMonth()) << "/" << to_string(obj->getDay());
}
ostream& operator << (ostream& out, Client obj) {
    return out <<"Full Name: "<< obj.getFullName() << " | Date Placed: " << obj.getPlaced();
}
ostream& operator << (ostream& out, Order obj) {
    return out << "Amount: " << obj.getAmount() << " | Pizza age: " << obj.getAge();
}
ostream& operator << (ostream& out, Data obj) {
    return out << "Client: " << get<0>(obj) << endl << "Order: " << get<1>(obj);
}





bool isSafePizza(Data& d)  {
    if ( get<1>(d).getAge() < 4 ) return true;
    return false;
}
stack<Data> getSafePizza(stack<Data> db) {
    stack<Data> result;
    while ( !db.empty() ) {
        if ( isSafePizza(db.top())) {
            result.push(db.top());
        }
        db.pop();
    }
    return result;
}
void displayDB(stack<Data> db) {
    while ( !db.empty() ) {
        cout << db.top() << endl;
        db.pop();
    }
}
void displayEstimatedProfit(stack<Data> safePizzas, Date currentDate) {
    float profit = 0;
    while ( !safePizzas.empty() ) {
        Data iter = safePizzas.top();
        Date* temp = get<0>(iter).getPlaced();
        if ( (*temp).isEligible(currentDate) ) {
            profit += (get<1>(iter).getAmount() * 0.75);
        }
        safePizzas.pop();
    }
    cout << "The total profit is: " << profit << endl;
}


int main()
{
    cout << "INITIAL DATABASE" << endl;

    Date currentDate = Date(2021,8,8);

    stack<Data> db;
    db.push(Data(Client("Mihai Eminem",2021,4,7),Order(4,2)));
    db.push(Data(Client("Dolor Sit'Amet", 2021, 8, 7), Order(10, 4)));
    db.push(Data(Client("Gheorghe Ioan", 2021, 8, 2), Order(2, 1)));
    db.push(Data(Client("Mircea Georgescu", 2021, 7, 10), Order(3, 1)));
    db.push(Data(Client("Florentina Narcotic", 2021, 2, 1), Order(7, 2)));
    displayDB(db);
    cout << endl << "SAFE PIZZA DATABASE" << endl;
    stack<Data> safePizza = getSafePizza(db);
    displayDB(safePizza);
    cout << endl << "Estimated profit from 7 days ago, curent date is -> " << &currentDate << endl;
    displayEstimatedProfit(safePizza, currentDate);
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
