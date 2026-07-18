#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RotationalStiffnessPerLengthUnit : std::uint16_t
    {
        NewtonMetersPerRadianPerMeter,
        KilonewtonMetersPerRadianPerMeter,
        MeganewtonMetersPerRadianPerMeter,
        PoundForceFeetPerDegreesPerFeet,
        KilopoundForceFeetPerDegreesPerFeet,
    };

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffnessPerLength
    {
    public:
        constexpr explicit RotationalStiffnessPerLength(
            double value,
            RotationalStiffnessPerLengthUnit unit = RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RotationalStiffnessPerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator+(RotationalStiffnessPerLength other) const noexcept
        {
            return RotationalStiffnessPerLength(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator-(RotationalStiffnessPerLength other) const noexcept
        {
            return RotationalStiffnessPerLength(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator*(double scalar) const noexcept
        {
            return RotationalStiffnessPerLength(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator/(double scalar) const noexcept
        {
            return RotationalStiffnessPerLength(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RotationalStiffnessPerLength other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RotationalStiffnessPerLength other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double newton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_newton_meters_per_radian_per_meter(double value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr double kilonewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilonewton_meters_per_radian_per_meter(double value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr double meganewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_meganewton_meters_per_radian_per_meter(double value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr double pound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_pound_force_feet_per_degrees_per_feet(double value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet);
        }


        [[nodiscard]] constexpr double kilopound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilopound_force_feet_per_degrees_per_feet(double value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RotationalStiffnessPerLengthUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter:
                return value;

            case RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter:
                return (value * 1e3);

            case RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter:
                return (value * 1e6);

            case RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet:
                return value * (4.4482216152605 * 180 / std::numbers::pi);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet:
                return value * (4.4482216152605e3 * 180 / std::numbers::pi);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RotationalStiffnessPerLengthUnit unit) const
        {
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter:
                return value_;

            case RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter:
                return (value_) / 1e3;

            case RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter:
                return (value_) / 1e6;

            case RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet:
                return value_ / (4.4482216152605 * 180 / std::numbers::pi);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet:
                return value_ / (4.4482216152605e3 * 180 / std::numbers::pi);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        double value_;
    };
}
