// made by Othman Althabit

#pragma once 
#include "BookingOffice.h"
#include "Ticket.h"



// ============== Flight Class ==============

class Flight {


    string FlightID , Destination , Gate , DepartureTime ;
    vector<Ticket> TicketList ;


public :


    // ########## Safety Functions for Setter functions #########

    bool checkText(string value) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }
         
        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid input , field can't be spaces only !" << endl;
            return false;
        }

        if (value.length() < 2 || value.length() > 25) {

            cout << "Invalid input , length must be between 2 and 25 !!" << endl;
            return false;
        }

        return true;
    }



    bool checkTicketList(vector<Ticket> TList) {

        if (TList.empty()) {

            cout << "Ticket List cannot be empty !" << endl;
            return false;
        }

        return true;
    }



    bool checkDepartureTime(string value) {

        if (value.empty()) {

            cout << "Departure Time cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Departure Time cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 3 || value.length() > 20) {

            cout << "Departure Time length must be between 3 and 20 !" << endl;
            return false;
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setFlightID() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Flight ID : " ;
            getline(cin, input);

            if (checkText(input)) {

                FlightID = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setDestination() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Destination : " ;
            getline(cin, input);

            if (checkText(input)) {

                Destination = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setGate() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Gate : " ;
            getline(cin, input);

            if (checkText(input)) {

                Gate = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setDepartureTime() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Departure Time : " ;
            getline(cin, input);

            if (checkDepartureTime(input)) {

                DepartureTime = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setTicketList(vector<Ticket> TList) {

        if (checkTicketList(TList)) {

            TicketList = TList ;
        }
    }



    // ############## GETTER FUNCTIONS #################

    string getFlightID() { return FlightID ; }

    string getDestination() { return Destination ; }

    string getGate() { return Gate ; }

    string getDepartureTime() { return DepartureTime ; }

    const vector<Ticket>& getTicketList() { return TicketList ; }



    // ########### Display Function ###########

    void displayFlightProfile() {

        cout << "=====================================" << endl;
        cout << "            Flight Profile           " << endl;
        cout << "=====================================" << endl;
        cout << "Flight ID       : " << FlightID << endl;
        cout << "Destination     : " << Destination << endl;
        cout << "Gate            : " << Gate << endl;
        cout << "Departure Time  : " << DepartureTime << endl;
        cout << "Issued Tickets  : " << endl;

        if (TicketList.empty()) {

            cout << "No Tickets Found !" << endl;
        }
        
       for (size_t i = 0 ; i < TicketList.size() ; i++){

            cout << i + 1 << ") Ticket No : " << TicketList[i].getTicketNo()
                 << " | Office Name : " << TicketList[i].getOfficeName()
                 << " | Flight No : " << TicketList[i].getFlightNo() << endl;
        }

        cout << endl;
    }

};

    // Fix UI By Mohammed 
