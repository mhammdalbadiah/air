
/*


 ████     █   █             █   █     ███     █   █     ███     █   █    █   █    █████    ████  
 █   █     █ █              ██ ██    █   █    █   █    █   █    ██ ██    ██ ██    █        █   █ 
 ████       █               █ █ █    █   █    █████    █████    █ █ █    █ █ █    ████     █   █ 
 █   █      █               █   █    █   █    █   █    █   █    █   █    █   █    █        █   █ 
 ████       █               █   █     ███     █   █    █   █    █   █    █   █    █████    ████  



*/


// 4/17/2026 Fix the performenc by using SWITCH insted of if 
// 4/22/2026 , Fix If 

#include "menus.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std ;


// ############################################################################
//                     PART 1 : LINKED LIST MENU FUNCTIONS
// ############################################################################


// ==== Passenger Linked List Menu ========

void passengerMenu(LinkedList<Passenger>& passengerList) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "         Passenger Linked List          " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All Passengers               " << endl;
        cout << "2) Insert Passenger                     " << endl;
        cout << "3) Delete Passenger                     " << endl;
        cout << "4) Modify Passenger                     " << endl;
        cout << "5) Find Passenger                       " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice  : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // ==== Display All Passengers ===
                if (passengerList.isEmpty()) 
                    cout << "No Passengers Found §!" << endl;
                    else {

                    Node<Passenger>* current = passengerList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {
                        // fix ui , mohammed
                        cout << "--- Passenger #" << counter << " ---" << endl;
                        current->data.displayPassenger() ;
                        current = current->next ;
                        counter++ ;

                    }
                }
                break;
            }

            case 2: {

                // === Insert New Passenger ====
                Passenger p ;
                p.setID() ;
                p.setName() ;
                p.setPassportNo() ;
                passengerList.insert(p) ;
                break;
            }

            case 3: {

                // === Delete Passenger by Position ===
                if (passengerList.isEmpty())
                    cout << "No Passengers to delete !" << endl;
                    else {

                    int pos ;
                    cout << "Enter position to delete (1 - " << passengerList.getSize() << ") : " ;
                    cin >> pos ;
                    cin.ignore() ;
                    passengerList.deleteByPosition(pos) ;


                }
                break;
            }

            case 4: {

                // === Modify Passenger at Position -==
                if (passengerList.isEmpty()) 
                    cout << "No Passengers to modify !" << endl;
                    else {

                    int pos ;
                    cout << "Enter position to modify (1 - " << passengerList.getSize() << ") : " ;
                    cin >> pos ;
                    cin.ignore() ;

                    if (pos < 1 || pos > passengerList.getSize()) 
                        cout << "Invalid position !" << endl;
                        else {

                        Passenger newP ;
                        newP.setID() ;
                        newP.setName() ;
                        newP.setPassportNo() ;
                        passengerList.modifyAt(pos , newP) ;

                    }
                }
                break;
            }

            case 5: {

                // === Find Passenger by ID ====
                if (passengerList.isEmpty()) 
                    cout << "No Passengers to search !" << endl;
                    else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Passenger ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Passenger>* current = passengerList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getID() == searchID) {

                            cout << "Found at Position #" << counter << " :" << endl;
                            current->data.displayPassenger() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Passenger with ID " << searchID << " not found !!" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice !! Please try again  " << endl;
        }

    } while (choice != 0) ;
}




// ======== Flight Linked List Menu ========

