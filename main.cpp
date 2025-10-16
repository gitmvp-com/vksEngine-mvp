#include <iostream>
#include <print>
#include "app/Application.h"

int main()
{
    try
    {
        vks_engine::Application app(800, 600, "VKSEngine MVP");

        std::print("Starting VKSEngine MVP...\n");
        std::print("Press ESC to exit\n\n");

        app.run();

        std::print("\nShutting down...\n");
    }
    catch (const std::exception &e)
    {
        std::print("============== ERROR: {} ==============\n", e.what());
        return 1;
    }

    return 0;
}
