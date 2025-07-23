#include "Hotel.h"
#include "start.h"


void Hotel :: insert_floor(Floor* new_floor) 
{
    if (floors == nullptr) 
    {
        floors = new_floor;;
    }
    else
    {
        Floor *temp = floors;
        while(temp->get_nextt() != nullptr)
        {
            temp = temp->get_nextt();
        }
        temp->set_nextt(new_floor);
    }
}    
void Hotel :: display_floors(Floor* current) 
{
    if (current) 
    {
        cout << "Floor " << current->get_floor_no() << " has rooms:" << endl;
        current->get_floor_rooms();
        display_floors(current->get_nextt());
    }
}
void Hotel :: delete_all_floors(Floor* current) 
{
    if (current) 
    {
        delete_all_floors(current->get_nextt());
        delete current;
    }
}
Hotel :: Hotel(int i_f) 
{

    floors = nullptr;
    no_of_floors = i_f;
    for (int i = 0; i < i_f; i++) 
    {
        Floor *new_f = new Floor(i, 0);
        insert_floor(new_f);

    }
    history = new stack;
    request = new queue;
    start s;

}

void Hotel :: add_floor() 
{
    Floor* new_floor = new Floor(no_of_floors, 1);
    insert_floor(new_floor);
    cout << "Floor " << no_of_floors << " added successfully." << endl;
    no_of_floors++;
}

void Hotel :: display_all_floor_rooms() 
{
    display_floors(floors);
}
void Hotel :: _booking_request()
{
    Booking_req* new_req = new Booking_req();
    Floor* temp = floors;

    while (temp != nullptr)
    {
        if (!temp->process_booking_request(new_req , temp->get_floor_no())) 
        {
            cout << "Room booked successfully.\n";
            request->enqueue(new_req, history); 
            return;
        }
        temp = temp->get_nextt(); 
    }

    cout << "Sorry, no available rooms of type " << new_req->get_room_type() << " at the moment.\n";
    delete new_req; 
}


void Hotel :: show_booking_history() 
{
    history->display_stack();
}
void Hotel :: show_booking_requests()
{
    request->display_queue();
}
void Hotel :: cancel_request()
{
    request->dequeue();
}
void Hotel :: all_available_rooms()
{
    Floor* temp = floors;
    while (temp != nullptr)
    {
        temp->available_rooms();
        temp = temp->get_nextt();
    }
}
void Hotel :: type_available_rooms_on_floors(string t)
{
    Floor* temp = floors;
    while (temp != nullptr)
    {
        temp->type_available_rooms(t);
        temp = temp->get_nextt();
    }
}
Hotel :: ~Hotel() 
{
    delete_all_floors(floors);
}