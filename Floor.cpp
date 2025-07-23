#include "Floor.h"


void Floor ::set_room_id_type(int f_n, int single , int doublee , int suit ) 
{
    no_of_rooms = single + doublee + suit;
    rooms = new Room[no_of_rooms];
    int index = 0;

    for (int i = 0; i < no_of_rooms; i++) 
    {
        if (single > 0) 
        {
            rooms[i].set_type("Single");
            single--;
        } 
        else if (doublee > 0) 
        {
            rooms[i].set_type("Double") ;
            doublee--;
        } 
        else 
        {
            rooms[i].set_type("Suit") ;
            suit--;
        }
        rooms[i].set_ID(f_n * 100 + i) ; 
    }
    floor_no = f_n;
}

Floor :: Floor(int f_n, bool choice) : nextt(nullptr)
{
    int single = 4, doublee = 3, suit = 3;
    if (choice) 
    {
        do {
            cout << "Enter the number of single rooms: ";
            cin >> single;
            cout << "Enter the number of double rooms: ";
            cin >> doublee;
            cout << "Enter the number of suite rooms: ";
            cin >> suit;
            cout << endl;

        } while (single < 0 || doublee < 0 || suit < 0 || (single == 0 && doublee == 0 && suit == 0) && (single + doublee + suit > 99));
    }
    set_room_id_type(f_n, single, doublee, suit);
}

void Floor :: type_available_rooms(string t) 
{
    cout << t << " rooms available on floor " << floor_no << endl;
    for (int i = 0; i < no_of_rooms; i++) 
    {
        if (rooms[i].get_status() == "Ready" && rooms[i].get_type() == t) 
        {
            cout << "Room: " << setw(3) << setfill('0') << rooms[i].get_ID() << endl;
        }
    }
}

void Floor :: available_rooms() 
{
    cout << "Available rooms on floor " << floor_no  << endl;
    for (int i = 0; i < no_of_rooms; i++) 
    {
        if (rooms[i].get_status() == "Ready") 
        {
            cout << "Room: " << setw(3) << setfill('0') << rooms[i].get_ID() << endl;
        }
    }
}

void Floor :: get_floor_rooms() 
{
    for (int i = 0; i < no_of_rooms; i++) 
    {
        rooms[i].get_room_info(floor_no);
        cout << endl;
    }
}
bool Floor :: process_booking_request(Booking_req* req , int f) 
{
    for (int i = 0; i < no_of_rooms; i++) 
    {
        if (rooms[i].get_type() == req->get_room_type() && rooms[i].get_status() == "Ready") 
        {
            req->set_room_no(f, i);
            rooms[i].book_room(req );
            
            return 0;
        }
    }
    return 1;
}

int Floor :: get_floor_no() 
{
    return floor_no;
}
Floor* Floor :: get_nextt() 
{
    return nextt;
}
void Floor :: set_nextt(Floor* f) 
{
    nextt = f;
}
Floor :: ~Floor() {
    delete[] rooms;
}
