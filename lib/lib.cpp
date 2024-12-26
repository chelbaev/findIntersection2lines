#include "lib.hpp"


using namespace std;


namespace {
    std::vector<double> operator/(const std::vector<double>& vec, double scalar) {
        vector<double> result;
        for (int i = 0; i < vec.size(); i++)
            result.push_back(vec[i] / scalar);
        return result;
    }

    std::vector<double> operator*(const std::vector<double>& vec, double scalar) {
        vector<double> result;
        for (int i = 0; i < vec.size(); i++)
            result.push_back(vec[i] * scalar);
        return result;
    }

    std::vector<double> operator-(const std::vector<double>& vec1, const std::vector<double>& vec2) {
        vector<double> result;
        for (int i = 0; i < vec1.size(); i++)
            result.push_back(vec1[i] - vec2[i]);
        return result;
    }

    bool solve (vector<vector<double>> matrix, double &t, double &s){
        if (abs(matrix[0][0]) < 1e-6){
            if (abs(matrix[1][0]) < 1e-6){
                if (abs(matrix[2][0]) < 1e-6)
                    return false; // вся первая колонка близка к нулю, значит решений нет. Будем считать что число < 1e-6 это 0, так как double может содержать погрешность вычислений 
                matrix[0].swap(matrix[2]);
            }
            matrix[0].swap(matrix[1]);
        }

        // for (auto vec : matrix){
        //     for(double x : vec){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        matrix[0] = matrix[0] / matrix[0][0]; // делаем первую строку вида 1.0 double double
        matrix[1] = matrix[1] - matrix[0] * matrix[1][0]; // вычитание из второй строки первую, чтобы получилось 0 double double
        if (abs(matrix[1][1]) < 1e-6){ // на случай если матрица 2х3 не решаема
            matrix[1].swap(matrix[2]);
            matrix[1] = matrix[1] - matrix[0] * matrix[1][0];
            if (abs(matrix[1][1]) < 1e-6)
                return false; // вся матрица не решаема
        }

        // for (auto vec : matrix){
        //     for(double x : vec){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        matrix[1] = matrix[1] / matrix[1][1];
        matrix[0] = matrix[0] - matrix[1] * matrix[0][1];


        // for (auto vec : matrix){
        //     for(double x : vec){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        t = matrix[0][2];
        s = matrix[1][2];

        return true;
    }
}

// Функция для нахождения точки пересечения двух прямых  
bool Intersect::Intersect(const Segment3D& line1, const Segment3D& line2, Vector3D& intersection) {
    Vector3D p1(line1.getStart());
    Vector3D p2(line1.getEnd());
    Vector3D p3(line2.getStart());
    Vector3D p4(line2.getEnd());

    // матрица для х, у и z в заполненом состоянии выглядит так:
    /*      t            s          answer
    x2l1 - x1l1  x1l2 - x2l2  x1l2 - x1l1
    y2l1 - y1l1  y1l2 - y2l2  y1l2 - y1l1
    z2l1 - z1l1  z1l2 - z2l2  z1l2 - z1l1
    где x1 и x2 это координаты первой и второй точки соответсвенно по х, аналогично y1 y2, z1 z2
    l1 и l2 это первая и вторая линия соответсвенно
    */ 
    vector<vector<double>> matrix = {{p2.getx() - p1.getx(), p3.getx() - p4.getx(), p3.getx() - p1.getx()},
                                    {p2.gety() - p1.gety(), p3.gety() - p4.gety(), p3.gety() - p1.gety()},
                                    {p2.getz() - p1.getz(), p3.getz() - p4.getz(), p3.getz() - p1.getz()}};
    
    // for (auto vec : matrix){
    //     for(double x : vec){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    double t, s;
    if (!solve(matrix, t, s))
        return false;
    Vector3D tmp;
    tmp.setx(int((s * (p4.getx() - p3.getx()) + p3.getx()) * 1000000) / 1000000.0);
    tmp.sety(int((s * (p4.gety() - p3.gety()) + p3.gety()) * 1000000) / 1000000.0);
    tmp.setz(int((s * (p4.getz() - p3.getz()) + p3.getz()) * 1000000) / 1000000.0);
    intersection.setx(int((t * (p2.getx() - p1.getx()) + p1.getx()) * 1000000) / 1000000.0);
    intersection.sety(int((t * (p2.gety() - p1.gety()) + p1.gety()) * 1000000) / 1000000.0);
    intersection.setz(int((t * (p2.getz() - p1.getz()) + p1.getz()) * 1000000) / 1000000.0);
    
    if (tmp == intersection)
        return true;
    return false;
}

double Vector3D::getx () const {return this->x;}
double Vector3D::gety () const {return this->y;}
double Vector3D::getz () const {return this->z;}

void Vector3D::setx (double val) {this->x = val;}
void Vector3D::sety (double val) {this->y = val;}
void Vector3D::setz (double val) {this->z = val;}

bool Vector3D::operator == (const Vector3D tmp){
    if (this->x == tmp.x && this->y == tmp.y && this->z == tmp.z)
        return true;
    return false;
}

Vector3D Vector3D::operator - (const Vector3D tmp) const {
    return Vector3D(this->getx() - tmp.getx(), this->gety() - tmp.gety(), this->getz() - tmp.getz());
}

Vector3D Segment3D::getStart () const {return start;}
Vector3D Segment3D::getEnd () const {return end;}