#include "fileReader.h"
#include "/workspaces/cs225FinalProject2022/code/MotionPlanning/include/single_include/nlohmann/json.hpp"


using json = nlohmann::json;

using namespace std;

PointCloud readDataFile(string filename) {
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
            cloud.addLidarPoint(row.at(0), row.at(1), row.at(2), row.at(3));
            count = 0;
            row.clear();
        }
    }
    return cloud;
}

vector<SceneObject> readAnnotFile(string filename) {
    std::ifstream f(filename);
    json j = json::parse(f);
    vector<SceneObject> objects;
    auto &frames = j["frames"];
    for (auto frame : frames) {
        if (frame["sequence_id"] == "000113") {
            for (const auto& data : frame["annos"]["boxes_3d"]) {
                if (data == NULL) continue;
                objects.push_back(SceneObject(data[0], data[1], data[2], data[3], data[4], data[5], data[6]));
            }
        }

    }
    return objects;
    
}