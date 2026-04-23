#include "Terminal.hpp"
#include <cstdlib>
#include <iostream>
void Terminal::ClearTerminal()
{
#if (defined(_WIN32) || defined(_WIN64))
    system("cls");
#else
    system("clear");
#endif
}
void Terminal::Clear2LastLines()
{
    std::cout<<"\033[A\033[2K\r"; // tom linijke napisał gemini
    std::cout<<"\033[A\033[2K\r";
}

#if  (defined(_WIN32) || defined(_WIN64)) //Ten Kawałek Napisał gemini
    #include <windows.h>
    void Terminal::ActivateANSI() 
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; // Budzimy ANSI!
        SetConsoleMode(hOut, dwMode);
        system("chcp 65001 > nul");
    }
#else
    void Terminal::ActivateANSI() {}
#endif