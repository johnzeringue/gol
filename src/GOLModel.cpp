#include "GOLModel.h"

#include <iostream>
#include <vector>

using std::vector;

//
// CONSTRUCTORS
//
GOLModel::GOLModel(unsigned size) {
    init(size, size);
}

GOLModel::GOLModel(unsigned number_of_rows, unsigned number_of_columns) {
    init(number_of_rows, number_of_columns);
}

//
// PUBLIC METHODS
//
void GOLModel::step() {
    vector<vector<bool>> next_grid;

    for (unsigned row = 0; row < number_of_rows; row++) {
        vector<bool> row_vector;

        for (unsigned column = 0; column < number_of_columns; column++) {
            row_vector.push_back(shouldBeAlive(row, column));
        }

        next_grid.push_back(row_vector);
    }

    grid = next_grid;
}

void GOLModel::flip(unsigned row, unsigned column) {
    grid[row][column] = !grid[row][column];
}

bool GOLModel::isAlive(unsigned row, unsigned column) {
    return grid[row][column];
}

bool GOLModel::isDead(unsigned row, unsigned column) {
    return !grid[row][column];
}

//
// PRIVATE METHODS
//
void GOLModel::init(unsigned number_of_rows, unsigned number_of_columns) {
    this->number_of_rows = number_of_rows;
    this->number_of_columns = number_of_columns;

    for (unsigned row = 0; row < number_of_rows; row++) {
        vector<bool> row_vector(number_of_columns, false);
        grid.push_back(row_vector);
    }
}

bool GOLModel::shouldBeAlive(unsigned row, unsigned column) {
    int number_of_living_neighbors = numberOfLivingNeighbors(row, column);

    if (isAlive(row, column)) {
        return number_of_living_neighbors == 2
            || number_of_living_neighbors == 3;
    } else {
        return number_of_living_neighbors == 3;
    }
}

int GOLModel::numberOfLivingNeighbors(unsigned row, unsigned column) {
    int number_of_living_neighbors = 0;

    for (int row_offset = -1; row_offset <= 1; row_offset++) {
        for (int column_offset = -1; column_offset <= 1; column_offset++) {
            if (row_offset == 0 && column_offset == 0) continue;

            unsigned neighbor_row
                = (row + number_of_rows + row_offset) % number_of_rows;
            unsigned neighbor_column
                = (column + number_of_columns + column_offset)
                % number_of_columns;

            if (isAlive(neighbor_row, neighbor_column)) {
                number_of_living_neighbors++;
            }
        }
    }

    return number_of_living_neighbors;
}
