#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LinearDensityUnit : std::uint8_t
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
            const un_scalar_t value,
            const LinearDensityUnit unit = LinearDensityUnit::KilogramsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const LinearDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LinearDensity operator+(const LinearDensity other) const noexcept
        {
            return LinearDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr LinearDensity operator-(const LinearDensity other) const noexcept
        {
            return LinearDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr LinearDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LinearDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr LinearDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LinearDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LinearDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const LinearDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_inch() const
        {
            return convert_from_base(LinearDensityUnit::PoundsPerInch);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_inch(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundsPerInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::PoundsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundsPerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::GramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramsPerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramsPerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MilligramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramsPerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::KilogramsPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramsPerFoot);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LinearDensityUnit unit)
        {
            switch (unit)
            {

            case LinearDensityUnit::GramsPerMillimeter:
                return value;

            case LinearDensityUnit::MicrogramsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LinearDensityUnit::MilligramsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LinearDensityUnit::KilogramsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LinearDensityUnit::GramsPerCentimeter:
                return value * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MicrogramsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MilligramsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::KilogramsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::GramsPerMeter:
                return value * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MicrogramsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MilligramsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramsPerMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::PoundsPerInch:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(2.54e-2);

            case LinearDensityUnit::PoundsPerFoot:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.3048);

            case LinearDensityUnit::GramsPerFoot:
                return value * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MicrogramsPerFoot:
                return (value * static_cast<un_scalar_t>(1e-6)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MilligramsPerFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::KilogramsPerFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LinearDensityUnit unit) const
        {
            switch (unit)
            {

            case LinearDensityUnit::GramsPerMillimeter:
                return value_;

            case LinearDensityUnit::MicrogramsPerMillimeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramsPerMillimeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramsPerMillimeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::GramsPerCentimeter:
                return value_ / static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MicrogramsPerCentimeter:
                return (value_ / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramsPerCentimeter:
                return (value_ / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramsPerCentimeter:
                return (value_ / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::GramsPerMeter:
                return value_ / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MicrogramsPerMeter:
                return (value_ / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramsPerMeter:
                return (value_ / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramsPerMeter:
                return (value_ / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::PoundsPerInch:
                return value_ * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(0.45359237);

            case LinearDensityUnit::PoundsPerFoot:
                return value_ * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.45359237);

            case LinearDensityUnit::GramsPerFoot:
                return value_ / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MicrogramsPerFoot:
                return (value_ / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramsPerFoot:
                return (value_ / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramsPerFoot:
                return (value_ / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        un_scalar_t value_;
    };
}
