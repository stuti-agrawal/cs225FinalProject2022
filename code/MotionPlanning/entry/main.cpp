// it all begins here...
#include "filereader.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
    return 0;
}