#ifndef STACK_H
#define STACK_H
#include "Booking_req.h"

class stack
{
    Booking_req *top;

    void delete_stack();
    void design();

public:

    stack();
    void push(Booking_req *c);
    void pop();
    void display_stack();
    ~stack();

};
#endif