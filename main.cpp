#include "stack.h"

// task
// Read from txt file and put every symbol in stack except *.
void decrypt(const char* filename)
{
    std::ifstream ifs;
    ifs.open(filename, std::ios::in);
    if(!ifs.is_open())
    {
        std::cerr << "Could not open file." << std::endl;
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
        }
        else if(symbol == '*')
        {
            if(ifs.eof())
            {
                break;
            }
            std::cout << input.top();
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
    std::cout << "Stack elements: ";
    myStack.print();
    std::cout << std::endl;

    /** Creating a new stack with the same values as the one above, in this case we call the Copy Constructor. */
    Stack<int> copyStack(myStack);

    /** print copied stack */
    std::cout << "Copied stack elements: ";
    copyStack.print();
    std::cout << std::endl;

    /** Creating new stack with assignment operator, almost the same as the Copy Constructor */
    Stack<int> assignmentStack = copyStack;

    /** Print assignment stack */
    std::cout << "Assignment stack elements: ";
    assignmentStack.print();
    std::cout << std::endl;

    /** top element of stack */
    std::cout << "Stack top element: " << assignmentStack.top() << std::endl;

    /** remove element of stack, in this case we remove 5 */
    assignmentStack.pop();
    std::cout << "New stack elements: ";
    assignmentStack.print();
    std::cout << std::endl;

    return 0;
}
