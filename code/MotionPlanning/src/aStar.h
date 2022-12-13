#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class AStar {
    public:

        typedef std::pair<int, int> Pair;
        typedef std::pair<double, std::pair<int, int> > pPair;
        struct cell {
            int parent_i, parent_j;
            double f, g, h;
        };

        AStar(int row, int col);

        bool isValid(int row, int col);
        bool isUnBlocked(vector<vector<int>> grid, int row, int col);
        bool isDestination(int row, int col, Pair dest);
        double calculateHValue(int row, int col, Pair dest);
        vector<pair<int, int>> tracePath(vector<std::vector<cell>> cellDetails, Pair dest);
        vector<pair<int, int>> aStarSearch(vector<vector<int>> grid, Pair src, Pair dest);
    private:
        int ROW;
        int COL;
};
