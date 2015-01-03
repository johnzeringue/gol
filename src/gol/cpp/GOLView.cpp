#include <iostream>
#include <string>

#include "GOLModel.hpp"
#include "GOLView.hpp"

using std::string;

using std::cin;
using std::cout;
using std::endl;

//
// CONSTRUCTORS
//
GOLView::GOLView(): alive_char('O'), dead_char('.') {}

GOLView::GOLView(char alive_char, char dead_char) {
    this->alive_char = alive_char;
    this->dead_char = dead_char;
}

//
// PUBLIC METHODS
//
void GOLView::display(GOLModel model) {
    string user_input;

    printGrid(model);
    while (true) {
        user_input = promptForInput();
        
        if (user_input == "p" || user_input == "print") {
            printGrid(model);
        } else if (user_input == "q" || user_input == "quit") {
            break;
        } else {
            cout << "Unknown command." << endl;
        }
    }
}

//
// PRIVATE METHODS
//
void GOLView::printGrid(GOLModel model) {
    for (unsigned row = 0; row < model.number_of_rows; row++) {
        printRow(row, model);
    }

    cout << endl;
}

void GOLView::printRow(unsigned row, GOLModel model) {
    for (unsigned column = 0; column < model.number_of_columns; column++) {
        if (model.isAlive(row, column)) {
            cout << alive_char;
        } else {
            cout << dead_char;
        }
    }

    cout << endl;
}

string GOLView::promptForInput() {
    string user_input;

    cout << "What would you like to do? ";
    getline(cin, user_input);

    return user_input;
}
