// Tema4_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct node {
    node<T>* next;
    T data;
};

template<class T>
class MyContainer {
private:
    node<T>* first;
    unsigned int count;
public:
    
    MyContainer<T>() {
        first = NULL;
        count = 0;
    }
    void addEnd(T obj) {
        if (!first) {
            first = new node<T>;
            first->data = obj;
            first->next = NULL;
            count++;
            return;
        }
        node<T>* it = first;
        while (it->next) {
            it = it->next;
        }
        it->next = new node<T>;
        it->next->data = obj;
        it->next->next = NULL;
        count++;
    }
    void addBegin(T obj) {
        if (!first) {
            first = new node<T>;
            first->data = obj;
            first->next = NULL;
            count++;
            return;
        }
        node<T>* it = new node<T>;
        it->next = first;
        it->data = obj;
        first = it;
        count++;
    }
    void removeLast() {
        if (first) {
            node<T>* it = first;
            while (it->next->next) {
                it = it->next;
            }
            it->next = NULL;
            count--;
        }
    }
    void removeFirst() {
        if (first) {
            first = first->next;
            count--;
        }   
    }
};



class Student {
private:
    string name;
    string university;
    unsigned int age;
public:
    string getName() {
        return this->name;
    }
    string getUniversity() {
        return this->university;
    }
    unsigned int getAge() {
        return this->age;
    }
    Student(string name, string university, unsigned int age) {
        this->name = name;
        this->university = university;
        this->age = age;
    }
    
    void display() {
        cout << "Name: " << this->name << " University: " << this->university << " Age: " << this->age << endl;
    }
};

bool bigAge(Student stud) {
    if (stud.getAge() > 22) {
        return true;
    }
    return false;
}

bool otherUni(Student stud) {
    if (stud.getUniversity() == "POLI") {
        return true;
    }
    return false;
}

int main()
{
    vector<Student> container;
    container.push_back(Student("Ion", "UVT", 20));
    container.push_back(Student("Alex", "POLI", 22));
    container.push_back(Student("Carina", "POLI", 20));
    container.push_back(Student("Crivet", "UVT", 25));
    container.push_back(Student("Banino", "UVT", 26));
    container.push_back(Student("Beto", "TIBISCUS", 22));
    container.push_back(Student("Alpha", "TIBISCUS", 21));
    container.push_back(Student("Omega", "TIBISCUS", 18));
    container.push_back(Student("Chitara", "TIBISCUS", 19));
    for (auto i : container) {
        i.display();
    }
    cout << endl << "find_if (greater than 22 years old)" << endl;
    vector<Student>::iterator stud = find_if(container.begin(), container.end(), bigAge);
    stud->display();

    cout << endl << "remove_if (greater than 22 years old)" << endl;
    container.erase(remove_if(container.begin(), container.end(), otherUni),container.end());
    for (auto i : container) {
        i.display();
    }
    MyContainer<string> test;
    test.addBegin("sss");
    test.addBegin("aaa");
    test.addBegin("aaa2");
    test.addBegin("aaa3");
    /*test.removeLast();*/
    test.removeFirst();
    test.removeLast();

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
