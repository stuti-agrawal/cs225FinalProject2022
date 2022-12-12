#include "discreteGridNew.h"


using namespace std;

auto PAIR_NULL = make_pair(2000,2000);

DiscreteGrid::DiscreteGrid() {}

DiscreteGrid::DiscreteGrid(const PointCloud& cloud, const vector<SceneObject> sceneObjs) {
  int width = ceil(cloud.max()[0] - cloud.min()[0]);
  int height = ceil(cloud.max()[1] - cloud.min()[1]);

  for (auto _ = width; _--;) {
    travGrid_.push_back(vector<int> (height, 1));
  }

  for (const auto& obj : sceneObjs) {
    // cout << abs(cloud.min()[0] - obj[0]) << " " << floor(obj[0]) << " " << obj[1] << " " << floor(obj[1]) << endl;
    travGrid_.at(floor(obj[0])).at(floor(obj[1])) = 0; //TODO: add function to add whole object
  }

  // for (int c = 0; c < width; c++) {
  //   for (int r = 0; r < height; r++) {
  //     cout << travGrid_.at(c).at(r);
  //   }
  // }
}

vector<vector<int>> DiscreteGrid::travGrid() const {
  return travGrid_;
}

bool BFS::isValid(const vector<vector<int>> &mat, int row, int col)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < (int) mat.size()) &&
		(col >= 0) && (col < (int) mat.at(0).size());
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

// function to find the shortest path between
// a given source cell to a destination cell.
vector<pair<int, int>> BFS::bfs(vector<vector<int>> &mat, Point src, Point dest)
{
	// check source and destination cell
	// of the matrix have value 1
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return vector<pair<int, int>>();
    
    int row = mat.size();
	int col = mat[0].size();
	// construct an `M × N` matrix to keep track of visited cells
	vector<vector<bool>> visited;
	visited.resize(row, vector<bool>(col));

	vector<vector<pair<int, int>>> prev;
	prev.resize(row, vector<pair<int, int>>(col, make_pair(-1, -1)));
	
	
	// Mark the source cell as visited
	visited[src.x][src.y] = true;


	// Create a queue for BFS
	queue<queueNode> q;
	
	// Distance of source cell is 0
	queueNode s = {src, 0};
	q.push(s); // Enqueue source cell

	// Do a BFS starting from source cell
	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		// If we have reached the destination cell,
		// we are done
		if (pt.x == dest.x && pt.y == dest.y) {
			// backtrack after finding solution
			vector<pair<int, int>> path;
			pair<int, int> currPair = make_pair(pt.x, pt.y);
			while (currPair.first != -1 && currPair.second != -1) {
				path.push_back(currPair);
				currPair = prev[currPair.first][currPair.second];
			}
			return path;
		}

		// Otherwise dequeue the front
		// cell in the queue
		// and enqueue its adjacent cells
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			
			// if adjacent cell is valid, has path and
			// not visited yet, enqueue it.
			if (isValid(mat, row, col) && mat[row][col] &&
			!visited[row][col])
			{
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				q.push(Adjcell);
				prev[row][col] = make_pair(pt.x, pt.y);
			}
		}
	}

	// Return -1 if destination cannot be reached
	return vector<pair<int, int>>();
}

// Utility DFS function -- returns DFS Path if it exists, -1 if not exists
vector<pair<int, int>> dfs_util(vector<pair<int, int>> path, pair<int, int> target, vector<vector<int>> &grid, int depth, vector<vector<int>>& visited)
{
    pair<int, int> curr_cell = path.back();
    if (curr_cell == target)
        return path;
    if (depth <= 0)
    {
        vector<pair<int, int>> tmp;
        tmp.push_back(PAIR_NULL);
        return tmp;
    }
    vector<pair<int, int>> children;
    if (curr_cell.first > 0 && grid[curr_cell.first-1][curr_cell.second]) children.push_back(make_pair(curr_cell.first-1, curr_cell.second));
    if (curr_cell.second+1 < (int)grid.size() && grid[curr_cell.first][curr_cell.second+1]) children.push_back(make_pair(curr_cell.first, curr_cell.second+1));
    if (curr_cell.first+1 < (int)grid[0].size() && grid[curr_cell.first+1][curr_cell.second]) children.push_back(make_pair(curr_cell.first+1, curr_cell.second));
    if (curr_cell.second > 0 && grid[curr_cell.first][curr_cell.second-1]) children.push_back(make_pair(curr_cell.first, curr_cell.second-1));
    for (auto neighbour : children)
    {
		cout << "&&&&&" <<  neighbour.first << "," << neighbour.second << endl;
        vector<pair<int, int>> new_path = path;
        if (!visited[neighbour.first][neighbour.second]) new_path.push_back(neighbour);
		visited[neighbour.first][neighbour.second] = 1;
        vector<pair<int, int>> result = dfs_util(new_path, target, grid, depth - 1, visited);
        if (result.back() != PAIR_NULL)
        {
            return result;
        }
    }
    children.clear();
    vector<pair<int, int>> tmp;
    tmp.push_back(PAIR_NULL);
    return tmp;
}

