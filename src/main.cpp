//Ahmed farraj Alotaibi


// Fix UI & UX by Ahmed 23/4 


// Add UI Using Python Script by Mohammed
// 4/30/2026


#include <iostream>
#include "menus.h"
using namespace std ;


 
int main() {



  

    // ===== Part 1 : Declare the 4 Linked Lists =====
    LinkedList<Passenger>      passengerList ;
    LinkedList<Flight>         flightList    ;
    LinkedList<Booking_Office> officeList    ;
    LinkedList<Ticket>         ticketList    ;

    // ====== Part 2 : Declare the 4 Stacks =====
    Stack<Passenger>      passengerStack ;
    Stack<Flight>         flightStack    ;
    Stack<Booking_Office> officeStack    ;
    Stack<Ticket>         ticketStack    ;

    // ==== Part 3 : Declare the 4 Queues =====
    Queue<Passenger>      passengerQueue ;
    Queue<Flight>         flightQueue    ;
    Queue<Booking_Office> officeQueue    ;
    Queue<Ticket>         ticketQueue    ;

      


    int mainChoice ;

    do {

        cout << endl << endl ;
        cout << "==========================================================================================" << endl;
        cout << endl;
        cout << "    ###     #####    ####     #        #####    #   #    ##### " << endl;
        cout << "   #   #      #      #   #    #          #      ##  #    #     " << endl;     
        cout << "   #####      #      ####     #          #      # # #    ####  " << endl;
        cout << "   #   #      #      #  #     #          #      #  ##    #     " << endl;
        cout << "   #   #    #####    #   #    #####    #####    #   #    ##### " << endl;
        cout << endl;
        cout << "==========================================================================================" << endl;
        cout << endl;
        cout << "                      ####    #   #     ####    #####    #####    #   #               #   " << endl;
        cout << "                     #         # #     #          #      #        ## ##               #    " << endl;
        cout << "                      ###       #       ###       #      ####     # # #               #    " << endl;
        cout << "                         #      #          #      #      #        #   #                    " << endl;
        cout << "                     ####       #      ####       #      #####    #   #               #    " << endl;
        cout << endl;
        cout << "==========================================================================================" << endl;
        cout << endl;
        cout << "1) Part 1 : Linked Lists                    " << endl;
        cout << "2) Part 2 : Stacks                          " << endl;
        cout << "3) Part 3 : Queues                          " << endl;
        cout << "0) Exit                                     " << endl;
        cout << endl;
        cout << "==========================================================================================" << endl;
        cout << "Enter your choice : " ;
        cin >> mainChoice ;
        cin.ignore() ;

        cout << endl;

        switch (mainChoice) {


            // ===== Part 1 : Linked Lists ======
            case 1: {

                int llChoice ;

                do {

                    cout << endl ;
                    cout << "================================================================" << endl;
                    cout << "                      Part 1 : Linked List                      " << endl;
                    cout << "================================================================" << endl;
                    cout << "1) Passengers                           " << endl;
                    cout << "2) Flights                              " << endl;
                    cout << "3) Booking Offices                      " << endl;
                    cout << "4) Tickets                              " << endl;
                    cout << "0) Back to Main Menu                    " << endl;
                    cout << "========================================" << endl;
                    cout << "Enter your choice : " ;
                    cin >> llChoice ;
                    cin.ignore() ;

                    switch (llChoice) {

                        case 1: passengerMenu(passengerList) ; break ;
                        case 2: flightMenu(flightList)       ; break ;
                        case 3: officeMenu(officeList)       ; break ;
                        case 4: ticketMenu(ticketList)       ; break ;
                        case 0:                                break ;
                        default: cout << "Invalid choice !!" << endl  ; break ;
                    }

                }  while (llChoice != 0) ;

                break ;
            }


            // ===== Part 2 : Stacks =====

            case 2: {

                int stChoice ;

                do {

                    cout << endl;
                    cout << "========================================" << endl;
                    cout << "           Part 2 : Stacks              " << endl;
                    cout << "========================================" << endl;
                    cout << "1) Passengers                           " << endl;
                    cout << "2) Flights                              " << endl;
                    cout << "3) Booking Offices                      " << endl;
                    cout << "4) Tickets                              " << endl;
                    cout << "0) Back to Main Menu                    " << endl;
                    cout << "========================================" << endl;
                    cout << "Enter your choice : " ;
                    cin >> stChoice ;
                    cin.ignore() ;

                    switch (stChoice) {

                        case 1: passengerStackMenu(passengerStack) ; break ;
                        case 2: flightStackMenu(flightStack)       ; break ;
                        case 3: officeStackMenu(officeStack)       ; break ;
                        case 4: ticketStackMenu(ticketStack)       ; break ;
                        case 0:                                      break ;
                        default: cout << "Invalid choice !!!  " << endl  ; break ;
                    }

                } while (stChoice != 0) ;

                break ;
            }


            // ==== Part 3 : Queues =====
            case 3: {

                int qChoice ;

                do {

                    cout << endl;
                    cout << "========================================" << endl;
                    cout << "           Part 3 : Queues              " << endl;
                    cout << "========================================" << endl;
                    cout << "1) Passengers                           " << endl;
                    cout << "2) Flights                              " << endl;
                    cout << "3) Booking Offices                      " << endl;
                    cout << "4) Tickets                              " << endl;
                    cout << "0) Back to Main Menu                    " << endl;
                    cout << "========================================" << endl;
                    cout << "Enter your choice : " ;
                    cin >> qChoice ;
                    cin.ignore() ;

                    switch (qChoice) {

                        case 1: passengerQueueMenu(passengerQueue) ; break ;
                        case 2: flightQueueMenu(flightQueue)       ; break ;
                        case 3: officeQueueMenu(officeQueue)       ; break ;
                        case 4: ticketQueueMenu(ticketQueue)       ; break ;
                        case 0:                                      break ;
                        default: cout << "Invalid choice !!" << endl  ; break ;
                    }

                } while (qChoice != 0) ;

                break ;
            }


            case 0:
                // Exit do nothing , the loop condition will handle it
                break ;

            default:
                cout << "Invalid choice !! Please try again " << endl;
                break ;
        }

    } while (mainChoice != 0) ;


    cout << endl;
    cout << "=====================================" << endl;
    cout << "  Thank you for using our system !!   " << endl;
    cout << "=====================================" << endl;

    return 0 ;
}


