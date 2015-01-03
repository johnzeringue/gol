#ifndef GOL_VIEW_H
#define GOL_VIEW_H

#include <string>

#include "GOLModel.hpp"

class GOLView {
    public:
        //
        // CONSTRUCTORS
        //
        GOLView();
        GOLView(char alive_char, char dead_char);

        //
        // INSTANCE VARIABLES
        //
        char alive_char;
        char dead_char;

        //
        // METHODS
        //
        void display(GOLModel model);

    private:
        //
        // METHODS
        //
        void printRow(unsigned row, GOLModel model);
        void printGrid(GOLModel model);
        std::string promptForInput();
};

#endif
