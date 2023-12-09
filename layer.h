#pragma once
#include <stdlib.h>

typedef struct {
    float* weights;
    float* biases;
    int32_t input_dim;
    int32_t output_dim;
} layer;

layer layer_make(int32_t input_dim, int32_t output_dim);
void layer_free(layer* l);
void layer_fill(layer l, float* wnb);

void layer_forward(layer l, float* inputs, float* outputs);
void layer_activation(float* data, int32_t len);
