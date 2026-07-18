#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumePerLengthUnit : std::uint16_t
    {
        CubicMetersPerMeter,
        LitersPerMeter,
        LitersPerKilometer,
        LitersPerMillimeter,
        OilBarrelsPerFoot,
        CubicYardsPerFoot,
        CubicYardsPerUsSurveyFoot,
        UsGallonsPerMile,
        ImperialGallonsPerMile,
    };

    /// <summary>Volume, typically of fluid, that a container can hold within a unit of length.</summary>
    class VolumePerLength
    {
    public:
        constexpr explicit VolumePerLength(
            double value,
            VolumePerLengthUnit unit = VolumePerLengthUnit::CubicMetersPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumePerLength operator+(VolumePerLength other) const noexcept
        {
            return VolumePerLength(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumePerLength operator-(VolumePerLength other) const noexcept
        {
            return VolumePerLength(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumePerLength operator*(double scalar) const noexcept
        {
            return VolumePerLength(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumePerLength operator/(double scalar) const noexcept
        {
            return VolumePerLength(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VolumePerLength other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VolumePerLength other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double cubic_meters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicMetersPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_meters_per_meter(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicMetersPerMeter);
        }


        [[nodiscard]] constexpr double liters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_meter(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerMeter);
        }


        [[nodiscard]] constexpr double liters_per_kilometer() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerKilometer);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_kilometer(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerKilometer);
        }


        [[nodiscard]] constexpr double liters_per_millimeter() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerMillimeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_millimeter(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerMillimeter);
        }


        [[nodiscard]] constexpr double oil_barrels_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::OilBarrelsPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_oil_barrels_per_foot(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::OilBarrelsPerFoot);
        }


        [[nodiscard]] constexpr double cubic_yards_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardsPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_foot(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardsPerFoot);
        }


        [[nodiscard]] constexpr double cubic_yards_per_us_survey_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardsPerUsSurveyFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_us_survey_foot(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardsPerUsSurveyFoot);
        }


        [[nodiscard]] constexpr double us_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::UsGallonsPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_us_gallons_per_mile(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::UsGallonsPerMile);
        }


        [[nodiscard]] constexpr double imperial_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::ImperialGallonsPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_imperial_gallons_per_mile(double value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::ImperialGallonsPerMile);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumePerLengthUnit unit)
        {
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMetersPerMeter:
                return value;

            case VolumePerLengthUnit::LitersPerMeter:
                return value / 1000;

            case VolumePerLengthUnit::LitersPerKilometer:
                return value / 1e6;

            case VolumePerLengthUnit::LitersPerMillimeter:
                return value;

            case VolumePerLengthUnit::OilBarrelsPerFoot:
                return value * 0.158987294928 / 0.3048;

            case VolumePerLengthUnit::CubicYardsPerFoot:
                return value * 0.764554857984 / 0.3048;

            case VolumePerLengthUnit::CubicYardsPerUsSurveyFoot:
                return value * 0.764554857984 * 3937 / 1200;

            case VolumePerLengthUnit::UsGallonsPerMile:
                return value * 0.003785411784 / 1609.344;

            case VolumePerLengthUnit::ImperialGallonsPerMile:
                return value * 0.00454609 / 1609.344;

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumePerLengthUnit unit) const
        {
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMetersPerMeter:
                return value_;

            case VolumePerLengthUnit::LitersPerMeter:
                return value_ * 1000;

            case VolumePerLengthUnit::LitersPerKilometer:
                return value_ * 1e6;

            case VolumePerLengthUnit::LitersPerMillimeter:
                return value_;

            case VolumePerLengthUnit::OilBarrelsPerFoot:
                return value_ * 0.3048 / 0.158987294928;

            case VolumePerLengthUnit::CubicYardsPerFoot:
                return value_ * 0.3048 / 0.764554857984;

            case VolumePerLengthUnit::CubicYardsPerUsSurveyFoot:
                return value_ * 1200 / (0.764554857984 * 3937);

            case VolumePerLengthUnit::UsGallonsPerMile:
                return value_ * 1609.344 / 0.003785411784;

            case VolumePerLengthUnit::ImperialGallonsPerMile:
                return value_ * 1609.344 / 0.00454609;

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        double value_;
    };
}
