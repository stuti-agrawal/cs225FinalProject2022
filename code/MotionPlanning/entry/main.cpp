// it all begins here...
#include "filereader.h"
#include "KDTree.h"
#include "cluster.h"
#include "discreteGrid.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"
#include "visualize.h"
using namespace std;
using namespace cs225;

int main(int argc, char** argv) {
    string dataFilename = argv[1];
    string annotFilename = argv[2];

    PointCloud cloud = readDataFile(dataFilename);
    vector<SceneObject> objects = readAnnotFile(annotFilename);
    DiscreteGrid dGrid(cloud, objects);
    vector<vector<int>> travGrid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
				{1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
				{1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
				{1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
				{1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
				{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    // dGrid.travGrid();
    Djikstra djikstra;
    pair<int, int> start(0, 0);
    pair<int, int> end(7, 9);
    int dist = djikstra.findShortestPathLength(travGrid, start, end);
    cout << dist << endl;
    // for (const auto& object : objects) {
    //     cout << object[0] << " " << object[1] << " " << object[2] << endl;
    // }
    return 0;
}

