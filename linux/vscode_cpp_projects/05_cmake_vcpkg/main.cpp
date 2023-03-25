// CMakeLists.txt is generated by the CMake Tools Extension
// https://vector-of-bool.github.io/docs/vscode-cmake-tools/index.html
// https://pspdfkit.com/blog/2019/visual-studio-code-for-cpp/

// https://fmt.dev/latest/index.html

// https://stackoverflow.com/questions/56749068/cmake-is-not-able-to-link-to-vcpkg-library
// $    cd build
// $    cmake ../CMakeLists.txt "-DCMAKE_TOOLCHAIN_FILE=/home/lbc/vcpkg/scripts/buildsystems/vcpkg.cmake"

// #define FMT_HEADER_ONLY
#include <fmt/format.h>

int main()
{
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n\n",
               fmt::arg("name", "World"), fmt::arg("number", 42));
    fmt::print("The answer is {}.\n\n", 42);
}
