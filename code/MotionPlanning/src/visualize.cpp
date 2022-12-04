#include "visualize.h"

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

void paint() {
    HSLAPixel blackPixel(180, 1, 0);

    PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
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