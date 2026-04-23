#ifndef Menu_hpp
#define Menu_hpp
#include <vector>
class Menu
{
private:
std::vector<const char* > m_MenuContent;
public:
Menu(std::vector<const char*> MC);
~Menu();
int GetMenuAns();



};

#endif /*Menu_hpp*/