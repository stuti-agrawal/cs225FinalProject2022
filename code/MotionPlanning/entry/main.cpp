// it all begins here...
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

using namespace std;
using namespace cs225;

    
int main(int argc, char** argv) {
    string dataFilename = argv[1];
    string annotFilename = argv[2];
    string frameID = argv[3];

    PointCloud cloud = readDataFile(dataFilename);
    vector<SceneObject> objects = readAnnotFile(annotFilename, frameID, cloud.min()[0], cloud.min()[1]);
    DiscreteGrid dGrid(cloud, objects);

    vector<vector<int>> travGrid = dGrid.travGrid();
    pair<int, int> egoVehicleLoc = cloud.egoVehicleLoc();
    BFS bfs;
    BFS::Point startPt{egoVehicleLoc.first, egoVehicleLoc.second};
    BFS::Point endPt{egoVehicleLoc.first, 0};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    
    int ROW = travGrid.size();
    int COL = travGrid.at(0).size();
    AStar aStar(ROW, COL);
    std::pair<int, int> start(egoVehicleLoc.first, egoVehicleLoc.second);
    std::pair<int, int> end(egoVehicleLoc.first, 0);
    vector<pair<int, int>> aStarPath = aStar.aStarSearch(travGrid, start, end);

    vector<pair<int, int>> floydPath = floydWardshallAlgorithm(travGrid, start, end);
    
    PNG toReturn = paintWithPointCloud(cloud);
    
    int count = 0;
    for (const auto& obj : objects) {
        toReturn = paintSceneObj(obj, toReturn);
    }
    toReturn = paintPath(bfsPath, toReturn, "aStar");
    toReturn = paintPath(aStarPath, toReturn, "bfs");
    toReturn = paintPath(floydPath, toReturn, "floyd")

    toReturn.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");

    // vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    //                                 {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
    //                                 {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    //                                 {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    //                                 {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    //                                 {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    //                                 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    //                                 {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    //                                 {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    // std::pair<int, int> start(0, 0);
    // std::pair<int, int> end(1,0);
    // auto floydPath = floydWardshallAlgorithm(travGrid, start, end);
    return 0;
}




