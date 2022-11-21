#ifndef LIDARPOINT_H
#define LIDARPOINT_H

template <typename T>
class LidarPoint {
    public:
        T x_;
        T y_;
        T z_;
        T r_;

        LidarPoint();
        LidarPoint(T x, T y, T z);
        LidarPoint(T x, T y, T z, T r);

        bool operator==(LidarPoint const & other) const;
        bool operator!=(LidarPoint const & other) const;
};

#endif