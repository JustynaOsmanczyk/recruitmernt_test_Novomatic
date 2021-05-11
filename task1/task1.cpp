#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

struct vec3 { float x,y,z; };
struct Sphere
{
     vec3 center;
     float radius;
};
// Axis-aligned bounding box. Cube with edges aligned to x,y,z axis.
struct Aabb
{
     vec3 min;
     vec3 max;
};
// Triangular pyramid.
struct Tetrahedron
{
     vec3 points[4];
};
// Cylinder with hemispherical ends.
struct Capsule
{
     vec3 points[2];
     float radius;
};

template <typename Shape>
vec3 support(vec3 v, Shape& s);

float dot_product(const vec3& a, const vec3& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float length(const vec3& v){
    return sqrt(dot_product(v, v));
}

vec3 normalize(const vec3& v){
    float len = length(v);
    return {v.x / len, v.y / len, v.z / len};
}

vec3 operator* (const vec3& v, float r){
    return {r * v.x, r * v.y, r * v.z};
}

vec3 operator* (float r, const vec3& v){
    return v * r;
}

vec3 operator/ (const vec3& v, float r){
    return {v.x / r, v.y / r, v.z / r};
}

vec3 operator+ (const vec3& a, const vec3& b){
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 operator-(const vec3& a){
    return {-a.x, -a.y, -a.z};
}

vec3 operator- (const vec3& a, const vec3& b){
    return a + (-b);
}

template<>
vec3 support(vec3 v, Sphere& s)
{
    vec3 w = normalize(v);
    return s.center + s.radius * w;
}


template<>
vec3 support(vec3 v, Aabb& a)
{
    vec3 center = (a.max + a.min) / 2;
    vec3 u = normalize(v);

    float t = numeric_limits<float>::infinity();
    for(vec3 w : {a.min, a.max}){
        if (fabs(u.x) > 1e-6){
            float t2 = (w.x - center.x) / u.x;
            if (t2 > 0 && t2 < t){
                t = t2;
            }
        }
        if (fabs(u.y) > 1e-6){
            float t2 = (w.y - center.y) / u.y;
            if (t2 > 0 && t2 < t){
                t = t2;
            }
        }
        if (fabs(u.z) > 1e-6){
            float t2 = (w.z - center.z) / u.z;
            if (t2 > 0 && t2 < t){
                t = t2;
            }
        }
    }
    return center + t * u;
}

//template<>
//vec3 support(vec3 v, Tetrahedron& t){}

template<>
vec3 support(vec3 v, Capsule& c)
{
    vec3 center = (c.points[0] + c.points[1]) / 2;
    vec3 w = c.points[1] - c.points[0];
    vec3 u = normalize(v);

    float scalar_wv = dot_product(v, w);
    float distance_w = length(w);
    float distance_v = length(v);
    float cos_uv = scalar_wv / (distance_w * distance_v);
    float sin_uv = sqrt(1 - cos_uv * cos_uv);
    float hypotenuse = (c.radius / 2) / sin_uv;

    if(distance_w / 2 - c.radius > fabs(cos_uv * hypotenuse))
    {
        // we are hitting the cillinder
        return center + hypotenuse * u;
    }
    else
    {
        float l = (distance_w / 2 - c.radius);

        float cos_abs = fabs(cos_uv);
        float delta = 4.0f * (l * l * cos_abs * cos_abs - l * l + c.radius*c.radius);
        float x = (2.0f * l * cos_abs + sqrt(delta)) / 2.0f;

        return center + x * u;
    }

    return v;
}

int main()
{
    vec3 v = {1, 1, 0};
    Sphere shape = {0, 0, 0, 2};
    support(v, shape);
    Aabb aabb = {{0, 0, 0}, {1, 2, 3}};
    vec3 aabb_sup = support(v, aabb);
    cout << aabb_sup.x << " " << aabb_sup.y << " " << aabb_sup.z << endl;
    //Tetrahedron tetra = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1};
    //support(v, tetra);
    Capsule caps = {0, 0, 0, 2, 0, 0, 0.5};
    vec3 caps_sup = support(v, caps);
    cout << caps_sup.x << " " << caps_sup.y << " " << caps_sup.z << endl;
    Capsule caps2 = {0, 0, 0, 2, 2, 0, 0.5};
    vec3 caps2_sup = support(v, caps2);
    cout << caps2_sup.x << " " << caps2_sup.y << " " << caps2_sup.z << endl;


    return 0;
}

