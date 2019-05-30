#pragma once

#include "string"

namespace tasks
{
typedef unsigned int tid_t;
struct task_t
{
    tid_t tid;
    tid_t ptid;
    std::string name;
    task_t(std::string name) : name(name){};
};
} // namespace tasks