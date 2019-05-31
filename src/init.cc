#include "fstream"

#include "planreader.h"
#include "taskmngr.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide a file name.\n");
        return -1;
    }
    std::string fpath = argv[1];
    tasks::TaskManager tmg = tasks::TaskManager();
    io::read_tasks(tmg, fpath);
    return 0;
}