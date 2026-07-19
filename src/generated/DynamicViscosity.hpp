#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class DynamicViscosityUnit : std::uint8_t
    {
        NewtonSecondsPerMeterSquared,
        PascalSeconds,
        MillipascalSeconds,
        MicropascalSeconds,
        Poise,
        Centipoise,
        Reyns,
        PoundsForceSecondPerSquareInch,
        PoundsForceSecondPerSquareFoot,
        PoundsPerFootSecond,
    };

    /// <summary>The dynamic (shear) viscosity of a fluid expresses its resistance to shearing flows, where adjacent layers move parallel to each other with different speeds</summary>
    class DynamicViscosity
    {
    public:
        constexpr explicit DynamicViscosity(
            const un_scalar_t value,
            const DynamicViscosityUnit unit = DynamicViscosityUnit::NewtonSecondsPerMeterSquared)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const DynamicViscosityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr DynamicViscosity operator+(const DynamicViscosity other) const noexcept
        {
            return DynamicViscosity(value_ + other.value_);
        }

        [[nodiscard]] constexpr DynamicViscosity operator-(const DynamicViscosity other) const noexcept
        {
            return DynamicViscosity(value_ - other.value_);
        }

        [[nodiscard]] constexpr DynamicViscosity operator*(const un_scalar_t scalar) const noexcept
        {
            return DynamicViscosity(value_ * scalar);
        }

        [[nodiscard]] constexpr DynamicViscosity operator/(const un_scalar_t scalar) const noexcept
        {
            return DynamicViscosity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const DynamicViscosity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const DynamicViscosity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t newton_seconds_per_meter_squared() const
        {
            return convert_from_base(DynamicViscosityUnit::NewtonSecondsPerMeterSquared);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_newton_seconds_per_meter_squared(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::NewtonSecondsPerMeterSquared);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::PascalSeconds);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PascalSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t millipascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::MillipascalSeconds);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_millipascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::MillipascalSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t micropascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::MicropascalSeconds);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_micropascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::MicropascalSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t poise() const
        {
            return convert_from_base(DynamicViscosityUnit::Poise);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_poise(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Poise);
        }


        [[nodiscard]] constexpr un_scalar_t centipoise() const
        {
            return convert_from_base(DynamicViscosityUnit::Centipoise);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_centipoise(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Centipoise);
        }


        [[nodiscard]] constexpr un_scalar_t reyns() const
        {
            return convert_from_base(DynamicViscosityUnit::Reyns);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_reyns(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Reyns);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_second_per_square_inch() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundsForceSecondPerSquareInch);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_force_second_per_square_inch(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundsForceSecondPerSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_second_per_square_foot() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundsForceSecondPerSquareFoot);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_force_second_per_square_foot(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundsForceSecondPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_foot_second() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundsPerFootSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_per_foot_second(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundsPerFootSecond);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DynamicViscosityUnit unit)
        {
            switch (unit)
            {

            case DynamicViscosityUnit::NewtonSecondsPerMeterSquared:
                return value;

            case DynamicViscosityUnit::PascalSeconds:
                return value;

            case DynamicViscosityUnit::MillipascalSeconds:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DynamicViscosityUnit::MicropascalSeconds:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DynamicViscosityUnit::Poise:
                return value / 10;

            case DynamicViscosityUnit::Centipoise:
                return (value * static_cast<un_scalar_t>(1e-2)) / 10;

            case DynamicViscosityUnit::Reyns:
                return value * 4.4482216152605 / 0.00064516;

            case DynamicViscosityUnit::PoundsForceSecondPerSquareInch:
                return value * 4.4482216152605 / 0.00064516;

            case DynamicViscosityUnit::PoundsForceSecondPerSquareFoot:
                return value * 4.4482216152605 / 9.290304e-2;

            case DynamicViscosityUnit::PoundsPerFootSecond:
                return value * 0.45359237 / 0.3048;

            }

            throw std::invalid_argument("Unknown DynamicViscosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DynamicViscosityUnit unit) const
        {
            switch (unit)
            {

            case DynamicViscosityUnit::NewtonSecondsPerMeterSquared:
                return value_;

            case DynamicViscosityUnit::PascalSeconds:
                return value_;

            case DynamicViscosityUnit::MillipascalSeconds:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case DynamicViscosityUnit::MicropascalSeconds:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case DynamicViscosityUnit::Poise:
                return value_ * 10;

            case DynamicViscosityUnit::Centipoise:
                return (value_ * 10) / static_cast<un_scalar_t>(1e-2);

            case DynamicViscosityUnit::Reyns:
                return value_ * 0.00064516 / 4.4482216152605;

            case DynamicViscosityUnit::PoundsForceSecondPerSquareInch:
                return value_ * 0.00064516 / 4.4482216152605;

            case DynamicViscosityUnit::PoundsForceSecondPerSquareFoot:
                return value_ * 9.290304e-2 / 4.4482216152605;

            case DynamicViscosityUnit::PoundsPerFootSecond:
                return value_ * 0.3048 / 0.45359237;

            }

            throw std::invalid_argument("Unknown DynamicViscosity unit.");
        }

        un_scalar_t value_;
    };
}
