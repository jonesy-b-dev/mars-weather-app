#include "Application/Application.h"
#include <iostream>

int main()
{
    Application app;

    if (!app.Start(1300, 900))
    {
        std::cerr << "Failed to start application\n";
        exit(1);
    }

    app.Update();

    return 0;
}
