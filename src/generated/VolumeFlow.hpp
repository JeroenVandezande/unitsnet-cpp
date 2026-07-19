#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class VolumeFlowUnit : std::uint8_t
    {
        CubicMetersPerSecond,
        CubicMetersPerMinute,
        CubicMetersPerHour,
        CubicMetersPerDay,
        CubicFeetPerSecond,
        CubicFeetPerMinute,
        CubicFeetPerHour,
        CubicYardsPerSecond,
        CubicYardsPerMinute,
        CubicYardsPerHour,
        CubicYardsPerDay,
        MillionUsGallonsPerDay,
        UsGallonsPerDay,
        MegausGallonsPerDay,
        LitersPerSecond,
        NanolitersPerSecond,
        MicrolitersPerSecond,
        MillilitersPerSecond,
        CentilitersPerSecond,
        DecilitersPerSecond,
        DecalitersPerSecond,
        HectolitersPerSecond,
        KilolitersPerSecond,
        MegalitersPerSecond,
        LitersPerMinute,
        NanolitersPerMinute,
        MicrolitersPerMinute,
        MillilitersPerMinute,
        CentilitersPerMinute,
        DecilitersPerMinute,
        DecalitersPerMinute,
        HectolitersPerMinute,
        KilolitersPerMinute,
        MegalitersPerMinute,
        LitersPerHour,
        NanolitersPerHour,
        MicrolitersPerHour,
        MillilitersPerHour,
        CentilitersPerHour,
        DecilitersPerHour,
        DecalitersPerHour,
        HectolitersPerHour,
        KilolitersPerHour,
        MegalitersPerHour,
        LitersPerDay,
        NanolitersPerDay,
        MicrolitersPerDay,
        MillilitersPerDay,
        CentilitersPerDay,
        DecilitersPerDay,
        DecalitersPerDay,
        HectolitersPerDay,
        KilolitersPerDay,
        MegalitersPerDay,
        UsGallonsPerSecond,
        UsGallonsPerMinute,
        UkGallonsPerDay,
        MegaukGallonsPerDay,
        UkGallonsPerHour,
        UkGallonsPerMinute,
        UkGallonsPerSecond,
        MegaukGallonsPerSecond,
        KilousGallonsPerMinute,
        UsGallonsPerHour,
        CubicDecimetersPerMinute,
        OilBarrelsPerDay,
        OilBarrelsPerMinute,
        OilBarrelsPerHour,
        OilBarrelsPerSecond,
        CubicMillimetersPerSecond,
        AcreFeetPerSecond,
        AcreFeetPerMinute,
        AcreFeetPerHour,
        AcreFeetPerDay,
        CubicCentimetersPerMinute,
    };

    /// <summary>In physics and engineering, in particular fluid dynamics and hydrometry, the volumetric flow rate, (also known as volume flow rate, rate of fluid flow or volume velocity) is the volume of fluid which passes through a given surface per unit time. The SI unit is m³/s (cubic meters per second). In US Customary Units and British Imperial Units, volumetric flow rate is often expressed as ft³/s (cubic feet per second). It is usually represented by the symbol Q.</summary>
    class VolumeFlow : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeFlow(
            const un_scalar_t value,
            const VolumeFlowUnit unit = VolumeFlowUnit::CubicMetersPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == VolumeFlowUnit::CubicMetersPerSecond)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeFlow operator+(const VolumeFlow& other) const noexcept
        {
            return VolumeFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlow operator-(const VolumeFlow& other)const noexcept
        {
            return VolumeFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t million_us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MillionUsGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_million_us_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillionUsGallonsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t megaus_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegausGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaus_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegausGallonsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t hectoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kiloliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t decaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t hectoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t kiloliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t megaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t decaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t hectoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t kiloliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t megaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t decaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t hectoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t kiloliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t megaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t us_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t us_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t megauk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megauk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilous_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KilousGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kilous_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilousGallonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t us_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_decimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicDecimetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_decimeters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicDecimetersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_millimeters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMillimetersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_millimeters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMillimetersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t acre_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t acre_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t acre_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t acre_feet_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_centimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicCentimetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_centimeters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicCentimetersPerMinute);
        }


        [[nodiscard]] static constexpr VolumeFlow from_invalid()
        {
            return VolumeFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeFlowUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowUnit::CubicMetersPerSecond:
                return value;

            case VolumeFlowUnit::CubicMetersPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicMetersPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicMetersPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicFeetPerSecond:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case VolumeFlowUnit::CubicFeetPerMinute:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicFeetPerHour:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicYardsPerSecond:
                return value * static_cast<un_scalar_t>(0.764554857984);

            case VolumeFlowUnit::CubicYardsPerMinute:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicYardsPerHour:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicYardsPerDay:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MillionUsGallonsPerDay:
                return value * static_cast<un_scalar_t>(1e6) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::UsGallonsPerDay:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MegausGallonsPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::LitersPerSecond:
                return value / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::NanolitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MicrolitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MillilitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::CentilitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::DecilitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::DecalitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::HectolitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::KilolitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MegalitersPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::LitersPerMinute:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::NanolitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MicrolitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MillilitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CentilitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::DecilitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::DecalitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::HectolitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::KilolitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MegalitersPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::LitersPerHour:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::NanolitersPerHour:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MicrolitersPerHour:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MillilitersPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CentilitersPerHour:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::DecilitersPerHour:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::DecalitersPerHour:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::HectolitersPerHour:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::KilolitersPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MegalitersPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::LitersPerDay:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::NanolitersPerDay:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MicrolitersPerDay:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MillilitersPerDay:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::CentilitersPerDay:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::DecilitersPerDay:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::DecalitersPerDay:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::HectolitersPerDay:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::KilolitersPerDay:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegalitersPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::UsGallonsPerSecond:
                return value * static_cast<un_scalar_t>(0.003785411784);

            case VolumeFlowUnit::UsGallonsPerMinute:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UkGallonsPerDay:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MegaukGallonsPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::UkGallonsPerHour:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::UkGallonsPerMinute:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UkGallonsPerSecond:
                return value * static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::MegaukGallonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::KilousGallonsPerMinute:
                return value * static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UsGallonsPerHour:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicDecimetersPerMinute:
                return value / static_cast<un_scalar_t>(60000.00000);

            case VolumeFlowUnit::OilBarrelsPerDay:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::OilBarrelsPerMinute:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::OilBarrelsPerHour:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::OilBarrelsPerSecond:
                return value * static_cast<un_scalar_t>(0.158987294928);

            case VolumeFlowUnit::CubicMillimetersPerSecond:
                return value * static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::AcreFeetPerSecond:
                return value * static_cast<un_scalar_t>(1233.48183754752);

            case VolumeFlowUnit::AcreFeetPerMinute:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::AcreFeetPerHour:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::AcreFeetPerDay:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicCentimetersPerMinute:
                return value * static_cast<un_scalar_t>(1e-6) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case VolumeFlowUnit::CubicMetersPerSecond:
                return base_value_;

            case VolumeFlowUnit::CubicMetersPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicMetersPerHour:
                return base_value_ * static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicMetersPerDay:
                return base_value_ * static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicFeetPerSecond:
                return base_value_ / static_cast<un_scalar_t>(0.028316846592);

            case VolumeFlowUnit::CubicFeetPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CubicFeetPerHour:
                return base_value_ / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicYardsPerSecond:
                return base_value_ / static_cast<un_scalar_t>(0.764554857984);

            case VolumeFlowUnit::CubicYardsPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CubicYardsPerHour:
                return base_value_ / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicYardsPerDay:
                return base_value_ / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MillionUsGallonsPerDay:
                return base_value_ / (static_cast<un_scalar_t>(1e6) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::UsGallonsPerDay:
                return base_value_ / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegausGallonsPerDay:
                return (base_value_ / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LitersPerSecond:
                return base_value_ * static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::NanolitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicrolitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MillilitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentilitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DecilitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecalitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectolitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KilolitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegalitersPerSecond:
                return (base_value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LitersPerMinute:
                return base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::NanolitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicrolitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MillilitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentilitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DecilitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecalitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectolitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KilolitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegalitersPerMinute:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LitersPerHour:
                return base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::NanolitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicrolitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MillilitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentilitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DecilitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecalitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectolitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KilolitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegalitersPerHour:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LitersPerDay:
                return base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::NanolitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicrolitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MillilitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentilitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DecilitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecalitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectolitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KilolitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegalitersPerDay:
                return (base_value_ * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::UsGallonsPerSecond:
                return base_value_ / static_cast<un_scalar_t>(0.003785411784);

            case VolumeFlowUnit::UsGallonsPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UkGallonsPerDay:
                return base_value_ / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegaukGallonsPerDay:
                return (base_value_ / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::UkGallonsPerHour:
                return base_value_ / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::UkGallonsPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UkGallonsPerSecond:
                return base_value_ / static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::MegaukGallonsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::KilousGallonsPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UsGallonsPerHour:
                return base_value_ / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicDecimetersPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60000.00000);

            case VolumeFlowUnit::OilBarrelsPerDay:
                return base_value_ / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::OilBarrelsPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::OilBarrelsPerHour:
                return base_value_ / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::OilBarrelsPerSecond:
                return base_value_ / static_cast<un_scalar_t>(0.158987294928);

            case VolumeFlowUnit::CubicMillimetersPerSecond:
                return base_value_ / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::AcreFeetPerSecond:
                return base_value_ / static_cast<un_scalar_t>(1233.48183754752);

            case VolumeFlowUnit::AcreFeetPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::AcreFeetPerHour:
                return base_value_ / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::AcreFeetPerDay:
                return base_value_ / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::CubicCentimetersPerMinute:
                return base_value_ / (static_cast<un_scalar_t>(1e-6) / static_cast<un_scalar_t>(60));

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        un_scalar_t value_;
        VolumeFlowUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
