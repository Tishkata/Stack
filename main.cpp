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

            input.Push(symbol);
//            input.push(' ');
        }
        else if(symbol == '*')
        {
            if(ifs.eof())
            {
                break;
            }
            cout << input.Top();
            input.Pop();
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
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);

    /** print stack */
    cout << "Stack elements: ";
    myStack.Print();
    cout << endl;

    /** Creating a new stack with the same values as the one above, in this case we call the Copy Constructor. */
    Stack<int> copyStack(myStack);

    /** print copied stack */
    cout << "Copied stack elements: ";
    copyStack.Print();
    cout << endl;

    /** Creating new stack with assignment operator, almost the same as the Copy Constructor */
    Stack<int> assignmentStack = copyStack;

    /** Print assignment stack */
    cout << "Assignment stack elements: ";
    assignmentStack.Print();
    cout << endl;

    /** top element of stack */
    cout << "Stack top element: " << assignmentStack.Top() << endl;

    /** remove element of stack, in this case we remove 5 */
    assignmentStack.Pop();
    cout << "New stack elements: ";
    assignmentStack.Print();
    cout << endl;

    return 0;
}
