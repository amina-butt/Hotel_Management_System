#include "queue.h"

void queue :: design()
{
    char a = 196;
    for (int i = 0; i < 65; i++)
        cout << "|";
    cout <<  endl;
}
queue :: queue()
{
    arr = new Booking_req*[3];
    size = 0;
}
void queue :: enqueue(Booking_req* r, stack *s)
{
    if (is_full())
    { 
        Booking_req* temp = dequeue();
        s->push(temp);
    }
        int h;
        for ( h = ++size; h > 1 && r->get_priority() > arr[h / 2]->get_priority(); h = h /2)
        {
            arr[h] = arr[h / 2];    
        }
        arr[h] = r;
}
void queue :: heapify(int h)
{
    int c = h * 2;
    Booking_req *t = arr[h];
    while(c <= size)
    {   
        if( c + 1 <= size && arr[c]->get_priority() > arr[c + 1]->get_priority())
        {
            c++;
        }
        if(arr[c]->get_priority() >= t->get_priority())
        {
            arr[h] = arr[c];
            h = c;
        }
        else
        {
            break;
        }
    }
    arr[h] = t;
}
void queue :: display_queue()
{
    if (is_empty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        char t = 24;
        for (int i = 1; i <= size; i++) 
        { 
            design();
            cout << "| Name : " << left << setw(25) << setfill(' ') << arr[i]->get_name() << "Type : " << setw(10) << arr[i]->get_room_type() << "Duration : " << setw(2) << arr[i]->get_duration() << "|" << endl ;
            design();
            cout << "\t\t\t\t   " << t << endl;
        }
        cout << endl;
    }
}
Booking_req* queue :: dequeue()
{
    if (is_empty())
    {
        return nullptr;
    }
    
        Booking_req *max = arr[1];
        arr[1] = arr[size];
        arr[size] = nullptr;
        size--;
        heapify(1);
        return max;
}
bool queue :: is_full() 
{
    return size == 2;  
}
bool queue :: is_empty() 
{
    return size == 0; 
}
queue::~queue()
{
    for (int i = 1; i <= size; i++) 
    {
        delete arr[i];
    }
    delete[] arr;
}
