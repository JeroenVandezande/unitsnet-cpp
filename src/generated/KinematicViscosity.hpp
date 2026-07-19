#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class KinematicViscosityUnit : std::uint8_t
    {
        SquareMetersPerSecond,
        Stokes,
        Nanostokes,
        Microstokes,
        Millistokes,
        Centistokes,
        Decistokes,
        Kilostokes,
        SquareFeetPerSecond,
    };

    /// <summary>The viscosity of a fluid is a measure of its resistance to gradual deformation by shear stress or tensile stress.</summary>
    class KinematicViscosity
    {
    public:
        constexpr explicit KinematicViscosity(
            const un_scalar_t value,
            const KinematicViscosityUnit unit = KinematicViscosityUnit::SquareMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const KinematicViscosityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr KinematicViscosity operator+(const KinematicViscosity other) const noexcept
        {
            return KinematicViscosity(value_ + other.value_);
        }

        [[nodiscard]] constexpr KinematicViscosity operator-(const KinematicViscosity other) const noexcept
        {
            return KinematicViscosity(value_ - other.value_);
        }

        [[nodiscard]] constexpr KinematicViscosity operator*(const un_scalar_t scalar) const noexcept
        {
            return KinematicViscosity(value_ * scalar);
        }

        [[nodiscard]] constexpr KinematicViscosity operator/(const un_scalar_t scalar) const noexcept
        {
            return KinematicViscosity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const KinematicViscosity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const KinematicViscosity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t square_meters_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareMetersPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_meters_per_second(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareMetersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t stokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Stokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_stokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Stokes);
        }


        [[nodiscard]] constexpr un_scalar_t nanostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Nanostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_nanostokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Nanostokes);
        }


        [[nodiscard]] constexpr un_scalar_t microstokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Microstokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_microstokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Microstokes);
        }


        [[nodiscard]] constexpr un_scalar_t millistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Millistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_millistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Millistokes);
        }


        [[nodiscard]] constexpr un_scalar_t centistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Centistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_centistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Centistokes);
        }


        [[nodiscard]] constexpr un_scalar_t decistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Decistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_decistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Decistokes);
        }


        [[nodiscard]] constexpr un_scalar_t kilostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Kilostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_kilostokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Kilostokes);
        }


        [[nodiscard]] constexpr un_scalar_t square_feet_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareFeetPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_feet_per_second(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareFeetPerSecond);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, KinematicViscosityUnit unit)
        {
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMetersPerSecond:
                return value;

            case KinematicViscosityUnit::Stokes:
                return value / 1e4;

            case KinematicViscosityUnit::Nanostokes:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1e4;

            case KinematicViscosityUnit::Microstokes:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e4;

            case KinematicViscosityUnit::Millistokes:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e4;

            case KinematicViscosityUnit::Centistokes:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1e4;

            case KinematicViscosityUnit::Decistokes:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1e4;

            case KinematicViscosityUnit::Kilostokes:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e4;

            case KinematicViscosityUnit::SquareFeetPerSecond:
                return value * 9.290304e-2;

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const KinematicViscosityUnit unit) const
        {
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMetersPerSecond:
                return value_;

            case KinematicViscosityUnit::Stokes:
                return value_ * 1e4;

            case KinematicViscosityUnit::Nanostokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e-9);

            case KinematicViscosityUnit::Microstokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e-6);

            case KinematicViscosityUnit::Millistokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e-3);

            case KinematicViscosityUnit::Centistokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e-2);

            case KinematicViscosityUnit::Decistokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e-1);

            case KinematicViscosityUnit::Kilostokes:
                return (value_ * 1e4) / static_cast<un_scalar_t>(1e3);

            case KinematicViscosityUnit::SquareFeetPerSecond:
                return value_ / 9.290304e-2;

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        un_scalar_t value_;
    };
}
