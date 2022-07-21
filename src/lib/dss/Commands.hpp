#pragma once

#include <variant>

#include "commands/CommitTransaction.hpp"
#include "commands/ExecuteQuery.hpp"
#include "commands/InsertValue.hpp"
#include "commands/PrepareTransaction.hpp"
#include "commands/ReleaseLock.hpp"
#include "commands/RemoveValue.hpp"
#include "commands/RequestLock.hpp"

namespace dss {
// Rendering between messages and commands
using CommandMessage =
    std::variant<commands::CommitTransaction, commands::ExecuteQuery,
                 commands::InsertValue, commands::PrepareTransaction,
                 commands::ReleaseLock, commands::RemoveValue,
                 commands::RequestLock>;
} // namespace dss