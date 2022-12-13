#pragma once

#include <vector>
#include <iostream>

/**
 * class to store 3-dimensional point information from LidarPoint
 */

const unsigned short Dim = 3;

class LidarPoint {
    public:
        bool processed_;

        LidarPoint();
        LidarPoint(float x, float y, float z);
        LidarPoint(float x, float y, float z, float r);
        void print(std::ostream& out) const;
        bool isProcessed() const;

        float operator[](int subscript) const;
        bool operator==(LidarPoint const & other) const;
        bool operator!=(LidarPoint const & other) const;
        bool operator<(const LidarPoint p) const;
        bool operator<=(const LidarPoint p) const;
        bool operator>(const LidarPoint p) const;
        bool operator>=(const LidarPoint p) const;
    
    private:
        float vals_[Dim];
        
};

std::ostream& operator<<(std::ostream& out, const LidarPoint& p);