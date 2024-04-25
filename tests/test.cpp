#include "stack/stack.h"
#include <iostream>
#include <string>

class myObj {
private:
    int ID;
    std::string name;

public:
    myObj(int i, std::string n) {
        ID = i;
        name = n;
    }

    int getId() {
        return ID;
    }

    std::string getName() {
        return name;
    }

    bool operator==(const myObj& other) const {
        return (name == other.name && ID == other.ID);
    }
    
    

    bool operator!=(const myObj& other) const {
        return (name != other.name || ID != other.ID);
    }

    
    friend std::ostream& operator<< (std::ostream& os, const myObj& s)
    {
        os << s.ID << " - " << s.name;
        return os;
    }

};


int main() {
    
    Stack<int> myStack0;
    myStack0.push(10);
    myStack0.push(27);
    myStack0.push(33);
    myStack0.push(77);
    myStack0.push(65);

    myStack0.printStack();

    std::cout << "\n";
    

    Stack<myObj> myStack1;

    myObj* obj1 = new myObj(1, "Joe");
    myObj* obj2 = new myObj(2, "John");


    myStack1.push(obj1);
    myStack1.push(obj2);

    myStack1.printStack();

    std::cout << "\n";

    myObj obj = myStack1.pop();

    myStack1.printStack();

    std::cout << "\n" << obj << "\n";





    return 0;
}