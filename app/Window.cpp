#include "Window.h"
#include <stdexcept>
#include <print>

namespace vks_engine
{
    Window::Window(int width, int height, const std::string &title)
        : m_Width(width), m_Height(height), m_FramebufferResized(false)
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        // Tell GLFW not to create an OpenGL context
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (!m_Window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        // Set user pointer for callbacks
        glfwSetWindowUserPointer(m_Window, this);

        // Set callbacks
        glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);
        glfwSetKeyCallback(m_Window, keyCallback);
        glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);

        std::print("Window created: {}x{}\n", width, height);
    }

    Window::~Window()
    {
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            m_Window = nullptr;
        }
        glfwTerminate();
    }

    bool Window::isOpen() const
    {
        return !glfwWindowShouldClose(m_Window);
    }

    void Window::close()
    {
        glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    bool Window::wasResized()
    {
        return m_FramebufferResized;
    }

    void Window::resetResizeFlag()
    {
        m_FramebufferResized = false;
    }

    void Window::setFramebufferResizeCallback(std::function<void(int, int)> function)
    {
        m_FramebufferResizeCallback = std::move(function);
    }

    void Window::setKeyCallback(std::function<void(int, int, int, int)> function)
    {
        m_KeyCallback = std::move(function);
    }

    void Window::setButtonCallback(std::function<void(int, int, int)> function)
    {
        m_ButtonCallback = std::move(function);
    }

    void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto *self = static_cast<Window *>(glfwGetWindowUserPointer(window));
        self->m_FramebufferResized = true;
        self->m_Width = width;
        self->m_Height = height;

        if (self->m_FramebufferResizeCallback)
        {
            self->m_FramebufferResizeCallback(width, height);
        }
    }

    void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        auto *self = static_cast<Window *>(glfwGetWindowUserPointer(window));

        if (self->m_KeyCallback)
        {
            self->m_KeyCallback(key, scancode, action, mods);
        }
    }

    void Window::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
    {
        auto *self = static_cast<Window *>(glfwGetWindowUserPointer(window));

        if (self->m_ButtonCallback)
        {
            self->m_ButtonCallback(button, action, mods);
        }
    }
}
