#include <iostream>
#include <vector>
using namespace std;

// Function to perform flood fill algorithm
void floodFillUtil(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    int rows = image.size();
    int cols = image[0].size();

    // Boundary conditions
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (image[x][y] != oldColor) return;

    // Replace the color
    image[x][y] = newColor;

    // Recursive calls for 4-directionally connected neighbors
    floodFillUtil(image, x + 1, y, newColor, oldColor);
    floodFillUtil(image, x - 1, y, newColor, oldColor);
    floodFillUtil(image, x, y + 1, newColor, oldColor);
    floodFillUtil(image, x, y - 1, newColor, oldColor);
}

void floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
    int oldColor = image[x][y];

    // If the starting pixel is already the new color, no need to process
    if (oldColor == newColor) return;

    floodFillUtil(image, x, y, newColor, oldColor);
}

// Helper function to print the image
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 1, 1, 1}
    };

    cout << "Original Image:" << endl;
    printImage(image);

    int x = 1; // Starting x-coordinate
    int y = 1; // Starting y-coordinate
    int newColor = 2; // New color to fill

    floodFill(image, x, y, newColor);

    cout << "\nImage after Flood Fill:" << endl;
    printImage(image);

    return 0;
}
