# ifndef Books_Manage_H
# define Books_Manage_H
# include <iostream>
# include "DoublyLinked_list.cpp"
# include "book.h"

using namespace std;



class book_manage
{
    public:
    void insert_book();
    void delete_book ();
    void search();
    void sort();
    void display();
    void destroy_list();
    void get_length ();
    void updateBook();
    doubly_linkedlist library;
};



#endif