#include <iostream>
#include <iomanip>
#include "DoublyLinked_list.h"
using namespace std;

/// @brief Constructor to initialize an empty doubly linked list
doubly_linkedlist::doubly_linkedlist()
{
    head = nullptr;   // Initialize head to null (no elements in the list)
    tail = nullptr;   // Initialize tail to null (no elements in the list)
    length = 0;       // Initialize length to 0 (no elements in the list)
}

/// @brief Insert a node at the beginning of the list
void doubly_linkedlist::insert_first()
{
    node* newNode = new node;  // Create a new node

    if (newNode == nullptr) {  // Check if memory allocation failed
        cout << "Memory allocation failed" << endl;
        return;
    }

    if (isEmpty()) {  // Check if the list is empty
        head = newNode;  // Set head to the new node
        tail = newNode;  // Set tail to the new node
    }
    else {
        if (isFound(newNode->data.name)) {
            cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
            delete newNode;
            return;
        }

        newNode->next = head;   // Set the new node's next to the current head
        head->prev = newNode;   // Set the current head's previous to the new node
        head = newNode;         // Move head to the new node
    }

    length++;   // Increment length of the list
    cout << "Book \"" << newNode->data.name << "\" added successfully to the beginning of the list.\n";
}

/// @brief Insert a node at the end of the list
void doubly_linkedlist::insert_last()
{
    if (isEmpty()) {  // Check if the list is empty
        insert_first();  // If empty, insert at the beginning
    }
    else {
        node* newNode = new node;  // Create a new node

        if (newNode == nullptr) {  // Check if memory allocation failed
            cout << "Memory allocation failed" << endl;
            return;
        }

        if (isFound(newNode->data.name)) {
            cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
            delete newNode;
            return;
        }

        newNode->prev = tail;  // Set the new node's previous to the current tail
        tail->next = newNode;  // Set the current tail's next to the new node
        tail = newNode;        // Move tail to the new node
        length++;  // Increment length of the list

        cout << "Book \"" << newNode->data.name << "\" added successfully to the end of the list.\n";
    }
}

/// @brief Insert a node at a specific position in the list
void doubly_linkedlist::insert_at_pos(int n)
{
    if (n <= 0 || n > length) {
        cout << "Position out of range. Valid range is [1, " << length << "].\n";
        return;
    }

    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty" << endl;
        return;
    }
    else {
        if (n == 1) {  // If position is 1, insert at the beginning
            insert_first();
        }
        else if (n == length + 1) {  // If position is the last, insert at the end
            insert_last();
        }
        else {
            node* current = head;  // Start from the head
            for (int i = 1; i < n; i++)  // Traverse the list to position n
                current = current->next;

            node* newNode = new node;  // Create a new node
            if (newNode == nullptr) {  // Check if memory allocation failed
                cout << "Memory allocation failed" << endl;
                return;
            }

            if (isFound(newNode->data.name)) {
                cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
                delete newNode;
                return;
            }

            newNode->next = current;  // Set new node's next to the current node
            newNode->prev = current->prev;  // Set new node's previous to the previous of current node
            current->prev->next = newNode;  // Set previous node's next to the new node
            current->prev = newNode;        // Set current node's previous to the new node
            length++;  // Increment length of the list

            cout << "Book \"" << newNode->data.name << "\" added successfully at position " << n << ".\n";
        }
    }
    
    
}

/// @brief Insert a node before a specific node containing the given book name
/* 
void doubly_linkedlist::insert_before()
{
    if (isEmpty()) {  // Check if the list is empty
        insert_first();  // If empty, insert at the beginning
        return;
    }
    else {
        string x;
        cout << "Enter the name of the book you want to add this book before: ";
        cin >> x;
        
        if (isFound(x)) {  // Check if the book is found in the list
            if (x == head->data.name) {  // If the book is the first in the list, insert at the beginning
                insert_first();
            }
            else {
                node* newNode = new node;  // Create a new node
                if (newNode == nullptr) {  // Check if memory allocation failed
                    cout << "Memory allocation failed" << endl;
                    return;
                }
                node* temp = head;  // Start from the head
                while (temp && temp->data.name != x) {  // Traverse the list to find the book
                    temp = temp->next;
                }
                newNode->next = temp;  // Set new node's next to the current node (book node)
                newNode->prev = temp->prev;  // Set new node's previous to the previous of the current node
                temp->prev->next = newNode;  // Set previous node's next to the new node
                temp->prev = newNode;        // Set current node's previous to the new node
                length++;  // Increment length of the list
            }
        } 
        else {
            cout << "This book is not in the list." << endl;  // If book is not found, print a message
        }
    }
}
*/

