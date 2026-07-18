#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class HeatFluxUnit : std::uint16_t
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
            double value,
            HeatFluxUnit unit = HeatFluxUnit::WattsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(HeatFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr HeatFlux operator+(HeatFlux other) const noexcept
        {
            return HeatFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr HeatFlux operator-(HeatFlux other) const noexcept
        {
            return HeatFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr HeatFlux operator*(double scalar) const noexcept
        {
            return HeatFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr HeatFlux operator/(double scalar) const noexcept
        {
            return HeatFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(HeatFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(HeatFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double nanowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double microwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double centiwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double deciwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double watts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double nanowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double microwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double centiwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double deciwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_millimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double watts_per_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_inch(double value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareInch);
        }


        [[nodiscard]] constexpr double watts_per_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::WattsPerSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_foot(double value)
        {
            return HeatFlux(value, HeatFluxUnit::WattsPerSquareFoot);
        }


        [[nodiscard]] constexpr double btus_per_second_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerSecondSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_inch(double value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerSecondSquareInch);
        }


        [[nodiscard]] constexpr double btus_per_second_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerSecondSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_foot(double value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerSecondSquareFoot);
        }


        [[nodiscard]] constexpr double btus_per_minute_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerMinuteSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_minute_square_foot(double value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerMinuteSquareFoot);
        }


        [[nodiscard]] constexpr double btus_per_hour_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtusPerHourSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_hour_square_foot(double value)
        {
            return HeatFlux(value, HeatFluxUnit::BtusPerHourSquareFoot);
        }


        [[nodiscard]] constexpr double calories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::CaloriesPerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_calories_per_second_square_centimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::CaloriesPerSecondSquareCentimeter);
        }


        [[nodiscard]] constexpr double kilocalories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_second_square_centimeter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriesPerSecondSquareCentimeter);
        }


        [[nodiscard]] constexpr double kilocalories_per_hour_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriesPerHourSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_hour_square_meter(double value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriesPerHourSquareMeter);
        }


        [[nodiscard]] constexpr double pounds_force_per_foot_second() const
        {
            return convert_from_base(HeatFluxUnit::PoundsForcePerFootSecond);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_force_per_foot_second(double value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundsForcePerFootSecond);
        }


        [[nodiscard]] constexpr double pounds_per_second_cubed() const
        {
            return convert_from_base(HeatFluxUnit::PoundsPerSecondCubed);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_per_second_cubed(double value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundsPerSecondCubed);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, HeatFluxUnit unit)
        {
            switch (unit)
            {

            case HeatFluxUnit::WattsPerSquareMeter:
                return value;

            case HeatFluxUnit::NanowattsPerSquareMeter:
                return (value * 1e-9);

            case HeatFluxUnit::MicrowattsPerSquareMeter:
                return (value * 1e-6);

            case HeatFluxUnit::MilliwattsPerSquareMeter:
                return (value * 1e-3);

            case HeatFluxUnit::CentiwattsPerSquareMeter:
                return (value * 1e-2);

            case HeatFluxUnit::DeciwattsPerSquareMeter:
                return (value * 1e-1);

            case HeatFluxUnit::KilowattsPerSquareMeter:
                return (value * 1e3);

            case HeatFluxUnit::WattsPerSquareMillimeter:
                return value / 1e-6;

            case HeatFluxUnit::NanowattsPerSquareMillimeter:
                return (value * 1e-9) / 1e-6;

            case HeatFluxUnit::MicrowattsPerSquareMillimeter:
                return (value * 1e-6) / 1e-6;

            case HeatFluxUnit::MilliwattsPerSquareMillimeter:
                return (value * 1e-3) / 1e-6;

            case HeatFluxUnit::CentiwattsPerSquareMillimeter:
                return (value * 1e-2) / 1e-6;

            case HeatFluxUnit::DeciwattsPerSquareMillimeter:
                return (value * 1e-1) / 1e-6;

            case HeatFluxUnit::KilowattsPerSquareMillimeter:
                return (value * 1e3) / 1e-6;

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
                return (value * 1e3) * 4.184e4;

            case HeatFluxUnit::KilocaloriesPerHourSquareMeter:
                return value * 4.184e3 / 3600;

            case HeatFluxUnit::PoundsForcePerFootSecond:
                return value * 1.3558179483314004 / 9.290304e-2;

            case HeatFluxUnit::PoundsPerSecondCubed:
                return value * 4.5359237e-1;

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(HeatFluxUnit unit) const
        {
            switch (unit)
            {

            case HeatFluxUnit::WattsPerSquareMeter:
                return value_;

            case HeatFluxUnit::NanowattsPerSquareMeter:
                return (value_) / 1e-9;

            case HeatFluxUnit::MicrowattsPerSquareMeter:
                return (value_) / 1e-6;

            case HeatFluxUnit::MilliwattsPerSquareMeter:
                return (value_) / 1e-3;

            case HeatFluxUnit::CentiwattsPerSquareMeter:
                return (value_) / 1e-2;

            case HeatFluxUnit::DeciwattsPerSquareMeter:
                return (value_) / 1e-1;

            case HeatFluxUnit::KilowattsPerSquareMeter:
                return (value_) / 1e3;

            case HeatFluxUnit::WattsPerSquareMillimeter:
                return value_ * 1e-6;

            case HeatFluxUnit::NanowattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e-9;

            case HeatFluxUnit::MicrowattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e-6;

            case HeatFluxUnit::MilliwattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e-3;

            case HeatFluxUnit::CentiwattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e-2;

            case HeatFluxUnit::DeciwattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e-1;

            case HeatFluxUnit::KilowattsPerSquareMillimeter:
                return (value_ * 1e-6) / 1e3;

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
                return (value_ / 4.184e4) / 1e3;

            case HeatFluxUnit::KilocaloriesPerHourSquareMeter:
                return value_ * 3600 / 4.184e3;

            case HeatFluxUnit::PoundsForcePerFootSecond:
                return value_ * 9.290304e-2 / 1.3558179483314004;

            case HeatFluxUnit::PoundsPerSecondCubed:
                return value_ / 4.5359237e-1;

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        double value_;
    };
}
