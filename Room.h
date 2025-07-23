#ifndef ROOM_H
#define ROOM_H
#include "Booking_req.h"

class Room 
{
    string type;
    int ID;
    string status;

public:

    Room();
    void get_room_info(int fl);
    void book_room(Booking_req* req );
    void release_room();
    void set_type(string s);

    string get_type();
    void set_ID(int i);
    int get_ID();
    string get_status();

};
#endif