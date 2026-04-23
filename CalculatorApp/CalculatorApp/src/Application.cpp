#define _USE_MATH_DEFINES
#include "Application.hpp"
#include "IO.hpp"
#include <cmath>
#include <array>
#include "MyMath.hpp"
const char* StartText= R"(
################################################################################
#                                                                              #
#                                                                              #
#                         #     # # #####  ###    ###                          #
#                         #     # #   #   #   #     #                          #
#                         #  #  # #   #   #####     #                          #
#                         # # # # #   #   #   # #   #                          #
#                          #   #  #   #   #   #  ###                           #
#                                                                              #
#               #                                                              #
#       #   # ##### #   # ##### #   #  ###  #     # #   # # #   # #   #        #
#       #   #    #   # #    #   #  #  #   # #     # ##  # # #  #  #   #        #
#       #   #   #     #     #   ###   #   # #  #  # # # # # ###   #   #        #
#       #   #  #      #     #   #  #  #   # # # # # #  ## # #  #  #   #        #
#        ###  #####   #     #   #   #  ###   #   #  #   # # #   #  ###         #
#                                                                              #
#                                                                              #
################################################################################


)";







const char* EndText = R"(
################################################################################
#                                                                              #
#                                                                              #
#                         #                                                    #
#                       ##### #####  ###  #   #  ###    ###                    #
#                          #  #     #     ##  # #   #     #                    #
#                         #   ####  # ### # # # #####     #                    #
#                        #    #     #   # #  ## #   # #   #                    #
#                       ##### #####  ###  #   # #   #  ###                     #
#                                                                              #
#                                                                              #
#               #                                                              #
#       #   # ##### #   # ##### #   #  ###  #     # #   # # #   # #   #        #
#       #   #    #   # #    #   #  #  #   # #     # ##  # # #  #  #   #        #
#       #   #   #     #     #   ###   #   # #  #  # # # # # ###   #   #        #
#       #   #  #      #     #   #  #  #   # # # # # #  ## # #  #  #   #        #
#        ###  #####   #     #   #   #  ###   #   #  #   # # #   #  ###         #
#                                                                              #
#                                                                              #
################################################################################

)"
;


