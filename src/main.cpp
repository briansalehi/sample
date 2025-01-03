#include <filesystem>
#include <iostream>

int main(int argc, char** argv)
{
    std::cerr << std::filesystem::path{argv[0]}.filename().string() << "v" PROGRAM_VERSION;
}
