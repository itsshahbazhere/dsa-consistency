#include<iostream>
using namespace std;

// Single parent class
class Parent {
public:
    string name;
    int age;

    void commonFunction() {
        cout << "This is from the parent class" << endl;
    }
};

// Child1 inherits from Parent
class Child1 : public Parent {
public:
    string skill;
};

// Child2 also inherits from Parent
class Child2 : public Parent {
public:
    string hobby;
};

int main() {
    Child1 c1;
    c1.name = "Alice";
    c1.skill = "Coding";
    c1.commonFunction();  // from Parent
    cout << c1.name << " - " << c1.skill << endl;

    Child2 c2;
    c2.name = "Bob";
    c2.hobby = "Painting";
    c2.commonFunction();  // from Parent
    cout << c2.name << " - " << c2.hobby << endl;

    return 0;
}
