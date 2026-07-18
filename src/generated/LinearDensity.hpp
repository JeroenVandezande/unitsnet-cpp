#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LinearDensityUnit : std::uint16_t
    {
        GramsPerMillimeter,
        MicrogramsPerMillimeter,
        MilligramsPerMillimeter,
        KilogramsPerMillimeter,
        GramsPerCentimeter,
        MicrogramsPerCentimeter,
        MilligramsPerCentimeter,
        KilogramsPerCentimeter,
        GramsPerMeter,
        MicrogramsPerMeter,
        MilligramsPerMeter,
        KilogramsPerMeter,
        PoundsPerInch,
        PoundsPerFoot,
        GramsPerFoot,
        MicrogramsPerFoot,
        MilligramsPerFoot,
        KilogramsPerFoot,
    };

    /// <summary>The Linear Density, or more precisely, the linear mass density, of a substance is its mass per unit length.  The term linear density is most often used when describing the characteristics of one-dimensional objects, although linear density can also be used to describe the density of a three-dimensional quantity along one particular dimension.</summary>
    class LinearDensity
    {
    public:
        constexpr explicit LinearDensity(
            double value,
            LinearDensityUnit unit = LinearDensityUnit::KilogramsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LinearDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LinearDensity operator+(LinearDensity other) const noexcept
        {
            return LinearDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr LinearDensity operator-(LinearDensity other) const noexcept
        {
            return LinearDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr LinearDensity operator*(double scalar) const noexcept
        {
            return LinearDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr LinearDensity operator/(double scalar) const noexcept
        {
            return LinearDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(LinearDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(LinearDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_millimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerMillimeter);
        }


        [[nodiscard]] constexpr double micrograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_millimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerMillimeter);
        }


        [[nodiscard]] constexpr double milligrams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_millimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerMillimeter);
        }


        [[nodiscard]] constexpr double kilograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_millimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerMillimeter);
        }


        [[nodiscard]] constexpr double grams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_centimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerCentimeter);
        }


        [[nodiscard]] constexpr double micrograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_centimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerCentimeter);
        }


        [[nodiscard]] constexpr double milligrams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_centimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerCentimeter);
        }


        [[nodiscard]] constexpr double kilograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_centimeter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerCentimeter);
        }


        [[nodiscard]] constexpr double grams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_meter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerMeter);
        }


        [[nodiscard]] constexpr double micrograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_meter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerMeter);
        }


        [[nodiscard]] constexpr double milligrams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_meter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerMeter);
        }


        [[nodiscard]] constexpr double kilograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_meter(double value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerMeter);
        }


        [[nodiscard]] constexpr double pounds_per_inch() const
        {
            return convert_from_base(LinearDensityUnit::PoundsPerInch);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_inch(double value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundsPerInch);
        }


        [[nodiscard]] constexpr double pounds_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::PoundsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_foot(double value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundsPerFoot);
        }


        [[nodiscard]] constexpr double grams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_foot(double value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerFoot);
        }


        [[nodiscard]] constexpr double micrograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_foot(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerFoot);
        }


        [[nodiscard]] constexpr double milligrams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_foot(double value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerFoot);
        }


        [[nodiscard]] constexpr double kilograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_foot(double value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LinearDensityUnit unit)
        {
            switch (unit)
            {

            case LinearDensityUnit::GramsPerMillimeter:
                return value;

            case LinearDensityUnit::MicrogramsPerMillimeter:
                return (value * 1e-6);

            case LinearDensityUnit::MilligramsPerMillimeter:
                return (value * 1e-3);

            case LinearDensityUnit::KilogramsPerMillimeter:
                return (value * 1e3);

            case LinearDensityUnit::GramsPerCentimeter:
                return value * 1e-1;

            case LinearDensityUnit::MicrogramsPerCentimeter:
                return (value * 1e-6) * 1e-1;

            case LinearDensityUnit::MilligramsPerCentimeter:
                return (value * 1e-3) * 1e-1;

            case LinearDensityUnit::KilogramsPerCentimeter:
                return (value * 1e3) * 1e-1;

            case LinearDensityUnit::GramsPerMeter:
                return value * 1e-3;

            case LinearDensityUnit::MicrogramsPerMeter:
                return (value * 1e-6) * 1e-3;

            case LinearDensityUnit::MilligramsPerMeter:
                return (value * 1e-3) * 1e-3;

            case LinearDensityUnit::KilogramsPerMeter:
                return (value * 1e3) * 1e-3;

            case LinearDensityUnit::PoundsPerInch:
                return value * 0.45359237 / 2.54e-2;

            case LinearDensityUnit::PoundsPerFoot:
                return value * 0.45359237 / 0.3048;

            case LinearDensityUnit::GramsPerFoot:
                return value * ( 1e-3 / 0.3048 );

            case LinearDensityUnit::MicrogramsPerFoot:
                return (value * 1e-6) * ( 1e-3 / 0.3048 );

            case LinearDensityUnit::MilligramsPerFoot:
                return (value * 1e-3) * ( 1e-3 / 0.3048 );

            case LinearDensityUnit::KilogramsPerFoot:
                return (value * 1e3) * ( 1e-3 / 0.3048 );

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LinearDensityUnit unit) const
        {
            switch (unit)
            {

            case LinearDensityUnit::GramsPerMillimeter:
                return value_;

            case LinearDensityUnit::MicrogramsPerMillimeter:
                return (value_) / 1e-6;

            case LinearDensityUnit::MilligramsPerMillimeter:
                return (value_) / 1e-3;

            case LinearDensityUnit::KilogramsPerMillimeter:
                return (value_) / 1e3;

            case LinearDensityUnit::GramsPerCentimeter:
                return value_ / 1e-1;

            case LinearDensityUnit::MicrogramsPerCentimeter:
                return (value_ / 1e-1) / 1e-6;

            case LinearDensityUnit::MilligramsPerCentimeter:
                return (value_ / 1e-1) / 1e-3;

            case LinearDensityUnit::KilogramsPerCentimeter:
                return (value_ / 1e-1) / 1e3;

            case LinearDensityUnit::GramsPerMeter:
                return value_ / 1e-3;

            case LinearDensityUnit::MicrogramsPerMeter:
                return (value_ / 1e-3) / 1e-6;

            case LinearDensityUnit::MilligramsPerMeter:
                return (value_ / 1e-3) / 1e-3;

            case LinearDensityUnit::KilogramsPerMeter:
                return (value_ / 1e-3) / 1e3;

            case LinearDensityUnit::PoundsPerInch:
                return value_ * 2.54e-2 / 0.45359237;

            case LinearDensityUnit::PoundsPerFoot:
                return value_ * 0.3048 / 0.45359237;

            case LinearDensityUnit::GramsPerFoot:
                return value_ / ( 1e-3 / 0.3048 );

            case LinearDensityUnit::MicrogramsPerFoot:
                return (value_ / ( 1e-3 / 0.3048 )) / 1e-6;

            case LinearDensityUnit::MilligramsPerFoot:
                return (value_ / ( 1e-3 / 0.3048 )) / 1e-3;

            case LinearDensityUnit::KilogramsPerFoot:
                return (value_ / ( 1e-3 / 0.3048 )) / 1e3;

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        double value_;
    };
}
