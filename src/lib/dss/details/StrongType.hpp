#pragma once

namespace dss::details {
template <typename TRaw, typename Tag> class StrongType {
public:
  StrongType(TRaw raw) noexcept : raw_{raw} {}
  StrongType() = default;

  StrongType(const StrongType &) = default;
  StrongType(StrongType &&) = default;

  StrongType &operator=(const StrongType &) = default;
  StrongType &operator=(StrongType &&) = default;

  auto raw() const noexcept { return raw_; }

  bool operator==(const StrongType &rv) const noexcept {
    return raw_ == rv.raw_;
  }

  bool operator<(const StrongType &rv) const noexcept { return raw_ < rv.raw_; }

  operator bool() const noexcept { return bool(raw_); }

private:
  TRaw raw_{};
};

} // namespace dss::details