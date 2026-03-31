# Neural Networks from Scratch In C

Implementation of a machine learning for solve some logic gates.

I build this project to understand how neural networks works at the lowest level without using any libraries (like PyTorch or TensorFlow) I just uses C.

## Project Structure

* **`main.c` :** A basic linear model ($y = w \cdot x + b$) to understand the main concept of cost functions and learning rates.
* **`gates.c` (Single Neurons):** Trains single neurons to simulate basic logic gates (OR, AND, NAND).
* **`xor.c` (Multi-Layer Perceptron):** A 2-layer neural network, non-linearly separable XOR, The problem solved by using an the combination of OR, NAND, and AND.
* **`build.sh`:** A bash script for quick compilation and execution the code (for Linux user).

## Mathematical Foundation

Until now the model train using **Finite Differences** to approximate gradients rather than backpropagation. 

**Activation Function (Sigmoid):**
$$\sigma(x) = \frac{1}{1 + e^{-x}}$$

**Gradient Approximation (Finite Difference):**
To calculate how a specific weight ($w$) affects the cost ($J$), I bump up (gently push) the weight by small value ($h = 1e^{-3}$) and measure the change:
$$\frac{\partial J}{\partial w} \approx \frac{J(w + h) - J(w)}{h}$$, Weights are then updated using standard Gradient Descent.

## How to run the code:
You only need a C compiler (`gcc`) installed on your OS.
