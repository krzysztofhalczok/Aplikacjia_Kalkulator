#ifndef Application_hpp
#define Application_hpp
#include "Menu.hpp" // implies vector
class Application
{
private:
enum AppPoints
{
    START,
    NORMAL_CALC,
    GEOMETRY_CALC,
    FUNCTION_CALC,
    
    
    SUM,
    SUBTRUCT,
    MULTIPLY,
    DIVIDE,
    POWER,
    ROOT,
    
    GEOMETRY_2D,
    GEOMETRY_3D,

    CIRCLE_AREA ,
    N_SIDED_SHAPE_AREA,
    RECTANGLE_AREA ,
    TRIANGEL_AREA,
    PARALERLOGARM_AREA,
    TRAPEZ_AREA,

    PRISIM,
    CONE,

    CIRCLE_AREA_CONE ,
    N_SIDED_SHAPE_AREA_CONE,
    RECTANGLE_AREA_CONE ,
    TRIANGEL_AREA_CONE,
    PARALERLOGARM_AREA_CONE,
    TRAPEZ_AREA_CONE,

    CIRCLE_AREA_PRISIM ,
    N_SIDED_SHAPE_AREA_PRISIM,
    RECTANGLE_AREA_PRISIM ,
    TRIANGEL_AREA_PRISIM,
    PARALERLOGARM_AREA_PRISIM,
    TRAPEZ_AREA_PRISIM,
    
    LINELAR_FUNCTION,
    QUADRATIC_FUNCTION,

    QUADRATIC_NORMAL_TO_HOMOGRAFICAl_FUNC,
    QUADRATIC_NORMAL_ZERO_POS,
    
   
    
};
enum
{
    MainMenu,
    CalculatorMenu,
    GeometryMenu,
    Menu2D,
    Menu3D,
    Bases3D,
    FunctionMenu,
    QuadraticMenu,
    
    

};
std::vector<Menu> m_Menu;
AppPoints m_AppPoint;
bool m_running;
float m_Memory;
public:
Application();
~Application();
void Init();
bool running();
void AppLoop();
void clean();

void AnwserCode();
bool FloatEqule(float a, float b);
void CheckIfAnswerCode(float &a);

};
#endif /*Application_hpp */