#include <iostream>
# include<limits>
int main()
{
    int userInput;

    std::cout << "Enter an integer: ";

    // Try to read an integer
    std::cin >> userInput;

    // Check if the input was successful (an integer)
    if (std::cin.fail())
    {
        std::cin.clear();                                                   // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter an integer." << std::endl;
    }
    else
    {
        // Input is an integer
        std::cout << "You entered: " << userInput << std::endl;
    }

    return 0;
}
