// Tema7_Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;



enum class School
{
    GENERAL,
    HIGHSCHOOL
};

enum class ImpactArea
{
    PHYSICS,
    BIOLOGY,
    ELECTRONICS
};

//              st_name     type                invention_id     
typedef tuple<  string,     School,             int>                Contestant;

//              grading     invention_id        ev_name
typedef tuple<  int,        int,                string>             Evaluation;

//              invention_id                    area                        
typedef tuple<  int,                            ImpactArea>         Invention;


int getScore(priority_queue<Evaluation>  evaluations ,int &inventionId) {
    
    
    Evaluation ev = evaluations.top();
    evaluations.pop();
    evaluations.push(ev);
    return 0;
}


void printContestants(priority_queue<Contestant> q) {
    while ( !q.empty() ) {
        cout << "Id: " << get<2>(q.top()) << " Name: " << get<0>(q.top()) << " School: ";
        if( get<1>(q.top()) == School::GENERAL)
        cout << "GENERAL" << endl;
        else
        cout << "HIGHSCHOOL" << endl;
        q.pop();
    }
}

void printEvaluations(priority_queue<Evaluation> q) {
    while ( !q.empty() ) {
        cout << "Grading: " << get<0>(q.top())  << " Invention id: " << get<1>(q.top()) << " Evaluator: " << get<2>(q.top()) << endl;
        q.pop();
    }
}


void printInventions(priority_queue<Invention> q) {
    while ( !q.empty() ) {
        cout << "Invention id: " << get<0>(q.top()) << " Field: ";

        if ( get<1>(q.top()) == ImpactArea::BIOLOGY )
            cout << "BIOLOGY" << endl;
        else if ( get<1>(q.top()) == ImpactArea::ELECTRONICS )
            cout << "ELECTRONICS" << endl;
        else
            cout << "PHYSICS" << endl;
        q.pop();
    }
}

Invention getInventionById(int id,priority_queue<Invention> q) {
    while ( !q.empty() ) {
        if ( get<0>(q.top()) == id ) {
            return q.top();
        }
        q.pop();
    }
}

priority_queue<Invention> removeLowScore(priority_queue<Evaluation>  evaluations, priority_queue<Invention> inventions) {
    priority_queue<Invention> result;
    while ( !evaluations.empty() ) {
        if ( ! (get<0>(evaluations.top()) < 60) )
            result.push(getInventionById(get<1>(evaluations.top()), inventions));
        else break;
        evaluations.pop();
    }
    return result;
}


ImpactArea getImpactAreaById(int id, priority_queue<Invention>& inventions) {
    while ( !inventions.empty() ) {
        if ( get<0>(inventions.top()) ) {
            return get<1>(inventions.top());
        }
        inventions.pop();
    }
}

void printBestFieldOfActivity(priority_queue<Invention> &inventions, priority_queue<Evaluation>  evaluations) {
    cout << "THE FIELD OF ACTIVITY WITH THE BEST SCORE IS -> ";

    int BIOLOGY = 0;
    int PHYSICS = 0;
    int ELECTRONICS = 0;
    ImpactArea area;
    int score;
    while ( !evaluations.empty() ) {
        area = getImpactAreaById(get<0>(evaluations.top()), inventions);
        score = get<1>(evaluations.top());
        if ( area == ImpactArea::BIOLOGY )
            BIOLOGY += score;
        else if ( area == ImpactArea::ELECTRONICS )
           ELECTRONICS+=score;
        else
           PHYSICS+=score;
        evaluations.pop();
    }

    if ( BIOLOGY > PHYSICS && BIOLOGY > ELECTRONICS ) {
        cout << "BIOLOGY" << endl;
    }
    else if ( PHYSICS > BIOLOGY && PHYSICS > ELECTRONICS ) {
        cout << "PHYSICS" << endl;
    }
    else {
        cout << "ELECTRONICS" << endl;
    }

    
}


int main(void)
{   
  
    priority_queue<Contestant>  contestants;
    priority_queue<Evaluation>  evaluations;
    priority_queue<Invention>   inventions;

    contestants.push(make_tuple("George Peterson",     School::GENERAL,         100));
    contestants.push(make_tuple("Alex Binga",          School::GENERAL,         101));
    contestants.push(make_tuple("Critica Naomi",       School::HIGHSCHOOL,      102));
    contestants.push(make_tuple("Elisabeth da'Burgh",  School::HIGHSCHOOL,      103));
    contestants.push(make_tuple("Zanni Petrov",        School::HIGHSCHOOL,      104));

    evaluations.push(make_tuple(55, 100,"Bazinga Sheldon"));
    evaluations.push(make_tuple(33,101,"Bazinga Sheldon"));
    evaluations.push(make_tuple(65,102,"Bazinga Sheldon"));
    evaluations.push(make_tuple(100,103,"Alex Sipi"));
    evaluations.push(make_tuple(77,104,"Alex Sipi"));

    inventions.push(make_tuple(100,                    ImpactArea::ELECTRONICS));
    inventions.push(make_tuple(101,                    ImpactArea::PHYSICS));
    inventions.push(make_tuple(102,                    ImpactArea::ELECTRONICS));
    inventions.push(make_tuple(103,                    ImpactArea::BIOLOGY));
    inventions.push(make_tuple(104,                    ImpactArea::BIOLOGY));

    cout << "CONTESTANTS" << endl;
    printContestants(contestants);
    cout <<  endl;

    cout << "EVALUATIONS" << endl;
    printEvaluations(evaluations);
    cout <<  endl;

    cout << "INVENTIONS" << endl;
    printInventions(inventions);
    cout << endl;

    cout << "REMOVED UNDER 60 INVENTIONS" << endl;
    priority_queue<Invention> over60 = removeLowScore(evaluations, inventions);
    printInventions(over60);
    cout << endl;
    printBestFieldOfActivity(inventions,evaluations);
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
