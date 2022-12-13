#include "lidarPoint.h"

// template <typename T>
LidarPoint::LidarPoint() {
    for (int i = 0; i < Dim; ++i)
        vals_[i] = 0.0;
    processed_ = false; // used for clustering
}

// template <typename T>
LidarPoint::LidarPoint(float x, float y, float z) {
    vals_[0] = x;
    vals_[1] = y;
    vals_[2] = z;
    // vals_[3] = 1.0;
    processed_ = false; // used for clustering
}

// template <typename T>
LidarPoint::LidarPoint(float x, float y, float z, float r) {
    vals_[0] = x;
    vals_[1] = y;
    vals_[2] = z;
    // vals_[3] = r;
    processed_ = false; // used for clustering
}

// bool isProcessed() const {
//     return processed_;
// }

void LidarPoint::print(std::ostream& out) const {
    out << '(';

    for (int i = 0; i < Dim - 1; ++i)
        out << vals_[i] << ", ";
    out << vals_[Dim - 1];

    out << ')';
}

// template <typename T>
bool LidarPoint::operator==(LidarPoint const & other) const {
    return (vals_[0] == other.vals_[0] && vals_[1] == other.vals_[1] && vals_[2] == other.vals_[2]);
}

// template <typename T>
bool LidarPoint::operator!=(LidarPoint const & other) const {
    return !(*this == other);
}

float LidarPoint::operator[](int nSubscript) const {
    static int iErr = -1;

    if(nSubscript >= 0 && nSubscript < Dim)
        return vals_[nSubscript];
    else {
        return iErr;
    }
}

bool LidarPoint::operator<(const LidarPoint p) const {
    bool less = false;
    for (int i = 0; i < Dim; ++i) {
        less = vals_[i] < p[i];
        if (vals_[i] != p[i])
            break;
    }
    return less;
}

bool LidarPoint::operator<=(const LidarPoint p) const {
    return (*this < p) || (*this == p);
}

bool LidarPoint::operator>(const LidarPoint p) const {
    return !(*this < p);
}

bool LidarPoint::operator>=(const LidarPoint p) const {
    return (*this > p) || (*this == p);
}

std::ostream& operator<<(std::ostream& out, const LidarPoint& p) {
    p.print(out);
    return out;
}