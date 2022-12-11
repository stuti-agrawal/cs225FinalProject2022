// it all begins here...
#include "filereader.h"
#include "KDTree.h"

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
    KDTree tree(cloud);
    LidarPoint pt = tree.findNearestNeighbor(LidarPoint(0, 0, 0));
    cout << pt << endl;
    return 0;
}