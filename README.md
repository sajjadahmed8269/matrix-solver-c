<div align="center">
<h1> Matrix Solver </h1>

**A powerful, lightweight C library for solving systems of linear equations**

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-lightgrey)]()
[![Language](https://img.shields.io/badge/language-C-orange.svg)]()

*Applying fundamental Computer Science principles to mathematical computation*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) •  [Uninstallation](#️-uninstallation) • [Building](#-building-from-source) • [Documentation](#-documentation)

</div>

---

## 📋 Overview

Matrix Solver is an efficient command-line tool for solving systems of linear equations of any size (n×n). Built with performance and reliability in mind, it implements industry-standard numerical methods with comprehensive error handling and a beautiful terminal interface.

### Why Matrix Solver?

- **🎯 Precision**: Implements Gaussian elimination with partial pivoting for numerical stability
- **🔍 Intelligence**: Automatically detects singular matrices, infinite solutions, and inconsistent systems
- **💡 Versatility**: Handles systems from 1×1 to 100×100 (and beyond with recompilation)
- **🎨 User-Friendly**: Colorful, intuitive interface with clear error messages
- **⚡ Performance**: Optimized C implementation with minimal memory footprint
- **🔧 Cross-Platform**: Works seamlessly on Linux and Windows

---

## ✨ Features

### Core Functionality

- **System Solver**: Solve n×n systems of linear equations using Gaussian elimination
- **Determinant Calculator**: Compute matrix determinants using cofactor expansion
- **Solution Classification**: Automatically identifies:
  - ✅ Unique solutions
  - ⚠️ Infinite solutions (dependent equations)
  - ❌ No solution (inconsistent systems)
  - 🚫 Singular matrices (non-invertible)

### Technical Highlights

- **Gaussian Elimination** with partial pivoting for enhanced numerical stability
- **Dynamic memory management** for efficient handling of variable-sized matrices
- **Robust error detection** including singular matrix detection and solution validation
- **IEEE 754 floating-point arithmetic** with configurable precision thresholds
- **Modular architecture** with clean separation between interface and logic

### User Experience

- 🎨 **Beautiful terminal UI** with ANSI color support
- ✓ **Unicode symbols** for visual feedback (cross-platform compatible)
- 📊 **Formatted output** with clear solution presentation
- 🛡️ **Input validation** with helpful error messages
- 🔄 **Graceful error handling** for edge cases

---

## 🚀 Installation

### Quick Install (Recommended)

#### Linux / macOS

```bash
curl -L https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/install.sh | bash
```

Or download and run manually:

```bash
wget https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/install.sh
chmod +x install.sh
./install.sh
```

#### Windows (PowerShell)

Run PowerShell as Administrator and execute:

```powershell
irm https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/install.ps1 | iex
```

Or download and run:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/install.ps1" -OutFile "install.ps1"
.\install.ps1
```

**Note**: After installation on Windows, restart your PowerShell window to update the PATH.

### Manual Installation

Download the latest pre-compiled binary from the [releases page](https://github.com/sajjadahmed8269/matrix-solver-c/releases):

- **Linux**: `matrix-solver-linux`
- **Windows**: `matrix-solver.exe`

Place the binary in your system PATH or run it directly.

---

## 💻 Usage

After installation, simply run:

```bash
matrix-solver
```

### Interactive Interface

The program will guide you through:

1. **Matrix Dimension**: Enter the size (n) for your n×n system
2. **Operation Selection**: Choose between:
   - Solving a system of linear equations
   - Calculating a matrix determinant
3. **Data Input**: Enter your matrix coefficients and constants
4. **Results**: View the computed solution or determinant

---

## 🗑️ Uninstallation

If you wish to remove the Matrix Solver from your system:

### 🐧 Linux
```bash
curl -sSL https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/uninstall.sh | bash
```

### 🪟 Windows (PowerShell)
```powershell
irm https://raw.githubusercontent.com/sajjadahmed8269/matrix-solver-c/main/uninstall.ps1 | iex
```
---

## 🔨 Building from Source

### Prerequisites

- **GCC** or any C compiler
- **Git** (for cloning)

### Clone the Repository

```bash
git clone https://github.com/sajjadahmed8269/matrix-solver-c.git
cd matrix-solver-c
```

### Compile

#### Compilation

```bash
gcc -o matrix-solver main.c matrix.c -lm
```

### Run

```bash
./matrix-solver
```

---

## 📚 Documentation

### Project Structure

```
matrix-solver-c/
├── main.c              # User interface and I/O handling
├── matrix.c            # Core mathematical operations
├── matrix.h            # Function declarations and structures
├── install.sh          # Linux/macOS installer
├── install.ps1         # Windows installer
└── README.md           # Project documentation
```

### Algorithm Details

#### Gaussian Elimination

The solver implements Gaussian elimination with partial pivoting:

1. **Forward Elimination**: Transforms the augmented matrix to row echelon form
2. **Partial Pivoting**: Selects the largest pivot to minimize rounding errors
3. **Singularity Detection**: Checks for near-zero pivots (< 10⁻¹²)
4. **Back Substitution**: Solves the triangular system from bottom to top

#### Determinant Calculation

Uses recursive cofactor expansion:

- **Base cases**: Direct calculation for 1×1 and 2×2 matrices
- **Recursive case**: Expansion along the first row
- **Complexity**: O(n!) - suitable for small to medium matrices

### Data Structures

```c
typedef struct {
    int size;        // Matrix dimension (n)
    double **data;   // 2D array of coefficients
} Matrix;
```

### Solution Types

```c
#define NO_SOLUTION        0  // Inconsistent system
#define UNIQUE_SOLUTION    1  // Single solution exists
#define INFINITE_SOLUTIONS 2  // Dependent equations
```

---

## 🎯 Use Cases

- **Engineering**: Solve circuit analysis, structural mechanics problems
- **Physics**: Linear system modeling and simulation
- **Computer Graphics**: Transformation matrix calculations
- **Economics**: Input-output models, equilibrium analysis
- **Education**: Learning linear algebra and numerical methods
- **Data Science**: Linear regression, least squares problems

---

## ⚙️ Configuration

### Precision Threshold

The default epsilon value is `1e-12`. To modify:

```c
// In matrix.c, change comparisons like:
if (fabs(value) < 1e-12)  // Current threshold
```

### Maximum Matrix Size

Default maximum is 100×100. To increase, modify validation in `main.c`:

```c
if (sscanf(buffer, "%d", &n) == 1 && n >= 1 && n <= 100)
```

---

## 🐛 Troubleshooting

### Common Issues

**Problem**: Colors not displaying correctly on Windows
- **Solution**: Ensure you're using Windows 10 version 1511 or later. The installer enables ANSI support automatically.

**Problem**: "Permission denied" when running installer on Linux
- **Solution**: Make the script executable: `chmod +x install.sh`

**Problem**: Matrix solver not found after installation
- **Solution**: On Windows, restart PowerShell. On Linux, run `source ~/.bashrc` or open a new terminal.

**Problem**: "Singular matrix detected" error
- **Solution**: Your system has no unique solution. Check that equations are independent and the coefficient matrix is invertible.

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Ideas for Contribution

- Add support for matrix multiplication and addition
- Implement LU decomposition
- Add QR decomposition solver
- Create a Python/JavaScript binding
- Improve performance with SIMD operations
- Add file input/output support

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

**Sajjad Ahmed**

- GitHub: [@sajjadahmed8269](https://github.com/sajjadahmed8269)
- Email: sajjadahmed8269@gmail.com

---

## 🌟 Acknowledgments

- Inspired by foundational linear algebra textbooks and numerical methods courses
- Built with a focus on clarity, correctness, and educational value
- Thanks to Mr. Hammad Nasir for the idea and testing support.

---

<div align="center">

**If you find this project helpful, please consider giving it a ⭐!**

Made with ❤️ and C

</div>