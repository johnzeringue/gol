#include <iostream>
#include <string>

#include "GOLModel.hpp"
#include "GOLView.hpp"

using std::string;
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
    for (unsigned row = 0; row < model.number_of_rows; row++) {
        for (unsigned column = 0; column < model.number_of_columns; column++) {
            if (model.isAlive(row, column)) {
                cout << alive_char;
            } else {
                cout << dead_char;
            }
        }

        // new line after each row
        cout << endl;
    }

    // new line after finished grid
    cout << endl;
}
