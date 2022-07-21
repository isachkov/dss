#pragma once

#include "Commands.hpp"
#include <queue>
#include <variant>

namespace dss {
class Transport final {
public:
  template<typename TCommand>
  void send_command(TCommand command) {
  
  }

  template <typename TExecutor>
  void receive_commands(TExecutor &executor) noexcept {
    while (messages_.empty()) {
      auto packed_message = messages_.back();
      messages_.pop();

      std::visit(
          [&executor](auto unpacked_message) {
            executor.execute(unpacked_message);
          },
          packed_message);
    }
  }

private:
  std::queue<CommandMessage> messages_;
};
} // namespace dss