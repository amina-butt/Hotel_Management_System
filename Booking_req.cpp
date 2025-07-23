#include "Booking_req.h"

Booking_req::Booking_req() : next(nullptr)
{
    string code;
        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the priority code: ";
        getline(cin, code); 
        if (code == "VIP_Galaxy")
        {
            priority = 1;
        }
        else
        {
            priority = 0;
        }
        do
        {
            cout << "Enter the type of room you require (Single, Double or Suit): ";
            cin >> room_type;
            if (!(room_type == "Single" || room_type == "Double" || room_type == "Suit"))
            {
                cout << "Incorrect room type. Please try again." << endl;
            }
        } while (!(room_type == "Single" || room_type == "Double" || room_type == "Suit"));
        do
        {
            cout << "Enter the number of nights you want to stay: ";
            cin >> duration;
            if (duration > 30 || duration <= 0)
            {
                cout << "You can book a room for 1 to 30 nights only." << endl;
            }
        } while (duration > 30 || duration <= 0);
}
string Booking_req :: get_name()                          
{                                          
    return name;                           
}                                          
string Booking_req :: get_room_type()
{
    return room_type;
}
bool Booking_req :: get_priority()
{
    return priority;
}
int Booking_req :: get_duration()
{
    return duration;
}
int Booking_req :: get_room_no()
{
    return room_no;
}
void Booking_req :: set_room_no(int f, int r)
{
    room_no = ((f * 100) + r);
}


