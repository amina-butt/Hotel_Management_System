#ifndef QUEUE_H
#define QUEUE_H
#include "Booking_req.h"
#include "stack.h"

class queue
{
    Booking_req **arr;
    int size;
    void design();
    void heapify(int h);

public:
    
    queue();
    void enqueue(Booking_req* r, stack *s);  
    void display_queue();
    Booking_req* dequeue();
    bool is_full();
    bool is_empty();
    ~queue();
};
#endif