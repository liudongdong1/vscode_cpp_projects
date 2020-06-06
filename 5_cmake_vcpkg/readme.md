## More info on using `vcpkg`
 - I initially had a difficult time with CmakeLists.txt content, but received some guidance online.  
 - I will say I don't entirely understand the linker line of code `target_link_libraries(CmakeVcpkg PRIVATE fmt::fmt fmt::fmt-header-only)`   What's up with `fmt::fmt fmt::fmt-header-only` ?  Never seen that before.  Is that an idiosyncrasy of the **fmt** library? is there a reference describing that format?
 - Many thanks to [Syys96 for assistance on this one... ](https://github.com/microsoft/vcpkg/issues/11354#issuecomment-633248199)
 - Oops.  I totally missed this the first time through.  When you run `$ vcpkg install fmt` the system eventually responds with 
 
     `The package fmt:x64-linux provides CMake targets:`
     
     `    find_package(fmt CONFIG REQUIRED)`
     
     `    target_link_libraries(main PRIVATE fmt::fmt fmt::fmt-header-only)`
     
 - Those lines of code get inserted into the CMakeLists.txt file, and thats where the odd `fmt::fmt fmt::fmt-header-only` came from!
 - Additionally when you `$ vcpkg integrate install` the system responds with: 
 
     `    Applied user-wide integration for this vcpkg root.`

     `    CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/home/lbc/vcpkg/scripts/buildsystems/vcpkg.cmake"`
     
 - With that last little bit you should create one more entry for the CMakeLists.txt file:  
 
      `     set(CMAKE_TOOLCHAIN_FILE /home/lbc/vcpkg/scripts/buildsystems/vcpkg.cmake)` 
      
  And when you are done, your **CMakeLists.txt** file should look like: 

     cmake_minimum_required(VERSION 3.12)     
     set(CMAKE_TOOLCHAIN_FILE /home/lbc/vcpkg/scripts/buildsystems/vcpkg.cmake)     
     project(test_cpp)     
     find_package(fmt CONFIG REQUIRED)     
     add_executable(test_cpp main.cpp)     
     target_link_libraries(test_cpp PRIVATE fmt::fmt fmt::fmt-header-only)

 