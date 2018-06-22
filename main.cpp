#include "stack.h"

// task
// Read from txt file and put every symbol in stack except *.
void decrypt(const char* filename)
{
    ifstream ifs;
    ifs.open(filename, ios::in);
    if(!ifs.is_open())
    {
        cerr << "Could not open file." << endl;
        return;
    }

    Stack<char> input;
    char symbol;
    while(true)
    {
        ifs >> symbol;
        if(symbol != '*')
        {
            if(ifs.eof())
            {
                break;
            }

            input.push(symbol);
//            input.push(' ');
        }
        else if(symbol == '*')
        {
            if(ifs.eof())
            {
                break;
            }
            cout << input.top();
            input.pop();
        }
    }
}

int main()
{
    // task
    const char* filename = "Text File";
    decrypt(filename);

    /** Creating a stack of int type, in this case we call the default constructor. */
    Stack<int> myStack;

    /** adding elements into stack */
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    /** print stack */
    cout << "Stack elements: ";
    myStack.print();
    cout << endl;

    /** Creating a new stack with the same values as the one above, in this case we call the Copy Constructor. */
    Stack<int> copyStack(myStack);

    /** print copied stack */
    cout << "Copied stack elements: ";
    copyStack.print();
    cout << endl;

    /** Creating new stack with assignment operator, almost the same as the Copy Constructor */
    Stack<int> assignmentStack = copyStack;

    /** Print assignment stack */
    cout << "Assignment stack elements: ";
    assignmentStack.print();
    cout << endl;

    /** top element of stack */
    cout << "Stack top element: " << assignmentStack.top() << endl;

    /** remove element of stack, in this case we remove 5 */
    assignmentStack.pop();
    cout << "New stack elements: ";
    assignmentStack.print();
    cout << endl;

    return 0;
}
