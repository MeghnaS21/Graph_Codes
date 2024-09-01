class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // getting the number of rows and coumns of the given matrix
        int n = grid.size();
        int m = grid[0].size();

        // creating a visited matrix of size nxm, intitialised with
        // 0(false/univisited)
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // creating a queue tracker that takes all the boundary cordinates wiht
        // the value 1(land)

        queue<pair<int, int>> tracker;

        // traverse boundary elements and put cordinates having 1 in it. i.e.
        // land traver first row, last row
        //TC = O(2N+2M)
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && grid[0][i] == 1) {
                visited[0][i] = 1;
                tracker.push({0, i});
            }

            if (!visited[n - 1][i] && grid[n - 1][i] == 1) {
                visited[n - 1][i] = 1;
                tracker.push({n - 1, i});
            }
        }

        // traverse first column, last column
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                visited[i][0] = 1;
                tracker.push({i, 0});
            }

            if (!visited[i][m - 1] && grid[i][m - 1] == 1) {
                visited[i][m - 1] = 1;
                tracker.push({i, m - 1});
            }
        }

        // done with the intitial configuration
        // marked all the boundry elememts with 1, visited and also pushed into
        // the queue

        // Traver all the neighbours of the queue elements and mark all of the
        // attached elememts as visited all 4 direction traversal

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        while (!tracker.empty()) { //tc = O(N*M)
            int row = tracker.front().first;
            int col = tracker.front().second;

            // now that i have extracted the cordinates, I'm gonna pop them.
            tracker.pop();

            // traverse and check for all 4 directions.
            // if found, then push it into the queue and mark it visited.

            for (int i = 0; i < 4; i++) {
                int new_row = row + delta_row[i];
                int new_col = col + delta_col[i];

                // check for the validity and condition if it ever encounters 1
                if (new_row >= 0 && new_row < n && new_col >= 0 &&
                    new_col < m && !visited[new_row][new_col] &&
                    grid[new_row][new_col] == 1) {
                    visited[new_row][new_col] = 1;
                    tracker.push({new_row, new_col});
                }
            }
        }

        // final traversal on the grid to check for 1 & not visited cordinates
        // also maintain a counter
        int count_land = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    ++count_land;
            }
        }

        return count_land;
    }
};
