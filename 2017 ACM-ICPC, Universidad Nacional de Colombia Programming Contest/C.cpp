#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>

#define PI 3.14159265358979323846
#define DEG2RAD PI/180.0
#define ll long long

template<typename T = ll>
struct Vec3 {
    T x, y, z;

    Vec3(T x = 0, T y = 0, T z = 0): x(x), y(y), z(z) {};

    double SqrLength() const {
        return x*x + y*y + z*z;
    }

    double Length() const {
        return sqrt(x*x + y*y + z*z);
    }

    bool isZero() const {
        return this->x == 0 && this->y == 0 && this->z == 0; 
    }

    static double SqrDistance(const Vec3<T>& v1, const Vec3<T>& v2) {
        T dx = (v1.x-v2.x);
        T dy = (v1.y-v2.y);
        T dz = (v1.z-v2.z);
        return dx*dx + dy*dy + dz*dz;
    }

    static double Distance(const Vec3<T>& v1, const Vec3<T>& v2) {
        return sqrt(Vec3<T>::SqrDistance(v1, v2));
    }

    static double Angle(const Vec3<T>& v1, const Vec3<T>& v2) {
        return atan2((v1 ^ v2).Length(), v1*v2);
    }

    static int Orientation(const Vec3<T>& p1, const Vec3<T>& p2, const Vec3<T>& p3) {
        double zCross = ((p2-p1)^(p3-p1)).z;
        if(zCross > 1e-7) return 1; // Counter-Clockwise
        else if (zCross < -1e-7) return -1; // Clockwise
        else return 0; // Collinear
    }

    static bool isCollinear(const Vec3<T>& p1, const Vec3<T>& p2, const Vec3<T>& p3) {
        return ((p2 - p1) ^ (p3 - p1)).isZero();
    }

    Vec3<T> operator+(const Vec3<T>& other) const {
        return {this->x + other.x, this->y + other.y, this->z + other.z};
    }

    Vec3<T> operator-(const Vec3<T>& other) const {
        return {this->x - other.x, this->y - other.y, this->z - other.z};
    }

    Vec3<T> operator-() const {
        return {-this->x, -this->y, -this->z};
    }

    Vec3<T> operator*(T s) const {
        return {this->x*s, this->y*s, this->z*s}; 
    }

    Vec3<T> operator/(T s) const {
        return {this->x/s, this->y/s, this->z/s}; 
    }

    // Normalize
    Vec3<double> Norm() const {
        double len = this->Length();
        return { this->x / len, this->y / len, this->z / len };
    }

private:
    double lerp(double a, double b, double t) const {
        return (1.0 - t) * a + b * t;
    }

public:

    // Lerp
    Vec3<double> Lerp(const Vec3<T>& target, double t) const {
        return {lerp(this->x, target.x, t), lerp(this->y, target.y, t), lerp(this->z, target.z, t)};
    }

    // Rotate
    Vec3<T> Rotate(double angle, Vec3<int> axis = {0, 0, 1}) {
        return {};
    }

    // Considering XZ as horizontal plane
    /*
    Vec3<double> ToPolar(double r) const {
        return {};
    }
    */

   // Considering XZ as horizontal plane. X is Longitude, Y is Latitude, Z is Radius
    Vec3<double> ToEuclidean() const {
        return {z*cos(y * DEG2RAD)*cos(x * DEG2RAD), z * sin(y * DEG2RAD), z * cos(y * DEG2RAD) * sin(x * DEG2RAD)};
    }

    // Rodrigues Rotation
    /*Vec3<T> RotateAround(const Vec3<T>& v, ) {

    }*/

    // Dot
    T operator*(const Vec3<T>& other) const {
        return this->x * other.x + this->y * other.y + this->z * other.z; 
    }

    // Cross
    Vec3<T> operator^(const Vec3<T>& other) const {
        return {
                this->y * other.z - this->z * other.y,
                this->z * other.x - this->x * other.z,
                this->x * other.y - this->y * other.x // Equivalent to 2D Cross
            }; 
    }

    bool operator==(const Vec3<T> other) const {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

    bool operator<(const Vec3<T> other) const {
        if(this->x != other.x) return this->x < other.x;
        if(this->y != other.y) return this->y < other.y;
        return this->z < other.z;
    }

    void Print() const {
        printf("[ %.2lf, %.2lf, %.2lf ]\n", (double)this->x, (double)this->y, (double)this->z);
    }
};

bool colinear(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    if(x1 * y2 != y1 * x2) return false;
    if(x1 * z2 != z1 * x2) return false;
    if(y1 * z2 != z1 * y2) return false;
    return true;
}

// Faz um set das direções e pega o tamanho.
constexpr int maxN = 5001;
#include <set>

int main() {

    int n;
    scanf("%d", &n);
    n--;

    Vec3<ll> earth;
    scanf("%lld%lld%lld", &earth.x, &earth.y, &earth.z);

    bool c[maxN]; 
    Vec3<ll> p[maxN];
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z);
        c[i] = true;
    }
    
    for(int i = 0; i < n; i++) {
        if(!c[i]) continue;
        for(int j = i+1; j < n; j++)
            if(colinear(p[i].x-earth.x, p[i].y-earth.y, p[i].z-earth.z, p[j].x-earth.x, p[j].y-earth.y, p[j].z-earth.z))
                c[j] = false;
    }
    
    int count = 0;
    for(int i = 0; i < n; i++) count += c[i]; 
    printf("%d\n", count);
    return 0;
}
