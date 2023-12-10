#include <stdio.h>
#include <time.h>
#include "neural_network.h"

int main() {
    // pasted inputs from example.ipynb
    float inputs[10] = { 0.07656088, -0.27443325, -0.12742866, -1.0739909 , -2.3203679 ,
        0.47109858,  0.96793253, -1.20658401, -0.45183336, -0.85693123};

    float outputs[4];

    forward(inputs, outputs);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", outputs[i]);
    }

    return 0;
}
