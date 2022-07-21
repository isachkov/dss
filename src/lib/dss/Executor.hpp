#pragma once

#include "Commands.hpp"
#include "Storage.hpp"

#include <iostream>

namespace dss {

template <typename TStorage, typename TTransport> class Executor final {
public:
  Executor(TStorage &storage, TTransport &transport) noexcept
      : storage_{storage}, transport_{transport} {}

  template <typename TCommand> void execute(TCommand) const noexcept {
    std::cout << "Executor: unknown command\n";
  }

  void execute(const commands::CommitTransaction &) {
    std::cout << "Executor: commit transaction\n";
  }

  void execute(const commands::ExecuteQuery &) {
    std::cout << "Executor: execute query\n";
  }

  void execute(const commands::InsertValue &command) {
    using Stored = typename TStorage::stored_t;

    std::cout << "Executor: insert value\n";
    storage_.insert(Stored{command.key, command.value});
  }

  void execute(const commands::PrepareTransaction &) {
    std::cout << "Executor: prepare transaction\n";
  }

  void execute(const commands::ReleaseLock &) {
    std::cout << "Executor: release lock\n";
  }

  void execute(const commands::RemoveValue &command) {
    using Stored = typename TStorage::stored_t;

    std::cout << "Executor: remove value\n";
    storage_.remove(Stored{command.key, ""});
  }

  void execute(const commands::RequestLock &) {
    std::cout << "Executor: request lock\n";
  }

private:
  TStorage &storage_;
  TTransport &transport_;
};
} // namespace dss