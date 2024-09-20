if _ACTION == "vs2022" then
  workspace "StoryFlow"
  location("build/VS")
  configurations { "Debug", "Release" }
  architecture "x64"

  targetdir("build/bin/%{cfg.buildcfg}")
  objdir("build/bin-int/%{cfg.buildcfg}")

  project "StoryFlow"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++20"

  location "build/VS"
  defines { "WIN32" }

  includedirs {
    "vcpkg_installed/x64-windows/x64-windows/include",
    "src"
  }
  libdirs {
    "vcpkg_installed/x64-windows/x64-windows/lib",
  }
  links {
    "opengl32",
    "glfw3dll",
    "imgui",
    "freetype"
  }
  files {
    "src/*.cpp",
    "src/*.h"
  }

  filter "configurations:Debug"
  defines { "DEBUG" }
  symbols "On"

  filter "configurations:Release"
  defines { "NDEBUG" }
  optimize "On"
elseif _ACTION == "clean" then
  print("TBD: cleaning procedure")
end
