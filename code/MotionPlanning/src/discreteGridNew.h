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
  DiscreteGrid(const PointCloud& cloud, const vector<SceneObject>& sceneObjs);
  vector<vector<int>> travGrid() const;
private:
  void markUntraversible(const vector<SceneObject>& sceneObjs);
  void linePoints(LidarPoint p1, LidarPoint p2, vector<pair<int, int>>& points);
  bool isNotVisited(LidarPoint currPoint);
  std::vector<std::vector<int>> travGrid_;
  int height_;
  int width_;
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


int distTo(pair<int, int> p1, pair<int, int> p2);

vector<pair<int, int>> floydWardshallAlgorithm(vector<vector<int>>&maze ,pair<int, int> src,pair<int, int> target);