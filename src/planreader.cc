#include "fstream"
#include "iostream"

#include "planreader.h"

namespace io
{
size_t check_indent(const std::string &line, const size_t linectr, unsigned int &ic)
{
    size_t indent = 0;
    for (const char &c : line)
    {
        if (c > ' ')
        {
            break;
        }
        else
        {
            indent++;
        }
    }
    printf("~%zu \tindent (%zu):", linectr, indent);
    for (int i = 0; i < indent; i++)
        printf("_");
    printf("\n");
    ic = indent;
    return indent;
}

void read_tasks(tasks::TaskManager &tmg, const std::string &fpath)
{
    std::ifstream plan(fpath);
    if (!plan)
    {
        std::cout << "The plan file `" << fpath << "` could not be opened.\n" << std::endl;
        return;
    }
    else
    {
        std::string line;
        size_t linectr = 0;
        while (getline(plan, line))
        {
            unsigned int ic = 0;
            io::check_indent(line, linectr, ic);
            linectr++;
        }
    }
}
} // namespace io