// Tema7_Ex5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define LOW "low"
#define MEDIUM "medium"
#define HIGH "high"

#define CRITICAL "critical"

#define FINAL "final"
#define INTERMEDIARY "intermediary"

enum class Priority {
    P1 = 1,
    P2 = 2,
    P3 = 3,
    P4 = 4
};

class Exam {
private:
    string importance = "";
    string dificulty = "";
    string type = "";
    int priority = 0;

    int calculatePriority() {
        if ( this->importance == LOW && this->dificulty == LOW ) { return (int)Priority::P1; }
        else if ( this->importance == LOW && this->dificulty == MEDIUM ) { return (int)Priority::P1; }
        else if ( this->importance == LOW && this->dificulty == HIGH ) { return (int)Priority::P2; }
        else if ( this->importance == MEDIUM && this->dificulty == LOW ) { return (int)Priority::P1; }
        else if ( this->importance == MEDIUM && this->dificulty == MEDIUM ) { return (int)Priority::P2; }
        else if ( this->importance == MEDIUM && this->dificulty == HIGH ) { return (int)Priority::P2; }
        else if ( this->importance == HIGH && this->dificulty == LOW ) { return (int)Priority::P2; }
        else if ( this->importance == HIGH && this->dificulty == MEDIUM ) { return (int)Priority::P3; }
        else if ( this->importance == HIGH && this->dificulty == HIGH ) { return (int)Priority::P3; }
        else if ( this->importance == CRITICAL && this->dificulty == LOW ) { return (int)Priority::P3; }
        else if ( this->importance == CRITICAL && this->dificulty == MEDIUM ) { return (int)Priority::P4; }
        else if ( this->importance == CRITICAL && this->dificulty == HIGH ) { return (int)Priority::P4; }
    }

public:
    Exam(string importance, string dificulty, string type) {
        this->importance = importance;
        this->dificulty = dificulty;
        this->type = type;
        this->priority = calculatePriority();
    }
    Exam() {}
    ~Exam() {}
    string getImportance() { return this->importance; }
    string getDificulty() { return this->dificulty; }
    string getType() { return this->type; }
    int getPriority() { return this->priority; }

   
};

bool compareExam (Exam& obj1,Exam& obj2) { return obj1.getPriority() > obj2.getPriority(); }

string priorityToString(int p) {
    if ( p == 1 ) {return "low";}
    else if ( p == 2 ) { return "medium"; }
    else if ( p == 3 ) { return "high"; }
    else {return "critical";}
}

ostream& operator << (ostream& out, Exam obj) {
    string priority;
    priority = priorityToString(obj.getPriority());
    return out << "Importance: " << obj.getImportance() << " | Dificulty: " << obj.getDificulty() << " | Exam Type: " << obj.getType() << " | Priority: " << priority;
}


void printList(list<Exam> examList) {
    for ( auto i : examList ) {
        cout << i << endl;
    }
}



int main()
{
    list<Exam> examList;
    examList.push_back(Exam(LOW, HIGH, INTERMEDIARY));
    examList.push_back(Exam(MEDIUM,MEDIUM,FINAL));
    examList.push_back(Exam(LOW, MEDIUM, INTERMEDIARY));
    examList.push_back(Exam(CRITICAL, MEDIUM, INTERMEDIARY));
    examList.push_back(Exam(LOW, MEDIUM, FINAL));
    examList.push_back(Exam(LOW, HIGH, INTERMEDIARY));
    examList.push_back(Exam(HIGH, HIGH, FINAL));
    examList.push_back(Exam(CRITICAL, HIGH, FINAL));
    examList.push_back(Exam(LOW, LOW, FINAL));
    examList.push_back(Exam(MEDIUM, LOW, INTERMEDIARY));
    examList.push_back(Exam(HIGH, MEDIUM, FINAL));
    cout << "INITIAL LIST" << endl;
    printList(examList);
    cout << endl;

    cout << "SORTED LIST" << endl;
    examList.sort(compareExam);
    printList(examList);
    cout << endl;


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
