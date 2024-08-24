// class Solution {

// private:
//     void dfs(int row, int col, int newColor, int initcolor, vector<vector<int>>& ans,
//              int deltaRow[], int deltaCol[]) {
//         ans[row][col] = newColor;
//         int n = ans.size();
//         int m = ans[0].size();

//         for (int i = 0; i < 4; i++) {
//             int nrow = row + deltaRow[i];
//             int ncol = col + deltaCol[i];
//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                 ans[nrow][ncol] == initcolor) {

//                 dfs(nrow, ncol, newColor, initcolor, ans, deltaRow,
//                     deltaCol);
//             }
//         }
//     }

// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
//                                   int color) {
        
//         int initialColor = image[sr][sc];
//         if (initialColor == color) return image;
//         vector<vector<int>> ans = image;

//         int deltaRow[] = {-1, 0, +1, 0};
//         int deltaCol[] = {0, +1, 0, -1};

//         dfs(sr, sc, color, initialColor, ans, deltaRow, deltaCol);

//         return ans;
//     }
// };

//------------CLEAN, MODULAR AND PRODUCTION READY CODE

// #include <vector>

// class Solution {
// public:
//     std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
//         int initialColor = image[sr][sc];
        
//         // If the new color is the same as the initial color, no need to proceed
//         if (initialColor == newColor) return image;

//         // Create a copy of the image to store the result
//         std::vector<std::vector<int>> result = image;

//         // Define direction vectors for the four possible directions (up, right, down, left)
//         const std::vector<int> deltaRow = {-1, 0, +1, 0};
//         const std::vector<int> deltaCol = {0, +1, 0, -1};

//         // Start DFS to fill the connected component
//         dfs(sr, sc, newColor, initialColor, result, deltaRow, deltaCol);

//         return result;
//     }

// private:
//     // Depth-First Search (DFS) function to perform the flood fill
//     void dfs(int row, int col, int newColor, int initialColor, 
//              std::vector<std::vector<int>>& image, 
//              const std::vector<int>& deltaRow, const std::vector<int>& deltaCol) {
        
//         int rows = image.size();
//         int cols = image[0].size();
        
//         // Fill the current pixel with the new color
//         image[row][col] = newColor;

//         // Explore the four possible directions
//         for (int i = 0; i < 4; ++i) {
//             int newRow = row + deltaRow[i];
//             int newCol = col + deltaCol[i];
            
//             // Check if the new position is within bounds and has the initial color
//             if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
//                 image[newRow][newCol] == initialColor) {
//                 dfs(newRow, newCol, newColor, initialColor, image, deltaRow, deltaCol);
//             }
//         }
//     }
// };

//PRODUCTION READY +GOOGLE STYLE GUIDE CODE
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, 
                                           int sr, int sc, int new_color) {
    int initial_color = image[sr][sc];
    
    // If the new color is the same as the initial color, no need to proceed.
    if (initial_color == new_color) return image;

    // Create a copy of the image to store the result.
    std::vector<std::vector<int>> result = image;

    // Direction vectors for the four possible directions (up, right, down, left).
    constexpr int kNumDirections = 4;
    constexpr int delta_row[kNumDirections] = {-1, 0, +1, 0};
    constexpr int delta_col[kNumDirections] = {0, +1, 0, -1};

    // Start DFS to fill the connected component.
    Dfs(sr, sc, new_color, initial_color, result, delta_row, delta_col, kNumDirections);

    return result;
  }

 private:
  // Depth-First Search (DFS) function to perform the flood fill.
  void Dfs(int row, int col, int new_color, int initial_color, 
           std::vector<std::vector<int>>& image, 
           const int delta_row[], const int delta_col[], int kNumDirections) {
    int rows = image.size();
    int cols = image[0].size();
    
    // Fill the current pixel with the new color.
    image[row][col] = new_color;

    // Explore the four possible directions.
    for (int i = 0; i < kNumDirections; ++i) {
      int new_row = row + delta_row[i];
      int new_col = col + delta_col[i];
      
      // Check if the new position is within bounds and has the initial color.
      if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && 
          image[new_row][new_col] == initial_color) {
        Dfs(new_row, new_col, new_color, initial_color, image, delta_row, delta_col, kNumDirections);
      }
    }
  }
};

