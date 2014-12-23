#ifndef GOL_MODEL_H
#define GOL_MODEL_H

#include <vector>

using std::vector;

class GOLModel {
    public:
        //
        // CONSTRUCTORS
        //
        GOLModel(unsigned size);
        GOLModel(unsigned number_of_rows, unsigned number_of_columns);

        //
        // INSTANCE VARIABLES
        //
        unsigned number_of_rows;
        unsigned number_of_columns;

        //
        // METHODS
        //
        void step();
        void flip(unsigned row, unsigned column);
        bool isAlive(unsigned row, unsigned column);
        bool isDead(unsigned row, unsigned column);

    private:
        //
        // INSTANCE VARIABLES
        //
        vector<vector<bool>> grid;

        //
        // PRIVATE METHODS
        //
        void init(unsigned number_of_rows, unsigned number_of_columns);
        bool shouldBeAlive(unsigned row, unsigned column);
        int numberOfLivingNeighbors(unsigned row, unsigned column);
};

#endif
