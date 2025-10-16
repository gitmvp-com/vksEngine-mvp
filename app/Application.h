#ifndef VKSENGINE_MVP_APPLICATION_H
#define VKSENGINE_MVP_APPLICATION_H

#include "Window.h"
#include "VulkanContext.h"
#include <string>

namespace vks_engine
{
    class Application
    {
    public:
        Application(int windowWidth, int windowHeight, const std::string &windowTitle);
        ~Application();

        // Delete copy constructor and assignment operator
        Application(const Application &) = delete;
        Application &operator=(const Application &) = delete;

        void run();

    private:
        void setupCallbacks();
        void onWindowResize(int width, int height);
        void onKeyPress(int key, int scancode, int action, int mods);
        void onMouseButton(int button, int action, int mods);

        Window m_Window;
        VulkanContext m_VulkanContext;
    };
}

#endif // VKSENGINE_MVP_APPLICATION_H
