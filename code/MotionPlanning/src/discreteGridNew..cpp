#include "discreteGridNew.h"

using namespace std;

DiscreteGrid::DiscreteGrid() {}

DiscreteGrid::DiscreteGrid(const PointCloud& cloud, const vector<SceneObject> sceneObjs) {
  int width = ceil(cloud.max()[0] - cloud.min()[0]);
  int height = ceil(cloud.max()[1] - cloud.min()[1]);

  for (auto _ = width; _--;) {
    travGrid_.push_back(vector<int> (height, 1));
  }

  for (const auto& obj : sceneObjs) {
    // cout << abs(cloud.min()[0] - obj[0]) << " " << floor(obj[0]) << " " << obj[1] << " " << floor(obj[1]) << endl;
    travGrid_.at(abs(cloud.min()[0] - obj[0])).at(abs(cloud.min()[1] - obj[1])) = 0; //TODO: add function to add whole object
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

bool Djikstra::isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y)
{
	return (x >= 0 && x < (int) mat.size() && y >= 0 && y < (int) mat[0].size()) &&
			mat[x][y] == 1 && !visited[x][y];
}


void Djikstra::findShortestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
				int i, int j, int x, int y, int &min_dist, int dist){
	cout << "called" << endl;
  if (i == x && j == y){
		min_dist = min(dist, min_dist);
		return;
	}
	// set (i, j) cell as visited
	visited[i][j] = true;
	// go to the bottom cell
	if (isSafe(mat, visited, i + 1, j)) {
		findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
	}
	// go to the right cell
	if (isSafe(mat, visited, i, j + 1)) {
		findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
	}
	// go to the top cell
	if (isSafe(mat, visited, i - 1, j)) {
		findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
	}
	// go to the left cell
	if (isSafe(mat, visited, i, j - 1)) {
		findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
	}
	// backtrack: remove (i, j) from the visited matrix
	visited[i][j] = false;
}

// Wrapper over findShortestPath() function
int Djikstra::findShortestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
					pair<int, int> &dest){
	if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
			mat[dest.first][dest.second] == 0)
		return -1;
	
	int row = mat.size();
	int col = mat[0].size();
	// construct an `M × N` matrix to keep track of visited cells
	vector<vector<bool>> visited;
	visited.resize(row, vector<bool>(col));

	int dist = INT_MAX;
	findShortestPath(mat, visited, src.first, src.second, dest.first, dest.second,
			dist, 0);

	if (dist != INT_MAX)
		return dist;
	return -1;
}

bool BFS::isValid(int row, int col)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

// function to find the shortest path between
// a given source cell to a destination cell.
int BFS::findShortestPathLength(vector<vector<int>> &mat, Point src, Point dest)
{
	// check source and destination cell
	// of the matrix have value 1
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
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
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

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
			if (isValid(row, col) && mat[row][col] &&
			!visited[row][col])
			{
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	// Return -1 if destination cannot be reached
	return -1;
}