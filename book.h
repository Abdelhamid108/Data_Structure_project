#ifndef BOOK_H  // Header guard to prevent multiple inclusions
#define BOOK_H

#include <iostream>
#include <limits>    // For numeric limits

using namespace std;

// Class representing a book
class book {
public:
    string name;      // Book name
    string author;    // Author name
    string category;  // Book category (e.g., fiction, non-fiction)
    int p_year;       // Publish year

    // Constructor to initialize book details
    book() {
        cout << "------------------------------------------\n";
        cout << "Enter the name of the book: ";
        cin.ignore();  // Clear input buffer for getline
        getline(cin, name);  // Allow spaces in the book name

        cout << "Enter the author of the book: ";
        getline(cin, author);  // Allow spaces in the author's name

        cout << "Enter the category of the book: ";
        getline(cin, category);  // Allow spaces in the category

        cout << "Enter the publish year (between 1000 and 2025): ";
        while (true) {  // Input validation for the publish year
            cin >> p_year;
            
            // Check if the input is a valid number within the range
            if (cin.fail() || p_year < 1000 || p_year > 2025) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a valid year between 1000 and 2025: ";
            } else {
                break;  // Exit loop if input is valid
            }
        }
        cin.ignore();  // Ignore remaining newline character in the buffer
        cout << "------------------------------------------\n";
    }

    // Method to update book data
    void update_data() {
        cout << "------------------------------------------\n";
        cout << "Enter the New name of the book: ";
        cin.ignore();  // Clear input buffer for getline
        getline(cin, name);  // Allow spaces in the book name

        cout << "Enter the New author of the book: ";
        getline(cin, author);  // Allow spaces in the author's name

        cout << "Enter the New category of the book: ";
        getline(cin, category);  // Allow spaces in the category

        cout << "Enter the New publish year (between 1000 and 2025): ";
        while (true) {  // Input validation for the publish year
            cin >> p_year;
            
            // Check if the input is a valid number within the range
            if (cin.fail() || p_year < 1000 || p_year > 2025) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a valid year between 1000 and 2025: ";
            } else {
                break;  // Exit loop if input is valid
            }
        }
        cin.ignore();  // Ignore remaining newline character in the buffer
        cout << "------------------------------------------\n";
    }

    // Method to print book details in a formatted manner
    void print() const {
        cout << "**********************************\n\n";
        cout << "This is the information for the book \n";
        cout << "Name : " << name;
        cout << "\nAuthor : " << author;
        cout << "\nCategory : " << category;
        cout << "\nPublish Year : " << p_year << endl;
        cout << "**********************************\n\n";
    }
};


#endif  // End of the header guard
