#pragma once 

#include "reflection.hpp"

#include <string_view>

/*
 * This class holds annotations for each entity.
 */

namespace metaorm {

struct primaryKey {};
struct generated {};
struct ignore {};

struct column {
    std::string_view name;
};

} // namespace meta