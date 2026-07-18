#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MagneticFieldUnit : std::uint16_t
    {
        Teslas,
        Nanoteslas,
        Microteslas,
        Milliteslas,
        Gausses,
        Milligausses,
    };

    /// <summary>A magnetic field is a force field that is created by moving electric charges (electric currents) and magnetic dipoles, and exerts a force on other nearby moving charges and magnetic dipoles.</summary>
    class MagneticField
    {
    public:
        constexpr explicit MagneticField(
            double value,
            MagneticFieldUnit unit = MagneticFieldUnit::Teslas)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MagneticFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticField operator+(MagneticField other) const noexcept
        {
            return MagneticField(value_ + other.value_);
        }

        [[nodiscard]] constexpr MagneticField operator-(MagneticField other) const noexcept
        {
            return MagneticField(value_ - other.value_);
        }

        [[nodiscard]] constexpr MagneticField operator*(double scalar) const noexcept
        {
            return MagneticField(value_ * scalar);
        }

        [[nodiscard]] constexpr MagneticField operator/(double scalar) const noexcept
        {
            return MagneticField(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MagneticField other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MagneticField other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double teslas() const
        {
            return convert_from_base(MagneticFieldUnit::Teslas);
        }

        [[nodiscard]] static constexpr MagneticField from_teslas(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Teslas);
        }


        [[nodiscard]] constexpr double nanoteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Nanoteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_nanoteslas(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Nanoteslas);
        }


        [[nodiscard]] constexpr double microteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Microteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_microteslas(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Microteslas);
        }


        [[nodiscard]] constexpr double milliteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Milliteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_milliteslas(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Milliteslas);
        }


        [[nodiscard]] constexpr double gausses() const
        {
            return convert_from_base(MagneticFieldUnit::Gausses);
        }

        [[nodiscard]] static constexpr MagneticField from_gausses(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Gausses);
        }


        [[nodiscard]] constexpr double milligausses() const
        {
            return convert_from_base(MagneticFieldUnit::Milligausses);
        }

        [[nodiscard]] static constexpr MagneticField from_milligausses(double value)
        {
            return MagneticField(value, MagneticFieldUnit::Milligausses);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MagneticFieldUnit unit)
        {
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return value;

            case MagneticFieldUnit::Nanoteslas:
                return (value * 1e-9);

            case MagneticFieldUnit::Microteslas:
                return (value * 1e-6);

            case MagneticFieldUnit::Milliteslas:
                return (value * 1e-3);

            case MagneticFieldUnit::Gausses:
                return value / 1e4;

            case MagneticFieldUnit::Milligausses:
                return (value * 1e-3) / 1e4;

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MagneticFieldUnit unit) const
        {
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return value_;

            case MagneticFieldUnit::Nanoteslas:
                return (value_) / 1e-9;

            case MagneticFieldUnit::Microteslas:
                return (value_) / 1e-6;

            case MagneticFieldUnit::Milliteslas:
                return (value_) / 1e-3;

            case MagneticFieldUnit::Gausses:
                return value_ * 1e4;

            case MagneticFieldUnit::Milligausses:
                return (value_ * 1e4) / 1e-3;

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        double value_;
    };
}
