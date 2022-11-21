
class LidarPoint {
    public:
        double x_;
        double y_;
        double z_;
        double r_;

        LidarPoint();
        LidarPoint(double x, double y, double z);
        LidarPoint(double x, double y, double z, double r);
};