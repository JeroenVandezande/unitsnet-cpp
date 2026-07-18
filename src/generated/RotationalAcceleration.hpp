#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RotationalAccelerationUnit : std::uint16_t
    {
        RadiansPerSecondSquared,
        DegreesPerSecondSquared,
        RevolutionsPerMinutePerSecond,
        RevolutionsPerSecondSquared,
    };

    /// <summary>Angular acceleration is the rate of change of rotational speed.</summary>
    class RotationalAcceleration
    {
    public:
        constexpr explicit RotationalAcceleration(
            double value,
            RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadiansPerSecondSquared)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RotationalAccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator+(RotationalAcceleration other) const noexcept
        {
            return RotationalAcceleration(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator-(RotationalAcceleration other) const noexcept
        {
            return RotationalAcceleration(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator*(double scalar) const noexcept
        {
            return RotationalAcceleration(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator/(double scalar) const noexcept
        {
            return RotationalAcceleration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RotationalAcceleration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RotationalAcceleration other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double radians_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RadiansPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_radians_per_second_squared(double value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RadiansPerSecondSquared);
        }


        [[nodiscard]] constexpr double degrees_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::DegreesPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_degrees_per_second_squared(double value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::DegreesPerSecondSquared);
        }


        [[nodiscard]] constexpr double revolutions_per_minute_per_second() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_minute_per_second(double value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }


        [[nodiscard]] constexpr double revolutions_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_second_squared(double value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RotationalAccelerationUnit unit)
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return value;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (std::numbers::pi / 180) * value;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return ((2 * std::numbers::pi) / 60) * value;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (2 * std::numbers::pi) * value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RotationalAccelerationUnit unit) const
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return value_;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (180 / std::numbers::pi) * value_;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return (60 / (2 * std::numbers::pi)) * value_;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (1 / (2 * std::numbers::pi)) * value_;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        double value_;
    };
}