/// @brief Delete the first node in the list
void doubly_linkedlist::delete_first()
{
    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty.\n";  // Print message if the list is empty
        return;
    }
    else {
        node* delPtr;  // Create a pointer to hold the node to be deleted
        delPtr = head;  // Set the pointer to the head
        if (head == tail) {  // If there is only one node in the list
            head = tail = nullptr;  // Set both head and tail to null
        }
        else {
            head = head->next;  // Move head to the next node
            head->prev = nullptr;  // Set the new head's previous to null
        }
        delete delPtr;  // Delete the node
        length--;  // Decrement length of the list
    }  
}

/// @brief Delete the last node in the list
void doubly_linkedlist::delete_at_end()
{
    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty.\n";  // Print message if the list is empty
    }
    else {            
        node* delPtr = tail;  // Set the pointer to the tail node
        if (head == tail) {  // If there is only one node in the list
            head = tail = nullptr;  // Set both head and tail to null
        }
        else { 
            tail = tail->prev;  // Move tail to the previous node
            tail->next = nullptr;  // Set the new tail's next to null
        }
        delete delPtr;  // Delete the node
        length--;  // Decrement length of the list
    }
}

/// @brief Delete a node at a specific position
void doubly_linkedlist::delete_at_pos(int n)
{
    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty.\n";  // Print message if the list is empty
        return;
    }
    else {
        if (n <= 0 || n > length) {
            cout << "Position out of range. Valid range is [1, " << length << "].\n";
            return;
        }
        if (n == 1) {  // If position is 1, delete the first node
            delete_first();
        }
        else if (n == length) {  // If position is the last, delete the last node
            delete_at_end();
        }
        else {
            node* delPtr = head;  // Set pointer to the head
            for (int i = 1; i < n; i++) {  // Traverse the list to position n
                delPtr = delPtr->next;
            }
            delPtr->prev->next = delPtr->next;  // Link previous node's next to the node after the current node
            delPtr->next->prev = delPtr->prev;  // Link next node's previous to the node before the current node
            delete delPtr;  // Delete the node
            length--;  // Decrement length of the list
        }
    }
}

void doubly_linkedlist::update_book(const string& book_name) 
{
    if (isEmpty()) {
        cout << "The list is empty. No book to update.\n";
        return;
    }
    node* current = head;
    while (current) {
        if (current->data.name == book_name) {
            cout << "Book found: \n";
            cout << "Name: " << current->data.name 
                 << ", Author: " << current->data.author 
                 << ", Category: " << current->data.category 
                 << ", Publish Year: " << current->data.p_year << "\n";

            // Update the book's details
            current->data.update_data();

            cout << "Book updated successfully!\n";
            return;
        }
        current = current->next;
    }
    cout << "Book with name \"" << book_name << "\" not found in the list.\n";
}

/// @brief Delete a specific book by name
void doubly_linkedlist::delete_book(const string& name)
{
    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty.\n";  // Print message if the list is empty
        return;
    }
    else {
        node* delPtr = head;  // Create pointer to traverse the list
        if (isFound(name)) {  // Check if the book is found
            if (head->data.name == name) {  // If the book is the first in the list, delete the first node
                delete_first();
            }
            else if (tail->data.name == name) {  // If the book is the last in the list, delete the last node
                delete_at_end();
            }
            else {
                while (delPtr->data.name != name) {  // Traverse the list to find the book
                    delPtr = delPtr->next;
                }
                delPtr->prev->next = delPtr->next;  // Link previous node's next to the node after the current node
                delPtr->next->prev = delPtr->prev;  // Link next node's previous to the node before the current node
                delete delPtr;  // Delete the node
            }
            length--;  // Decrement length of the list
        }
        else {
            cout << "This book is not in the list.\n";  // If book is not found, print message
        }
    }
}

