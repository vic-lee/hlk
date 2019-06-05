#include "fstream"
#include "iostream"

#include "planreader.h"

#include "task.h"
#include "taskmngr.h"

namespace io
{
size_t check_indent(const std::string& line, const size_t linectr,
                    unsigned int& ic)
{
    size_t indent = 0;
    for (const char& c : line)
    {
        if (c > ' ')
            break;
        else
            indent++;
    }

    printf("~%zu \tindent (%zu):", linectr, indent);
    for (int i = 0; i < indent; i++) printf("_");
    printf("\n");

    ic = indent;
    return indent;
}

void read_tasks(tasks::TaskManager& tmg, const std::string& fpath)
{
    std::ifstream plan(fpath);
    if (!plan)
    {
        std::cout << "The plan file `" << fpath << "` could not be opened."
                  << std::endl;
        return;
    }
    else
    {
        std::string line;
        size_t linectr     = 0;
        size_t prev_indent = 0;
        tasks::tid_t prev_tid;
        tasks::tid_t curr_ptid = tasks::TaskManager::ROOT_;
        while (getline(plan, line))
        {
            unsigned int ic    = 0;
            size_t curr_indent = io::check_indent(line, linectr, ic);

            if (curr_indent > prev_indent) curr_ptid = prev_tid;

            prev_tid    = tmg.add_task(line.substr(ic + 2), curr_ptid);
            prev_indent = curr_indent;
            linectr++;
        }
    }
}
} // namespace io