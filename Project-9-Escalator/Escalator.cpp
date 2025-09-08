#include <iostream>
using namespace std;

class StackDes {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void peek() = 0;      
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void display() = 0;
    virtual ~StackDes() {} 
};

class Stack : public StackDes { 
    private:
        static const int MAX = 5;  
        int arr[MAX];              
        int topIndex;              

    public:
    
        Stack() {
            topIndex = -1;
        }

        void push(int value) {  
            if (isFull()) {
                cout << "Stack is full. Cannot push " << value << endl;
            } else {
                arr[++topIndex] = value;
                cout << value << " pushed into stack." << endl;
            }
        }

        void pop() {  
            if (isEmpty()) {
                cout << "Stack is empty. Nothing to pop." << endl;
            } else {
                cout << arr[topIndex--] << " popped from stack." << endl;
            }
        }

        void peek() {  
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Top element: " << arr[topIndex] << endl;
            }
        }

        bool isEmpty() {  
            return topIndex == -1;
        }

        bool isFull() {   
            return topIndex == MAX - 1;
        }

        void display() {  
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack elements : ";
                for (int i = topIndex; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Stack s;   
    int choice, value;

    do {
        cout << endl;
        cout << "--- Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;   
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display Stack" << endl;
        cout << "0. Exit" << endl;
        
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 6:
            s.display();
            break;

        case 0:
            cout << "Exit From Program..." << endl;
            break;

        default:
            cout << "Invalid Choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
