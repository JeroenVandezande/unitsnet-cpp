#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ScalarUnit : std::uint16_t
    {
        Amount,
    };

    /// <summary>A way of representing a number of items.</summary>
    class Scalar
    {
    public:
        constexpr explicit Scalar(
            double value,
            ScalarUnit unit = ScalarUnit::Amount)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ScalarUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Scalar operator+(Scalar other) const noexcept
        {
            return Scalar(value_ + other.value_);
        }

        [[nodiscard]] constexpr Scalar operator-(Scalar other) const noexcept
        {
            return Scalar(value_ - other.value_);
        }

        [[nodiscard]] constexpr Scalar operator*(double scalar) const noexcept
        {
            return Scalar(value_ * scalar);
        }

        [[nodiscard]] constexpr Scalar operator/(double scalar) const noexcept
        {
            return Scalar(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Scalar other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Scalar other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double amount() const
        {
            return convert_from_base(ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_amount(double value)
        {
            return Scalar(value, ScalarUnit::Amount);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ScalarUnit unit)
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ScalarUnit unit) const
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value_;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        double value_;
    };
}
