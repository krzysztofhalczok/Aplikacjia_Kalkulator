#include "Menu.hpp"
#include "Terminal.hpp"
#include "IO.hpp"
Menu::Menu(std::vector<const char*> MC):m_MenuContent(MC)
{}
Menu::~Menu()
{}
int Menu::GetMenuAns()
{
    int index;
    for(auto s: m_MenuContent)
    {
        IO::Print(s);
        IO::Print("\n");
    }
    index = IO::PrintQ<int>("Wchodzę w Opcję: ");
    Terminal::ClearTerminal();
    return index;
}
