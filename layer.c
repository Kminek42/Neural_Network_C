#include "neural_network.h"
#include <math.h>

layer layer_make(int32_t input_dim, int32_t output_dim) {
    layer l;
    l.input_dim = input_dim;
    l.output_dim = output_dim;
    l.weights = (float*) malloc(input_dim * output_dim * sizeof(float));
    l.biases = (float*) malloc(output_dim * sizeof(float));
    
    return l;
}

void layer_free(layer* l) {
    free(l->weights);
    free(l->biases);
}

void layer_fill(layer l, float* wnb) {
    int32_t index = 0;
    for (int i = 0; i < l.input_dim * l.output_dim; ++i) {
        l.weights[i] = wnb[index++];
    }

    for (int32_t i = 0; i < l.output_dim; ++i) {
        l.biases[i] = wnb[index++];
    }
}

void layer_forward(layer l, float* inputs, float* outputs) {
    for (int32_t i = 0; i < l.output_dim; i++) {
        outputs[i] = 0;
        for (int32_t j = 0; j < l.input_dim; j++) {
            outputs[i] += l.weights[i * l.input_dim + j] * inputs[j];
        }
        outputs[i] += l.biases[i];
    }
}

void layer_activation(float* data, int32_t len) {
    for (int32_t i = 0; i < len; i++) {
        data[i] = tanhf(data[i]);
    }
}
