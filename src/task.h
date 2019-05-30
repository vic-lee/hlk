#pragma once

#include "string"

namespace tasks
{
typedef int tid_t;
struct task_t
{
    tid_t tid;
    tid_t ptid;
    std::string name;
    task_t(std::string name, tid_t tid, tid_t ptid) : tid(tid), ptid(ptid), name(name){};
};
} // namespace tasks