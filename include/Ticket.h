// made by Othman Althabit


#pragma once 
#include "BookingOffice.h"
#include "Passenger.h" 



//========== Ticket Class ==============

class Ticket {


    string TicketNo , FlightNo , OfficeName ;
    vector<Passenger> PassengerList ;


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

            cout << "Invalid input , field cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 2 || value.length() > 20) {

            cout << "Invalid input , length must be between 2 and 20 !" << endl;
            return false;
        }

        return true;
    }



    bool checkPassengerList(vector<Passenger> PList) {

        if (PList.empty()) {

            cout << "Passenger List cannot be empty !" << endl;
            return false;
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setTicketNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Ticket Number : " ;
            getline(cin, input);

            if (checkText(input)) {

                TicketNo = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setFlightNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Flight Number : " ;
            getline(cin, input);

            if (checkText(input)) {

                FlightNo = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setOfficeName() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Office Name : " ;
            getline(cin, input);

            if (checkText(input)) {

                OfficeName = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setPassengerList(vector<Passenger> PList) {

        if (checkPassengerList(PList)) {

            PassengerList = PList ;
        }
    }



    // ############## GETTER FUNCTIONS #################

    string getTicketNo() { return TicketNo ; }

    string getFlightNo() { return FlightNo ; }

    string getOfficeName() { return OfficeName ; }

    const vector<Passenger>& getPassengerList() { return PassengerList ; }



    // ########### Display Function ###########

    void displayTicket() {

        cout << "=====================================" << endl;
        cout << "            Ticket Profile           " << endl;
        cout << "=====================================" << endl;
        cout << "Ticket Number  : " << TicketNo << endl;
        cout << "Flight Number  : " << FlightNo << endl;
        cout << "Office Name    : " << OfficeName << endl;
        cout << "Passenger List : " << endl;

        if (PassengerList.empty()) {

            cout << "No Passengers Found !" << endl;
        }

        for (size_t i = 0 ; i < PassengerList.size() ; i++){
            cout << i + 1 << ") " << PassengerList[i].getName()
                 << " | ID : " << PassengerList[i].getID()
                 << " | Passport No : " << PassengerList[i].getPassportNo() << endl;
        }

        cout << endl;
    }

};


