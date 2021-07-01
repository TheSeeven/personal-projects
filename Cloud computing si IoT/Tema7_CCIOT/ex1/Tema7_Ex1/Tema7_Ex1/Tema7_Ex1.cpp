// Tema7_Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <list>
#include <string>
#include <map>

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
        localtime_s(&newtime , &now);

        year = newtime.tm_year + 1900;
        month = newtime.tm_mon + 1;
        day = newtime.tm_mday;
    }

    Date(unsigned int year , unsigned int month , unsigned int day) {
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

class Book {
private:
    string author;
    string title;
    Date* current_date;
    Date* return_date;
    int bookRating = 0;
public:
    Book(string author , string title , int year , int month , int day) {
        this->author = author;
        this->title = title;
        this->current_date = new Date();
        this->return_date = new Date(year , month , day);
    }
    Book(string author , string title , int year , int month , int day , int rating) {
        this->author = author;
        this->title = title;
        this->bookRating = rating;
        this->current_date = new Date();
        this->return_date = new Date(year , month , day);
    }
    ~Book() {}

    string getAuthor() {
        return this->author;
    }
    string getTitle() {
        return this->title;
    }

    int getRating() {
        return this->bookRating;
    }

    Date* getReturnDate() {
        return this->return_date;
    }

    Date* getCurentDate() {
        return this->current_date;
    }

    bool isDue() {
        if ( return_date < current_date )
            return true;
        return false;
    }
    bool isPopular() {
        if ( bookRating > 4 )
            return true;
        return false;
    }

};

bool isDue(Book& value) {
    if ( *value.getReturnDate() < *value.getCurentDate() )
        return true;
    return false;
}


ostream& operator << (ostream& out , Date* obj) {
    return out << to_string(obj->getYear()) << "/" << to_string(obj->getMonth()) << "/" << to_string(obj->getDay());
}

ostream& operator << (ostream& out , Book& obj) {
    return out << "Author: " << obj.getAuthor() << endl << "Title: " << obj.getTitle() << endl << "Return date: " << obj.getReturnDate() << endl;
}


int main() {
    list<Book> bookList;

    bookList.push_back(Book("Mihai Eminem" , "Luptatorul ne-fricos" , 2021 , 5 , 7));
    bookList.push_back(Book("Mihai Eminem" , "No', asta da barbat!" , 2021 , 1 , 20));
    bookList.push_back(Book("Calupesucu Pristine" , "The truck mover" , 2020 , 8 , 15));
    bookList.push_back(Book("By myself" , "No inspiration" , 2021 , 7 , 31));
    bookList.push_back(Book("Nobody" , "Programing is easy!" , 2021 , 6 , 20));
    bookList.push_back(Book("Only me" , "Yea, it's fine!" , 2020 , 4 , 19));

    cout << "BEFORE REMMOVING" << endl;
    // original list
    for ( auto i : bookList ) {
        cout << i << endl;
    }
    cout << "AFTER REMMOVING" << endl;
    // list after filtering late return books
    bookList.remove_if(isDue);

    // after removing due books
    for ( auto i : bookList ) {
        cout << i << endl;
    }

    // friends map exercise
    map<string , list<Book>> friends;
    friends["Alex"].push_back(Book("Mihai Eminem" , "Luptatorul ne-fricos" , 2021 , 5 , 7 , 5));
    friends["Alex"].push_back(Book("Calupesucu Pristine" , "The truck mover" , 2020 , 8 , 15 , 2));
    friends["Alex"].push_back(Book("Only me" , "Yea, it's fine!" , 2020 , 4 , 19 , 4));
    friends["Mihai"].push_back(Book("Mihai Eminem" , "No', asta da barbat!" , 2021 , 1 , 20 , 1));
    friends["Mihai"].push_back(Book("By myself" , "No inspiration" , 2021 , 7 , 31 , 5));
    friends["Mihai"].push_back(Book("By myself" , "Am I alive?" , 2021 , 7 , 31 , 3));
    friends["Nicky"].push_back(Book("Mihai Eminem" , "Blunt, Smoke, graa" , 2004 , 10 , 20 , 4));
    friends["Nicky"].push_back(Book("Vigilante Marcus Stropus" , "Really!?" , 2022 , 4 , 4 , 2));
    friends["Nicky"].push_back(Book("Ion Asparagus" , "How to not ! not eat" , 2069 , 7 , 8 , 3));
    friends["Nicky"].push_back(Book("Bill Windows" , "MacroSoft Gates 10" , 2020 , 8 , 14 , 5));
    cout << "BOOKS FROM EVERY FRIEND IF 5 STAR RATING" << endl;
    for ( auto i : friends ) {
        cout << "Reader: " << i.first << endl;
        for ( auto book : i.second ) {
            if ( book.isPopular() ) {
                cout << book << endl;
            }
        }
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
