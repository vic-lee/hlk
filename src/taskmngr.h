#pragma once

#include <iostream>
#include <map>

#include "task.h"

namespace tasks
{
class TaskManager
{
    typedef std::pair<tid_t, task_t> TDE_t;
    typedef std::map<tid_t, task_t> TaskTable;

  public:
    static const unsigned int ROOT_;
    TaskManager();
    bool find(tid_t tid);
    task_t* find_parent_of(tid_t tid);
    tid_t add_task(std::string taskname);
    tid_t add_task(std::string taskname, tid_t ptid, ChildDependencyModes mode);
    friend std::ostream& operator<<(std::ostream& os, const TaskManager& tmg);

  private:
    static unsigned int taskctr_;
    TaskTable tasktable_;
};
} // namespace tasks