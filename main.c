#include <stdio.h>
#include <time.h>
#include "neural_network.h"

int main() {
    // pasted inputs from example.ipynb
    float inputs[10] = { 0.07082579,  1.19235938, -2.11560745,  1.67636365, -0.36249863,
       -0.589093  , -0.52791061, -0.30395947, -0.70612336,  1.48633107};

    float outputs[4];

    forward(inputs, outputs);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", outputs[i]);
    }

    return 0;
}