void flightMenu(LinkedList<Flight>& flightList) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "           Flight Linked List           " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All Flights                  " << endl;
        cout << "2) Insert Flight                        " << endl;
        cout << "3) Delete Flight                        " << endl;
        cout << "4) Modify Flight                        " << endl;
        cout << "5) Find Flight                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // === Display All Flights ===
                if (flightList.isEmpty()) 
                    cout << "No Flights Found !" << endl;
                    else {

                    Node<Flight>* current = flightList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- Flight #" << counter << " ---" << endl;
                        current->data.displayFlightProfile() ;
                        current = current->next ;
                        counter++ ;


                    }
                }
                break;
            }

            case 2: {

                // === Insert New Flight ===
                Flight f ;
                f.setFlightID() ;
                f.setDestination() ;
                f.setGate() ;
                f.setDepartureTime() ;
                flightList.insert(f) ;
                break;
            }

            case 3: {

                // === Delete Flight by Position ===
                if (flightList.isEmpty()) 
                    cout << "No Flights to delete !" << endl;
                    else {

                    int pos ;
                    cout << "Enter position to delete (1 - " << flightList.getSize() << "): " ;
                    cin >> pos ;
                    cin.ignore() ;
                    flightList.deleteByPosition(pos) ;

                }
                break;
            }

            case 4: {

                // === Modify Flight at Position ===
                if (flightList.isEmpty())
                    cout << "No Flights to modify !" << endl;
                 else {

                    int pos ;
                    cout << "Enter position to modify (1 - " << flightList.getSize() << "): " ;
                    cin >> pos ;
                    cin.ignore() ;

                    if (pos < 1 || pos > flightList.getSize()) 
                        cout << "Invalid position !" << endl;
                    else {

                        Flight newF ;
                        newF.setFlightID() ;
                        newF.setDestination() ;
                        newF.setGate() ;
                        newF.setDepartureTime() ;
                        flightList.modifyAt(pos , newF) ;
                    }
                }
                break;
            }

            case 5: {

                // === Find Flight by Flight ID ===
                if (flightList.isEmpty()) 
                    cout << "No Flights to search !" << endl;
                else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Flight ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Flight>* current = flightList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getFlightID() == searchID) {

                            cout << "Found at Position #" << counter << " :" << endl;
                            current->data.displayFlightProfile() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Flight with ID " << searchID << " not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again " << endl;
        }

    } while (choice != 0) ;
}




// ======== Booking Office Linked List Menu ======

void officeMenu(LinkedList<Booking_Office>& officeList) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "       Booking Office Linked List       " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All Offices                  " << endl;
        cout << "2) Insert Office                        " << endl;
        cout << "3) Delete Office                        " << endl;
        cout << "4) Modify Office                        " << endl;
        cout << "5) Find Office                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // === Display All Offices ===
                if (officeList.isEmpty()) 
                    cout << "No Offices Found !" << endl;
                 else {

                    Node<Booking_Office>* current = officeList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- Office #" << counter << " ---" << endl;
                        current->data.displayOffice() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                // === Insert New Office ===
                Booking_Office o ;
                o.set_Office_ID() ;
                o.set_Office_Name() ;
                o.set_Office_Location() ;
                officeList.insert(o) ;
                break;
            }

            case 3: {

                // === Delete Office by Position ===
                if (officeList.isEmpty()) 
                    cout << "No Offices to delete !!!" << endl;
                 else {

                    int pos ;
                    cout << "Enter position to delete (1 - " << officeList.getSize() << ") : " ;
                    cin >> pos ;
                    cin.ignore() ;
                    officeList.deleteByPosition(pos) ;
                }
                break;
            }

            case 4: {

                // === Modify Office at Position ===
                if (officeList.isEmpty()) 
                    cout << "No Offices to modify !" << endl;
                 else {

                    int pos ;
                    cout << "Enter position to modify (1 - " << officeList.getSize() << ")  : " ;
                    cin >> pos ;
                    cin.ignore() ;

                    if (pos < 1 || pos > officeList.getSize()) 
                        cout << "Invalid position !" << endl;
                     else {

                        Booking_Office newO ;
                        newO.set_Office_ID() ;
                        newO.set_Office_Name() ;
                        newO.set_Office_Location() ;
                        officeList.modifyAt(pos , newO) ;


                    }
                }
                break;
            }

            case 5: {

                // === Find Office by Office ID ===
                if (officeList.isEmpty()) 
                    cout << "No Offices to search !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Office ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Booking_Office>* current = officeList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.get_Office_ID() == searchID) {

                            cout << "Found at Position #" << counter << "  :" << endl;
                            current->data.displayOffice() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Office with ID " << searchID << " not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again " << endl;
        }

    } while (choice != 0) ;
}




// ======== Ticket Linked List Menu ========

