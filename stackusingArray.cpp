#include<iostream>
using namespace std;

#define INVALID_CAPACITY 1
#define INVALID_STACK 2
#define OVERFLOW_STACK 3
#define STACK_UNDERFLOW 4

class stack
{
    private:
        int top;
        int capacity;
        int *ptr;
    public:
        stack(int);
        bool isFull();
        bool isEmpty();
        void push(int);
        int peek();
        int pop();
        ~stack();
};

stack::stack(int cap)
{
    ptr=nullptr;
    if(cap<1)
        throw INVALID_CAPACITY;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}

stack::~stack()
{
    delete []ptr;
}

void stack::push(int data)
{  
    if(ptr==nullptr)
        throw INVALID_STACK;
    if(top>capacity)
        throw OVERFLOW_STACK;
    if(isFull( ))
        throw OVERFLOW_STACK;
    ptr[++top]=data;

}

bool stack::isFull()
{
    if(ptr==nullptr)
        throw INVALID_STACK;
    return top+1==capacity;
    
}

bool stack::isEmpty()
{
    if(ptr==nullptr)
        throw INVALID_STACK;
    return top==-1;
    
}

int stack::peek()
{
    if(ptr==nullptr)
        throw INVALID_STACK;
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return ptr[top];   
}

int stack::pop()
{
    if(ptr==nullptr)
        throw INVALID_STACK;
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return ptr[top--];   
}

int main()
{
    int capacity;
    cout << "Enter stack capacity: ";
    cin >> capacity;

    try
    {
        stack s(capacity);
        int choice, value;

        do
        {
            cout << "\nStack Operations Menu:\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Peek\n";
            cout << "4. Check if Stack is Full\n";
            cout << "5. Check if Stack is Empty\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                try
                {
                    s.push(value);
                    cout << "Pushed " << value << " onto the stack.\n";
                }
                catch (int e)
                {
                    cout << "Error: Stack Overflow!\n";
                }
                break;

            case 2:
                try
                {
                    value = s.pop();
                    cout << "Popped " << value << " from the stack.\n";
                }
                catch (int e)
                {
                    cout << "Error: Stack Underflow!\n";
                }
                break;

            case 3:
                try
                {
                    value = s.peek();
                    cout << "Top element is " << value << ".\n";
                }
                catch (int e)
                {
                    cout << "Error: Stack Underflow!\n";
                }
                break;

            case 4:
                cout << (s.isFull() ? "Stack is Full.\n" : "Stack is not Full.\n");
                break;

            case 5:
                cout << (s.isEmpty() ? "Stack is Empty.\n" : "Stack is not Empty.\n");
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 6);
    }
    catch (int e)
    {
        if (e == INVALID_CAPACITY)
            cout << "Error: Invalid Stack Capacity!\n";
    }

    return 0;
}