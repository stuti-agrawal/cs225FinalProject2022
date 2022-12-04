#include "visualize.h"

using namespace cs225;
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



    PNG toReturn(width, height);
    
}