void ticketMenu(LinkedList<Ticket>& ticketList) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "           Ticket Linked List           " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All Tickets                  " << endl;
        cout << "2) Insert Ticket                        " << endl;
        cout << "3) Delete Ticket                        " << endl;
        cout << "4) Modify Ticket                        " << endl;
        cout << "5) Find Ticket                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // === Display All Tickets ===
                if (ticketList.isEmpty()) 
                    cout << "No Tickets Found !" << endl;
                 else {

                    Node<Ticket>* current = ticketList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- Ticket #" << counter << " ---" << endl;
                        current->data.displayTicket() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                // === Insert New Ticket ===
                Ticket t ;
                t.setTicketNo() ;
                t.setFlightNo() ;
                t.setOfficeName() ;

                int numPassengers ;
                cout << "################################" << endl;
                cout << "How many passengers for this ticket ? " ;
                cin >> numPassengers ;
                cin.ignore() ;

                vector<Passenger> pList ;

                for (int i = 0 ; i < numPassengers ; i++) {

                    cout << endl;
                    cout << "--- Enter Passenger #" << i + 1 << " ---" << endl;
                    Passenger p ;
                    p.setID() ;
                    p.setName() ;
                    p.setPassportNo() ;
                    pList.push_back(p) ;
                }

                t.setPassengerList(pList) ;
                ticketList.insert(t) ;
                break;
            }

            case 3: {

                // === Delete Ticket by Position ===
                if (ticketList.isEmpty()) 
                    cout << "No Tickets to delete !" << endl;
                 else {

                    int pos ;
                    cout << "Enter position to delete (1 - " << ticketList.getSize() << ")  : " ;
                    cin >> pos ;
                    cin.ignore() ;
                    ticketList.deleteByPosition(pos) ;
                }
                break;
            }

            case 4: {

                // === Modify Ticket at Position ===
                if (ticketList.isEmpty()) 
                    cout << "No Tickets to modify !" << endl;
                else {

                    int pos ;
                    cout << "Enter position to modify (1 - " << ticketList.getSize() << "): " ;
                    cin >> pos ;
                    cin.ignore() ;

                    if (pos < 1 || pos > ticketList.getSize()) 
                        cout << "Invalid position !" << endl;
                     else {

                        Ticket newT ;
                        newT.setTicketNo() ;
                        newT.setFlightNo() ;
                        newT.setOfficeName() ;

                        int numPassengers ;
                        cout << "################################" << endl;
                        cout << "How many passengers for this ticket ? " ;
                        cin >> numPassengers ;
                        cin.ignore() ;

                        vector<Passenger> pList ;

                        for (int i = 0 ; i < numPassengers ; i++) {

                            cout << endl;
                            cout << "--- Enter Passenger #" << i + 1 << " ---" << endl;
                            Passenger p ;
                            p.setID() ;
                            p.setName() ;
                            p.setPassportNo() ;
                            pList.push_back(p) ;
                        }

                        newT.setPassengerList(pList) ;
                        ticketList.modifyAt(pos , newT) ;
                    }
                }
                break;
            }

            case 5: {

                // === Find Ticket by Ticket Number ===
                if (ticketList.isEmpty()) 
                    cout << "No Tickets to search !" << endl;
                 else {

                    string searchNo ;
                    cout << "################################" << endl;
                    cout << "Enter Ticket Number to search : " ;
                    getline(cin , searchNo) ;

                    bool found = false ;
                    Node<Ticket>* current = ticketList.getHead() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getTicketNo() == searchNo) {

                            cout << "Found at Position #" << counter << " :" << endl;
                            current->data.displayTicket() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Ticket with Number " << searchNo << " not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again" << endl;
        }

    } while (choice != 0) ;
}




// ############################################################################
//                       PART 2 : STACK MENU FUNCTIONS
// ############################################################################


// ======== Passenger Stack Menu ========

void passengerStackMenu(Stack<Passenger>& pStack) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "            Passenger Stack             " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Top to Bottom)          " << endl;
        cout << "2) Push Passenger                       " << endl;
        cout << "3) Pop Passenger                        " << endl;
        cout << "4) Peek (View Top)                      " << endl;
        cout << "5) Find Passenger                       " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // === Display All from Top to Bottom ===
                if (pStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    Node<Passenger>* current = pStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from top ) ---" << endl;
                        current->data.displayPassenger() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                // === Push New Passenger ===
                Passenger p ;
                p.setID() ;
                p.setName() ;
                p.setPassportNo() ;
                pStack.push(p) ;
                break;
            }

            case 3: {

                // === Pop Top Passenger ===
                pStack.pop() ;
                break;
            }

            case 4: {

                // === Peek Top Passenger ===
                if (pStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    cout << "Top of Stack :" << endl;
                    pStack.peek()->data.displayPassenger() ;
                }
                break;
            }

            case 5: {

                // === Find Passenger by ID ===
                if (pStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Passenger ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Passenger>* current = pStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getID() == searchID) {

                            cout << "Found at Level #" << counter << " from top :" << endl;
                            current->data.displayPassenger() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Passenger not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again " << endl;
        }

    } while (choice != 0) ;
}




