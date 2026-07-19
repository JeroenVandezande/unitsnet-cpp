#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class AreaDensityUnit : std::uint8_t
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
            const un_scalar_t value,
            const AreaDensityUnit unit = AreaDensityUnit::KilogramsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AreaDensity operator+(const AreaDensity other) const noexcept
        {
            return AreaDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr AreaDensity operator-(const AreaDensity other) const noexcept
        {
            return AreaDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr AreaDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr AreaDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AreaDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const AreaDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::KilogramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_kilograms_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::KilogramsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::GramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_grams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::GramsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::MilligramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_milligrams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::MilligramsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_square_foot() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerSquareFoot);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_square_foot(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_thousand_square_feet() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerThousandSquareFeet);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_thousand_square_feet(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerThousandSquareFeet);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaDensityUnit unit)
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

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaDensityUnit unit) const
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

        un_scalar_t value_;
    };
}