/// @brief Display the list from head to tail
void doubly_linkedlist::display_Forward()
{
    if (isEmpty())  // Check if the list is empty
    {
        cout << "The list is empty\n";  // Print message if the list is empty
        return;
    }

    node* current = head;  // Start from the head
    cout << left << setw(10) << "No." 
         << setw(30) << "Book Name" 
         << setw(30) << "Author" 
         << setw(30) << "Publication Year" 
         << setw(30) << "Category" 
         << endl;
    cout << "---------------------------------------------------------------" << endl;

    int i = 1;  // For printing the number of the book
    while (current)
    {
        cout << left << setw(10) << i  // Display the number of the book
             << setw(30) << current->data.name         // Align the book name
             << setw(30) << current->data.author       // Align the author's name
             << setw(30) << current->data.p_year      // Align the publication year
             << setw(30) << current->data.category    // Align the category
             << endl;
        
        current = current->next;  // Move to the next node
        i++;
    }
}

/// @brief Display the list from tail to head
void doubly_linkedlist::display_backward()
{
    if (isEmpty())  // Check if the list is empty
    {
        cout << "The list is empty\n";  // Print message if the list is empty
        return;
    }

    cout << left << setw(10) << "No." 
         << setw(30) << "Book Name" 
         << setw(30) << "Author" 
         << setw(30) << "Publication Year" 
         << setw(30) << "Category" 
         << endl;
    cout << "---------------------------------------------------------------" << endl;

    node* current = tail;  // Start from the tail
    int i = 1;  // For printing the number of the book
    while (current)
    {
        cout << left << setw(10) << i  // Display the number of the book
             << setw(30) << current->data.name         // Align the book name
             << setw(30) << current->data.author       // Align the author's name
             << setw(30) << current->data.p_year      // Align the publication year
             << setw(30) << current->data.category    // Align the category
             << endl;

        current = current->prev;  // Move to the previous node
        i++;  // Increment the book number
    }
}

/// @brief Search for a book by name and print its details
void doubly_linkedlist::search_Book(const string& name)
{
    node* temp = head;  // Start from the head
    bool found = false;  // Flag to indicate whether the book is found

    while (temp)
    {
        if (temp->data.name == name)  // If the book's name matches
        {
            temp->data.print();  // Print the book's data
            found = true;  // Set found flag to true
            break;  // Exit the loop after finding the book
        }
        temp = temp->next;  // Move to the next node
    }

    if (!found)
        cout << "Book not found\n";  // Print message if book is not found
}

/// @brief Check if the list is empty
bool doubly_linkedlist::isEmpty()
{
    return (head == nullptr);  // Return true if head is null (list is empty)
}

/// @brief Check if a book is found in the list by its name
bool doubly_linkedlist::isFound(const string& name)
{
    node* temp = head;  // Start from the head

    while (temp)
    {
        if (temp->data.name == name)  // If the book's name matches
        {
            return true;  // Return true if found
        }
        temp = temp->next;  // Move to the next node
    }

    return false;  // Return false if not found
}

/// @brief Display the number of books in the list
void doubly_linkedlist::get_length()
{
    cout << "The list contains " << length << " books" << endl;  // Print the number of books
}

/// @brief Sort the list alphabetically by book name
void doubly_linkedlist::sort()
{
    if (isEmpty() || length == 1) return;  // Return if the list is empty or has only one book

    for (node* i = head; i->next != nullptr; i = i->next)  // Outer loop for sorting
    {
        for (node* j = i->next; j != nullptr; j = j->next)  // Inner loop for comparison
        {
            if (i->data.name > j->data.name)  // If the current book's name is greater, swap
            {
                swap(i->data, j->data);
            }
        }
    }
}

/// @brief Free all nodes in the list and reset to empty
void doubly_linkedlist::freeList()
{
    if (isEmpty())  // Check if the list is empty
    {
        cout << "The list is already empty" << endl;  // Print message if the list is already empty
        return;
    }

    node* temp;  // Create pointer for deleting nodes
    while (head)  // While there are nodes to delete
    {
        temp = head;  // Set temp to the current head
        head = head->next;  // Move head to the next node
        delete temp;  // Delete the current node
    }

    tail = nullptr;  // Set tail to null
    length = 0;  // Set length to 0
}

/// @brief Destructor to free the list when it is no longer needed
doubly_linkedlist::~doubly_linkedlist()
{
    freeList();  // Call freeList to delete all nodes
}