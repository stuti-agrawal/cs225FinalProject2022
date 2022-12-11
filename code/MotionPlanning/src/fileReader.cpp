#include "fileReader.h"

using namespace std;
PointCloud readFile(std::string filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) throw std::invalid_argument("file unreadable"); 

    float item;
    int count = 0;
    std::vector<float> row;

   PointCloud cloud(3000);
    while (file.read((char*)&item, 4)) {
        row.push_back(item);
        count++;
        if (count == 4) {
            for (const auto& it : row) cout << it << " ";
            cloud.addLidarPoint(row.at(0), row.at(1), row.at(2), row.at(3));
            count = 0;
            row.clear();
            cout << endl;
        }
    }
    return cloud;
}