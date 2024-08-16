#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    string gender;
    int age;

    Student(string name, string gender, int age)
    {
        this->name = name; 
        this->gender = gender;
        this->age = age;
    }

    string toString() {
        return "name: " + name + " gender: " + gender + " age: " + to_string(age);
    }
};

int main()
{
    Student* std = new Student("Anas", "Male", 20);
    cout << std->toString() << endl;

    delete std; // Free the allocated memory
    return 0;
}
