#include "taskmngr.h"

namespace tasks
{
const unsigned int TaskManager::ROOT_ = 0;
unsigned int TaskManager::taskctr_    = 1;

TaskManager::TaskManager() {}

tid_t TaskManager::add_task(std::string taskname)
{
    return add_task(taskname, ROOT_, ChildDependencyModes::parallel);
}

tid_t TaskManager::add_task(std::string taskname, tid_t ptid,
                            ChildDependencyModes mode)
{
    if (!find(ptid)) return -1;
    tid_t tid = taskctr_++;
    tasktable_.insert(TDE_t(tid, task_t(taskname, tid, ptid, mode)));
    return tid;
}

bool TaskManager::find(tid_t tid) { return tid < taskctr_; }

/**
 * Return pointer to a task's parent given the task's id, 
 * or nullptr if this parent does not exist.
 */
task_t* TaskManager::find_parent_of(tid_t tid)
{
    if (!find(tid))
    {
        return nullptr;
    }
    else if (!find(tasktable_[tid].ptid))
    {
        return nullptr;
    }
    else
    {
        tid_t ptid = tasktable_[tid].ptid;
        return &tasktable_[ptid];
    }
}

std::ostream& operator<<(std::ostream& os, const TaskManager& tmg)
{
    os << "-------------------- Tasks --------------------\n";
    os << "TID \tPTID \tMODE \tNAME";
    for (auto const& task : tmg.tasktable_)
    {
        os << "\n"
           << task.second.tid << "\t" << task.second.ptid << "\t"
           << task.second.mode << "\t" << task.second.name;
    }
    return os;
}

} // namespace tasks