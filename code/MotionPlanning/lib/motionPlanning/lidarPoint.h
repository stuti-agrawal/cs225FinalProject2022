#ifndef LIDARPOINT_H
#define LIDARPOINT_H


/**
 * class to store 3-dimensional point information from LidarPoint
 */

class LidarPoint {
    public:
        float x_;
        float y_;
        float z_;
        float r_;

        LidarPoint();
        LidarPoint(float x, float y, float z);
        LidarPoint(float x, float y, float z, float r);

        bool operator==(LidarPoint const & other) const;
        bool operator!=(LidarPoint const & other) const;
};

#endif