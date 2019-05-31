#pragma once

#include "stddef.h"
#include "string"

#include "taskmngr.h"

namespace io
{
size_t check_indent(const std::string &line, const size_t linectr, unsigned int &ic);
void read_tasks(tasks::TaskManager &tmg, const std::string &fpath);
}