#pragma once

#include "../Types.hpp"

namespace dss::commands {
struct ReleaseLock {
  LockID id;
};
} // namespace dss::commands