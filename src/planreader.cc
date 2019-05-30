#include "fstream"
#include "iostream"

int main(int argc, char *argv[])
{
    std::ifstream plan("in/sample.md");
    std::string line;
    while (getline(plan, line))
    {
        std::cout << line << std::endl;
    }
    return 0;
}