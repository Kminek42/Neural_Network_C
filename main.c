#include <stdio.h>
#include <time.h>
#include "neural_network.h"

int main() {
    float inputs[10] = {-1.07345792,  0.27974646,  2.58024343,  0.25565184,  0.15403624,
       -1.38389756,  0.32025532, -0.07782008,  0.23977592, -1.03075154};

    float outputs[4];

    forward(inputs, outputs);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", outputs[i]);
    }
    
    return 0;
}
