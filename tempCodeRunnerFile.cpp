#include "Hotel.h"

int main()
{
    Hotel hotel;
    char choice;

    do
    {
        string password;
        cout << "1. Customer" << endl;
        cout << "2. Admin" << endl;
        cout << "Enter your choice (1/2): ";
        cin >> choice;

        if (choice == '1')
        {
            system("cls");
            while (true)
            {
                cout << "1. Make a Booking Request" << endl;
                cout << "2. Cancel a Booking Request" << endl;
                cout << "3. View Available Rooms" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice (1-4): ";
                cin >> choice;
                system("cls");

                if (choice == '1') 
                {
                    hotel._booking_request();
                }
                else if (choice == '2') 
                {
                    hotel.cancel_request();
                }
                else if (choice == '3') 
                {
                    hotel.display_all_floor_rooms();
                }
                else if (choice == '4') 
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice. Please try again." << endl;
                }
                cout << "Press any key to continue...";
                getch(); 
                system("cls");
            }
        }
        else if (choice == '2') 
        {
            system("cls");
            cout << "Enter admin password: ";
            cin.ignore();
            getline(cin, password);
            system("cls");

            if (password == "666666")
            {
                while (true)
                {
                    cout << "1. Add a New Floor" << endl;
                    cout << "2. View Booking History" << endl;
                    cout << "3. View Floor Data" << endl;
                    cout << "4. View Booking Requests" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice (1-5): ";
                    cin >> choice;

                    if (choice == '1')
                    {
                        hotel.add_floor();
                    }
                    else if (choice == '2')
                    {
                        hotel.show_booking_history();
                    }
                    else if (choice == '3') 
                    {
                        system("CLS");
                        cout << "1. View All Rooms" << endl;
                        cout << "2. View Available Rooms" << endl;
                        cout << "3. View Single Rooms" << endl;
                        cout << "4. View Double Rooms" << endl;
                        cout << "5. View Suit Rooms" << endl;
                        cout << "Enter your choice (1-5): ";
                        cin >> choice; 
                        if (choice == '1')
                        {
                             hotel.display_all_floor_rooms(); 
                        }
                        else if (choice == '2')
                        {
                            hotel.all_available_rooms();
                        }
                        else if (choice == '3')
                        {
                            hotel.type_available_rooms_on_floors("Single");
                        }
                        else if (choice == '4')
                        {
                            hotel.type_available_rooms_on_floors("Double");
                        }
                        else if (choice == '5')
                        {
                            hotel.type_available_rooms_on_floors("Suit");
                        }
                        else
                        {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    else if (choice == '4') 
                    {
                        cout << "Pending Booking Requests: " << endl;
                        hotel.show_booking_requests(); 
                    }
                    else if (choice == '5') 
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                    cout << endl << "Press any key to continue...";
                    getch(); 
                    system("cls");
                }
            }
            else
            {
                cout << "Invalid password." << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to run the program again? (y or n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
