import numpy as np

tab = "    "

def print_matrix_mul(data, inputs_size, output_size, input_name, output_name):
    s = ""
    for i in range(output_size):
        s += f"{tab}{output_name}[{i}] = tanhf({data[i * inputs_size]} * {input_name}[0]"
        for j in range(1, inputs_size):
            s += f" + {data[i * inputs_size + j]} * {input_name}[{j}]"

        s += f" + {data[output_size * inputs_size + i]});\n"

    return s


layers = np.array([5, 4, 3, 2])

with open("genotype.csv", "r") as file:
    genotype = file.read().replace("\n", "").replace(" ", "").split(",")

genotype = np.array([float(num) for num in genotype])

print("#include <math.h>\n")

layer_names = ["inputs"]
for i in range(1, len(layers) - 1):
    layer_names.append(f"temp_{i}")
    print(f"static float temp_{i}[{layers[i]}];")
layer_names.append("outputs")

s = f"\nvoid forward(float inputs[{layers[0]}], float outputs[{layers[-1]}]) {{"
for i in range(len(layer_names) - 1):
    s += "\n"
    s += print_matrix_mul(genotype, layers[i], layers[i+1], layer_names[i], layer_names[i+1])
    genotype = genotype[layers[i] * layers[i + 1] + layers[i + 1]:]

print(s, end="")
print("}")