// ======== Flight Stack Menu ========

void flightStackMenu(Stack<Flight>& fStack) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "              Flight Stack              " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Top to Bottom)          " << endl;
        cout << "2) Push Flight                          " << endl;
        cout << "3) Pop Flight                           " << endl;
        cout << "4) Peek (View Top)                      " << endl;
        cout << "5) Find Flight                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (fStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                else {

                    Node<Flight>* current = fStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from top) ---" << endl;
                        current->data.displayFlightProfile() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                Flight f ;
                f.setFlightID() ;
                f.setDestination() ;
                f.setGate() ;
                f.setDepartureTime() ;
                fStack.push(f) ;
                break;
            }

            case 3: {

                fStack.pop() ;
                break;
            }

            case 4: {

                if (fStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    cout << "Top of Stack :" << endl;
                    fStack.peek()->data.displayFlightProfile() ;
                }
                break;
            }

            case 5: {

                if (fStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Flight ID to search  " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Flight>* current = fStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getFlightID() == searchID) {

                            cout << "Found at Level #" << counter << " from top :" << endl;
                            current->data.displayFlightProfile() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Flight not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again  " << endl;
        }

    } while (choice != 0) ;
}




// ======== Office Stack Menu ========

void officeStackMenu(Stack<Booking_Office>& oStack) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "          Booking Office Stack          " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Top to Bottom)          " << endl;
        cout << "2) Push Office                          " << endl;
        cout << "3) Pop Office                           " << endl;
        cout << "4) Peek (View Top)                      " << endl;
        cout << "5) Find Office                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (oStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                else {

                    Node<Booking_Office>* current = oStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from top) ---" << endl;
                        current->data.displayOffice() ;
                        current = current->next ;
                        counter++ ;
                        // Fix bug in loop body !! 
                    }
                }
                break;
            }

            case 2: {

                Booking_Office o ;
                o.set_Office_ID() ;
                o.set_Office_Name() ;
                o.set_Office_Location() ;
                oStack.push(o) ;
                break;
            }

            case 3: {

                oStack.pop() ;
                break;
            }

            case 4: {

                if (oStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    cout << "Top of Stack :" << endl;
                    oStack.peek()->data.displayOffice() ;
                }
                break;
            }

            case 5: {

                if (oStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Office ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Booking_Office>* current = oStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.get_Office_ID() == searchID) {

                            cout << "Found at Level #" << counter << " from top :" << endl;
                            current->data.displayOffice() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Office not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again" << endl;
        }

    } while (choice != 0) ;
}




// ======== Ticket Stack Menu ========

