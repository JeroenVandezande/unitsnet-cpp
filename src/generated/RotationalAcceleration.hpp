#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RotationalAccelerationUnit : std::uint8_t
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
            const un_scalar_t value,
            const RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadiansPerSecondSquared)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalAccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator+(const RotationalAcceleration other) const noexcept
        {
            return RotationalAcceleration(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator-(const RotationalAcceleration other) const noexcept
        {
            return RotationalAcceleration(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalAcceleration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RotationalAcceleration other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t radians_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RadiansPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_radians_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RadiansPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::DegreesPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_degrees_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::DegreesPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t revolutions_per_minute_per_second() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_minute_per_second(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t revolutions_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalAccelerationUnit unit)
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return value;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * value;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return ((static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(60)) * value;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) * value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalAccelerationUnit unit) const
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return value_;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * value_;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return (static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * value_;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (static_cast<un_scalar_t>(1) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * value_;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        un_scalar_t value_;
    };
}
