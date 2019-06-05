#pragma once

#include "stddef.h"
#include "string"

#include "taskmngr.h"

namespace io
{
void read_tasks(tasks::TaskManager &tmg, const std::string &fpath);
}
