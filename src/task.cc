#include <iostream>

#include "task.h"

namespace tasks
{
std::ostream& operator<<(std::ostream& os, const ChildDependencyModes& mode)
{
    switch (mode)
    {
    case ChildDependencyModes::undefined: os << "u"; break;
    case ChildDependencyModes::parallel: os << "P"; break;
    case ChildDependencyModes::sequential: os << "S"; break;
    }
    return os;
}
} // namespace tasks