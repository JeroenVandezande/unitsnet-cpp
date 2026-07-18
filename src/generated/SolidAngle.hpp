#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SolidAngleUnit : std::uint16_t
    {
        Steradians,
    };

    /// <summary>In geometry, a solid angle is the two-dimensional angle in three-dimensional space that an object subtends at a point.</summary>
    class SolidAngle
    {
    public:
        constexpr explicit SolidAngle(
            double value,
            SolidAngleUnit unit = SolidAngleUnit::Steradians)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SolidAngleUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SolidAngle operator+(SolidAngle other) const noexcept
        {
            return SolidAngle(value_ + other.value_);
        }

        [[nodiscard]] constexpr SolidAngle operator-(SolidAngle other) const noexcept
        {
            return SolidAngle(value_ - other.value_);
        }

        [[nodiscard]] constexpr SolidAngle operator*(double scalar) const noexcept
        {
            return SolidAngle(value_ * scalar);
        }

        [[nodiscard]] constexpr SolidAngle operator/(double scalar) const noexcept
        {
            return SolidAngle(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SolidAngle other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SolidAngle other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double steradians() const
        {
            return convert_from_base(SolidAngleUnit::Steradians);
        }

        [[nodiscard]] static constexpr SolidAngle from_steradians(double value)
        {
            return SolidAngle(value, SolidAngleUnit::Steradians);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SolidAngleUnit unit)
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return value;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SolidAngleUnit unit) const
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return value_;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        double value_;
    };
}
