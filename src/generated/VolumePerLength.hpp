#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class VolumePerLengthUnit : std::uint8_t
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
    class VolumePerLength : public UnitsNetBase
    {
    public:
        constexpr explicit VolumePerLength(
            const un_scalar_t value,
            const VolumePerLengthUnit unit = VolumePerLengthUnit::CubicMetersPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumePerLength operator+(const VolumePerLength& other) const noexcept
        {
            return VolumePerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumePerLength operator-(const VolumePerLength& other)const noexcept
        {
            return VolumePerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumePerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumePerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumePerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumePerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumePerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumePerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumePerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicMetersPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_meters_per_meter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicMetersPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_meter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_kilometer() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerKilometer);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_kilometer(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerKilometer);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_millimeter() const
        {
            return convert_from_base(VolumePerLengthUnit::LitersPerMillimeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_millimeter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LitersPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::OilBarrelsPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_oil_barrels_per_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::OilBarrelsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardsPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_us_survey_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardsPerUsSurveyFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_us_survey_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardsPerUsSurveyFoot);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::UsGallonsPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_us_gallons_per_mile(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::UsGallonsPerMile);
        }

        [[nodiscard]] constexpr un_scalar_t imperial_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::ImperialGallonsPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_imperial_gallons_per_mile(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::ImperialGallonsPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_invalid()
        {
            return VolumePerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumePerLengthUnit unit)
        {
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMetersPerMeter:
                return value;

            case VolumePerLengthUnit::LitersPerMeter:
                return value / static_cast<un_scalar_t>(1000);

            case VolumePerLengthUnit::LitersPerKilometer:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumePerLengthUnit::LitersPerMillimeter:
                return value;

            case VolumePerLengthUnit::OilBarrelsPerFoot:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(0.3048);

            case VolumePerLengthUnit::CubicYardsPerFoot:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(0.3048);

            case VolumePerLengthUnit::CubicYardsPerUsSurveyFoot:
                return value * static_cast<un_scalar_t>(0.764554857984) * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case VolumePerLengthUnit::UsGallonsPerMile:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(1609.344);

            case VolumePerLengthUnit::ImperialGallonsPerMile:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(1609.344);

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumePerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMetersPerMeter:
                return base_value;

            case VolumePerLengthUnit::LitersPerMeter:
                return base_value * static_cast<un_scalar_t>(1000);

            case VolumePerLengthUnit::LitersPerKilometer:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumePerLengthUnit::LitersPerMillimeter:
                return base_value;

            case VolumePerLengthUnit::OilBarrelsPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.158987294928);

            case VolumePerLengthUnit::CubicYardsPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.764554857984);

            case VolumePerLengthUnit::CubicYardsPerUsSurveyFoot:
                return base_value * static_cast<un_scalar_t>(1200) / (static_cast<un_scalar_t>(0.764554857984) * static_cast<un_scalar_t>(3937));

            case VolumePerLengthUnit::UsGallonsPerMile:
                return base_value * static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(0.003785411784);

            case VolumePerLengthUnit::ImperialGallonsPerMile:
                return base_value * static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(0.00454609);

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        un_scalar_t value_;
        VolumePerLengthUnit value_unit_type_;       
    };
}
