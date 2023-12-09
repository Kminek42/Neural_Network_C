#include <math.h>

static float temp_1[4];
static float temp_2[3];

void forward(float inputs[5], float outputs[2]) {
    temp_1[0] = tanhf(0.21407825 * inputs[0] + 1.91917722 * inputs[1] + 2.53201529 * inputs[2] + 1.20476862 * inputs[3] + 1.31907295 * inputs[4] + -1.08764871);
    temp_1[1] = tanhf(-0.43052109 * inputs[0] + 0.2256469 * inputs[1] + 0.38884644 * inputs[2] + -0.51587187 * inputs[3] + 0.78786143 * inputs[4] + 1.56900279);
    temp_1[2] = tanhf(2.06420699 * inputs[0] + 2.12416658 * inputs[1] + -0.31582192 * inputs[2] + 0.82640666 * inputs[3] + 0.64632549 * inputs[4] + 0.24926898);
    temp_1[3] = tanhf(0.34626039 * inputs[0] + 1.95900035 * inputs[1] + 0.38662253 * inputs[2] + 1.08813946 * inputs[3] + -0.01620853 * inputs[4] + -0.75606542);

    temp_2[0] = tanhf(0.46905266 * temp_1[0] + -0.36024512 * temp_1[1] + 1.0294405 * temp_1[2] + -0.4251499 * temp_1[3] + 1.38346398);
    temp_2[1] = tanhf(0.63591815 * temp_1[0] + -0.01324119 * temp_1[1] + 0.66007271 * temp_1[2] + -0.14130964 * temp_1[3] + -1.38589353);
    temp_2[2] = tanhf(-1.74546171 * temp_1[0] + -1.69609045 * temp_1[1] + 0.28918981 * temp_1[2] + -2.28418226 * temp_1[3] + 1.43257772);

    outputs[0] = tanhf(1.05240218 * temp_2[0] + -0.46976046 * temp_2[1] + -0.63811541 * temp_2[2] + -0.66270276);
    outputs[1] = tanhf(-0.61461197 * temp_2[0] + -0.74432011 * temp_2[1] + 1.62107963 * temp_2[2] + 1.77150746);
}
