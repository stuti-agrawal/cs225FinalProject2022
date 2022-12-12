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