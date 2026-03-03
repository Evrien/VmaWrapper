
cmake_minimum_required(VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(Vma)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(Vma STATIC
    Vma.cpp
)

if (MSVC) 
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REPLACE "/GR" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

    target_compile_definitions(Vma PRIVATE UNICODE _UNICODE)
    target_compile_options(Vma PRIVATE /utf-8)
    target_compile_options(Vma PRIVATE /WX)

endif ()

message(STATUS "CMake CXX Flags: ${CMAKE_CXX_FLAGS}")

find_package(Vulkan REQUIRED)
target_link_libraries(Vma
        Vulkan::Vulkan
)

target_include_directories(Vma
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source
        PUBLIC C:/VulkanSDK/1.4.309.0/Include
)