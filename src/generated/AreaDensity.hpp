#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AreaDensityUnit : std::uint16_t
    {
        KilogramsPerSquareMeter,
        GramsPerSquareMeter,
        MilligramsPerSquareMeter,
        PoundsPerSquareFoot,
        PoundsPerThousandSquareFeet,
    };

    /// <summary>The area density of a two-dimensional object is calculated as the mass per unit area. For paper this is also called grammage.</summary>
    class AreaDensity
    {
    public:
        constexpr explicit AreaDensity(
            double value,
            AreaDensityUnit unit = AreaDensityUnit::KilogramsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AreaDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AreaDensity operator+(AreaDensity other) const noexcept
        {
            return AreaDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr AreaDensity operator-(AreaDensity other) const noexcept
        {
            return AreaDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr AreaDensity operator*(double scalar) const noexcept
        {
            return AreaDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr AreaDensity operator/(double scalar) const noexcept
        {
            return AreaDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(AreaDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(AreaDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double kilograms_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::KilogramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_kilograms_per_square_meter(double value)
        {
            return AreaDensity(value, AreaDensityUnit::KilogramsPerSquareMeter);
        }


        [[nodiscard]] constexpr double grams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::GramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_grams_per_square_meter(double value)
        {
            return AreaDensity(value, AreaDensityUnit::GramsPerSquareMeter);
        }


        [[nodiscard]] constexpr double milligrams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::MilligramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_milligrams_per_square_meter(double value)
        {
            return AreaDensity(value, AreaDensityUnit::MilligramsPerSquareMeter);
        }


        [[nodiscard]] constexpr double pounds_per_square_foot() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerSquareFoot);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_square_foot(double value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerSquareFoot);
        }


        [[nodiscard]] constexpr double pounds_per_thousand_square_feet() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerThousandSquareFeet);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_thousand_square_feet(double value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerThousandSquareFeet);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AreaDensityUnit unit)
        {
            switch (unit)
            {

            case AreaDensityUnit::KilogramsPerSquareMeter:
                return value;

            case AreaDensityUnit::GramsPerSquareMeter:
                return value / 1000;

            case AreaDensityUnit::MilligramsPerSquareMeter:
                return value / 1000000;

            case AreaDensityUnit::PoundsPerSquareFoot:
                return value * (0.45359237 / 0.09290304);

            case AreaDensityUnit::PoundsPerThousandSquareFeet:
                return value * (0.45359237 / 0.09290304) / 1000;

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AreaDensityUnit unit) const
        {
            switch (unit)
            {

            case AreaDensityUnit::KilogramsPerSquareMeter:
                return value_;

            case AreaDensityUnit::GramsPerSquareMeter:
                return value_ * 1000;

            case AreaDensityUnit::MilligramsPerSquareMeter:
                return value_ * 1000000;

            case AreaDensityUnit::PoundsPerSquareFoot:
                return value_ / (0.45359237 / 0.09290304);

            case AreaDensityUnit::PoundsPerThousandSquareFeet:
                return value_ / (0.45359237 / 0.09290304) * 1000;

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        double value_;
    };
}
