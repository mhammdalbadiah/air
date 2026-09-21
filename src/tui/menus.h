
/*


 ████     █   █             █   █     ███     █   █     ███     █   █    █   █    █████    ████  
 █   █     █ █              ██ ██    █   █    █   █    █   █    ██ ██    ██ ██    █        █   █ 
 ████       █               █ █ █    █   █    █████    █████    █ █ █    █ █ █    ████     █   █ 
 █   █      █               █   █    █   █    █   █    █   █    █   █    █   █    █        █   █ 
 ████       █               █   █     ███     █   █    █   █    █   █    █   █    █████    ████  



*/

#pragma once

#include "../../core/Core.h"
// Core.h has all the headers files that we gonna need 
// ** IF YOU WANT TO ADD .h FILE ADD IT THERE "Core.h" 

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


namespace tui {
    void run();
}