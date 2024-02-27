/**********************************************************************************************
 *
 * CIS269 - Data Structures
 * Pima College - Spring 2024
 * Chapter 6 - Pg 464 - Ex #28
 * "coffee_shop.cpp"
 *
 * This program uses a switch-menu to operate a coffee shop, offering transactions for 3 
 * different sizes, and functions to track the cups sold in each size, total ounces of coffee
 * sold, and total dollar amount made.
 *
 * Author: Sean Castle
 *
**********************************************************************************************/

#include<iostream> // Preprocessing directives
#include<iomanip>

using namespace std;

// Function prototypes
void showInstructions();
void sellCoffee(int, int, int&, int&, int&, double&, double&);
void showCupsSold(int, int, int);
void showCoffeeSold(double);
void showMoneyMade(double);

// Global constants
const int SMALL_SIZE = 9;
const int MEDIUM_SIZE = 12;
const int LARGE_SIZE = 15;

const double SMALL_COST = 1.75;
const double MEDIUM_COST = 1.90;
const double LARGE_COST = 2.00;

// Main
int main() {
    // Initialize local variables
    int input = 0;
    int size = 0;
    int quantity = 0;
    int smallCupsSold = 0;
    int mediumCupsSold = 0;
    int largeCupsSold = 0;
    double totalCoffeeSold = 0.00;
    double totalMoneyMade = 0.00;

    do {                            // Prompt menu choices until user quits
        showInstructions();
        
        // Input
        cout << "\nEnter your choice: ";
        cin >> input;

        switch (input) {
        case 1:
        case 2:
        case 3:                             
            cout << "Enter the quantity: ";
            cin >> quantity;                // Processing
            sellCoffee(input, quantity, smallCupsSold, mediumCupsSold, largeCupsSold, totalCoffeeSold, totalMoneyMade);
            break;
        case 4:                             // Output
            showCupsSold(smallCupsSold, mediumCupsSold, largeCupsSold);
            break;
        case 5:
            showCoffeeSold(totalCoffeeSold);
            break;
        case 6:
            showMoneyMade(totalMoneyMade);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice entered. Please try again." << endl;
        }
    } while (input != 0);

    return 0;
}// End main


// --- Functions ---

// Display instructions to the user
void showInstructions() {
    cout << fixed << setprecision(2);		// Fixed-point formatting
    cout << "\nWelcome to Jason's coffee shop!" << endl;
    cout << "Small  (" << SMALL_SIZE << "oz):  $" << SMALL_COST << endl;
    cout << "Medium (" << MEDIUM_SIZE << "oz): $" << MEDIUM_COST << endl;
    cout << "Large  (" << LARGE_SIZE << "oz):  $" << LARGE_COST << endl;
    cout << "\nTo process a sale: enter the size (1 = small, 2 = medium, 3 = large) and the quantity." << endl;
    cout << "To view the number of cups sold, enter '4'." << endl;
    cout << "To view the total ounces of coffee sold, enter '5'." << endl;
    cout << "To view the total money made, enter '6'." << endl;
    cout << "To quit the program, enter '0'." << endl;
}

// Process user input to update variables for coffee sold
void sellCoffee(int size, int quantity, int& smallCupsSold, int& mediumCupsSold, int& largeCupsSold, double& totalCoffeeSold, double& totalMoneyMade) {
    switch (size) {
    case 1:
        smallCupsSold += quantity;
        totalCoffeeSold += SMALL_SIZE * quantity;
        totalMoneyMade += SMALL_COST * quantity;
        break;
    case 2:
        mediumCupsSold += quantity;
        totalCoffeeSold += MEDIUM_SIZE * quantity;
        totalMoneyMade += MEDIUM_COST * quantity;
        break;
    case 3:
        largeCupsSold += quantity;
        totalCoffeeSold += LARGE_SIZE * quantity;
        totalMoneyMade += LARGE_COST * quantity;
        break;
    default:
        cout << "Invalid size entered. Please try again." << endl;
    }
}

// Display outputs...
void showCupsSold(int smallCupsSold, int mediumCupsSold, int largeCupsSold) {
    cout << "\nSmall cups sold: " << smallCupsSold << endl;
    cout << "Medium cups sold: " << mediumCupsSold << endl;
    cout << "Large cups sold: " << largeCupsSold << endl;
}

void showCoffeeSold(double totalCoffeeSold) {
    cout << "\nTotal coffee sold: " << totalCoffeeSold << " oz." << endl;
}

void showMoneyMade(double totalMoneyMade) {
    cout << "\nTotal money made: $" << totalMoneyMade << endl;
}
