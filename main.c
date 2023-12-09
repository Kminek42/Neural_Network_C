#include <stdio.h>
#include <time.h>
#include "neural_network.h"

int main() {
    float inputs[10] = {-0.50056352,  1.01071153,  0.61573535,  0.80953371,  0.64661649,
        0.70775609, -1.10972236,  0.33435146,  1.89885651, -0.64108054};

    float outputs[4];

    forward(inputs, outputs);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", outputs[i]);
    }

    return 0;
}
