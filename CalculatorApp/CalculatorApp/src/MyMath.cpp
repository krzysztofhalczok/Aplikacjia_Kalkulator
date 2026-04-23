#include "MyMath.hpp"
namespace MyMath
{
    float Powf2(float vlaue)
    {
        return vlaue * vlaue;
    }
    float Absf(float value)
    {
    value = value < 0? value *-1:value;
    return value;
    }
    float CircleArea(float r,float pi)
    {
        return Powf2(r) * pi;
    }
    float NGonArea(float r,int sides,float pi/*podaj wartość M_PI z cmath*/,float (*sin)(float) /*podaj funkcje sinf z cmath*/)
    {
        return Absf(0.5f*sides*Powf2(r) * sin((2*pi / sides)));
    }
    float RectangleArea(float a, float b)
    {
        return Absf(a * b);
    }
    float TriangleArea(float base,float height)
    {
        return Absf(base * height * 0.5f);
    }
    float ParalelRectArea(float base,float height)
    {
        return Absf(base * height);
    }
    float TrapezArea(float base1,float base2,float height)
    {
        return Absf((base1+base2)*height *0.5f);
    }
}