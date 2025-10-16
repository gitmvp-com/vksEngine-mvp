#ifndef VKSENGINE_MVP_VULKANCONTEXT_H
#define VKSENGINE_MVP_VULKANCONTEXT_H

#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

struct GLFWwindow;

namespace vks_engine
{
    struct QueueFamilyIndices
    {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete() const
        {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    class VulkanContext
    {
    public:
        VulkanContext();
        ~VulkanContext();

        // Delete copy constructor and assignment operator
        VulkanContext(const VulkanContext &) = delete;
        VulkanContext &operator=(const VulkanContext &) = delete;

        void init(GLFWwindow *window);
        void cleanup();
        void waitIdle();

        VkInstance getInstance() const { return m_Instance; }
        VkPhysicalDevice getPhysicalDevice() const { return m_PhysicalDevice; }
        VkDevice getDevice() const { return m_Device; }
        VkSurfaceKHR getSurface() const { return m_Surface; }
        VkQueue getGraphicsQueue() const { return m_GraphicsQueue; }
        VkQueue getPresentQueue() const { return m_PresentQueue; }

    private:
        void createInstance();
        void createSurface(GLFWwindow *window);
        void pickPhysicalDevice();
        void createLogicalDevice();

        bool isDeviceSuitable(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        std::vector<const char *> getRequiredExtensions();
        bool checkValidationLayerSupport();

        VkInstance m_Instance = VK_NULL_HANDLE;
        VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
        VkDevice m_Device = VK_NULL_HANDLE;
        VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
        VkQueue m_GraphicsQueue = VK_NULL_HANDLE;
        VkQueue m_PresentQueue = VK_NULL_HANDLE;

#ifdef _DEBUG
        const bool enableValidationLayers = true;
#else
        const bool enableValidationLayers = false;
#endif

        const std::vector<const char *> validationLayers = {
            "VK_LAYER_KHRONOS_validation"};

        const std::vector<const char *> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    };
}

#endif // VKSENGINE_MVP_VULKANCONTEXT_H
