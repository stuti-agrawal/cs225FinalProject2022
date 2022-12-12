#pragma once
#include "pointCloud.h"
#include <vector>
/**
 * child class of PointCloud. stores information about
 * objects within a scene. it is a subset of the PointCloud.
 */
using namespace std;
class SceneObject : public PointCloud {
    public:
        SceneObject(float cx, float cy, float cz, float l, float w, float h, float theta);
        /**
        * Returns center x, y, z coordinates of point cloud
        * @return a pointer array storing x, y, z data
        */
        float operator[](int subscript) const;
    public:
    private:
        vector<float> data_;

};