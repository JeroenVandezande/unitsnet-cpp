#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class KinematicViscosityUnit : std::uint16_t
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
            double value,
            KinematicViscosityUnit unit = KinematicViscosityUnit::SquareMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(KinematicViscosityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr KinematicViscosity operator+(KinematicViscosity other) const noexcept
        {
            return KinematicViscosity(value_ + other.value_);
        }

        [[nodiscard]] constexpr KinematicViscosity operator-(KinematicViscosity other) const noexcept
        {
            return KinematicViscosity(value_ - other.value_);
        }

        [[nodiscard]] constexpr KinematicViscosity operator*(double scalar) const noexcept
        {
            return KinematicViscosity(value_ * scalar);
        }

        [[nodiscard]] constexpr KinematicViscosity operator/(double scalar) const noexcept
        {
            return KinematicViscosity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(KinematicViscosity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(KinematicViscosity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double square_meters_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareMetersPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_meters_per_second(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareMetersPerSecond);
        }


        [[nodiscard]] constexpr double stokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Stokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_stokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Stokes);
        }


        [[nodiscard]] constexpr double nanostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Nanostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_nanostokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Nanostokes);
        }


        [[nodiscard]] constexpr double microstokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Microstokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_microstokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Microstokes);
        }


        [[nodiscard]] constexpr double millistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Millistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_millistokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Millistokes);
        }


        [[nodiscard]] constexpr double centistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Centistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_centistokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Centistokes);
        }


        [[nodiscard]] constexpr double decistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Decistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_decistokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Decistokes);
        }


        [[nodiscard]] constexpr double kilostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Kilostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_kilostokes(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Kilostokes);
        }


        [[nodiscard]] constexpr double square_feet_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareFeetPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_feet_per_second(double value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareFeetPerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, KinematicViscosityUnit unit)
        {
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMetersPerSecond:
                return value;

            case KinematicViscosityUnit::Stokes:
                return value / 1e4;

            case KinematicViscosityUnit::Nanostokes:
                return (value * 1e-9) / 1e4;

            case KinematicViscosityUnit::Microstokes:
                return (value * 1e-6) / 1e4;

            case KinematicViscosityUnit::Millistokes:
                return (value * 1e-3) / 1e4;

            case KinematicViscosityUnit::Centistokes:
                return (value * 1e-2) / 1e4;

            case KinematicViscosityUnit::Decistokes:
                return (value * 1e-1) / 1e4;

            case KinematicViscosityUnit::Kilostokes:
                return (value * 1e3) / 1e4;

            case KinematicViscosityUnit::SquareFeetPerSecond:
                return value * 9.290304e-2;

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(KinematicViscosityUnit unit) const
        {
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMetersPerSecond:
                return value_;

            case KinematicViscosityUnit::Stokes:
                return value_ * 1e4;

            case KinematicViscosityUnit::Nanostokes:
                return (value_ * 1e4) / 1e-9;

            case KinematicViscosityUnit::Microstokes:
                return (value_ * 1e4) / 1e-6;

            case KinematicViscosityUnit::Millistokes:
                return (value_ * 1e4) / 1e-3;

            case KinematicViscosityUnit::Centistokes:
                return (value_ * 1e4) / 1e-2;

            case KinematicViscosityUnit::Decistokes:
                return (value_ * 1e4) / 1e-1;

            case KinematicViscosityUnit::Kilostokes:
                return (value_ * 1e4) / 1e3;

            case KinematicViscosityUnit::SquareFeetPerSecond:
                return value_ / 9.290304e-2;

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        double value_;
    };
}
