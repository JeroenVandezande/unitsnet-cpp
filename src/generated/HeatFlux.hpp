#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class HeatFluxUnit : std::uint8_t
    {
        WattsPerSquareMeter,
        NanowattsPerSquareMeter,
        MicrowattsPerSquareMeter,
        MilliwattsPerSquareMeter,
        CentiwattsPerSquareMeter,
        DeciwattsPerSquareMeter,
        KilowattsPerSquareMeter,
        WattsPerSquareMillimeter,
        NanowattsPerSquareMillimeter,
        MicrowattsPerSquareMillimeter,
        MilliwattsPerSquareMillimeter,
        CentiwattsPerSquareMillimeter,
        DeciwattsPerSquareMillimeter,
        KilowattsPerSquareMillimeter,
        WattsPerSquareInch,
        WattsPerSquareFoot,
        BtusPerSecondSquareInch,
        BtusPerSecondSquareFoot,
        BtusPerMinuteSquareFoot,
        BtusPerHourSquareFoot,
        CaloriesPerSecondSquareCentimeter,
        KilocaloriesPerSecondSquareCentimeter,
        KilocaloriesPerHourSquareMeter,
        PoundsForcePerFootSecond,
        PoundsPerSecondCubed,
    };

    /// <summary>Heat flux is the flow of energy per unit of area per unit of time</summary>
    class HeatFlux
    {
    public:
        constexpr explicit HeatFlux(
            const un_scalar_t value,
            const HeatFluxUnit unit = HeatFluxUnit::WattsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const HeatFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr HeatFlux operator+(const HeatFlux other) const noexcept
        {
            return HeatFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr HeatFlux operator-(const HeatFlux other) const noexcept
        {
            return HeatFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr HeatFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return HeatFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr HeatFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return HeatFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const HeatFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const HeatFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t centiwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t centiwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_inch(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerSecondSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_inch(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerSecondSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerSecondSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerSecondSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_minute_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerMinuteSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_minute_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerMinuteSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_hour_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerHourSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_hour_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerHourSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t calories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::CaloriesPerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_calories_per_second_square_centimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CaloriesPerSecondSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_second_square_centimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories_per_hour_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriesPerHourSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_hour_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriesPerHourSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_foot_second() const
        {
            return convert_from_base(HeatFluxUnit::PoundsForcePerFootSecond);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_force_per_foot_second(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundsForcePerFootSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_second_cubed() const
        {
            return convert_from_base(HeatFluxUnit::PoundsPerSecondCubed);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_per_second_cubed(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundsPerSecondCubed);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, HeatFluxUnit unit)
        {
            switch (unit)
            {

            case HeatFluxUnit::WattsPerSquareMeter:
                return value;

            case HeatFluxUnit::NanowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case HeatFluxUnit::MicrowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case HeatFluxUnit::MilliwattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case HeatFluxUnit::CentiwattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case HeatFluxUnit::DeciwattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case HeatFluxUnit::KilowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case HeatFluxUnit::WattsPerSquareMillimeter:
                return value / 1e-6;

            case HeatFluxUnit::NanowattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1e-6;

            case HeatFluxUnit::MicrowattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e-6;

            case HeatFluxUnit::MilliwattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e-6;

            case HeatFluxUnit::CentiwattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1e-6;

            case HeatFluxUnit::DeciwattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1e-6;

            case HeatFluxUnit::KilowattsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e-6;

            case HeatFluxUnit::WattsPerSquareInch:
                return value / (2.54e-2 * 2.54e-2);

            case HeatFluxUnit::WattsPerSquareFoot:
                return value / (0.3048 * 0.3048);

            case HeatFluxUnit::BtusPerSecondSquareInch:
                return value * 1055.05585262 / (2.54e-2 * 2.54e-2);

            case HeatFluxUnit::BtusPerSecondSquareFoot:
                return value * 1055.05585262 / (0.3048 * 0.3048);

            case HeatFluxUnit::BtusPerMinuteSquareFoot:
                return value * 1055.05585262 / (0.3048 * 0.3048 * 60);

            case HeatFluxUnit::BtusPerHourSquareFoot:
                return value * 1055.05585262 / (0.3048 * 0.3048 * 3600);

            case HeatFluxUnit::CaloriesPerSecondSquareCentimeter:
                return value * 4.184e4;

            case HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * 4.184e4;

            case HeatFluxUnit::KilocaloriesPerHourSquareMeter:
                return value * 4.184e3 / 3600;

            case HeatFluxUnit::PoundsForcePerFootSecond:
                return value * 1.3558179483314004 / 9.290304e-2;

            case HeatFluxUnit::PoundsPerSecondCubed:
                return value * 4.5359237e-1;

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const HeatFluxUnit unit) const
        {
            switch (unit)
            {

            case HeatFluxUnit::WattsPerSquareMeter:
                return value_;

            case HeatFluxUnit::NanowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case HeatFluxUnit::MicrowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MilliwattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case HeatFluxUnit::CentiwattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case HeatFluxUnit::DeciwattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case HeatFluxUnit::KilowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::WattsPerSquareMillimeter:
                return value_ * 1e-6;

            case HeatFluxUnit::NanowattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e-9);

            case HeatFluxUnit::MicrowattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MilliwattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e-3);

            case HeatFluxUnit::CentiwattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e-2);

            case HeatFluxUnit::DeciwattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e-1);

            case HeatFluxUnit::KilowattsPerSquareMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::WattsPerSquareInch:
                return value_ * (2.54e-2 * 2.54e-2);

            case HeatFluxUnit::WattsPerSquareFoot:
                return value_ * (0.3048 * 0.3048);

            case HeatFluxUnit::BtusPerSecondSquareInch:
                return value_ * (2.54e-2 * 2.54e-2) / 1055.05585262;

            case HeatFluxUnit::BtusPerSecondSquareFoot:
                return value_ * (0.3048 * 0.3048) / 1055.05585262;

            case HeatFluxUnit::BtusPerMinuteSquareFoot:
                return value_ * (0.3048 * 0.3048 * 60) / 1055.05585262;

            case HeatFluxUnit::BtusPerHourSquareFoot:
                return value_ * (0.3048 * 0.3048 * 3600) / 1055.05585262;

            case HeatFluxUnit::CaloriesPerSecondSquareCentimeter:
                return value_ / 4.184e4;

            case HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter:
                return (value_ / 4.184e4) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::KilocaloriesPerHourSquareMeter:
                return value_ * 3600 / 4.184e3;

            case HeatFluxUnit::PoundsForcePerFootSecond:
                return value_ * 9.290304e-2 / 1.3558179483314004;

            case HeatFluxUnit::PoundsPerSecondCubed:
                return value_ / 4.5359237e-1;

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        un_scalar_t value_;
    };
}
