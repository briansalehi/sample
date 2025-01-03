#include <filesystem>
#include <iostream>
#include <print>

int main(int argc, char** argv)
{
    std::println(std::cerr, "{} v{}", std::filesystem::path{argv[0]}.filename().string(), PROGRAM_VERSION);
}
