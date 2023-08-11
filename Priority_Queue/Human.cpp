#include <iostream>
#include "Priority_Queue.h"
using namespace std;

class Human {

    public:
        string name;
        int age;
        Human(string name="", int age=0);
};



Human::Human(string name, int age) : name(name), age(age) {}

bool operator<(Human a, Human b) {return a.age < b.age ? true : false;}
bool operator>(Human a, Human b) {return a.age > b.age ? true : false;}
bool operator==(Human a, Human b) {return a.age == b.age ? true : false;}

int main() {

    Human p1("Child",5);
    Human p2("Grandfather",70);
    Human p3("Older son",20);
    Human p4("Father",40);
    Human p5("Younger son",10); 

    Priority_Queue<Human> Q;

    Q.Insert(p1);
    Q.Insert(p2);
    Q.Insert(p3);
    Q.Insert(p4);
    Q.Insert(p5);
    //Q.Print();

    while(!Q.empty()) {

        cout << "Name: " << Q.Findmax().name << ", age: " << Q.Findmax().age << endl;
        Q.ExtractMax();
    }
    return 0;
}
