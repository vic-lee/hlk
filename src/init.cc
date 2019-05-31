#include "fstream"

#include "planreader.h"
#include "taskmngr.h"

int main(int argc, char *argv[])
{
    std::string fpath;
    if (argc < 2)
    {
        fpath = "in/sample.md";
        printf("File name not provided, using `%s`.\n", fpath.c_str());
    }
    else
    {
        fpath = argv[1];
    }

    tasks::TaskManager tmg = tasks::TaskManager();
    io::read_tasks(tmg, fpath);

    return 0;
}