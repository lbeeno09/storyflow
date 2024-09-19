workspace "StoryFlow"
configurations { "Debug", "Release" }
architecture "x64"

targetdir("build/bin/%{cfg.buildcfg}")
objdir("build/bin-int/%{cfg.buildcfg}")

filter "system:windows"
includedirs {
  os.getenv("VCPKG_PATH") .. "/packages/glfw3_x64-windows/include",
  os.getenv("VCPKG_PATH") .. "/packages/imgui_x64-windows/include",
  "src"
}
libdirs {
  os.getenv("VCPKG_PATH") .. "/packages/glfw3_x64-windows/lib",
  os.getenv("VCPKG_PATH") .. "/packages/imgui_x64-windows/lib",
}
links {
  "opengl32",
  "glfw3dll",
  "imgui",
}
defines { "WIN32" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "NDEBUG" }
optimize "On"

filter "action:vs*"
location "build/VS"

project "StoryFlow"
kind "ConsoleApp"
language "C++"
cppdialect "C++20"


files {
  "src/*.cpp",
  "src/*.h"
}
