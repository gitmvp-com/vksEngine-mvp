#include "Application.h"
#include <print>

namespace vks_engine
{
    Application::Application(int windowWidth, int windowHeight, const std::string &windowTitle)
        : m_Window(windowWidth, windowHeight, windowTitle)
    {
        m_VulkanContext.init(m_Window.getWindow());
        setupCallbacks();
    }

    Application::~Application()
    {
        m_VulkanContext.waitIdle();
    }

    void Application::run()
    {
        while (m_Window.isOpen())
        {
            m_Window.pollEvents();

            // In a full engine, this is where you'd:
            // - Update scene
            // - Record command buffers
            // - Submit rendering
            // - Present to screen

            // For MVP, we just handle window events
            if (m_Window.wasResized())
            {
                m_Window.resetResizeFlag();
                // In full version: recreate swapchain
            }
        }
    }

    void Application::setupCallbacks()
    {
        m_Window.setFramebufferResizeCallback(
            [this](int width, int height)
            {
                onWindowResize(width, height);
            });

        m_Window.setKeyCallback(
            [this](int key, int scancode, int action, int mods)
            {
                onKeyPress(key, scancode, action, mods);
            });

        m_Window.setButtonCallback(
            [this](int button, int action, int mods)
            {
                onMouseButton(button, action, mods);
            });
    }

    void Application::onWindowResize(int width, int height)
    {
        std::print("Window resized to: {}x{}\n", width, height);
    }

    void Application::onKeyPress(int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            std::print("ESC pressed - closing window\n");
            m_Window.close();
        }
    }

    void Application::onMouseButton(int button, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            const char *buttonName = (button == GLFW_MOUSE_BUTTON_LEFT) ? "Left" : (button == GLFW_MOUSE_BUTTON_RIGHT) ? "Right"
                                                                                                                           : "Middle";
            std::print("Mouse button pressed: {}\n", buttonName);
        }
    }
}
