#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumeFlowUnit : std::uint16_t
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
    class VolumeFlow
    {
    public:
        constexpr explicit VolumeFlow(
            double value,
            VolumeFlowUnit unit = VolumeFlowUnit::CubicMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeFlow operator+(VolumeFlow other) const noexcept
        {
            return VolumeFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumeFlow operator-(VolumeFlow other) const noexcept
        {
            return VolumeFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumeFlow operator*(double scalar) const noexcept
        {
            return VolumeFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumeFlow operator/(double scalar) const noexcept
        {
            return VolumeFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VolumeFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VolumeFlow other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double cubic_meters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerSecond);
        }


        [[nodiscard]] constexpr double cubic_meters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerMinute);
        }


        [[nodiscard]] constexpr double cubic_meters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerHour);
        }


        [[nodiscard]] constexpr double cubic_meters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMetersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMetersPerDay);
        }


        [[nodiscard]] constexpr double cubic_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerSecond);
        }


        [[nodiscard]] constexpr double cubic_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerMinute);
        }


        [[nodiscard]] constexpr double cubic_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFeetPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFeetPerHour);
        }


        [[nodiscard]] constexpr double cubic_yards_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerSecond);
        }


        [[nodiscard]] constexpr double cubic_yards_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerMinute);
        }


        [[nodiscard]] constexpr double cubic_yards_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerHour);
        }


        [[nodiscard]] constexpr double cubic_yards_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardsPerDay);
        }


        [[nodiscard]] constexpr double million_us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MillionUsGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_million_us_gallons_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillionUsGallonsPerDay);
        }


        [[nodiscard]] constexpr double us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerDay);
        }


        [[nodiscard]] constexpr double megaus_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegausGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaus_gallons_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegausGallonsPerDay);
        }


        [[nodiscard]] constexpr double liters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerSecond);
        }


        [[nodiscard]] constexpr double nanoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerSecond);
        }


        [[nodiscard]] constexpr double microliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerSecond);
        }


        [[nodiscard]] constexpr double milliliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerSecond);
        }


        [[nodiscard]] constexpr double centiliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerSecond);
        }


        [[nodiscard]] constexpr double deciliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerSecond);
        }


        [[nodiscard]] constexpr double decaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerSecond);
        }


        [[nodiscard]] constexpr double hectoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerSecond);
        }


        [[nodiscard]] constexpr double kiloliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerSecond);
        }


        [[nodiscard]] constexpr double megaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerSecond);
        }


        [[nodiscard]] constexpr double liters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerMinute);
        }


        [[nodiscard]] constexpr double nanoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerMinute);
        }


        [[nodiscard]] constexpr double microliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerMinute);
        }


        [[nodiscard]] constexpr double milliliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerMinute);
        }


        [[nodiscard]] constexpr double centiliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerMinute);
        }


        [[nodiscard]] constexpr double deciliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerMinute);
        }


        [[nodiscard]] constexpr double decaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerMinute);
        }


        [[nodiscard]] constexpr double hectoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerMinute);
        }


        [[nodiscard]] constexpr double kiloliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerMinute);
        }


        [[nodiscard]] constexpr double megaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerMinute);
        }


        [[nodiscard]] constexpr double liters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerHour);
        }


        [[nodiscard]] constexpr double nanoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerHour);
        }


        [[nodiscard]] constexpr double microliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerHour);
        }


        [[nodiscard]] constexpr double milliliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerHour);
        }


        [[nodiscard]] constexpr double centiliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerHour);
        }


        [[nodiscard]] constexpr double deciliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerHour);
        }


        [[nodiscard]] constexpr double decaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerHour);
        }


        [[nodiscard]] constexpr double hectoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerHour);
        }


        [[nodiscard]] constexpr double kiloliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerHour);
        }


        [[nodiscard]] constexpr double megaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerHour);
        }


        [[nodiscard]] constexpr double liters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::LitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LitersPerDay);
        }


        [[nodiscard]] constexpr double nanoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::NanolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanolitersPerDay);
        }


        [[nodiscard]] constexpr double microliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MicrolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicrolitersPerDay);
        }


        [[nodiscard]] constexpr double milliliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MillilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillilitersPerDay);
        }


        [[nodiscard]] constexpr double centiliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CentilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentilitersPerDay);
        }


        [[nodiscard]] constexpr double deciliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DecilitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecilitersPerDay);
        }


        [[nodiscard]] constexpr double decaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DecalitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecalitersPerDay);
        }


        [[nodiscard]] constexpr double hectoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::HectolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectolitersPerDay);
        }


        [[nodiscard]] constexpr double kiloliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::KilolitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilolitersPerDay);
        }


        [[nodiscard]] constexpr double megaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegalitersPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegalitersPerDay);
        }


        [[nodiscard]] constexpr double us_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerSecond);
        }


        [[nodiscard]] constexpr double us_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerMinute);
        }


        [[nodiscard]] constexpr double uk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerDay);
        }


        [[nodiscard]] constexpr double megauk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonsPerDay);
        }


        [[nodiscard]] constexpr double uk_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerHour);
        }


        [[nodiscard]] constexpr double uk_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerMinute);
        }


        [[nodiscard]] constexpr double uk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonsPerSecond);
        }


        [[nodiscard]] constexpr double megauk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonsPerSecond);
        }


        [[nodiscard]] constexpr double kilous_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KilousGallonsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kilous_gallons_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilousGallonsPerMinute);
        }


        [[nodiscard]] constexpr double us_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonsPerHour);
        }


        [[nodiscard]] constexpr double cubic_decimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicDecimetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_decimeters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicDecimetersPerMinute);
        }


        [[nodiscard]] constexpr double oil_barrels_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerDay);
        }


        [[nodiscard]] constexpr double oil_barrels_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerMinute);
        }


        [[nodiscard]] constexpr double oil_barrels_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerHour);
        }


        [[nodiscard]] constexpr double oil_barrels_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelsPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelsPerSecond);
        }


        [[nodiscard]] constexpr double cubic_millimeters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMillimetersPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_millimeters_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMillimetersPerSecond);
        }


        [[nodiscard]] constexpr double acre_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_second(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerSecond);
        }


        [[nodiscard]] constexpr double acre_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerMinute);
        }


        [[nodiscard]] constexpr double acre_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_hour(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerHour);
        }


        [[nodiscard]] constexpr double acre_feet_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFeetPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_day(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFeetPerDay);
        }


        [[nodiscard]] constexpr double cubic_centimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicCentimetersPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_centimeters_per_minute(double value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicCentimetersPerMinute);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumeFlowUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowUnit::CubicMetersPerSecond:
                return value;

            case VolumeFlowUnit::CubicMetersPerMinute:
                return value / 60;

            case VolumeFlowUnit::CubicMetersPerHour:
                return value / 3600;

            case VolumeFlowUnit::CubicMetersPerDay:
                return value / 86400;

            case VolumeFlowUnit::CubicFeetPerSecond:
                return value * 0.028316846592;

            case VolumeFlowUnit::CubicFeetPerMinute:
                return value * 0.028316846592 / 60;

            case VolumeFlowUnit::CubicFeetPerHour:
                return value * 0.028316846592 / 3600;

            case VolumeFlowUnit::CubicYardsPerSecond:
                return value * 0.764554857984;

            case VolumeFlowUnit::CubicYardsPerMinute:
                return value * 0.764554857984 / 60;

            case VolumeFlowUnit::CubicYardsPerHour:
                return value * 0.764554857984 / 3600;

            case VolumeFlowUnit::CubicYardsPerDay:
                return value * 0.764554857984 / 86400;

            case VolumeFlowUnit::MillionUsGallonsPerDay:
                return value * 1e6 * 0.003785411784 / 86400;

            case VolumeFlowUnit::UsGallonsPerDay:
                return value * 0.003785411784 / 86400;

            case VolumeFlowUnit::MegausGallonsPerDay:
                return (value * 1e6) * 0.003785411784 / 86400;

            case VolumeFlowUnit::LitersPerSecond:
                return value / 1000;

            case VolumeFlowUnit::NanolitersPerSecond:
                return (value * 1e-9) / 1000;

            case VolumeFlowUnit::MicrolitersPerSecond:
                return (value * 1e-6) / 1000;

            case VolumeFlowUnit::MillilitersPerSecond:
                return (value * 1e-3) / 1000;

            case VolumeFlowUnit::CentilitersPerSecond:
                return (value * 1e-2) / 1000;

            case VolumeFlowUnit::DecilitersPerSecond:
                return (value * 1e-1) / 1000;

            case VolumeFlowUnit::DecalitersPerSecond:
                return (value * 1e1) / 1000;

            case VolumeFlowUnit::HectolitersPerSecond:
                return (value * 1e2) / 1000;

            case VolumeFlowUnit::KilolitersPerSecond:
                return (value * 1e3) / 1000;

            case VolumeFlowUnit::MegalitersPerSecond:
                return (value * 1e6) / 1000;

            case VolumeFlowUnit::LitersPerMinute:
                return value / (1000 * 60);

            case VolumeFlowUnit::NanolitersPerMinute:
                return (value * 1e-9) / (1000 * 60);

            case VolumeFlowUnit::MicrolitersPerMinute:
                return (value * 1e-6) / (1000 * 60);

            case VolumeFlowUnit::MillilitersPerMinute:
                return (value * 1e-3) / (1000 * 60);

            case VolumeFlowUnit::CentilitersPerMinute:
                return (value * 1e-2) / (1000 * 60);

            case VolumeFlowUnit::DecilitersPerMinute:
                return (value * 1e-1) / (1000 * 60);

            case VolumeFlowUnit::DecalitersPerMinute:
                return (value * 1e1) / (1000 * 60);

            case VolumeFlowUnit::HectolitersPerMinute:
                return (value * 1e2) / (1000 * 60);

            case VolumeFlowUnit::KilolitersPerMinute:
                return (value * 1e3) / (1000 * 60);

            case VolumeFlowUnit::MegalitersPerMinute:
                return (value * 1e6) / (1000 * 60);

            case VolumeFlowUnit::LitersPerHour:
                return value / (1000 * 3600);

            case VolumeFlowUnit::NanolitersPerHour:
                return (value * 1e-9) / (1000 * 3600);

            case VolumeFlowUnit::MicrolitersPerHour:
                return (value * 1e-6) / (1000 * 3600);

            case VolumeFlowUnit::MillilitersPerHour:
                return (value * 1e-3) / (1000 * 3600);

            case VolumeFlowUnit::CentilitersPerHour:
                return (value * 1e-2) / (1000 * 3600);

            case VolumeFlowUnit::DecilitersPerHour:
                return (value * 1e-1) / (1000 * 3600);

            case VolumeFlowUnit::DecalitersPerHour:
                return (value * 1e1) / (1000 * 3600);

            case VolumeFlowUnit::HectolitersPerHour:
                return (value * 1e2) / (1000 * 3600);

            case VolumeFlowUnit::KilolitersPerHour:
                return (value * 1e3) / (1000 * 3600);

            case VolumeFlowUnit::MegalitersPerHour:
                return (value * 1e6) / (1000 * 3600);

            case VolumeFlowUnit::LitersPerDay:
                return value / (1000 * 86400);

            case VolumeFlowUnit::NanolitersPerDay:
                return (value * 1e-9) / (1000 * 86400);

            case VolumeFlowUnit::MicrolitersPerDay:
                return (value * 1e-6) / (1000 * 86400);

            case VolumeFlowUnit::MillilitersPerDay:
                return (value * 1e-3) / (1000 * 86400);

            case VolumeFlowUnit::CentilitersPerDay:
                return (value * 1e-2) / (1000 * 86400);

            case VolumeFlowUnit::DecilitersPerDay:
                return (value * 1e-1) / (1000 * 86400);

            case VolumeFlowUnit::DecalitersPerDay:
                return (value * 1e1) / (1000 * 86400);

            case VolumeFlowUnit::HectolitersPerDay:
                return (value * 1e2) / (1000 * 86400);

            case VolumeFlowUnit::KilolitersPerDay:
                return (value * 1e3) / (1000 * 86400);

            case VolumeFlowUnit::MegalitersPerDay:
                return (value * 1e6) / (1000 * 86400);

            case VolumeFlowUnit::UsGallonsPerSecond:
                return value * 0.003785411784;

            case VolumeFlowUnit::UsGallonsPerMinute:
                return value * 0.003785411784 / 60;

            case VolumeFlowUnit::UkGallonsPerDay:
                return value * 0.00454609 / 86400;

            case VolumeFlowUnit::MegaukGallonsPerDay:
                return (value * 1e6) * 0.00454609 / 86400;

            case VolumeFlowUnit::UkGallonsPerHour:
                return value * 0.00454609 / 3600;

            case VolumeFlowUnit::UkGallonsPerMinute:
                return value * 0.00454609 / 60;

            case VolumeFlowUnit::UkGallonsPerSecond:
                return value * 0.00454609;

            case VolumeFlowUnit::MegaukGallonsPerSecond:
                return (value * 1e6) * 0.00454609;

            case VolumeFlowUnit::KilousGallonsPerMinute:
                return value * 1000 * 0.003785411784 / 60;

            case VolumeFlowUnit::UsGallonsPerHour:
                return value * 0.003785411784 / 3600;

            case VolumeFlowUnit::CubicDecimetersPerMinute:
                return value / 60000.00000;

            case VolumeFlowUnit::OilBarrelsPerDay:
                return value * 0.158987294928 / 86400;

            case VolumeFlowUnit::OilBarrelsPerMinute:
                return value * 0.158987294928 / 60;

            case VolumeFlowUnit::OilBarrelsPerHour:
                return value * 0.158987294928 / 3600;

            case VolumeFlowUnit::OilBarrelsPerSecond:
                return value * 0.158987294928;

            case VolumeFlowUnit::CubicMillimetersPerSecond:
                return value * 1e-9;

            case VolumeFlowUnit::AcreFeetPerSecond:
                return value * 1233.48183754752;

            case VolumeFlowUnit::AcreFeetPerMinute:
                return value * 1233.48183754752 / 60;

            case VolumeFlowUnit::AcreFeetPerHour:
                return value * 1233.48183754752 / 3600;

            case VolumeFlowUnit::AcreFeetPerDay:
                return value * 1233.48183754752 / 86400;

            case VolumeFlowUnit::CubicCentimetersPerMinute:
                return value * 1e-6 / 60;

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumeFlowUnit unit) const
        {
            switch (unit)
            {

            case VolumeFlowUnit::CubicMetersPerSecond:
                return value_;

            case VolumeFlowUnit::CubicMetersPerMinute:
                return value_ * 60;

            case VolumeFlowUnit::CubicMetersPerHour:
                return value_ * 3600;

            case VolumeFlowUnit::CubicMetersPerDay:
                return value_ * 86400;

            case VolumeFlowUnit::CubicFeetPerSecond:
                return value_ / 0.028316846592;

            case VolumeFlowUnit::CubicFeetPerMinute:
                return value_ / (0.028316846592 / 60);

            case VolumeFlowUnit::CubicFeetPerHour:
                return value_ / (0.028316846592 / 3600);

            case VolumeFlowUnit::CubicYardsPerSecond:
                return value_ / 0.764554857984;

            case VolumeFlowUnit::CubicYardsPerMinute:
                return value_ / (0.764554857984 / 60);

            case VolumeFlowUnit::CubicYardsPerHour:
                return value_ / (0.764554857984 / 3600);

            case VolumeFlowUnit::CubicYardsPerDay:
                return value_ / (0.764554857984 / 86400);

            case VolumeFlowUnit::MillionUsGallonsPerDay:
                return value_ / (1e6 * 0.003785411784 / 86400);

            case VolumeFlowUnit::UsGallonsPerDay:
                return value_ / (0.003785411784 / 86400);

            case VolumeFlowUnit::MegausGallonsPerDay:
                return (value_ / (0.003785411784 / 86400)) / 1e6;

            case VolumeFlowUnit::LitersPerSecond:
                return value_ * 1000;

            case VolumeFlowUnit::NanolitersPerSecond:
                return (value_ * 1000) / 1e-9;

            case VolumeFlowUnit::MicrolitersPerSecond:
                return (value_ * 1000) / 1e-6;

            case VolumeFlowUnit::MillilitersPerSecond:
                return (value_ * 1000) / 1e-3;

            case VolumeFlowUnit::CentilitersPerSecond:
                return (value_ * 1000) / 1e-2;

            case VolumeFlowUnit::DecilitersPerSecond:
                return (value_ * 1000) / 1e-1;

            case VolumeFlowUnit::DecalitersPerSecond:
                return (value_ * 1000) / 1e1;

            case VolumeFlowUnit::HectolitersPerSecond:
                return (value_ * 1000) / 1e2;

            case VolumeFlowUnit::KilolitersPerSecond:
                return (value_ * 1000) / 1e3;

            case VolumeFlowUnit::MegalitersPerSecond:
                return (value_ * 1000) / 1e6;

            case VolumeFlowUnit::LitersPerMinute:
                return value_ * (1000 * 60);

            case VolumeFlowUnit::NanolitersPerMinute:
                return (value_ * (1000 * 60)) / 1e-9;

            case VolumeFlowUnit::MicrolitersPerMinute:
                return (value_ * (1000 * 60)) / 1e-6;

            case VolumeFlowUnit::MillilitersPerMinute:
                return (value_ * (1000 * 60)) / 1e-3;

            case VolumeFlowUnit::CentilitersPerMinute:
                return (value_ * (1000 * 60)) / 1e-2;

            case VolumeFlowUnit::DecilitersPerMinute:
                return (value_ * (1000 * 60)) / 1e-1;

            case VolumeFlowUnit::DecalitersPerMinute:
                return (value_ * (1000 * 60)) / 1e1;

            case VolumeFlowUnit::HectolitersPerMinute:
                return (value_ * (1000 * 60)) / 1e2;

            case VolumeFlowUnit::KilolitersPerMinute:
                return (value_ * (1000 * 60)) / 1e3;

            case VolumeFlowUnit::MegalitersPerMinute:
                return (value_ * (1000 * 60)) / 1e6;

            case VolumeFlowUnit::LitersPerHour:
                return value_ * (1000 * 3600);

            case VolumeFlowUnit::NanolitersPerHour:
                return (value_ * (1000 * 3600)) / 1e-9;

            case VolumeFlowUnit::MicrolitersPerHour:
                return (value_ * (1000 * 3600)) / 1e-6;

            case VolumeFlowUnit::MillilitersPerHour:
                return (value_ * (1000 * 3600)) / 1e-3;

            case VolumeFlowUnit::CentilitersPerHour:
                return (value_ * (1000 * 3600)) / 1e-2;

            case VolumeFlowUnit::DecilitersPerHour:
                return (value_ * (1000 * 3600)) / 1e-1;

            case VolumeFlowUnit::DecalitersPerHour:
                return (value_ * (1000 * 3600)) / 1e1;

            case VolumeFlowUnit::HectolitersPerHour:
                return (value_ * (1000 * 3600)) / 1e2;

            case VolumeFlowUnit::KilolitersPerHour:
                return (value_ * (1000 * 3600)) / 1e3;

            case VolumeFlowUnit::MegalitersPerHour:
                return (value_ * (1000 * 3600)) / 1e6;

            case VolumeFlowUnit::LitersPerDay:
                return value_ * (1000 * 86400);

            case VolumeFlowUnit::NanolitersPerDay:
                return (value_ * (1000 * 86400)) / 1e-9;

            case VolumeFlowUnit::MicrolitersPerDay:
                return (value_ * (1000 * 86400)) / 1e-6;

            case VolumeFlowUnit::MillilitersPerDay:
                return (value_ * (1000 * 86400)) / 1e-3;

            case VolumeFlowUnit::CentilitersPerDay:
                return (value_ * (1000 * 86400)) / 1e-2;

            case VolumeFlowUnit::DecilitersPerDay:
                return (value_ * (1000 * 86400)) / 1e-1;

            case VolumeFlowUnit::DecalitersPerDay:
                return (value_ * (1000 * 86400)) / 1e1;

            case VolumeFlowUnit::HectolitersPerDay:
                return (value_ * (1000 * 86400)) / 1e2;

            case VolumeFlowUnit::KilolitersPerDay:
                return (value_ * (1000 * 86400)) / 1e3;

            case VolumeFlowUnit::MegalitersPerDay:
                return (value_ * (1000 * 86400)) / 1e6;

            case VolumeFlowUnit::UsGallonsPerSecond:
                return value_ / 0.003785411784;

            case VolumeFlowUnit::UsGallonsPerMinute:
                return value_ / (0.003785411784 / 60);

            case VolumeFlowUnit::UkGallonsPerDay:
                return value_ / (0.00454609 / 86400);

            case VolumeFlowUnit::MegaukGallonsPerDay:
                return (value_ / (0.00454609 / 86400)) / 1e6;

            case VolumeFlowUnit::UkGallonsPerHour:
                return value_ / (0.00454609 / 3600);

            case VolumeFlowUnit::UkGallonsPerMinute:
                return value_ / (0.00454609 / 60);

            case VolumeFlowUnit::UkGallonsPerSecond:
                return value_ / 0.00454609;

            case VolumeFlowUnit::MegaukGallonsPerSecond:
                return (value_ / 0.00454609) / 1e6;

            case VolumeFlowUnit::KilousGallonsPerMinute:
                return value_ / (1000 * 0.003785411784 / 60);

            case VolumeFlowUnit::UsGallonsPerHour:
                return value_ / (0.003785411784 / 3600);

            case VolumeFlowUnit::CubicDecimetersPerMinute:
                return value_ * 60000.00000;

            case VolumeFlowUnit::OilBarrelsPerDay:
                return value_ / (0.158987294928 / 86400);

            case VolumeFlowUnit::OilBarrelsPerMinute:
                return value_ / (0.158987294928 / 60);

            case VolumeFlowUnit::OilBarrelsPerHour:
                return value_ / (0.158987294928 / 3600);

            case VolumeFlowUnit::OilBarrelsPerSecond:
                return value_ / 0.158987294928;

            case VolumeFlowUnit::CubicMillimetersPerSecond:
                return value_ / 1e-9;

            case VolumeFlowUnit::AcreFeetPerSecond:
                return value_ / 1233.48183754752;

            case VolumeFlowUnit::AcreFeetPerMinute:
                return value_ / (1233.48183754752 / 60);

            case VolumeFlowUnit::AcreFeetPerHour:
                return value_ / (1233.48183754752 / 3600);

            case VolumeFlowUnit::AcreFeetPerDay:
                return value_ / (1233.48183754752 / 86400);

            case VolumeFlowUnit::CubicCentimetersPerMinute:
                return value_ / (1e-6 / 60);

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        double value_;
    };
}
