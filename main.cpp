#include "CornerGrocer.h"

// Program entry point.
int main()
{
    // Create a CornerGrocer object.
    // The constructor automatically loads the input file
    // and creates the frequency.dat backup file.
    CornerGrocer grocery;

    // Display the menu until the user chooses to exit.
    grocery.DisplayMenu();

    // End the program successfully.
    return 0;
}