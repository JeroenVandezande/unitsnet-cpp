#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumeFlowPerAreaUnit : std::uint16_t
    {
        CubicMetersPerSecondPerSquareMeter,
        CubicFeetPerMinutePerSquareFoot,
    };

    /// <summary></summary>
    class VolumeFlowPerArea
    {
    public:
        constexpr explicit VolumeFlowPerArea(
            double value,
            VolumeFlowPerAreaUnit unit = VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumeFlowPerAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator+(VolumeFlowPerArea other) const noexcept
        {
            return VolumeFlowPerArea(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator-(VolumeFlowPerArea other) const noexcept
        {
            return VolumeFlowPerArea(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator*(double scalar) const noexcept
        {
            return VolumeFlowPerArea(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator/(double scalar) const noexcept
        {
            return VolumeFlowPerArea(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VolumeFlowPerArea other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VolumeFlowPerArea other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double cubic_meters_per_second_per_square_meter() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_meters_per_second_per_square_meter(double value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter);
        }


        [[nodiscard]] constexpr double cubic_feet_per_minute_per_square_foot() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_feet_per_minute_per_square_foot(double value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumeFlowPerAreaUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter:
                return value;

            case VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot:
                return value * (0.028316846592 / 60) / 9.290304e-2;

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumeFlowPerAreaUnit unit) const
        {
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter:
                return value_;

            case VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot:
                return value_ * 9.290304e-2 / (0.028316846592 / 60);

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        double value_;
    };
}
