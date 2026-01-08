# Matrix Solver (C)

A lightweight and efficient C library for solving systems of linear equations using fundamental linear algebra techniques. This project was developed to apply core Computer Science principles—such as memory management and modular programming—to mathematical computation.

## 🚀 Features
* **Cramer's Rule Solver:** Efficiently solves 3x3 systems using determinant ratios.
* **Matrix Inversion Method:** Solves systems of the form $AX = B$.
* **Modular Architecture:** Separated logic (`matrix.c`) and interface (`matrix.h`) for easy integration.
* **Automated Build:** Includes a `Makefile` for quick compilation.

## 🛠️ Installation & Usage
To use this solver, clone the repository and compile using `make`:

```bash
# Clone the repository
git clone https://github.com/sajjadahmed8269/matrix-solver-c.git

# Enter the directory
cd matrix-solver-c

# Build the project
make

# Run the program
./matrix_solver