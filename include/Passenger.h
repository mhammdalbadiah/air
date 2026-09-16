
// Rakan Alharbi


#pragma once 

#include "BookingOffice.h"


 // ============== Passengers Class ==============

class Passenger {


    string ID , Name , PassportNo ;


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

        if (value.length() < 3 || value.length() > 20) {

            cout << "Invalid input , length must be between 3 and 20 !" << endl;
            return false;
        }

        return true;
    }



    bool checkDigitsOnly(string value , int requiredLength) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }

        if (value.length() != (size_t)requiredLength) {

            cout << "Invalid input , it must be exactly " << requiredLength << " digits !" << endl;
            return false;
        }

        for (char c : value) {

            if (!isdigit(static_cast<unsigned char>(c))) {

                cout << "Invalid input , digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    bool checkPassportNo(string value) {

        if (value.empty()) {

            cout << "Passport Number cannot be empty !" << endl;
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

            cout << "Passport Number cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 5 || value.length() > 15) {

            cout << "Passport Number length must be between 5 and 15 !" << endl;
            return false;
        }

        for (char c : value) {

            if (!isalnum(static_cast<unsigned char>(c))) {

                cout << "Passport Number must contain letters and digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setID() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passenger ID : " ;
            getline(cin, input);

            if (checkDigitsOnly(input, 10)) {

                ID = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setName() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passenger Name : " ;
            getline(cin, input);

            if (checkText(input)) {

                Name = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setPassportNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passport Number : " ;
            getline(cin, input);

            if (checkPassportNo(input)) {

                PassportNo = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    // ############## GETTER FUNCTIONS #################

    string getID() { return ID; }

    string getName() { return Name; }

    string getPassportNo() { return PassportNo; }

    // ########### Display Function ###########
    void displayPassenger() {

        cout << "=====================================" << endl;
        cout << "         Passenger Profile           " << endl;
        cout << "=====================================" << endl;
        cout << "ID          : " << ID << endl;
        cout << "Name        : " << Name << endl;
        cout << "Passport No : " << PassportNo << endl;
        cout << endl;
    }

};