Application::Application():m_running(true),m_AppPoint(START),m_Memory(0.0f)
{
m_Menu.reserve(8);
}
Application::~Application()
{
}
void Application::Init()
{
    IO::Print(StartText);
    IO::Print(R"(
        Witaj w Kalkulatorze!

        --- INSTRUKCJA OBSŁUGI ---

        1. NAWIGACJA:
           Wpisz cyfrę wybranej opcji i wciśnij [ENTER].
           Przykład:
           0. Cofnij        <-- wpisz 0, by wrócić
           1. Geometria 2D  <-- wpisz 1, by wejść
           2. Geometria 3D  <-- wpisz 2, by wejść

        2. LICZBY DZIESIĘTNE:
           Zamiast przecinka zawsze używaj kropki (np. 123.45).

        3. PAMIĘĆ KALKULATORA:
           Aby użyć wyniku z poprzedniego obliczenia, wpisz: 2137.6967
           (Na starcie programu pamięć wynosi 0).

        Naciśnij [ENTER], aby kontynuować: )");
    std::cin.get();
    Terminal::ClearTerminal();
    using menu = std::vector<const char*>;
    m_Menu.emplace_back(menu{
"0. Zakończ Program. ",
"1. Kalkulator Normalny.",
"2. Kalkulator Geometryczny",
"3. Kalkulator Funkcji."
    });
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Suma.",
"2. Różnica.",
"3. Iloczyn.",
"4. Iloraz.",
"5. Potęga.",
"6. Pierwiastek.",
"7. Wyłącz Program."
    });
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Geometria 2D Liczenie Pola.",
"2. Geometria 3D Liczenie Objętości",
"3. Wyłącz Program."
    });
    
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Pole Trójkąta.",
"2. Pole Prostokąta",
"3. Pole Równoległoboku.",
"4. Pole Trapezu.",
"5. Pole Wielokąta foremnego.",
"6. Pole Koła.",
"7. Wyłącz Program."
    });
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Objętość Ostrosłupa.",
"2. Objętość Graniastosłupa.",
"3. Wyłącz Program."
    });
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. O Podstawie Trójkątnej.",
"2. O Podstawie Prostokątnej.",
"3. O Podstawie Równoległobocznej.",
"4. O Podstawie Trapezowej.",
"5. O Podstawie Wielokąta foremnego.",
"6. O Podstawie Koła.",
"7. Wyłącz Program."
    });
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Funkcja Liniowa.",
"2. Funkcja Kwadratowa.",
"3. Wyłącz Program."
    });
 
    m_Menu.emplace_back(menu{
"0. Cofnij.",
"1. Obliczenie Miejsc Zerowych z Funkcji f(x) = ax^2 + bx + c. ",
"2. Przemiana z f(x) = ax^2 + bx + c -> f(x) = a(x-p)^2+q .",
"3. Wyłącz Program."
    });


}
void Application::AppLoop()
{
switch(m_AppPoint)
{
case START:
{
    switch(m_Menu[MainMenu].GetMenuAns())
    {
    case 0:
    {
       m_running = false;
    }break;
    case 1:
    {
         m_AppPoint=NORMAL_CALC;
    }break;
    case 2:
    {
         m_AppPoint=GEOMETRY_CALC;
    }break;
     case 3:
    {
         m_AppPoint=FUNCTION_CALC;
    }break;
    default:break;
    }
}break;

case NORMAL_CALC:
{
switch(m_Menu[CalculatorMenu].GetMenuAns())
    {
    case 0:
    {
        m_AppPoint=START;
    }break;
    case 1:
    {
        m_AppPoint= SUM;
    }break;
    case 2:
    {
        m_AppPoint= SUBTRUCT;
    }break;
    case 3:
    {
        m_AppPoint= MULTIPLY;
    }break;
    case 4:
    {
        m_AppPoint= DIVIDE;
    }break;
    case 5:
    {
        m_AppPoint= POWER;
    }break;
    case 6:
    {
        m_AppPoint= ROOT;
    }break;
    case 7:
    {
        m_running = false;
    }break;
    default:break;
    }




}break;
case SUM:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj 1 składnik: ");
b = IO::PrintQ<float>("Podaj 2 składnik: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = a + b;
std::cout<<"SUMA: "<<a <<" + "<<b<<" = "<<m_Memory<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;
case SUBTRUCT:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj odjemną: ");
b = IO::PrintQ<float>("Podaj odjemnik: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = a - b;
std::cout<<"RÓŻNICA: "<<a <<" - "<<b<<" = "<<m_Memory<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;
case MULTIPLY:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj 1 czynnik: ");
b = IO::PrintQ<float>("Podaj 2 czynnik: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = a * b;
std::cout<<"ILOCZYN: "<<a <<" * "<<b<<" = "<<m_Memory<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;
case DIVIDE:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj Dzielną: ");
b = IO::PrintQ<float>("Podaj Dzielnik: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
if(FloatEqule(b,0.0f))
{
   IO::Print("Nie można dzielić przez zero\n");
}
else
{
m_Memory = a / b;
std::cout<<"ILORAZ :"<<a <<" / "<<b<<" = "<<m_Memory<<"\n";
}
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;
case POWER:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj Podstawę: ");
b = IO::PrintQ<float>("Podaj Wykładnik: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = powf(a,b);
std::cout<<"POTĘGA: "<<a <<" ^ "<<b<<" = "<<m_Memory<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;
case ROOT:
{
AnwserCode();
float a, b;
a = IO::PrintQ<float>("Podaj Liczbę podpierwiastkową: ");
b = IO::PrintQ<float>("Podaj stopień pierwiastka: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = powf(a,1/b);
std::cout<<"PIERWIASTEK: "<<a <<"Stopień pierwiastka"<<b<<" = "<<m_Memory<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = NORMAL_CALC;
}break;


case GEOMETRY_CALC:
{
    switch(m_Menu[GeometryMenu].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=START;
    }break;
    case 1:
    {
         m_AppPoint=GEOMETRY_2D;
    }break;
    case 2:
    {
         m_AppPoint=GEOMETRY_3D;
    }break;
    
    case 3:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;

case GEOMETRY_2D:
{
    switch(m_Menu[Menu2D].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=GEOMETRY_CALC;
    }break;
    case 1:
    {
         m_AppPoint=TRIANGEL_AREA;
    }break;
    case 2:
    {
         m_AppPoint=RECTANGLE_AREA;
    }break;
    case 3:
    {
         m_AppPoint=PARALERLOGARM_AREA;
    }break;
    case 4:
    {
         m_AppPoint=TRAPEZ_AREA;
    }break;
    case 5:
    {
         m_AppPoint=N_SIDED_SHAPE_AREA;
    }break;
    case 6:
    {
         m_AppPoint=CIRCLE_AREA;
    }break;
    
    case 7:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;
case CIRCLE_AREA:
{
AnwserCode();
float a;
a = IO::PrintQ<float>("Podaj Promień koła: ");
CheckIfAnswerCode(a);
m_Memory = MyMath::CircleArea(a,M_PI);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;
case N_SIDED_SHAPE_AREA:
{
AnwserCode();
float a;
int n;
n = IO::PrintQ<int>("Podaj liczbę boków figury: ");
a = IO::PrintQ<float>("Podaj odległość od środka do narożnika figury: ");
CheckIfAnswerCode(a);
m_Memory = MyMath::NGonArea(a,n,M_PI,sinf);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;
case RECTANGLE_AREA:
{
AnwserCode();
float a;
float b;
a = IO::PrintQ<float>("Podaj wysokość Prostokąta: ");
b = IO::PrintQ<float>("Podaj podstawę Prostokąta: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = MyMath::RectangleArea(a,b);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;
case TRIANGEL_AREA:
{
AnwserCode();
float a;
float b;
a = IO::PrintQ<float>("Podaj wysokość Trójkąta: ");
b = IO::PrintQ<float>("Podaj podstawę Trójkąta: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = MyMath::TriangleArea(a,b);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;
case PARALERLOGARM_AREA:
{
AnwserCode();
float a;
float b;
a = IO::PrintQ<float>("Podaj wysokość równoległoboku: ");
b = IO::PrintQ<float>("Podaj podstawę równoległoboku: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = MyMath::ParalelRectArea(a,b);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;
case TRAPEZ_AREA:
{
AnwserCode();
float a;
float b;
float h;
h = IO::PrintQ<float>("Podaj wysokość Trapezu: ");
b = IO::PrintQ<float>("Podaj 1 podstawę Trapezu: ");
a = IO::PrintQ<float>("Podaj 2 podstawę Trapezu: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
m_Memory = MyMath::TrapezArea(a,b,h);
std::cout<<"POLE:"<<" = "<<m_Memory<<" [u^2]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = GEOMETRY_2D;
}break;

case GEOMETRY_3D:
{
    switch(m_Menu[Menu3D].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=GEOMETRY_CALC;
    }break;
    case 1:
    {
         m_AppPoint=CONE;
    }break;
    case 2:
    {
         m_AppPoint=PRISIM;
    }break;
    case 3:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;
case CONE:
{
    switch(m_Menu[Bases3D].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=GEOMETRY_3D;
    }break;
    case 1:
    {
         m_AppPoint=TRIANGEL_AREA_CONE;
    }break;
    case 2:
    {
         m_AppPoint=RECTANGLE_AREA_CONE;
    }break;
    case 3:
    {
         m_AppPoint=PARALERLOGARM_AREA_CONE;
    }break;
    case 4:
    {
         m_AppPoint=TRAPEZ_AREA_CONE;
    }break;
    case 5:
    {
         m_AppPoint=N_SIDED_SHAPE_AREA_CONE;
    }break;
    case 6:
    {
         m_AppPoint=CIRCLE_AREA_CONE;
    }break;
    case 7:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;
case CIRCLE_AREA_CONE:
{
AnwserCode();
float a,h;
a = IO::PrintQ<float>("Podaj Promień Podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(h);
m_Memory = 1.0f/3.0f*h*MyMath::CircleArea(a,M_PI);
std::cout<<"OBJĘTOŚĆ: "<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case N_SIDED_SHAPE_AREA_CONE:
{
AnwserCode();
float a,h;
int n;
n = IO::PrintQ<int>("Podaj liczbę boków figury u podstawy: ");
a = IO::PrintQ<float>("Podaj odległość od środka do narożnika figury u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(h);
m_Memory = 1.0f/3.0f * h * MyMath::NGonArea(a,n,M_PI,sinf);
std::cout<<"OBJĘTOŚĆ: "<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case RECTANGLE_AREA_CONE:
{
AnwserCode();
float a,b,h;
a = IO::PrintQ<float>("Podaj wysokość Prostokąta u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę Prostokąta u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = 1.0f/3.0f * h *MyMath::RectangleArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case TRIANGEL_AREA_CONE:
{
AnwserCode();
float a, b,h;
a = IO::PrintQ<float>("Podaj wysokość Trójkąta u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę Trójkąta u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
m_Memory = 1.0f/3.0f * h * MyMath::TriangleArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case PARALERLOGARM_AREA_CONE:
{
AnwserCode();
float a,b,h;
a = IO::PrintQ<float>("Podaj wysokość równoległoboku u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę równoległoboku u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
m_Memory = 1.0f/3.0f * h *MyMath::ParalelRectArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case TRAPEZ_AREA_CONE:
{
AnwserCode();
float a, b,h,H;
h = IO::PrintQ<float>("Podaj wysokość Trapezu u podstawy: ");
b = IO::PrintQ<float>("Podaj 1 podstawę Trapezu u podstawy: ");
a = IO::PrintQ<float>("Podaj 2 podstawę Trapezu u podstawy: ");
H = IO::PrintQ<float>("Podaj wysokość Ostrosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
CheckIfAnswerCode(H);
m_Memory =  1.0f/3.0f * h * MyMath::TrapezArea(a,b,h);
std::cout<<"OBJĘOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;
case PRISIM:
{
    switch(m_Menu[Bases3D].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=GEOMETRY_3D;
    }break;
    case 1:
    {
         m_AppPoint=TRIANGEL_AREA_PRISIM;
    }break;
    case 2:
    {
         m_AppPoint=RECTANGLE_AREA_PRISIM;
    }break;
    case 3:
    {
         m_AppPoint=PARALERLOGARM_AREA_PRISIM;
    }break;
    case 4:
    {
         m_AppPoint=TRAPEZ_AREA_PRISIM;
    }break;
    case 5:
    {
         m_AppPoint=N_SIDED_SHAPE_AREA_PRISIM;
    }break;
    case 6:
    {
         m_AppPoint=CIRCLE_AREA_PRISIM;
    }break;
    case 7:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;
case CIRCLE_AREA_PRISIM:
{
AnwserCode();
float a,h;
a = IO::PrintQ<float>("Podaj Promień Podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(h);
m_Memory = h*MyMath::CircleArea(a,M_PI);
std::cout<<"OBJĘTOŚĆ: "<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = PRISIM;
}break;
case N_SIDED_SHAPE_AREA_PRISIM:
{
AnwserCode();
float a,h;
int n;
n = IO::PrintQ<int>("Podaj liczbę boków figury u podstawy: ");
a = IO::PrintQ<float>("Podaj odległość od środka do narożnika figury u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(h);
m_Memory = h * MyMath::NGonArea(a,n,M_PI,sinf);
std::cout<<"OBJĘTOŚĆ: "<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = PRISIM;
}break;
case RECTANGLE_AREA_PRISIM:
{
AnwserCode();
float a,b,h;
a = IO::PrintQ<float>("Podaj wysokość Prostokąta u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę Prostokąta u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
m_Memory = h *MyMath::RectangleArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = PRISIM;
}break;
case TRIANGEL_AREA_PRISIM:
{
AnwserCode();
float a, b,h;
a = IO::PrintQ<float>("Podaj wysokość Trójkąta u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę Trójkąta u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
m_Memory = h * MyMath::TriangleArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = PRISIM;
}break;
case PARALERLOGARM_AREA_PRISIM:
{
AnwserCode();
float a,b,h;
a = IO::PrintQ<float>("Podaj wysokość równoległoboku u podstawy: ");
b = IO::PrintQ<float>("Podaj podstawę równoległoboku u podstawy: ");
h = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
m_Memory =h *MyMath::ParalelRectArea(a,b);
std::cout<<"OBJĘTOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = PRISIM;
}break;
case TRAPEZ_AREA_PRISIM:
{
AnwserCode();
float a, b,h,H;
h = IO::PrintQ<float>("Podaj wysokość Trapezu u podstawy: ");
b = IO::PrintQ<float>("Podaj 1 podstawę Trapezu u podstawy: ");
a = IO::PrintQ<float>("Podaj 2 podstawę Trapezu u podstawy: ");
H = IO::PrintQ<float>("Podaj wysokość Graniastosłupa: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(h);
CheckIfAnswerCode(H);
m_Memory = h * MyMath::TrapezArea(a,b,h);
std::cout<<"OBJĘOŚĆ:"<<" = "<<m_Memory<<" [u^3]\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = CONE;
}break;


case FUNCTION_CALC:
{
    switch(m_Menu[FunctionMenu].GetMenuAns())
    {
    case 0:
    {
       m_AppPoint=START;
    }break;
    case 1:
    {
         m_AppPoint=LINELAR_FUNCTION;
    }break;
    case 2:
    {
         m_AppPoint=QUADRATIC_FUNCTION;
    }break;
    case 3:
    {
         m_running = false;
    }break;
    default:break;
    }
}break;
case LINELAR_FUNCTION:
{
AnwserCode();
float a,b;
IO::Print("f(x) = ax + b\n");
a = IO::PrintQ<float>("Podaj wartość a: ");
b = IO::PrintQ<float>("Podaj wartość b: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);

if(!FloatEqule(a,0.0f))
{
m_Memory = -b/a;
std::cout<<"Miejsce zerowe = "<<m_Memory<<"\n";
}
else
{
     std::cout<<"Brak Miejsc Zerowych\n";
}
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = FUNCTION_CALC;
}break;
case QUADRATIC_FUNCTION:
{
switch (m_Menu[QuadraticMenu].GetMenuAns())
{
case 0:
{
m_AppPoint=QUADRATIC_NORMAL_ZERO_POS;
}break;

case 1:
{
m_AppPoint=QUADRATIC_NORMAL_TO_HOMOGRAFICAl_FUNC;
}break;

case 2:
{
m_AppPoint=FUNCTION_CALC;
}break;

case 3:
{
m_running =false;
}break;

default:break;
}
}break;
case QUADRATIC_NORMAL_ZERO_POS:
{
AnwserCode();
float a,b,c;
IO::Print("F(x) = ax^2 + bx + c: \n");
a = IO::PrintQ<float>("Podaj a: ");
b = IO::PrintQ<float>("Podaj b: ");
c = IO::PrintQ<float>("Podaj c: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(c);
// obliczanie miejsc zerowych
if(FloatEqule(a,0.0f))
{
IO::Print("Czynnik a ,jest równy zero, czyli funkcja nie jest kwadratowa\n");
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;

}
float Delta = powf(b,2) -4*a*c;
if(FloatEqule(Delta,0.0f))
{
std::cout<<"Miejsce zerowe = "<<-b/2*a<<"\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;

}else if(Delta < 0.0f)
{

std::cout<<"Brak miejsc zerowych\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;

} else if(Delta > 0.0f)
{
float x1,x2;

x1 = (-b - powf(Delta,1/2))/2*a;
x2 = (-b + powf(Delta,1/2))/2*a;

std::cout<<"Miejsca zerowe:  x1 ="<< x1<<", x2 ="<<x2 <<".\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;
}
}break;
case QUADRATIC_NORMAL_TO_HOMOGRAFICAl_FUNC:
{
AnwserCode();
float a,b,c;
IO::Print("F(x) = ax^2 + bx + c: \n");
a = IO::PrintQ<float>("Podaj a: ");
b = IO::PrintQ<float>("Podaj b: ");
c = IO::PrintQ<float>("Podaj c: ");
CheckIfAnswerCode(a);
CheckIfAnswerCode(b);
CheckIfAnswerCode(c);
// obliczanie miejsc zerowych
if(FloatEqule(a,0.0f))
{
IO::Print("Czynnik a jest równy zero, czyli funkcja nie jest kwadratowa\n");
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;

}
float Delta = powf(b,2) -4*a*c;
if(FloatEqule(Delta,0.0f))
{
std::cout<<"f(x)="<<a<<"(x -"<<-b/2*a<<")\n";
IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;

}else
{
float p,q;

p = -b/2*a;
q = -Delta/4*a;
if(p >= 0)
{
std::cout<<"f(x)="<<a<<"(x +"<<fabs(p)<<") + "<< q<<"\n";     
}else
{
std::cout<<"f(x)="<<a<<"(x -"<<p<<") + "<< q<<"\n";
}

IO::Print("Naciśnij [ENTER] by kontynuować: ");
std::cin.get();
std::cin.get();
Terminal::ClearTerminal();
m_AppPoint = QUADRATIC_FUNCTION;
}
}break;







default:break;
}
}
void Application::clean()
{
IO::Print(EndText);
IO::Print(R"(
    
Autor: Krzysztof Halczok
    )");
std::cin.get();
std::cin.get();
}
bool Application::running()
{
    return m_running;
}

void Application::AnwserCode()
{
IO::Print("Ten program posiada pamięć krótką. Jeśli będziesz chciał wykorzystać wartość z poprzedniej kalkulacji, musisz wpisać abstrakcyjną liczbę: 2137.6967\n");
IO::Print("Pamięć krótka teraz jest równa = ");
std::cout<<m_Memory<<"\n";    
IO::Print("\n \n");
}
bool Application::FloatEqule(float a, float b)
{
const float EPSILON = 0.000'001f;
return (fabs(a - b) <=EPSILON);
}
void Application::CheckIfAnswerCode(float &a)
{
if(FloatEqule(a,2137.6967f))
{
    a = m_Memory;
}
}