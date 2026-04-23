#ifndef MyMath_hpp
#define MyMath_hpp
namespace MyMath
{
    float Powf2(float vlaue);
    float Absf(float value);
    float CircleArea(float r,float pi);
    float NGonArea(float r,int sides,float pi,float (*sin)(float));
    float RectangleArea(float a, float b);
    float TriangleArea(float base,float height);
    float ParalelRectArea(float base,float height);
    float TrapezArea(float base1,float base2,float height);
}
#endif /*MyMath_hpp */