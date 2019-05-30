#pragma once

#include <map>

#include "task.h"

namespace tasks
{
class TaskManager
{
typedef std::pair<tid_t, task_t> TDE_t;
typedef std::map<tid_t, task_t> TaskTable;
public:
    TaskManager();
    bool find(tid_t tid);
    tid_t add(std::string taskname);
    tid_t add(std::string taskname, tid_t ptid);
private:
    static unsigned int taskctr_;
    static const unsigned int ROOT_;
    TaskTable tasktable_;
};
}