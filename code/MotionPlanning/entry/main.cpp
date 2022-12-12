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

    PointCloud cloud = readDataFile(dataFilename);
    vector<SceneObject> objects = readAnnotFile(annotFilename);
    DiscreteGrid dGrid(cloud, objects);
    // vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    //                                 {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
    //                                 {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    //                                 {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    //                                 {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    //                                 {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    //                                 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    //                                 {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    //                                 {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    // cout << dGrid.travGrid().size() << " " << dGrid.travGrid().at(0).size();
    // cout << "data reading complete" << endl;
    // vector<vector<int>> travGrid;
    int limY = dGrid.travGrid().at(0).size();
    int limX = dGrid.travGrid().size();
    // for (int r = 0; r < lim; r++) {
    //     vector<int> row;
    //     for (int c = 0; c < lim; c++) {
    //         int dec = 1;
    //         row.push_back(dec);
    //     }
    //     travGrid.push_back(row);
    // }

    vector<vector<int>> travGrid = dGrid.travGrid();

    BFS bfs;
    BFS::Point startPt{0, 0};
    BFS::Point endPt{limX-1, limY-1};
    vector<pair<int, int>> bfsPath = bfs.bfs(travGrid, startPt, endPt);
    
    int ROW = travGrid.size();
    int COL = travGrid.at(0).size();
    AStar aStar(ROW, COL);
    std::pair<int, int> start(0, 0);
    std::pair<int, int> end(limX-1, limY-1);
    vector<pair<int, int>> aStarPath = aStar.aStarSearch(travGrid, start, end);
    
    PNG toReturn = paintWithPointCloud(cloud);
    int count = 0;
    for (const auto& obj : objects) {
        cout << count++ << endl;
        toReturn = paintSceneObj(obj, toReturn);
    }
    // toReturn = paintSceneObj(objects.at(2), toReturn);
    cout << "SIZE:" << objects.size() << endl;
    toReturn.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");
    return 0;
}

