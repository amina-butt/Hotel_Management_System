#ifndef FLOOR_H
#define FLOOR_H
#include "Room.h"

class Floor 
{
    int no_of_rooms;
    int floor_no;
    Room* rooms;
    Floor* nextt;

    void set_room_id_type(int f_n, int single = 10, int doublee = 10, int suit = 10);

public:
    Floor(int f_n, bool choice) ;
    void type_available_rooms(string t);
    void available_rooms();
    bool process_booking_request(Booking_req* req , int f);

    void get_floor_rooms();
    int get_floor_no();
    Floor* get_nextt() ;
    void set_nextt(Floor* f);
    ~Floor();
};
#endif
