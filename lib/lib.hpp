#include <iostream>
#include <vector>

class Vector3D {
    private:
        double x;
        double y;
        double z;
    public:
        Vector3D() {};
        Vector3D(double x, double y, double z): x(x), y(y), z(z) {}
        Vector3D(const Vector3D& obj): x(obj.getx()), y(obj.gety()), z(obj.getz()) {}
        ~Vector3D() = default;

        double getx () const;
        double gety () const;
        double getz () const;

        void setx (double val);
        void sety (double val);
        void setz (double val);

        bool operator == (const Vector3D tmp);

        Vector3D operator - (const Vector3D tmp) const;
};

class Segment3D {
    private:
        Vector3D start;
        Vector3D end;
    public:
        Segment3D (Vector3D s, Vector3D e): start(s) , end(e) {}
        Vector3D getStart () const;
        Vector3D getEnd () const;
};

namespace Intersect {
    bool Intersect(const Segment3D& line1, const Segment3D& line2, Vector3D& intersection);
}