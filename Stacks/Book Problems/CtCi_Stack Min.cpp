#include<iostream>
#include<vector>
#include<limits.h>

struct stackNode {
public:    
    stackNode():min(-100001) {};
    int data;
    int min;
};

class stack {

    private:

    std::vector<stackNode> stackVec;
    
    public:
    
    stack()
    {}

    int top();
    bool empty();
    int size();
    int min();

    // modifiers
    void push( int );
    void pop();

};

int stack::min() {
    if ( stackVec.empty() ) return -1;

    return stackVec.back().min;
}

int stack::top() {    

    if ( stackVec.empty() )
        return -1;

    //stackNode tmpNode =  ;
    return stackVec.back().data ;
}

bool stack::empty() {

    if ( stackVec.empty() )
        return true;
    
    return false;
}

int stack::size() {
    return stackVec.size();
}

void stack::push ( int newData ) {
    stackNode tmpNode;
    tmpNode.data = newData;
    tmpNode.min < newData ? tmpNode.min = newData : tmpNode.min ;
    stackVec.push_back( tmpNode );
}

void stack::pop() {
    if ( stackVec.empty() ) return;
    
    stackVec.pop_back();
}

int main() { 

    stack mystack;

    int choice = 1, input;
    std::cout   << "\n"
                <<"1: top "
                <<"2: push "
                <<"3: pop "
                <<"4: empty "
                <<"5: size "
                <<"6: min \n";

    while ( choice ) {
        
        std::cin >> input;
        
        switch(input)   {

            case 1: {
                std::cout << "\ndata on top :" << mystack.top() << "\n";
                break;
            }

            case 2: {
                int value;
                std::cout << "\nPUSH : ";
                std::cin >> value;  
                mystack.push( value );
                std::cout  << "\n";
                break;
            }
            
            case 3: {
                mystack.pop();
                std::cout << "\n";
                break;
            }

            case 4: {
                std::cout << "\n is Empty : " << std::boolalpha << mystack.empty() << "\n";
                break;
            }

            case 5: {
                std::cout << "\nsize :" <<  mystack.size() << "\n";
                break;
            }

            case 6: {
                std::cout << "\nmin :" <<  mystack.min() << "\n";
                break;
            }

        }

        std::cout << "continue ? ";
        std::cin >> choice;
        
    }
    
    return 0;
}