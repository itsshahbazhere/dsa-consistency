#include<iostream>
using namespace std;

// Base class
class Person {
public:
    string name;

    void introduce() {
        cout << "This is hierarchical inheritance"<< endl;
        cout <<" This all is called hybrid inheritance"<<endl;
    }
};


class Student : public Person {
public:
    int rollNo;
};

class Teacher : public Person {
public:
    string subject;
};

class TeachingAssistant : public Student, public Teacher {
public:
    string department;

    void displayInfo() {
        cout<<"this is mutiple inheritance"<<endl;
    }
};

int main() {

    
    TeachingAssistant ta;
    ta.displayInfo();
    ta.Student::introduce(); //this is called inheritance ambiguity -- compiler confuse introduce() function call from which class so we use :: (scope resolution ooperator)

    return 0;
}
