#ifndef BOOKING_REQ_H
#define BOOKING_REQ_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iomanip>
using  namespace std;

class Booking_req 
{
    string name;
    string  room_type;
    int duration;
    int room_no;
    bool priority;
    
public:

    Booking_req *next;
    Booking_req();

    string get_name();                                          
    string get_room_type();
    bool get_priority();
    int get_duration();
    int get_room_no();
    void set_room_no(int f, int r);
};

#endif