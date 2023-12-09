#include "neural_network.h"
#include <stdio.h>

neuralNetwork nn_make(int32_t* shape, int32_t layer_n) {
    neuralNetwork nn;
    nn.layer_n = layer_n;
    nn.layers = (layer*) malloc(sizeof(layer) * layer_n);

    for (int32_t i = 0; i < layer_n; i++) {
        nn.layers[i] = layer_make(shape[i], shape[i + 1]);
    }

    return nn;
}

void nn_free(neuralNetwork* nn) {
    for (int32_t i = 0; i < nn->layer_n - 1; i++) {
        layer_free(&nn->layers[i]);
    }
    free(nn->layers);
}

void nn_fill(neuralNetwork nn, float* wnb) {
    int32_t index = 0;
    for (int32_t i = 0; i < nn.layer_n; i++) {
        layer_fill(nn.layers[i], wnb + index);
        index += nn.layers[i].input_dim * nn.layers[i].output_dim;
        index += nn.layers[i].output_dim;
    }
}

void nn_forward(neuralNetwork nn, float* input, float* output) {
    float temp_input[50];
    for (int32_t j = 0; j < 10; j++) {
        output[j] = input[j];
    }

    for (int32_t i = 0; i < nn.layer_n; i++) {
        for (int32_t j = 0; j < 10; j++) {
            temp_input[j] = output[j];
        }

        layer_forward(nn.layers[i], temp_input, output);
        layer_activation(output, nn.layers[i].output_dim);
    }
}
