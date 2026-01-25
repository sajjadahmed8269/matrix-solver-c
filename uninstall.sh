#!/bin/bash
echo "Uninstalling Matrix Solver..."
if [ -f /usr/local/bin/matrix-solver ]; then
    sudo rm /usr/local/bin/matrix-solver
    echo -e "\033[1;32m✅ Successfully removed from /usr/local/bin\033[0m"
else
    echo "❌ Binary not found in /usr/local/bin"
fi