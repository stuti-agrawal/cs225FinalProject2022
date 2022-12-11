#pragma once

#include "lidarPoint.h"
#include <vector>


// const unsigned short Dimension = 3;
// const unsigned int DefaultChunkSizeAsPointCount = 2000;

/**
 * class to store point cloud information. essentially stores
 * collection of LidarPoints
 */

// template <typename T>
class PointCloud {
public:
    // TODO: rule of three?
    PointCloud(unsigned int chunkSizeAsPointCount = 2000);
    PointCloud(const PointCloud& other);
    ~PointCloud();

    /**
    * @return A vector of lidar points that build up
    * the point cloud
    */
    const std::vector<LidarPoint> cloud() const;

    /**
    * @return number of points in the point cloud
    */
    unsigned long numberOfLidarPoints() const;
    bool pointExists(float x, float y, float z) const;
    bool addLidarPoint(float x, float y, float z, float r); // TODO: change this to LidarPoitn
    // const float* min() const;
    // const float* max() const;
private:
    LidarPoint accessPoint(float x, float y, float z) const;
public:

private:
    std::vector<LidarPoint> cloud_;
    unsigned long pointCount_;
    // float pointMin_[3];
    // float pointMax_[3];
};
