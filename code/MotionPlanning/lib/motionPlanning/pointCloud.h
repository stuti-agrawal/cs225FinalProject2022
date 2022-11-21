#ifndef POINTCLOUD_H
#define POINTCLOUD_H

template <typename T>
class PointCloud {
public:
    PointCloud();
    virtual ~PointCloud();
    const T* cloud() const;
    unsigned long numberOfLidarPoints() const;
    bool pointExists(T x, T y, T z) const;
    bool addLidarPoint(T x, T y, T z, T r);
    const T* min() const;
    const T* max() const;


private:
    T* cloud_;
    unsigned long pointCount;

};

#endif