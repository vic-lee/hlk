#pragma once

#include "string"

namespace tasks
{
enum class ChildDependencyModes
{
    undefined,  /* for tasks without subtasks (leaf nodes) */
    sequential, /* each subtask is to be executed sequentially */
    parallel    /* each subtask can be run in parallel (no mutual dependency) */
};

typedef int tid_t;

struct task_t
{
    tid_t tid;
    tid_t ptid;
    ChildDependencyModes mode;
    std::string name;
    task_t(std::string name, tid_t tid, tid_t ptid, ChildDependencyModes mode)
        : tid(tid), ptid(ptid), mode(mode), name(name){};
};
} // namespace tasks