

// Rakan Alharbi

#pragma once 

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>

using namespace std ;




// ======== Booking Office Class !! ===========

class Booking_Office {


    string Office_Name , Office_Location , Office_ID ;


public :

    // Modify By Mohammed
    // Safety Functions for the Setter functions

    bool str_check(string Ofc) {

        if (Ofc.empty()) {

            cout << "Invalid Input , Don't make the input empty ! " << endl;
            return false;
        }

        bool onlySpaces = true ;

        // Fixx The loop , Othman 4/11/2026  
        // This loop check the white spaces 
        for (char c : Ofc) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid Input , Don't make the input spaces only ! " << endl;
            return false;
        }

        if (Ofc.length() < 3 || Ofc.length() > 20) {

            cout << "Invalid Input , Make the input between 3 - 20 characters ! " << endl;
            return false;
        }

        return true;
    }


    bool checkOfficeID() {

        if (Office_ID.empty()) {

            cout << "Office ID cannot be empty !" << endl;
            return false;
        }

        if (Office_ID.length() != 10) {

            cout << "Office ID must be exactly 10 digits !" << endl;
            return false;
        }

        for (char c : Office_ID) {

            if (!isdigit(static_cast<unsigned char>(c))) {

                cout << "Office ID must contain digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    // ############# Setter Functions ! ###########


    void set_Office_Name() {

        string OfcN ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter the Office Name: " ;
            getline(cin, OfcN);

            if (str_check(OfcN)) {

                Office_Name = OfcN;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void set_Office_Location() {

        string OfcL ;

        while (true) {

            cout << "#########################################" << endl;
            cout << "Please Enter the Location of the Office : " ;
            getline(cin, OfcL);

            if (str_check(OfcL)) {

                Office_Location = OfcL;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void set_Office_ID() {

        string ID ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter the Office ID (10 digits) : " ;
            getline(cin, ID);

            Office_ID = ID;

            if (checkOfficeID()) {
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    // ##### Getter Functions ! #####
    string get_Office_Name() { return Office_Name; }
    string get_Office_Location() { return Office_Location; }
    string get_Office_ID() { return Office_ID; }

    // ##### Display Function #####
    void displayOffice() {

        cout << "=====================================" << endl;
        cout << "          Office Profile             " << endl;
        cout << "=====================================" << endl;
        cout << "Office ID       : " << Office_ID << endl;
        cout << "Office Name     : " << Office_Name << endl;
        cout << "Office Location : " << Office_Location << endl;
        cout << endl;
    }

};
