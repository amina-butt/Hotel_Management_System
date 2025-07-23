#include "stack.h"

void stack :: design()
{
    char a = 196;
    cout << "|";
    for (int i = 0; i < 83; i++)
    {
        cout << a;
    }
    cout << "|" << endl;
}
void stack :: delete_stack()
{
    Booking_req *temp = top;
    while(temp != nullptr)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
}
stack :: stack()
{
    top = nullptr;
}
void stack :: push(Booking_req *c)               //ADD BOOKING 
{
    if(top == nullptr)
    {
        top = c;
    }
    else
    {
        c->next = top;
        top = c;
    }
}
void stack :: pop()                             //REMOVE THE LATEST BOOKING 
{
    if (top == nullptr)
    {
        cout << "Nothing in stack " << endl;
    }
    else
    {
        Booking_req *temp = top;
        top = top->next;
        delete temp;

    }
}
void stack :: display_stack()                  //SHOWS THE HISTORY OF BOOKINGS
{
    Booking_req *temp = top;
    cout << "Booking History " << endl;
    while(temp != nullptr)
    {
        design();
        cout << "| Request " << " Name : " << setw(20) << left << setfill(' ')<< temp->get_name() << "Type : " << setw(10) << temp->get_room_type() << "Duration : " << setw(5) << temp->get_duration() << "Room no : " << setw(3) << setfill('0') << temp->get_room_no() << "|"<< endl;
        temp = temp->next;
        design();
    }
}
stack :: ~stack()
{
    if(top != nullptr)
    {
        delete_stack();
    }
}