void ticketStackMenu(Stack<Ticket>& tStack) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "             Ticket Stack               " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Top to Bottom)          " << endl;
        cout << "2) Push Ticket                          " << endl;
        cout << "3) Pop Ticket                           " << endl;
        cout << "4) Peek (View Top)                      " << endl;
        cout << "5) Find Ticket                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (tStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    Node<Ticket>* current = tStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " ( from top) ---" << endl;
                        current->data.displayTicket() ;
                        current = current->next ;

                        counter++ ;

                    }
                }
                break;
            }

            case 2: {

                Ticket t ;
                t.setTicketNo() ;
                t.setFlightNo() ;
                t.setOfficeName() ;

                int numPassengers ;
                cout << "################################" << endl;
                cout << "How many passengers for this ticket ?? " ;
                cin >> numPassengers ;
                cin.ignore() ;

                vector<Passenger> pList ;

                // Logical Erro fixed , Relay ? 
                for (int i = 0 ; i < numPassengers ; i++) {

                    cout << endl;
                    cout << "--- Enter Passenger #" << i + 1 << " ---" << endl;
                    Passenger p ;
                    p.setID() ;
                    p.setName() ;
                    p.setPassportNo() ;
                    pList.push_back(p) ;
                }

                t.setPassengerList(pList) ;
                tStack.push(t) ;
                break;
            }

            case 3: {

                tStack.pop() ;
                break;
            }

            case 4: {

                if (tStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    cout << "Top of Stack :" << endl;
                    tStack.peek()->data.displayTicket() ;
                }
                break;
            }

            case 5: {

                if (tStack.isEmpty()) 
                    cout << "Stack is empty !" << endl;
                 else {

                    string searchNo ;
                    cout << "################################" << endl;
                    cout << "Enter Ticket Number to search : " ;
                    getline(cin , searchNo) ;

                    bool found = false ;
                    Node<Ticket>* current = tStack.getTop() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getTicketNo() == searchNo) {

                            cout << "Found at Level #" << counter << " from top :" << endl;
                            current->data.displayTicket() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Ticket not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again" << endl;
        }

    } while (choice != 0) ;
}




// ############################################################################
//                       PART 3 : QUEUE MENU FUNCTIONS
// ############################################################################


// ======== Passenger Queue Menu ========
// Argument Fix 
void passengerQueueMenu(Queue<Passenger>& pQueue) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "            Passenger Queue             " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Front to Back)          " << endl;
        cout << "2) Enqueue Passenger                    " << endl;
        cout << "3) Dequeue Passenger                    " << endl;
        cout << "4) Peek (View Front)                    " << endl;
        cout << "5) Find Passenger                       " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                // === Display All from Front to Back ===
                if (pQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    Node<Passenger>* current = pQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << "   (from front) ---" << endl;
                        current->data.displayPassenger() ;
                        current = current->next ;
                        counter++ ;

                    }
                }
                break;
            }

            case 2: {

                // === Enqueue New Passenger ====
                Passenger p ;
                p.setID() ;
                p.setName() ;
                p.setPassportNo() ;
                pQueue.enqueue(p) ;
                break;
            }

            case 3: {

                // === Dequeue Front Passenger ===
                pQueue.dequeue() ;
                break;
            }

            case 4: {

                // === Peek Front Passenger ===
                if (pQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    cout << "Front of Queue :" << endl;
                    pQueue.peek()->data.displayPassenger() ;
                }
                break;
            }

            case 5: {

                // ===- Find Passenger by ID ===
                if (pQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Passenger ID to search  : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Passenger>* current = pQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getID() == searchID) {

                            cout << "Found at Position #" << counter << " from front :" << endl;
                            current->data.displayPassenger() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Passenger not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again   " << endl;
        }

    } while (choice != 0) ;
}




// ======== Flight Queue Menu ========

void flightQueueMenu(Queue<Flight>& fQueue) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "              Flight Queue              " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Front to Back)          " << endl;
        cout << "2) Enqueue Flight                       " << endl;
        cout << "3) Dequeue Flight                       " << endl;
        cout << "4) Peek (View Front)                    " << endl;
        cout << "5) Find Flight                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (fQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    Node<Flight>* current = fQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from  front) ---" << endl;
                        current->data.displayFlightProfile() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                Flight f ;
                f.setFlightID() ;
                f.setDestination() ;
                f.setGate() ;
                f.setDepartureTime() ;
                fQueue.enqueue(f) ;
                break;
            }

            case 3: {

                fQueue.dequeue() ;
                break;
            }

            case 4: {

                if (fQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    cout << "Front of Queue :" << endl;
                    fQueue.peek()->data.displayFlightProfile() ;
                }
                // fix if condition , By Mohammed
                break;
            }

            case 5: {

                if (fQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Flight ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Flight>* current = fQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getFlightID() == searchID) {

                            cout << "Found at Position #" << counter << " from front :" << endl;
                            current->data.displayFlightProfile() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Flight not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again " << endl;
        }

    } while (choice != 0) ;
}




// ======== Office Queue Menu ========

