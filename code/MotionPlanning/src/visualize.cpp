#include "visualize.h"
#include <utility>
#include <math.h>
#include <cmath>


using namespace cs225;
using namespace std;
void test() {
    HSLAPixel blackPixel(180, 1, 0, 0.5);
    PNG visualization_test(100,100);
    for (unsigned i = 0; i < visualization_test.width(); i++) {
        for (unsigned j = 0; j < visualization_test.height(); j++) {
            visualization_test.getPixel(i,j) = blackPixel;
        }
    }
    visualization_test.writeToFile("/workspaces/cs225FinalProject2022/data/output_test.png");
}

PNG paintWithPointCloud(PointCloud cloud) {
    HSLAPixel blackPixel(0, 0, 0.75, 0.5);

    int min_x = cloud.min()[0];
    int min_y = cloud.min()[1];
    int max_x = cloud.max()[0];
    int max_y = cloud.max()[1];

    int width = max_x - min_x;
    int height = max_y - min_y;


    PNG toReturn(width, height);

    for (LidarPoint l: cloud.cloud()) {
        int x = l[0] - min_x;
        int y = l[1] - min_y;
        
        if (x > width || y > height) PNG();
        toReturn.getPixel(x, y) = blackPixel;
    }
    return toReturn;
}

void paintClusters(PointCloud cloud, vector<LidarPoint> vertex) {
    HSLAPixel blackPixel(180, 1, 0, 0.5);

    int min_x = cloud.min()[0];
    int min_y = cloud.min()[1];
    int max_x = cloud.max()[0];
    int max_y = cloud.max()[1];

    int width = max_x - min_x;
    int height = max_y - min_y;

    PNG toReturn(width, height);
    for (LidarPoint l: cloud.cloud()) {
        int x = l[0] - min_x;
        int y = l[1] - min_y;
        
        if (x > width || y > height) cout << "WARNING" << endl;
        else toReturn.getPixel(x, y) = blackPixel;
    }

    for (int i = 0; i < 4; i++) {
        LidarPoint point1 = vertex[i];
        LidarPoint point2 = vertex[(i+1)%4];

        toReturn = paintLine(point1, point2, toReturn);
    }
    
    toReturn.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");
}

PNG paintLine(LidarPoint x, LidarPoint y, PNG canvass) {
    HSLAPixel redPixel(0, 1, 0.5);
    HSLAPixel blackPixel(180, 1, 0);
    double a = y[1] - x[1];
    double b = x[0] - y[0];
    double c = a * x[0] + b * x[1];

    double k = -a/b;
    double constant = c/b;

    if (x[0] < y[0]) {
        for(int x_coord = x[0]; x_coord <= y[0]; x_coord++) {
            int y_coord = k*x_coord + constant;
            canvass.getPixel(x_coord, y_coord) = redPixel;
        }
    } else if (x[0] > y[0]) {
        for(int x_coord = y[0]; x_coord <= x[0]; x_coord++) {
            int y_coord = k*x_coord + constant;
            canvass.getPixel(x_coord, y_coord) = redPixel;
        }
    } else {
        if (x[1] > y[1]) {
            for(int y_coord = y[1]; y_coord <= x[1]; y_coord++) {
                int x_coord = x[0];
                canvass.getPixel(x_coord, y_coord) = redPixel;
            }
        } else {
            for(int y_coord = x[1]; y_coord <= y[1]; y_coord++) {
                int x_coord = x[0];
                canvass.getPixel(x_coord, y_coord) =  redPixel;
            }
        }
    }
    return canvass;
}

void paintWithSceneOjb_test() {
    HSLAPixel blackPixel(180, 1, 0, 0.5);

    int width = 200;
    int height = 200;

    PNG toReturn(width, height);

    SceneObject obj(50, 50, 0, 10, 20, 0, M_PI/4);

    toReturn = paintSceneObj(obj, toReturn);
    
    toReturn.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");
}


PNG paintPath(vector<pair<int, int>> path, PNG canvass, string traversalType) {
    HSLAPixel greenPixel(120, 1, 0.5);
    HSLAPixel purplePixel(300, 1, 0.5);

    for (const auto& trajectory : path) {
        if (traversalType == "aStar") {
            canvass.getPixel(trajectory.first, trajectory.second) =  purplePixel;
        } else if (traversalType == "bfs") {
            canvass.getPixel(trajectory.first, trajectory.second) =  greenPixel;
        }
    }
        
    return canvass;

}


PNG paintSceneObj(SceneObject sceneobj, PNG canvass) {
    double x = sceneobj[0];
    double y = sceneobj[1];
    double l = sceneobj[3];
    double w = sceneobj[4];
    double theta = sceneobj[6];

    double alpha = M_PI/2 - theta;
    double a = tan(alpha) * w/2;
    double b = w / 2 / cos(alpha);
    double c = l/2 - a;
    double d = c*w / (2*b);//w / 2 / b / c;
    double e = a / b / c;

    LidarPoint p1(x + d, y + e + b, 0);

    LidarPoint p2(p1[0] - cos(alpha) * l, p1[1] - sin(alpha) * l, 0);

    canvass = paintLine(p1, p2, canvass);
    LidarPoint p3(p2[0] + sin(alpha) * w, p2[1] - cos(alpha) * w, 0);

    canvass = paintLine(p2, p3, canvass);
    LidarPoint p4(p3[0] + cos(alpha) * l, p3[1] + sin(alpha) * l, 0);

    canvass = paintLine(p3, p4, canvass);
    canvass = paintLine(p1, p4, canvass);
    return canvass;
}