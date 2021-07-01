// Tema7_Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    Date(unsigned int year, unsigned int month, unsigned int day) {
        if ( month > 12) {
            throw "Month < 12";
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

ostream& operator << (ostream& out, Date* obj) {
    return out << to_string(obj->getYear()) << "/" << to_string(obj->getMonth()) << "/" << to_string(obj->getDay());
}


class Artifact {
protected:
    string artifactType = "Unknown";
    string condition;
    Date* discoveryDate = nullptr;
    Date* estimatedDateOfOrigin = nullptr;
public:
    virtual ~Artifact() {}
    virtual string getArtifact() {
        return this->artifactType;
    }
    virtual string getCondition() {
        return this->condition;
    }
    virtual Date* getDiscoveryDate() {
        return this->discoveryDate;
    }
    virtual Date* getEstimatedDateOfOrigin() {
        return this->estimatedDateOfOrigin;
    }

    bool operator < (const Artifact& second) const {
        if ( (*this->discoveryDate) < (*second.discoveryDate) ) return true;
        return false;
    }
    virtual ostream& operator << (ostream& out) {
        return out << "Artifact type: " << this->getArtifact() << endl << "Condition: " << this->getCondition() << endl << "Discovery date: " << this->getDiscoveryDate() << endl << "Estimated date: " << this->getEstimatedDateOfOrigin() << endl;
    };
};

class EgiptianArtifact :public Artifact {
private:
    string pharaoh;
public:
    EgiptianArtifact(string pharaoh,string artifactType, string condition, int discoveryYear, int discoveryMonth, int discoveryDay, int dateOfOriginYear, int dateOfOriginMonth, int dateOfOriginDay) {
        this->artifactType = artifactType;
        this->condition = condition;
        this->discoveryDate = new Date(discoveryYear, discoveryMonth, discoveryDay);
        this->estimatedDateOfOrigin = new Date(dateOfOriginYear, dateOfOriginMonth, dateOfOriginDay);
        this->pharaoh = pharaoh;
    }
    ~EgiptianArtifact() {}

    string getPharaoh() {
        return this->pharaoh;
    }
    ostream& operator << (ostream& out) {
    return out << "Pharaoh name: " << this->getPharaoh() << endl << "Artifact type: " << this->getArtifact() << endl << "Condition: " << this->getCondition() << endl << "Discovery date: " << this->getDiscoveryDate() << endl << "Estimated date: " << this->getEstimatedDateOfOrigin() << endl;
    }   
};

class GreekArtifact :public Artifact {
private:
    string greekGod = "Unknown";
public:
    GreekArtifact(string greekGod, string artifactType, string condition, int discoveryYear, int discoveryMonth, int discoveryDay, int dateOfOriginYear, int dateOfOriginMonth, int dateOfOriginDay) { 
        this->condition = condition;
        this->artifactType = artifactType;
        this->discoveryDate = new Date(discoveryYear, discoveryMonth, discoveryDay);
        this->estimatedDateOfOrigin = new Date(dateOfOriginYear, dateOfOriginMonth, dateOfOriginDay);
        this->greekGod = greekGod;
    }
    GreekArtifact(string artifactType, string condition, int discoveryYear, int discoveryMonth, int discoveryDay, int dateOfOriginYear, int dateOfOriginMonth, int dateOfOriginDay) {
        this->condition = condition;
        this->artifactType = artifactType;
        this->discoveryDate = new Date(discoveryYear, discoveryMonth, discoveryDay);
        this->estimatedDateOfOrigin = new Date(dateOfOriginYear, dateOfOriginMonth, dateOfOriginDay);
    }
    ~GreekArtifact() {}

    string getGod() {
        return this->greekGod;
    }
    virtual ostream& operator << (ostream& out) {
        return out << "God name: " << this->getGod() << endl << "Artifact type: " << this->getArtifact() << endl << "Condition: " << this->getCondition() << endl << "Discovery date: " << this->getDiscoveryDate() << endl << "Estimated date: " << this->getEstimatedDateOfOrigin() << endl;
    };
};



void printArtifacts(list<Artifact> &list) {
    for ( auto i : list ) {
        i << cout << endl;
    }
}

int main(void) {

    list<Artifact> artifactList;
    artifactList.push_back(GreekArtifact("Zeus","Jewelry","good",2020,4,6,-1500,10,8));
    artifactList.push_back(GreekArtifact("Hades","Vase","poor",2019,8,16,-1000,1,6));
    artifactList.push_back(GreekArtifact("Poseidon","partialRelic","poor",2016,5,5,-4000,5,8));
    artifactList.push_back(GreekArtifact("Vase","needSpecialHandling",2017,7,15,-3000,8,4));
    artifactList.push_back(GreekArtifact("Jewelry","mediocre",2015,4,15,-1500,7,3));
    artifactList.push_back(EgiptianArtifact("Harnedjheriotef","Jewelry","good",2012,7,8,-8000,4,9));
    artifactList.push_back(EgiptianArtifact("Hatshepsut","Vase","poor",2016,8,3,-6000,4,8));
    artifactList.push_back(EgiptianArtifact("Cleopatra","Jewelry","mediocre",2012,7,3,-7000,4,6));
    artifactList.push_back(EgiptianArtifact("Tanutamun","partialRelic","needSpecialHandling",2013,5,8,-4000,6,8));
    artifactList.push_back(EgiptianArtifact("Tutankhamen","Vase","good",2021,1,8,-1200,8,6));
    
    cout << "BEFORE SORT" << endl;
    printArtifacts(artifactList);
    cout << "AFTER SORT" << endl;
    artifactList.sort();
    printArtifacts(artifactList);

    cout << "MUSEUMS MAP" << endl;
    map<string, list<Artifact>> museums;
    museums["Singapore"].push_back(GreekArtifact("Zeus", "Jewelry", "good", 2020, 4, 6, -1500, 10, 8));
    museums["Singapore"].push_back(EgiptianArtifact("Harnedjheriotef", "Jewelry", "good", 2012, 7, 8, -8000, 4, 9));
    museums["Singapore"].push_back(GreekArtifact("Poseidon", "partialRelic", "poor", 2016, 5, 5, -4000, 5, 8));
    museums["Timisoara"].push_back(GreekArtifact("Hades", "Vase", "poor", 2019, 8, 16, -1000, 1, 6));
    museums["Timisoara"].push_back(GreekArtifact("Vase", "needSpecialHandling", 2017, 7, 15, -3000, 8, 4));
    museums["Timisoara"].push_back(EgiptianArtifact("Tutankhamen", "Vase", "good", 2021, 1, 8, -1200, 8, 6));
    museums["Rija"].push_back(GreekArtifact("Jewelry", "mediocre", 2015, 4, 15, -1500, 7, 3));
    museums["Rija"].push_back(EgiptianArtifact("Hatshepsut", "Vase", "poor", 2016, 8, 3, -6000, 4, 8));
    museums["Rija"].push_back(EgiptianArtifact("Cleopatra", "Jewelry", "mediocre", 2012, 7, 3, -7000, 4, 6));
    museums["Paris"].push_back(EgiptianArtifact("Tanutamun", "partialRelic", "needSpecialHandling", 2013, 5, 8, -4000, 6, 8));
    
    for ( auto i : museums ) {
        cout << i.first << ":" << endl;
        for ( auto j : i.second ) {
             j << cout << endl;
        }
        cout << endl;
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
