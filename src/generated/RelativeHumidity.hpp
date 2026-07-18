#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RelativeHumidityUnit : std::uint16_t
    {
        Percent,
    };

    /// <summary>Relative humidity is a ratio of the actual water vapor present in the air to the maximum water vapor in the air at the given temperature.</summary>
    class RelativeHumidity
    {
    public:
        constexpr explicit RelativeHumidity(
            double value,
            RelativeHumidityUnit unit = RelativeHumidityUnit::Percent)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RelativeHumidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RelativeHumidity operator+(RelativeHumidity other) const noexcept
        {
            return RelativeHumidity(value_ + other.value_);
        }

        [[nodiscard]] constexpr RelativeHumidity operator-(RelativeHumidity other) const noexcept
        {
            return RelativeHumidity(value_ - other.value_);
        }

        [[nodiscard]] constexpr RelativeHumidity operator*(double scalar) const noexcept
        {
            return RelativeHumidity(value_ * scalar);
        }

        [[nodiscard]] constexpr RelativeHumidity operator/(double scalar) const noexcept
        {
            return RelativeHumidity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RelativeHumidity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RelativeHumidity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double percent() const
        {
            return convert_from_base(RelativeHumidityUnit::Percent);
        }

        [[nodiscard]] static constexpr RelativeHumidity from_percent(double value)
        {
            return RelativeHumidity(value, RelativeHumidityUnit::Percent);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RelativeHumidityUnit unit)
        {
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return value;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RelativeHumidityUnit unit) const
        {
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return value_;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        double value_;
    };
}
