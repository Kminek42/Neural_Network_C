#pragma once
#include "layer.h"

typedef struct {
    layer* layers;
    int32_t layer_n;
} neuralNetwork;

neuralNetwork nn_make(int32_t* shape, int32_t layer_n);
void nn_free(neuralNetwork* nn);
void nn_fill(neuralNetwork nn, float* wnb);

void nn_forward(neuralNetwork nn, float* input, float* output);
