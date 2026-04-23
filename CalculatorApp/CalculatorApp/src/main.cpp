#include "Terminal.hpp"
#include "Application.hpp"

int main()
{
    Terminal::ActivateANSI();
    Application *app = new Application();
    app->Init();
    while(app->running())
    {
        app->AppLoop();
    }
    app->clean();
    delete app;
}