#ifndef HOTEL_H
#define HOTEL_
#include "Booking_req.h"
#include "stack.h"
#include "queue.h"
#include "Floor.h"

class Hotel 
{
    Floor* floors;
    int no_of_floors;
    stack *history;
    queue *request;

    void insert_floor(Floor* new_floor);  
    void display_floors(Floor* current);
    void delete_all_floors(Floor* current);
    
public:

    Hotel(int i_f = 5);
    void add_floor();
    void display_all_floor_rooms();
    void _booking_request();
    void show_booking_history();
    void show_booking_requests();
    void cancel_request();
    void all_available_rooms();
    void type_available_rooms_on_floors(string t);
    ~Hotel();

};
#endif