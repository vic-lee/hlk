#include "fstream"
#include "iostream"

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

int main(int argc, char *argv[])
{
    std::ifstream plan("in/sample.md");
    std::string line;
    size_t linectr = 0;
    while (getline(plan, line))
    {
        unsigned int ic = 0;
        check_indent(line, linectr, ic);
        linectr++;
    }
    return 0;
}