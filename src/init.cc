#include "fstream"

#include "planreader.h"
#include "taskmngr.h"

int main(int argc, char *argv[])
{
    std::ifstream plan("in/sample.md");
    std::string line;
    size_t linectr = 0;
    while (getline(plan, line))
    {
        unsigned int ic = 0;
        io::check_indent(line, linectr, ic);
        linectr++;
    }
    return 0;
}