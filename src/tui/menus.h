
/*


 ████     █   █             █   █     ███     █   █     ███     █   █    █   █    █████    ████  
 █   █     █ █              ██ ██    █   █    █   █    █   █    ██ ██    ██ ██    █        █   █ 
 ████       █               █ █ █    █   █    █████    █████    █ █ █    █ █ █    ████     █   █ 
 █   █      █               █   █    █   █    █   █    █   █    █   █    █   █    █        █   █ 
 ████       █               █   █     ███     █   █    █   █    █   █    █   █    █████    ████  



*/

// $$$$$$$$$$$ Prototypes $$$$$$$$$$


#pragma once

#include "../include/Passenger.h"
#include "../include/BookingOffice.h"
#include "../include/Ticket.h"
#include "../include/Flight.h"
#include "../data_structures/LinkedList.h"
#include "../data_structures/Stack.h"
#include "../data_structures/Queue.h"


// ############################################################################
//                         LINKED LIST MENU DECLARATIONS
// ############################################################################

void passengerMenu    ( LinkedList<Passenger>&     passengerList ) ;
void flightMenu       ( LinkedList<Flight>&         flightList   ) ;
void officeMenu       ( LinkedList<Booking_Office>& officeList   ) ;
void ticketMenu       ( LinkedList<Ticket>&         ticketList   ) ;


// ############################################################################
//                           STACK MENU DECLARATIONS
// ############################################################################

void passengerStackMenu ( Stack<Passenger>&     pStack ) ;
void flightStackMenu    ( Stack<Flight>&         fStack ) ;
void officeStackMenu    ( Stack<Booking_Office>& oStack ) ;
void ticketStackMenu    ( Stack<Ticket>&         tStack ) ;


// ############################################################################
//                           QUEUE MENU DECLARATIONS
// ############################################################################

void passengerQueueMenu ( Queue<Passenger>&     pQueue ) ;
void flightQueueMenu    ( Queue<Flight>&         fQueue ) ;
void officeQueueMenu    ( Queue<Booking_Office>& oQueue ) ;
void ticketQueueMenu    ( Queue<Ticket>&         tQueue ) ;
