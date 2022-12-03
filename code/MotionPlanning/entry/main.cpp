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
    const float* minPt = cloud.min();
    cout << "smallest point:" << endl;
    for (int i = 0; i < Dim; i++) cout << minPt[i] << " ";
    cout << endl;

    const float* maxPt = cloud.max();
    cout << "largest point:" << endl;
    for (int i = 0; i < Dim; i++) cout << maxPt[i] << " ";
    cout << endl;
    LidarPoint pt = tree.findNearestNeighbor(LidarPoint(0, 0, 0));
    cout << "pt: " << pt << endl;
    return 0;
}