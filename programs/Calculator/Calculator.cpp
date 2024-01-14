#include <iostream>
#include <cmath>

int main()
{
    //Variables to allow the user to choose math operation and numbers
    char op;
    double num1, num2;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> num1>>num2;
    std::cout << "Choose an operation: \"+, -, *, /, ^, %\"" << std::endl;
    std::cin >> op;

    //Switch statement to choose which operation to use, depending on what user sets op equal to
    switch(op)
    {
        //Addition
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        //Subtraction
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        //Multiplication
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        //Division
        case '/':
            if (num2 != 0)
                std::cout << num1 << " / " << num2 << " = " << num1 / num2;
            else
                //Division by 0 is undefined
                std::cout << num1 << " / " << num2 << " = undefined";
            break;
        //Power
        case '^':
            std::cout << num1 << " ^ " << num2 << " = " << pow(num1, num2);
            break;
        //Percentage
        case '%':
            std::cout << num2 << "% of " << num1 << " = " << num1 * (num2 / 100);
            break;
        default:
            //Prints this if op is not equal to any of the previous cases
            std::cout << "Unknown operator. Please try again.";
    }

    return 0;
}