void officeQueueMenu(Queue<Booking_Office>& oQueue) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "          Booking Office Queue          " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Front to Back)          " << endl;
        cout << "2) Enqueue Office                       " << endl;
        cout << "3) Dequeue Office                       " << endl;
        cout << "4) Peek (View Front)                    " << endl;
        cout << "5) Find Office                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (oQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                else {

                    Node<Booking_Office>* current = oQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from front) ---" << endl;
                        current->data.displayOffice() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                Booking_Office o ;
                o.set_Office_ID() ;
                o.set_Office_Name() ;
                o.set_Office_Location() ;
                oQueue.enqueue(o) ;
                break;
            }

            case 3: {

                oQueue.dequeue() ;
                break;
            }

            case 4: {

                if (oQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                else {

                    cout << "Front of Queue :" << endl;
                    oQueue.peek()->data.displayOffice() ;
                }
                break;
            }

            case 5: {

                if (oQueue.isEmpty()) cout << "Queue is empty !" << endl;
                 else {

                    string searchID ;
                    cout << "################################" << endl;
                    cout << "Enter Office ID to search : " ;
                    getline(cin , searchID) ;

                    bool found = false ;
                    Node<Booking_Office>* current = oQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.get_Office_ID() == searchID) {

                            cout << "Found at Position #" << counter << " from front :" << endl;
                            current->data.displayOffice() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Office not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again" << endl;
        }

    } while (choice != 0) ;
}




// ======== Ticket Queue Menu ========

void ticketQueueMenu(Queue<Ticket>& tQueue) {

    int choice ;

    do {

        cout << endl;
        cout << "========================================" << endl;
        cout << "             Ticket Queue               " << endl;
        cout << "========================================" << endl;
        cout << "1) Display All (Front to Back)          " << endl;
        cout << "2) Enqueue Ticket                       " << endl;
        cout << "3) Dequeue Ticket                       " << endl;
        cout << "4) Peek (View Front)                    " << endl;
        cout << "5) Find Ticket                          " << endl;
        cout << "0) Back to Main Menu                    " << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice : " ;
        cin >> choice ;
        cin.ignore() ;

        cout << endl;

        switch (choice) {

            case 1: {

                if (tQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    Node<Ticket>* current = tQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        cout << "--- #" << counter << " (from front) ---" << endl;
                        current->data.displayTicket() ;
                        current = current->next ;
                        counter++ ;
                    }
                }
                break;
            }

            case 2: {

                Ticket t ;
                t.setTicketNo() ;
                t.setFlightNo() ;
                t.setOfficeName() ;

                int numPassengers ;
                cout << "################################" << endl;
                cout << "How many passengers for this ticket  " ;
                cin >> numPassengers ;
                cin.ignore() ;

                vector<Passenger> pList ;

                for (int i = 0 ; i < numPassengers ; i++) {

                    cout << endl;
                    cout << "--- Enter Passenger #" << i + 1 << " ---" << endl;
                    Passenger p ;
                    p.setID() ;
                    p.setName() ;
                    p.setPassportNo() ;
                    pList.push_back(p) ;
                }

                t.setPassengerList(pList) ;
                tQueue.enqueue(t) ;
                break;
            }

            case 3: {

                tQueue.dequeue() ;
                break;
            }

            case 4: {

                if (tQueue.isEmpty()) 
                    cout << "Queue is empty !" << endl;
                 else {

                    cout << "Front of Queue :" << endl;
                    tQueue.peek()->data.displayTicket() ;
                }
                break;
            }

            case 5: {

                if (tQueue.isEmpty()) 
                    cout << "Queue is empty!!!" << endl;
                 else {

                    string searchNo ;
                    cout << "################################" << endl;
                    cout << "Enter Ticket Number to search : " ;
                    getline(cin , searchNo) ;

                    bool found = false ;
                    Node<Ticket>* current = tQueue.getFront() ;
                    int counter = 1 ;

                    while (current != nullptr) {

                        if (current->data.getTicketNo() == searchNo) {

                            cout << "Found at Position #" << counter << " from front :" << endl;
                            current->data.displayTicket() ;
                            found = true ;
                            break ;
                        }

                        current = current->next ;
                        counter++ ;
                    }

                    if (!found) 
                        cout << "Ticket not found !" << endl;
                    
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice ! Please try again" << endl;
        }

    } while (choice != 0) ;
}


// add semi column , Thx othman for letting me debug -_-
// by mohammed
