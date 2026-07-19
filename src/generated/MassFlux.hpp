#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MassFluxUnit : std::uint8_t
    {
        GramsPerSecondPerSquareMeter,
        KilogramsPerSecondPerSquareMeter,
        GramsPerSecondPerSquareCentimeter,
        KilogramsPerSecondPerSquareCentimeter,
        GramsPerSecondPerSquareMillimeter,
        KilogramsPerSecondPerSquareMillimeter,
        GramsPerHourPerSquareMeter,
        KilogramsPerHourPerSquareMeter,
        GramsPerHourPerSquareCentimeter,
        KilogramsPerHourPerSquareCentimeter,
        GramsPerHourPerSquareMillimeter,
        KilogramsPerHourPerSquareMillimeter,
    };

    /// <summary>Mass flux is the mass flow rate per unit area.</summary>
    class MassFlux
    {
    public:
        constexpr explicit MassFlux(
            const un_scalar_t value,
            const MassFluxUnit unit = MassFluxUnit::KilogramsPerSecondPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassFlux operator+(const MassFlux other) const noexcept
        {
            return MassFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr MassFlux operator-(const MassFlux other) const noexcept
        {
            return MassFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr MassFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr MassFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MassFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerSecondPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerSecondPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerSecondPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerSecondPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerSecondPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerSecondPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerHourPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerHourPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerHourPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerHourPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerHourPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerHourPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::GramsPerHourPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramsPerHourPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramsPerHourPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramsPerHourPerSquareMillimeter);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFluxUnit unit)
        {
            switch (unit)
            {

            case MassFluxUnit::GramsPerSecondPerSquareMeter:
                return value / 1e3;

            case MassFluxUnit::KilogramsPerSecondPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e3;

            case MassFluxUnit::GramsPerSecondPerSquareCentimeter:
                return value / 1e-1;

            case MassFluxUnit::KilogramsPerSecondPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e-1;

            case MassFluxUnit::GramsPerSecondPerSquareMillimeter:
                return value / 1e-3;

            case MassFluxUnit::KilogramsPerSecondPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e-3;

            case MassFluxUnit::GramsPerHourPerSquareMeter:
                return value / 3.6e6;

            case MassFluxUnit::KilogramsPerHourPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 3.6e6;

            case MassFluxUnit::GramsPerHourPerSquareCentimeter:
                return value / 3.6e2;

            case MassFluxUnit::KilogramsPerHourPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 3.6e2;

            case MassFluxUnit::GramsPerHourPerSquareMillimeter:
                return value / 3.6e0;

            case MassFluxUnit::KilogramsPerHourPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 3.6e0;

            }

            throw std::invalid_argument("Unknown MassFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFluxUnit unit) const
        {
            switch (unit)
            {

            case MassFluxUnit::GramsPerSecondPerSquareMeter:
                return value_ * 1e3;

            case MassFluxUnit::KilogramsPerSecondPerSquareMeter:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramsPerSecondPerSquareCentimeter:
                return value_ * 1e-1;

            case MassFluxUnit::KilogramsPerSecondPerSquareCentimeter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramsPerSecondPerSquareMillimeter:
                return value_ * 1e-3;

            case MassFluxUnit::KilogramsPerSecondPerSquareMillimeter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramsPerHourPerSquareMeter:
                return value_ * 3.6e6;

            case MassFluxUnit::KilogramsPerHourPerSquareMeter:
                return (value_ * 3.6e6) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramsPerHourPerSquareCentimeter:
                return value_ * 3.6e2;

            case MassFluxUnit::KilogramsPerHourPerSquareCentimeter:
                return (value_ * 3.6e2) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramsPerHourPerSquareMillimeter:
                return value_ * 3.6e0;

            case MassFluxUnit::KilogramsPerHourPerSquareMillimeter:
                return (value_ * 3.6e0) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown MassFlux unit.");
        }

        un_scalar_t value_;
    };
}
