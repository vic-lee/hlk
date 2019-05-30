#pragma once

#include "stddef.h"
#include "string"

namespace io
{
size_t check_indent(const std::string &line, const size_t linectr, unsigned int &ic);
}