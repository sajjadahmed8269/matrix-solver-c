#!/bin/bash

# Define the specific beta tag
TAG="v1.0.0-beta"
URL="https://github.com/sajjadahmed8269/matrix-solver-c/releases/download/v1.0.0-beta/matrix-solver-linux"

echo -e "\033[1;33m⚠️  Installing Test Version ($TAG)...\033[0m"

# Download the pre-compiled static binary
curl -L $URL -o matrix-solver

if [ $? -ne 0 ]; then
    echo "❌ Download failed. Please check your internet connection and try again."
    exit 1
fi

# Make it executable
chmod +x matrix-solver

# Move it to /usr/local/bin
echo "Moving binary to /usr/local/bin (sudo required)..."
sudo mv matrix-solver /usr/local/bin/matrix-solver

echo -e "\033[1;32m✅ Beta Installation complete! Type 'matrix-solver' to run.\033[0m"