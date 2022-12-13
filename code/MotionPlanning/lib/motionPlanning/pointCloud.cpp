#include "pointCloud.h"
#include <limits>
#include <algorithm>
#include <tgmath.h>

using namespace std;

PointCloud::PointCloud(unsigned int chunkSizeAsPointCount)
  : pointCount_(0) {

    cloud_.reserve(chunkSizeAsPointCount);

    float min = std::numeric_limits<float>::min();
    float max = std::numeric_limits<float>::max();

    for (auto _ = 3; _--;) {
        pointMin_[_] = max;
        pointMax_[_] = min;
    }
}

PointCloud::PointCloud(const PointCloud& other) {
    for (auto _ = 3; _--;) {
        pointMin_[_] = other.pointMin_[_];
        pointMax_[_] = other.pointMax_[_];
    }
   
    pointCount_ = other.pointCount_;
    cloud_ = other.cloud_;
    return;
}
PointCloud::~PointCloud() {
    cloud_.clear();
}

const std::vector<LidarPoint> PointCloud::cloud() const {
    return cloud_;
}

unsigned long PointCloud::numberOfLidarPoints() const {
    return pointCount_;
}

bool PointCloud::pointExists(float x, float y, float z) const {
    // return (accessPoint(x, y, z) != NULL);
    return false;
}

bool PointCloud::addLidarPoint(float x, float y, float z, float r) {
    if (pointExists(x, y, z)) {
        return false;
    }

    LidarPoint lP(x, y, z, r);
    cloud_.push_back(lP);
    
    float point[3] = {x, y, z};
    for (auto _ = 3; _--;) {
        if (pointMin_[_] > point[_]) pointMin_[_] = point[_];
        if (pointMax_[_] < point[_]) pointMax_[_] = point[_];
    }

    pointCount_++;
    return true;
}

bool PointCloud::addLidarPoint(const LidarPoint& point) {
    if (pointExists(point[0], point[1], point[2])) {
        return false;
    }

    cloud_.push_back(point);
    
    for (auto _ = 3; _--;) {
        if (pointMin_[_] > point[_]) pointMin_[_] = point[_];
        if (pointMax_[_] < point[_]) pointMax_[_] = point[_];
    }

    pointCount_++;
    return true;
}

pair<int, int> PointCloud::egoVehicleLoc() const {
    return make_pair(floor(abs(pointMax_[0] - pointMin_[0])/2), floor(abs(pointMax_[1] - pointMin_[1])/2));
}
const float* PointCloud::min() const {
    return pointMin_;
}

const float* PointCloud::max() const {  
    return pointMax_;
}

LidarPoint PointCloud::accessPoint(float x, float y, float z) const {

    LidarPoint returnPoint;
    // std::for_each(cloud_.begin(), cloud_.end(), [x, y, z, returnPoint](const LidarPoint& point) {
    //     if (point.x_ == x && point.y_ == y && point.z_ == z) {
    //         returnPoint = point;
    //         break;
    //     }
    // });
    for (const auto& point : cloud_) {
        if (point == LidarPoint(x, y, z)) return point;

    }
    
    return LidarPoint();
}