#include "Room.h"

Room :: Room() 
{
    status = "Ready";
}
void Room :: get_room_info(int fl) 
{
    cout << "Room number " << setw(3) << setfill('0') << ID << " status" << endl;
    cout << "Room type   : " << type << endl;
    cout << "Status      : " << status << endl;
}
void Room :: book_room(Booking_req* req ) 
{
    status = "Booked";
    cout << "Room no " << setw(3) << setfill('0') << req->get_room_no()  << " of type " << type << " is  for booked by " << req->get_name() << ".\n";
}
void Room :: release_room() 
{
    status = "Ready";
}
void Room :: set_type(string s)
{
    type = s;
}
string Room :: get_type()
{
    return type;
}
void Room :: set_ID(int i)
{
    ID = i;
}
int Room :: get_ID()
{
    return ID;
}
string Room :: get_status()
{
    return status;
}
