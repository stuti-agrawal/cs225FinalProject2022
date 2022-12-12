// it all begins here...
#include "filereader.h"
#include "KDTree.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"
#include "visualize.h"
using namespace std;
using namespace cs225;

int main() {
    // PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
    
    // KDTree tree(cloud);
    // const float* minPt = cloud.min();
    // cout << "smallest point:" << endl;
    // for (int i = 0; i < Dim; i++) cout << minPt[i] << " ";
    // cout << endl;

    // const float* maxPt = cloud.max();
    // cout << "largest point:" << endl;
    // for (int i = 0; i < Dim; i++) cout << maxPt[i] << " ";
    // cout << endl;
    

    // // visualization test
    // test();

    // PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
    // paint(cloud);
    // LidarPoint pt = tree.findNearestNeighbor(LidarPoint(0, 0, 0));
    // cout << "pt: " << pt << endl;

    PNG PaintLineTest(200, 200);
    // vector<LidarPoint> test;

    // test.push_back(LidarPoint(50,50,0));
    // test.push_back(LidarPoint(100,50,0));
    // test.push_back(LidarPoint(100,100,0));
    // test.push_back(LidarPoint(50,100,0));

    // LidarPoint p1(50,50,0);
    // LidarPoint p2(100,50,0);
    // LidarPoint p3(100,100,0);
    // LidarPoint p4(50,100,0);

    // PaintLineTest = paintLine(p1, p2, PaintLineTest);

    paintWithSceneOjb_test();
    // PaintLineTest.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");
    
    return 0;
}