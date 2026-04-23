#ifndef IO_hpp
#define IO_hpp
#include <iostream>
#include "Terminal.hpp"
class IO
{
public:
template <typename T>
static T PrintQ(const char* Ask)
{
T var; 
bool state = false;
auto ErrorHandeling = [&]()
{
std::cout<< Ask;
if(std::cin>>var)
{
    char p = std::cin.peek();
    if(p != '\n')
    {
        std::cin.ignore(10000,'\n');
    }
    state = false;
}
else
{
    std::cerr << "Zły Typ Odpowiedzi\n";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    state = true;
}
};
ErrorHandeling();
// Ten kod podał Geminai służy jako komenda konsoli by wyczy scił poprzedniąlinijkę w terminalu : "\033[A\033[2K\r"
while(state)
{
    Terminal::Clear2LastLines();
    ErrorHandeling();
}
return var;
}
static void Print(const char* AStringToWrite)
{
    std::cout<< AStringToWrite;
}
};
#endif /*IO_hpp*/