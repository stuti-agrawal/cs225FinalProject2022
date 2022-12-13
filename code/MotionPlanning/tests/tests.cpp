#include <catch2/catch_test_macros.hpp>
#include "filereader.h"
#include "KDTree.h"
#include "cluster.h"
#include "visualize.h"
#include "discreteGridNew.h"
#include "aStar.h"
#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

TEST_CASE("BFS finds the right order of points for points in the middle of the graph", "[part=1]") {
    int expected_size = 14;
    vector<pair<int, int>> expected_path(Point(5,5), Point(4,5),Point(4,4),Point(3,4),Point(2,4),Point(1,4),Point(0,4),Point(0,3),Point(0,2),Point(1,2),Point(2,2),Point(2,1),Point(2,0),Point(1,0),Point(0,0));
    vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    BFS bfs;
    BFS::Point startPt{0, 0};
    BFS::Point endPt{5, 5};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    REQUIRE( bfsPath.size()== expected_size);
    REQUIRE(bfsPath == expected_path); 
}

TEST_CASE("BFS finds the path for a point at the edge", "[part=1]") {
    int expected_size = 23;
    vector<pair<int, int>> expected_path(Point(8,0), Point(7,0),Point(6,0),Point(5,0),Point(4,0),Point(4,1),Point(4,2),Point(5,2),Point(5,3),Point(5,4),Point(4,4),Point(3,4),Point(2,4),Point(1,4),Point(0,4),Point(0,3),Point(0,2),Point(1,2),Point(2,2),Point(2,1),Point(2,0),Point(1,0),Point(0,0));
    vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    BFS bfs;
    BFS::Point startPt{0, 0};
    BFS::Point endPt{0, 9};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    REQUIRE( bfsPath.size()== expected_size);
    REQUIRE(bfsPath == expected_path); 
}

TEST_CASE("BFS: No path between two points", "[part=1]") {
    int expected_size = 0;
    vector<pair<int, int>> expected_path;
    vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    BFS bfs;
    BFS::Point startPt{0, 0};
    BFS::Point endPt{6,4};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    REQUIRE( bfsPath.size()== expected_size);
    REQUIRE(bfsPath == expected_path); 
}

TEST_CASE("Floyd-Warshall finds the right order of points for points in the middle of the grid", "[part=1]") {
  int expected_size = 13;
  vector<pair<int, int>> expected_path(make_pair(0,0), make_pair(1,0),make_pair(2,0),make_pair(2,1),make_pair(2,2),make_pair(1,2),make_pair(0,2),make_pair(0,3),make_pair(0,4),make_pair(1,4),make_pair(2,4),make_pair(3,4),make_pair(4,4));
  vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(4, 4);
    auto floydPath = floydWardshallAlgorithm(travGrid, start, end);
    REQUIRE(floydPath.size() == expected_size);
    REQUIRE(floydPath == expected_path);
}

TEST_CASE("Floyd-Warshall finds the path for a point at the edge", "[part=1]") {
   int expected_size = 24;
  vector<pair<int, int>> expected_path(make_pair(0,0), make_pair(1,0),make_pair(2,0),make_pair(2,1),make_pair(2,2),make_pair(1,2),make_pair(0,2),make_pair(0,3),make_pair(0,4),make_pair(1,4),make_pair(2,4),make_pair(3,4),make_pair(4,4),make_pair(5,4),make_pair(5,3),make_pair(5,2),make_pair(4,2),make_pair(4,1),make_pair(4,0),make_pair(5,0),make_pair(6,0),make_pair(7,0),make_pair(8,0),make_pair(8,1));
  vector<vector<int>> travGrid = {  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(8, 2);
    auto floydPath = floydWardshallAlgorithm(travGrid, start, end);
    REQUIRE(floydPath.size() == expected_size);
    REQUIRE(floydPath == expected_path);
}

TEST_CASE("Floyd-Warshall: no path exists between the start and end", "[part=1]") {
  int expected_size = 0;
  vector<pair<int, int>> expected_path;
  vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(8,3);
    auto floydPath = floydWardshallAlgorithm(travGrid, start, end);
    REQUIRE(floydPath.size()== expected_size);
    REQUIRE(floydPath == expected_path);
}

TEST_CASE("A* finds the right order of points for points at the edge of the grid", "[part=1]") {
  int expected_size = 4;
  vector<pair<int, int>> expected_path(make_pair(0,0), make_pair(1,0),make_pair(2,1),make_pair(2,2));
  vector<vector<int>> travGrid = {{1, 0, 1, 1, 1},
                                    {1, 0, 1, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 1},
                                    {1, 0, 0, 0, 0}};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(6,0);
    int ROW = travGrid.size();
    int COL = travGrid.at(0).size();
    AStar aStar(ROW, COL);
    vector<pair<int, int>> aStarPath = aStar.aStarSearch(travGrid, start, end);
    REQUIRE(aStarPath.size()== expected_size);
    REQUIRE(aStarPath == expected_path);
}

TEST_CASE("A* finds the path for a point at the edge", "[part=1]") {
  int expected_size = 14;
  vector<pair<int, int>> expected_path(make_pair(0,0), make_pair(1,0),make_pair(2,1),make_pair(1,2),make_pair(0,3),make_pair(1,4),make_pair(2,4),make_pair(3,4),make_pair(4,4),make_pair(5,3),make_pair(5,2),make_pair(4,1),make_pair(5,0),make_pair(6,0) );
  vector<vector<int>> travGrid = {{1, 0, 1, 1, 1},
                                    {1, 0, 1, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 1},
                                    {1, 0, 0, 0, 0}};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(6,0);
    int ROW = travGrid.size();
    int COL = travGrid.at(0).size();
    AStar aStar(ROW, COL);
    vector<pair<int, int>> aStarPath = aStar.aStarSearch(travGrid, start, end);
    REQUIRE(aStarPath.size()== expected_size);
    REQUIRE(aStarPath == expected_path);
}

TEST_CASE("A*: no path exists between the start and end", "[part=1]") {
  int expected_size = 0;
  vector<pair<int, int>> expected_path;
  vector<vector<int>> travGrid = {{1, 0, 1, 1, 1},
                                    {1, 0, 1, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 1},
                                    {1, 0, 0, 0, 0}};
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(6,2);
    int ROW = travGrid.size();
    int COL = travGrid.at(0).size();
    AStar aStar(ROW, COL);
    vector<pair<int, int>> aStarPath = aStar.aStarSearch(travGrid, start, end);
    REQUIRE(aStarPath.size()== expected_size);
    REQUIRE(aStarPath == expected_path);
}