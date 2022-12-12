#pragma once

#include <vector>
#include <iterator>
#include <stack>
#include <queue>
#include <cmath>
#include <limits.h>

#include "../lib/motionPlanning/pointCloud.h"
#include "../lib/motionPlanning/sceneObject.h"


class DiscreteGrid {
public:
  DiscreteGrid();
  DiscreteGrid(const PointCloud& cloud, const vector<SceneObject> sceneObjs);
  vector<vector<int>> travGrid() const;
private:
  bool isNotVisited(LidarPoint currPoint);
  std::vector<std::vector<int>> travGrid_;
  int height_;
  int width_;
};

class Djikstra {
  public:
    int findShortestPathLength(vector<vector<int>> &mat, pair<int, int> &src, pair<int, int> &dest);
  private:
    bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y);
    void findShortestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int x, int y, int &min_dist, int dist);
  public:
  
  private:
};

class BFS {
  public:
  struct Point {
    int x;
    int y;
  };
  struct queueNode {
    Point pt;  
    int dist;  
  };
  
  vector<pair<int, int>> bfs(vector<vector<int>> &mat, Point src, Point dest);
  private:
    bool isValid(const vector<vector<int>> &mat, int row, int col);

  public:
  private:
};