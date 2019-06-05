#include "fstream"
#include "iostream"

#include "planreader.h"

#include "task.h"
#include "taskmngr.h"

namespace io
{
const std::string WHITESPACE   = " \n\r\t\f\v";
const char ANGLE_BRACKET_CLOSE = '>';
// const char ANGLE_BRACKET_OPEN  = '<';

size_t parse_indent(std::string& line, const size_t linectr,
                    unsigned int& char_cursor)
{
    size_t indent = line.find_first_not_of(WHITESPACE);
    line          = (indent == std::string::npos) ? "" : line.substr(indent);

    /*      print indentation       */
    printf("~%zu \tindent (%zu):", linectr, indent);
    for (int i = 0; i < indent; i++) printf("_");
    printf("\n");

    char_cursor = indent;
    return indent;
}

/**
 * Find the dependency mode of a task. Dependency mode is `parallel` by default.
 */
tasks::ChildDependencyModes parse_dependency_mode(std::string& line)
{
    tasks::ChildDependencyModes res = tasks::ChildDependencyModes::parallel;
    size_t close_bracket_pos        = line.find_first_of(ANGLE_BRACKET_CLOSE);
    if (close_bracket_pos != std::string::npos)
    {
        if (close_bracket_pos >= 2 && line[close_bracket_pos - 2] == '<')
        {
            const char mode = line[close_bracket_pos - 1];
            if (mode == 'S' || 'P')
            {
                if (mode == 'S')
                {
                    res = tasks::ChildDependencyModes::sequential;
                }
                line.erase(close_bracket_pos - 2, 3);
            }
        }
    }
    return res;
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
            unsigned int char_cursor = 0;
            size_t curr_indent       = parse_indent(line, linectr, char_cursor);

            if (curr_indent > prev_indent) curr_ptid = prev_tid;

            tasks::ChildDependencyModes mode = parse_dependency_mode(line);

            prev_tid    = tmg.add_task(line, curr_ptid);
            prev_indent = curr_indent;

            linectr++;
        }
    }
}
} // namespace io