#ifndef VKSENGINE_MVP_WINDOW_H
#define VKSENGINE_MVP_WINDOW_H

#include <functional>
#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vks_engine
{
    class Window
    {
    public:
        Window(int width, int height, const std::string &title);
        ~Window();

        // Delete copy constructor and assignment operator
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        bool isOpen() const;
        void close();
        void pollEvents();

        GLFWwindow *getWindow() const { return m_Window; }
        int getWidth() const { return m_Width; }
        int getHeight() const { return m_Height; }

        bool wasResized();
        void resetResizeFlag();

        // Callback setters
        void setFramebufferResizeCallback(std::function<void(int, int)> function);
        void setKeyCallback(std::function<void(int, int, int, int)> function);
        void setButtonCallback(std::function<void(int, int, int)> function);

    private:
        GLFWwindow *m_Window;
        int m_Width;
        int m_Height;
        bool m_FramebufferResized;

        std::function<void(int, int)> m_FramebufferResizeCallback;
        std::function<void(int, int, int, int)> m_KeyCallback;
        std::function<void(int, int, int)> m_ButtonCallback;

        // Static GLFW callbacks
        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
    };
}

#endif // VKSENGINE_MVP_WINDOW_H
