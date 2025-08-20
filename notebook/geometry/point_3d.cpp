struct Point_3d {
	coordinate_t x, y, z;
	Point_3d(coordinate_t x_ = 0, coordinate_t y_ = 0, coordinate_t z_ = 0) : x(x_), y(y_), z(z_){}
	
	Point_3d operator+(const Point_3d& o) const { return {x+o.x, y+o.y, z+o.z}; }
	Point_3d operator-(const Point_3d& o) const { return {x-o.x, y-o.y, z-o.z}; }
};
 
inline coordinate_t dot(Point_3d a, Point_3d b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline Point_3d cross(Point_3d a, Point_3d b) { return Point_3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }