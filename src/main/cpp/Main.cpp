#include "GOLModel.hpp"
#include "GOLView.hpp"

int main() {
    // make a "spinner"
    GOLModel model(4);
    model.flip(0, 1);
    model.flip(1, 1);
    model.flip(2, 1);

    GOLView view('+', '.');
    for (int i = 0; i < 5; i++) {
        view.display(model);
        model.step();
    }
}
