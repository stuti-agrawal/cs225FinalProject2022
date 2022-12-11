#include "visualize.h"
#include <utility>

using namespace cs225;
using namespace std;
void test() {
    HSLAPixel blackPixel(180, 1, 0);
    PNG visualization_test(100,100);
    for (unsigned i = 0; i < visualization_test.width(); i++) {
        for (unsigned j = 0; j < visualization_test.height(); j++) {
            visualization_test.getPixel(i,j) = blackPixel;
        }
    }
    visualization_test.writeToFile("/workspaces/cs225FinalProject2022/data/output_test.png");
}

void paintWithPointCloud(PointCloud cloud) {
    HSLAPixel blackPixel(180, 1, 0);

    int min_x = cloud.min()[0];
    int min_y = cloud.min()[1];
    int max_x = cloud.max()[0];
    int max_y = cloud.max()[1];

    int width = max_x - min_x;
    int height = max_y - min_y;
    cout << "width" << width << endl;
    cout << "height" << height << endl;

    PNG toReturn(width, height);

    for (LidarPoint l: cloud.cloud()) {
        int x = l[0] - min_x;
        int y = l[1] - min_y;
        
        cout << x << " " << y << endl;
        if (x > width || y > height) return;
        toReturn.getPixel(x, y) = blackPixel;
    }
    toReturn.writeToFile("/workspaces/cs225FinalProject2022/data/Painted_Map.png");
}

void paintClusters(PointCloud cloud, vector<LidarPoint> vertex) {
    HSLAPixel blackPixel(180, 1, 0);

    int min_x = cloud.min()[0];
    int min_y = cloud.min()[1];
    int max_x = cloud.max()[0];
    int max_y = cloud.max()[1];

    int width = max_x - min_x;
    int height = max_y - min_y;
    cout << "width" << width << endl;
    cout << "height" << height << endl;

    PNG toReturn(width, height);
    cout << "im in here" << endl;
    for (LidarPoint l: cloud.cloud()) {
        int x = l[0] - min_x;
        int y = l[1] - min_y;
        
        // cout << x << " " << y << endl;
        if (x > width || y > height) cout << "WARNING" << endl;
        else toReturn.getPixel(x, y) = blackPixel;
    }

    for (int i = 0; i < 4; i++) {
        LidarPoint point1 = vertex[i];
        LidarPoint point2 = vertex[(i+1)%4];

        cout << "point1" << point1[0] << ", " << point1[1] << endl;
        cout << "point2" << point2[0] << ", " << point2[1] << endl;
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
            cout << x_coord << " " << y_coord << endl;
            canvass.getPixel(x_coord, y_coord) = redPixel;
        }
    } else if (x[0] > y[0]) {
        for(int x_coord = y[0]; x_coord <= x[0]; x_coord++) {
            int y_coord = k*x_coord + constant;
            cout << x_coord << " " << y_coord << endl;
            canvass.getPixel(x_coord, y_coord) = redPixel;
        }
    } else {
        if (x[1] > y[1]) {
            for(int y_coord = y[1]; y_coord <= x[1]; y_coord++) {
                int x_coord = x[0];
                cout << x_coord << " " << y_coord << endl;
                canvass.getPixel(x_coord, y_coord) = redPixel;
            }
        } else {
            for(int y_coord = x[1]; y_coord <= y[1]; y_coord++) {
                int x_coord = x[0];
                cout << x_coord << " " << y_coord << endl;
                canvass.getPixel(x_coord, y_coord) = redPixel;
            }
        }
    }
    return canvass;
}