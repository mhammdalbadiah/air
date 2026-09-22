
// NEW main.cpp FILE that is handle the flags 

#include <iostream>
#include <string>
#include "../core/Core.h"
#include "tui/menus.h"

using namespace std;

namespace gui {
    void run();
}

#ifndef AIR_GUI_IMPLEMENTED
namespace gui {
    void run() {
        cout << "air GUI running -> open http://localhost:8080 in your browser\n\n\n\n" ;
    }
}
#endif

void printUsage(const char* progName) {
    cerr << "Usage:\n"
         << "  " << progName << "        # Defaults to TUI\n"
         << "  " << progName << " -tui   # Launch Terminal UI\n"
         << "  " << progName << " -gui   # Launch Web GUI backend\n";
}

int main(int argc, char* argv[]) {
    string mode = "-tui";

    if (argc == 2) {
        mode = argv[1];
        if (mode != "-tui" && mode != "-gui") {
            cerr << "Error: Unknown flag '" << mode << "'\n\n";
            printUsage(argv[0]);
            return 1;
        }
    } else if (argc > 2) {
        cerr << "Error: Too many arguments.\n\n";
        printUsage(argv[0]);
        return 1;
    }

    LoadingBar(1);

    if (mode == "-tui") {
        tui::run();
    } else if (mode == "-gui") {
        gui::run();
    }

    return 0;
}