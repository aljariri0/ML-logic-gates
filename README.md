# Neural Networks from Scratch In C

A foundational implementation of machine learning concepts, logic gates, and a Multi-Layer Perceptron (MLP) written purely in C. 

demonstrates how neural networks operate at the lowest level without relying on external mathematical or machine learning libraries (like PyTorch or TensorFlow). It uses pure C to calculate gradients, update weights, and minimize cost functions to train models to replicate logical operations.

## Project Structure

* **`main.c` (Linear Regression):** A basic linear model trained on a simple dataset ($y = w \cdot x + b$) to demonstrate the concept of cost functions and learning rates.
* **`gates.c` (Single Neurons):** Trains individual neurons to replicate basic logic gates (OR, AND, NAND) using a Sigmoid activation function.
* **`xor.c` (Multi-Layer Perceptron):** A 2-layer neural network designed to solve the classic, non-linearly separable XOR problem. It structurally mimics the logical equivalent of XOR using an underlying combination of OR, NAND, and AND configurations.
* **`build.sh`:** A convenience bash script for quick compilation and execution (for Linux user).

## Mathematical Foundation

Currently, the models in this repository train using **Finite Differences** to approximate gradients rather than backpropagation. 

**Activation Function (Sigmoid):**
$$\sigma(x) = \frac{1}{1 + e^{-x}}$$

**Gradient Approximation (Finite Difference):**
To calculate how a specific weight ($w$) affects the cost ($J$), we tweak the weight by a microscopically small value ($h = 1e^{-3}$) and measure the change:
$$\frac{\partial J}{\partial w} \approx \frac{J(w + h) - J(w)}{h}$$, Weights are then updated using standard Gradient Descent.

## Getting Started

**Prerequisites:** You only need a C compiler (`gcc`) installed on your system.
