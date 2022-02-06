workspace "Funingine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Funingine"
    location "Funingine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.19041.0"

        defines
        {
            "FE_PLATFORM_WINDOWS",
            "FE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FE_DEBUG"
        symbols "On"

    filter "configurations:Debug"
        defines "FE_Release"
        symbols "On"
    
    filter "configurations:Dist"
        defines "FE_DIST"
        symbols "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    links
    {
        "Funingine"
    }

    includedirs
    {
        "Funingine/vendor/spdlog/include",
        "Funingine/source"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.19041.0"

        defines
        {
            "FE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FE_DEBUG"
        symbols "On"

    filter "configurations:Debug"
        defines "FE_Release"
        symbols "On"
    
    filter "configurations:Dist"
        defines "FE_DIST"
        symbols "On"


