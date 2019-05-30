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
} // namespace io