#include <iostream>
#include <limits>
#include "BooksManage.cpp"
using namespace std;

int main()
{
    int choose;  // To store the user's choice
    char k;      // To store the user's response for repeating operations
    book_manage obj; // Object of the book_manage class

    do {
        // Display the menu options
        cout << "1. Insert book\n";
        cout << "2. Delete book\n";
        cout << "3. Sort books\n";
        cout << "4. Display books\n";
        cout << "5. Destroy book list\n";
        cout << "6. Search for a book\n";
        cout << "7. Get the length of the book list\n";
        cout << "8. Update information for a certain book\n";
        cout << "Enter your choice (1-8): ";

        // Input validation for the user's choice (1-8)
        while (true) {
            cin >> choose;
            if (cin.fail() || choose < 1 || choose > 8) {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
                cout << "Enter your choice (1-8): "; // Prompt again
            } else {
                break; // Valid input, break out of the loop
            }
        }

        // Perform the operation based on the user's choice
        switch (choose) {
        case 1:
            obj.insert_book();
            break;
        case 2:
            obj.delete_book();
            break;
        case 3:
            obj.sort();
            break;
        case 4:
            obj.display();
            break;
        case 5:
            obj.destroy_list();
            break;
        case 6:
            obj.search();
            break;
        case 7:
            obj.get_length();
            break;
        case 8:
            obj.updateBook();
            break;
        default:
            cout << "Unexpected error.\n"; // This case will never happen due to the earlier validation
            break;
        }

        // Ask the user if they want to perform another operation
        cout << "Do you want another operation? (y/n): ";

        // Input validation for repeat question ('y' or 'n')
        while (true) {
            cin >> k;
            if (cin.fail() || (k != 'y' && k != 'Y' && k != 'n' && k != 'N')) {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter 'y' to continue or 'n' to exit.\n";
                cout << "Do you want another operation? (y/n): "; // Prompt again
            } else {
                break; // Valid input, break out of the loop
            }
        }

    } while (k == 'y' || k == 'Y'); // Repeat if the user enters 'y' or 'Y'

    // End of the program
    cout << "Exiting the program. Goodbye!\n";

    return 0;
}
