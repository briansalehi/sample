cmake_minimum_required(VERSION 3.30)
project(Sample VERSION 0.1 LANGUAGES CXX DESCRIPTION "Sample Project")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH $<INSTALL_INTERFACE:$CMAKE_INSTALL_LIBDIR>)

add_executable(sample src/main.cpp)
target_compile_definitions(sample PRIVATE -D PROGRAM_VERSION=${PROJECT_VERSION})

enable_testing()

write_basic_package_version_file(${CMAKE_BINARY_DIR}/SampleVersion.cmake COMPATIBILITY SameMinorVersion)
install(TARGETS sample RUNTIME CONFIGURATIONS Release MinSizeRel)
install(FILES ${CMAKE_BINARY_DIR}/SampleVersion.cmake CONFIGURATIONS Release MinSizeRel DESTINATION ${CMAKE_INSTALL_LIBDIR}/sample/cmake)

set(CPACK_PACKAGE_VENDOR "Brian Salehi <briansalehi@proton.me>")
set(CPACK_PACKAGE_CONTACT "briansalehi@proton.me")
set(CPACK_PACKAGE_DESCRIPTION "")
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_BINARY_DIR}/Packages)
include(CPack)
