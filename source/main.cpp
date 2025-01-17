#include "Application/Application.h"

int main()
{
    Application app;

    if (!app.Start(1300, 900))
    {
        std::cerr << "Failed to start application\n";
        exit(1);
    }

    app.Update();
    app.Shutdown();
    return 0;
}
