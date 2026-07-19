#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class SolidAngleUnit : std::uint8_t
    {
        Steradians,
    };

    /// <summary>In geometry, a solid angle is the two-dimensional angle in three-dimensional space that an object subtends at a point.</summary>
    class SolidAngle
    {
    public:
        constexpr explicit SolidAngle(
            const un_scalar_t value,
            const SolidAngleUnit unit = SolidAngleUnit::Steradians)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const SolidAngleUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SolidAngle operator+(const SolidAngle other) const noexcept
        {
            return SolidAngle(value_ + other.value_);
        }

        [[nodiscard]] constexpr SolidAngle operator-(const SolidAngle other) const noexcept
        {
            return SolidAngle(value_ - other.value_);
        }

        [[nodiscard]] constexpr SolidAngle operator*(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(value_ * scalar);
        }

        [[nodiscard]] constexpr SolidAngle operator/(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SolidAngle other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const SolidAngle other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t steradians() const
        {
            return convert_from_base(SolidAngleUnit::Steradians);
        }

        [[nodiscard]] static constexpr SolidAngle from_steradians(const un_scalar_t value)
        {
            return SolidAngle(value, SolidAngleUnit::Steradians);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SolidAngleUnit unit)
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return value;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SolidAngleUnit unit) const
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return value_;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        un_scalar_t value_;
    };
}
