# VKSEngine MVP

Minimal Vulkan-based graphics engine demonstrating window creation and Vulkan initialization.

## About This MVP

This is a simplified version of [vksEngine](https://github.com/siLViU1905/vksEngine) focusing on the core functionality:
- Window creation and management using GLFW
- Basic Vulkan instance initialization
- Window event handling
- Simple application loop

## Features

✅ GLFW window creation and management
✅ Vulkan instance and surface creation
✅ Physical device selection
✅ Logical device creation
✅ Basic event handling (keyboard, mouse, window resize)
✅ Clean shutdown and resource cleanup

## 🚀 Installation & Setup

### Prerequisites

- **CMake** 3.20 or higher
- **C++23** compatible compiler (MSVC 2022, GCC 13+, or Clang 16+)
- **Vulkan SDK** 1.3 or higher
- **Git** with submodule support

### Windows Installation

1. **Install Vulkan SDK**
   - Download from [vulkan.lunarg.com](https://vulkan.lunarg.com/)
   - Install to default location or set `VULKAN_SDK` environment variable

2. **Clone the repository with submodules**
   ```bash
   git clone --recursive https://github.com/gitmvp-com/vksEngine-mvp.git
   cd vksEngine-mvp
   ```

3. **Configure and build**
   ```bash
   cmake -B build
   cmake --build build
   ```

4. **Run the engine**
   ```bash
   build/Debug/vksEngine-mvp.exe
   ```
   or
   ```bash
   build/Release/vksEngine-mvp.exe
   ```

### Linux/macOS Installation

1. **Install Vulkan SDK**
   - Download from [vulkan.lunarg.com](https://vulkan.lunarg.com/)
   - Follow platform-specific installation instructions

2. **Clone and build**
   ```bash
   git clone --recursive https://github.com/gitmvp-com/vksEngine-mvp.git
   cd vksEngine-mvp
   cmake -B build
   cmake --build build
   ./build/vksEngine-mvp
   ```

### Troubleshooting

**Missing submodules:**
```bash
git submodule update --init --recursive
```

**CMake can't find Vulkan SDK:**
- Set environment variable `VULKAN_SDK` to your installation path
- Or modify `CMakeLists.txt` to point to your Vulkan SDK location

## 🏗️ Architecture

```
vksEngine-mvp/
├── app/
│   ├── Window.h/cpp          # GLFW window management
│   ├── Application.h/cpp     # Main application logic
│   └── VulkanContext.h/cpp   # Vulkan initialization and cleanup
├── external/                  # Git submodules
│   └── GLFW/                 # Window library
├── main.cpp                   # Entry point
└── CMakeLists.txt            # Build configuration
```

## 🛠️ Technical Implementation

### Core Technologies
- **C++23** with modern features
- **Vulkan 1.3** for GPU access
- **GLFW 3.x** for cross-platform window management

### Dependencies (Git Submodules)
- GLFW 3.x - Window and input handling

## 📝 Development

### Building for Development
```bash
# Debug build with validation layers
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Release build optimized
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## What's Not Included (Full Version Features)

This MVP excludes advanced features from the full vksEngine:
- ❌ 3D model loading (Assimp)
- ❌ Shader compilation and rendering pipeline
- ❌ Scene management with components
- ❌ Lighting system (directional, point lights)
- ❌ ImGui interface
- ❌ Texture loading
- ❌ Camera system
- ❌ Multi-threaded command buffer recording
- ❌ Uniform buffers

## Next Steps

To extend this MVP toward the full engine:
1. Add ImGui for UI rendering
2. Implement render pipeline with shaders
3. Add model loading with Assimp
4. Implement camera controls
5. Add lighting system
6. Create scene management

## License

This is an educational MVP based on vksEngine by siLViU1905.
