#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpecificVolumeUnit : std::uint16_t
    {
        CubicMetersPerKilogram,
        MillicubicMetersPerKilogram,
        CubicFeetPerPound,
    };

    /// <summary>In thermodynamics, the specific volume of a substance is the ratio of the substance's volume to its mass. It is the reciprocal of density and an intrinsic property of matter as well.</summary>
    class SpecificVolume
    {
    public:
        constexpr explicit SpecificVolume(
            double value,
            SpecificVolumeUnit unit = SpecificVolumeUnit::CubicMetersPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpecificVolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificVolume operator+(SpecificVolume other) const noexcept
        {
            return SpecificVolume(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificVolume operator-(SpecificVolume other) const noexcept
        {
            return SpecificVolume(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificVolume operator*(double scalar) const noexcept
        {
            return SpecificVolume(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificVolume operator/(double scalar) const noexcept
        {
            return SpecificVolume(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SpecificVolume other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SpecificVolume other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double cubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicMetersPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_meters_per_kilogram(double value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicMetersPerKilogram);
        }


        [[nodiscard]] constexpr double millicubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::MillicubicMetersPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_millicubic_meters_per_kilogram(double value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::MillicubicMetersPerKilogram);
        }


        [[nodiscard]] constexpr double cubic_feet_per_pound() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicFeetPerPound);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_feet_per_pound(double value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicFeetPerPound);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpecificVolumeUnit unit)
        {
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMetersPerKilogram:
                return value;

            case SpecificVolumeUnit::MillicubicMetersPerKilogram:
                return (value * 1e-3);

            case SpecificVolumeUnit::CubicFeetPerPound:
                return value * 0.028316846592 / 0.45359237;

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpecificVolumeUnit unit) const
        {
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMetersPerKilogram:
                return value_;

            case SpecificVolumeUnit::MillicubicMetersPerKilogram:
                return (value_) / 1e-3;

            case SpecificVolumeUnit::CubicFeetPerPound:
                return value_ * 0.45359237 / 0.028316846592;

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        double value_;
    };
}
