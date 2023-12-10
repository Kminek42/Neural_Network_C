#include <stdio.h>
#include <time.h>
#include "neural_network.h"

int main() {
    // pasted inputs from example.ipynb
    float inputs[10] = {0.43868786,  0.85664061, -0.02487097,  0.00396135,  0.82162637,
        0.98335014,  0.26654993,  0.72614198, -0.28507867, -0.60861918};

    float outputs[4];

    forward(inputs, outputs);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", outputs[i]);
    }

    return 0;
}
