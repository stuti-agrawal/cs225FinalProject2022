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

TEST_CASE("BFS finds the right order of points", "[weight=2][part=1]") {
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
    BFS::Point endPt{9, 8};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    REQUIRE( bfsPath.size()== 5);
    REQUIRE(bfsPath[0] == make_pair(0,0)); // change to expected
    // REQUIRE(bfsPath == "vec required"); // change to expected

}

TEST_CASE("IDDFS finds the right order of points", "[weight=2][part=1]") {
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
    std::pair<int, int> end(2, 2);
    auto iddfsPath = iddfs(travGrid, start, end, 4);
    REQUIRE( iddfs.size()== 5);
    REQUIRE(iddfs[0] == make_pair(0,0));
}