workspace "WeatherApp"
    architecture"x64"
    configurations { "Debug", "Release", "Dist" }

project "WeatherApp"
    kind "ConsoleApp"
    language "C++"
    OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
    targetdir("build/" .. OutputDir .. "/")
    objdir("build/intermediates" .. OutputDir .. "/")

    -- Project files
    files{
        "source/**.h",
        "source/**.hpp",
        "source/**.c",
        "source/**.cpp"
    }

    -- Dependency files
    files{
        -- GLFW
        "Dependencies/glfw-3.4/src/**.c",
        -- GLAD
        "Dependencies/glad/src/glad.c",
        -- ImGui
        "Dependencies/ImGui/**.cpp",
        "Dependencies/ImGui/**.h",
        -- ImPlot
        "Dependencies/ImPlot/**.cpp",
        "Dependencies/ImPlot/**.h"
    }

    includedirs{
        "Dependencies/httplib",
        "Dependencies/glfw-3.4/include",
        "Dependencies/glad/include",
        "Dependencies/ImGui",
        "Dependencies/ImPlot",
        "Dependencies/Stb"
    }

    -- Exclude CMake-specific or non-Windows files 
    filter { "system:windows" }
        defines { "_GLFW_WIN32" }
        files {
            "Dependencies/glfw-3.4/src/win32_*.*",
            "Dependencies/glfw-3.4/src/wgl_context.*",
            "Dependencies/glfw-3.4/src/egl_context.*",
            "Dependencies/glfw-3.4/src/osmesa_context.*"
        }
        excludes {
            "Dependencies/glfw-3.4/src/posix_*.*",
            "Dependencies/glfw-3.4/src/x11_*.*",
            "Dependencies/glfw-3.4/src/cocoa_*.*"
        }

    filter { "system:linux" }
        defines { "_GLFW_X11" }
        files {
            "Dependencies/glfw-3.4/src/x11_*.*",
            "Dependencies/glfw-3.4/src/posix_*.*",
            "Dependencies/glfw-3.4/src/glx_context.*",
            "Dependencies/glfw-3.4/src/egl_context.*",
            "Dependencies/glfw-3.4/src/osmesa_context.*"
        }
        excludes {
            "Dependencies/glfw-3.4/src/win32_*.*",
            "Dependencies/glfw-3.4/src/cocoa_*.*"
        }

    -- Add dependencies
    filter { "system:windows" }
        links { "opengl32" } 
    filter { "system:linux" }
        links { "X11", "pthread", "dl", "GL" }

    -- Settings for different build modes
    filter "configurations:Debug"
        defines { "DEBUG", "ST_PLATFORM_WINDOWS" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE", "ST_PLATFORM_WINDOWS" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "DIST", "ST_PLATFORM_WINDOWS" }
        runtime "Release"
        optimize "On"
        symbols "Off"