// IDDFS Function -- returns IDDFS Path if it exists, -1 if not
vector<pair<int, int>> iddfs(vector<vector<int>>&grid,pair<int, int> src,pair<int, int> target, int max_depth)
{
    vector<pair<int, int>> result;
    max_depth++;
    for (int depth = 0; depth < max_depth; depth++)
    {
		vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        vector<pair<int, int>> path;
        path.push_back(src);

        result = dfs_util(path, target, grid, depth, visited);
        if (result.back() == PAIR_NULL || result.size() == 0)
            continue;
        int final_index = 0;
        int idx_count = 0;
        for (auto item : result)
        {
            if (item == src)
                final_index = max(final_index, idx_count);
            idx_count++;
        }
        result = vector<pair<int, int>>(result.begin() + final_index, result.end());
    }
    return result;
}


vector<pair<int, int>> floydWardshallAlgorithm(vector<vector<int>>&maze ,pair<int, int> src,pair<int, int> target) {
	vector<vector<vector<vector<int>>>> dist(maze.size(), vector<vector<vector<int>>>
                                           (maze[0].size(), vector<vector<int>>
                                           (maze.size(), vector<int>
                                           (maze[0].size()))));
	vector<vector<vector<vector<pair<int, int>>>>> next(maze.size(), vector<vector<vector<pair<int, int>>>>
                                           (maze[0].size(), vector<vector<pair<int, int>>>
                                           (maze.size(), vector<pair<int, int>>
                                           (maze[0].size()))));
		
		for(int i = 0; i < (int)maze.size(); i++){
			for(int j = 0; j < (int)maze[0].size(); j++){
				pair<int, int> p1 = make_pair(i, j);
				
				for(int k = 0; k < (int)maze.size(); k++){
					for(int l = 0; l < (int)maze[0].size(); l++){
						pair<int, int> p2 = make_pair(k, l);
						
						dist[i][j][k][l] = (maze[k][l] != 1 && distTo(p1,p2) == 1) ? 1 : INT_MAX;
						next[i][j][k][l] = (distTo(p1, p2) > 1 || maze[k][l] == 1) ? pair<int, int>(): p2;
					}
				}
			}
		}
		
		for(int i = 0; i < (int)maze.size(); i++){
			for(int j = 0; j < (int)maze[0].size(); j++){
				for(int k = 0; k < (int)maze.size(); k++){
					for(int l = 0; l < (int)maze[0].size(); l++){
						if(dist[k][l][i][j] == INT_MAX)
							continue;
						
						for(int m = 0; m < (int)maze.size(); m++){
							for(int n = 0; n < (int)maze[0].size(); n++){
								if(dist[i][j][m][n] == INT_MAX)
									continue;
								
								if(dist[k][l][m][n] > dist[k][l][i][j] + dist[i][j][m][n]){
									dist[k][l][m][n] = dist[k][l][i][j] + dist[i][j][m][n];
									next[k][l][m][n] = next[k][l][i][j];
								}
							}
						}
					}
				}
			}
		}
		
		if(next[src.first][src.second][target.first][target.second] == pair<int, int>())
			return vector<pair<int, int>>();
		
		vector<pair<int, int>> result;
		pair<int, int> curr = src;
		
		result.push_back(curr);
		
		while(curr!=target){
			curr = next[curr.first][curr.second][target.first][target.second];
			result.push_back(curr);
		}
		
		return result;
}

int distTo(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}