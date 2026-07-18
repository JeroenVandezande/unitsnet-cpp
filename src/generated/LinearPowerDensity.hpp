#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LinearPowerDensityUnit : std::uint16_t
    {
        WattsPerMeter,
        MilliwattsPerMeter,
        KilowattsPerMeter,
        MegawattsPerMeter,
        GigawattsPerMeter,
        WattsPerCentimeter,
        MilliwattsPerCentimeter,
        KilowattsPerCentimeter,
        MegawattsPerCentimeter,
        GigawattsPerCentimeter,
        WattsPerMillimeter,
        MilliwattsPerMillimeter,
        KilowattsPerMillimeter,
        MegawattsPerMillimeter,
        GigawattsPerMillimeter,
        WattsPerInch,
        MilliwattsPerInch,
        KilowattsPerInch,
        MegawattsPerInch,
        GigawattsPerInch,
        WattsPerFoot,
        MilliwattsPerFoot,
        KilowattsPerFoot,
        MegawattsPerFoot,
        GigawattsPerFoot,
    };

    /// <summary>The Linear Power Density of a substance is its power per unit length.  The term linear density is most often used when describing the characteristics of one-dimensional objects, although linear density can also be used to describe the density of a three-dimensional quantity along one particular dimension.</summary>
    class LinearPowerDensity
    {
    public:
        constexpr explicit LinearPowerDensity(
            double value,
            LinearPowerDensityUnit unit = LinearPowerDensityUnit::WattsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LinearPowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator+(LinearPowerDensity other) const noexcept
        {
            return LinearPowerDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator-(LinearPowerDensity other) const noexcept
        {
            return LinearPowerDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator*(double scalar) const noexcept
        {
            return LinearPowerDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator/(double scalar) const noexcept
        {
            return LinearPowerDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(LinearPowerDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(LinearPowerDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_meter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerMeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_meter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerMeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_meter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerMeter);
        }


        [[nodiscard]] constexpr double megawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_meter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerMeter);
        }


        [[nodiscard]] constexpr double gigawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_meter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerMeter);
        }


        [[nodiscard]] constexpr double watts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_centimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerCentimeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_centimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerCentimeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_centimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerCentimeter);
        }


        [[nodiscard]] constexpr double megawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_centimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerCentimeter);
        }


        [[nodiscard]] constexpr double gigawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_centimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerCentimeter);
        }


        [[nodiscard]] constexpr double watts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_millimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerMillimeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_millimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerMillimeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_millimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerMillimeter);
        }


        [[nodiscard]] constexpr double megawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_millimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerMillimeter);
        }


        [[nodiscard]] constexpr double gigawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_millimeter(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerMillimeter);
        }


        [[nodiscard]] constexpr double watts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_inch(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerInch);
        }


        [[nodiscard]] constexpr double milliwatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_inch(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerInch);
        }


        [[nodiscard]] constexpr double kilowatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_inch(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerInch);
        }


        [[nodiscard]] constexpr double megawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_inch(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerInch);
        }


        [[nodiscard]] constexpr double gigawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_inch(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerInch);
        }


        [[nodiscard]] constexpr double watts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_foot(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerFoot);
        }


        [[nodiscard]] constexpr double milliwatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_foot(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerFoot);
        }


        [[nodiscard]] constexpr double kilowatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_foot(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerFoot);
        }


        [[nodiscard]] constexpr double megawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_foot(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerFoot);
        }


        [[nodiscard]] constexpr double gigawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_foot(double value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LinearPowerDensityUnit unit)
        {
            switch (unit)
            {

            case LinearPowerDensityUnit::WattsPerMeter:
                return value;

            case LinearPowerDensityUnit::MilliwattsPerMeter:
                return (value * 1e-3);

            case LinearPowerDensityUnit::KilowattsPerMeter:
                return (value * 1e3);

            case LinearPowerDensityUnit::MegawattsPerMeter:
                return (value * 1e6);

            case LinearPowerDensityUnit::GigawattsPerMeter:
                return (value * 1e9);

            case LinearPowerDensityUnit::WattsPerCentimeter:
                return value * 1e2;

            case LinearPowerDensityUnit::MilliwattsPerCentimeter:
                return (value * 1e-3) * 1e2;

            case LinearPowerDensityUnit::KilowattsPerCentimeter:
                return (value * 1e3) * 1e2;

            case LinearPowerDensityUnit::MegawattsPerCentimeter:
                return (value * 1e6) * 1e2;

            case LinearPowerDensityUnit::GigawattsPerCentimeter:
                return (value * 1e9) * 1e2;

            case LinearPowerDensityUnit::WattsPerMillimeter:
                return value * 1e3;

            case LinearPowerDensityUnit::MilliwattsPerMillimeter:
                return (value * 1e-3) * 1e3;

            case LinearPowerDensityUnit::KilowattsPerMillimeter:
                return (value * 1e3) * 1e3;

            case LinearPowerDensityUnit::MegawattsPerMillimeter:
                return (value * 1e6) * 1e3;

            case LinearPowerDensityUnit::GigawattsPerMillimeter:
                return (value * 1e9) * 1e3;

            case LinearPowerDensityUnit::WattsPerInch:
                return value / 2.54e-2;

            case LinearPowerDensityUnit::MilliwattsPerInch:
                return (value * 1e-3) / 2.54e-2;

            case LinearPowerDensityUnit::KilowattsPerInch:
                return (value * 1e3) / 2.54e-2;

            case LinearPowerDensityUnit::MegawattsPerInch:
                return (value * 1e6) / 2.54e-2;

            case LinearPowerDensityUnit::GigawattsPerInch:
                return (value * 1e9) / 2.54e-2;

            case LinearPowerDensityUnit::WattsPerFoot:
                return value / 0.3048;

            case LinearPowerDensityUnit::MilliwattsPerFoot:
                return (value * 1e-3) / 0.3048;

            case LinearPowerDensityUnit::KilowattsPerFoot:
                return (value * 1e3) / 0.3048;

            case LinearPowerDensityUnit::MegawattsPerFoot:
                return (value * 1e6) / 0.3048;

            case LinearPowerDensityUnit::GigawattsPerFoot:
                return (value * 1e9) / 0.3048;

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LinearPowerDensityUnit unit) const
        {
            switch (unit)
            {

            case LinearPowerDensityUnit::WattsPerMeter:
                return value_;

            case LinearPowerDensityUnit::MilliwattsPerMeter:
                return (value_) / 1e-3;

            case LinearPowerDensityUnit::KilowattsPerMeter:
                return (value_) / 1e3;

            case LinearPowerDensityUnit::MegawattsPerMeter:
                return (value_) / 1e6;

            case LinearPowerDensityUnit::GigawattsPerMeter:
                return (value_) / 1e9;

            case LinearPowerDensityUnit::WattsPerCentimeter:
                return value_ / 1e2;

            case LinearPowerDensityUnit::MilliwattsPerCentimeter:
                return (value_ / 1e2) / 1e-3;

            case LinearPowerDensityUnit::KilowattsPerCentimeter:
                return (value_ / 1e2) / 1e3;

            case LinearPowerDensityUnit::MegawattsPerCentimeter:
                return (value_ / 1e2) / 1e6;

            case LinearPowerDensityUnit::GigawattsPerCentimeter:
                return (value_ / 1e2) / 1e9;

            case LinearPowerDensityUnit::WattsPerMillimeter:
                return value_ / 1e3;

            case LinearPowerDensityUnit::MilliwattsPerMillimeter:
                return (value_ / 1e3) / 1e-3;

            case LinearPowerDensityUnit::KilowattsPerMillimeter:
                return (value_ / 1e3) / 1e3;

            case LinearPowerDensityUnit::MegawattsPerMillimeter:
                return (value_ / 1e3) / 1e6;

            case LinearPowerDensityUnit::GigawattsPerMillimeter:
                return (value_ / 1e3) / 1e9;

            case LinearPowerDensityUnit::WattsPerInch:
                return value_ * 2.54e-2;

            case LinearPowerDensityUnit::MilliwattsPerInch:
                return (value_ * 2.54e-2) / 1e-3;

            case LinearPowerDensityUnit::KilowattsPerInch:
                return (value_ * 2.54e-2) / 1e3;

            case LinearPowerDensityUnit::MegawattsPerInch:
                return (value_ * 2.54e-2) / 1e6;

            case LinearPowerDensityUnit::GigawattsPerInch:
                return (value_ * 2.54e-2) / 1e9;

            case LinearPowerDensityUnit::WattsPerFoot:
                return value_ * 0.3048;

            case LinearPowerDensityUnit::MilliwattsPerFoot:
                return (value_ * 0.3048) / 1e-3;

            case LinearPowerDensityUnit::KilowattsPerFoot:
                return (value_ * 0.3048) / 1e3;

            case LinearPowerDensityUnit::MegawattsPerFoot:
                return (value_ * 0.3048) / 1e6;

            case LinearPowerDensityUnit::GigawattsPerFoot:
                return (value_ * 0.3048) / 1e9;

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        double value_;
    };
}
