// By Mohammed ! 
// This function used after any invoce in the terminal 
// When there is a call , For example : 
// air -tui  | air -gui 
//  2026/9/20 

#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

inline void LoadingBar(int seconds) {
    const int totalSteps = 100;
    auto delay = chrono::milliseconds((seconds * 1000) / totalSteps);

    for (int i = 0; i <= totalSteps; ++i) {
        int percent = (i * 100) / totalSteps;

        string filled(i, '#');
        string empty(totalSteps - i, '.');
        cout << "\r[" << filled << empty << "] " << percent << "%" << std::flush;

        this_thread::sleep_for(delay);
    }

    cout << "\nDone!" << std::endl;
}