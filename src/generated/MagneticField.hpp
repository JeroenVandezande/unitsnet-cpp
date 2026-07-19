#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MagneticFieldUnit : std::uint8_t
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
            const un_scalar_t value,
            const MagneticFieldUnit unit = MagneticFieldUnit::Teslas)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticField operator+(const MagneticField other) const noexcept
        {
            return MagneticField(value_ + other.value_);
        }

        [[nodiscard]] constexpr MagneticField operator-(const MagneticField other) const noexcept
        {
            return MagneticField(value_ - other.value_);
        }

        [[nodiscard]] constexpr MagneticField operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(value_ * scalar);
        }

        [[nodiscard]] constexpr MagneticField operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticField other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MagneticField other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t teslas() const
        {
            return convert_from_base(MagneticFieldUnit::Teslas);
        }

        [[nodiscard]] static constexpr MagneticField from_teslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Teslas);
        }


        [[nodiscard]] constexpr un_scalar_t nanoteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Nanoteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_nanoteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Nanoteslas);
        }


        [[nodiscard]] constexpr un_scalar_t microteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Microteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_microteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Microteslas);
        }


        [[nodiscard]] constexpr un_scalar_t milliteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Milliteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_milliteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Milliteslas);
        }


        [[nodiscard]] constexpr un_scalar_t gausses() const
        {
            return convert_from_base(MagneticFieldUnit::Gausses);
        }

        [[nodiscard]] static constexpr MagneticField from_gausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Gausses);
        }


        [[nodiscard]] constexpr un_scalar_t milligausses() const
        {
            return convert_from_base(MagneticFieldUnit::Milligausses);
        }

        [[nodiscard]] static constexpr MagneticField from_milligausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Milligausses);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagneticFieldUnit unit)
        {
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return value;

            case MagneticFieldUnit::Nanoteslas:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MagneticFieldUnit::Microteslas:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MagneticFieldUnit::Milliteslas:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MagneticFieldUnit::Gausses:
                return value / static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligausses:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e4);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagneticFieldUnit unit) const
        {
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return value_;

            case MagneticFieldUnit::Nanoteslas:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case MagneticFieldUnit::Microteslas:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case MagneticFieldUnit::Milliteslas:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case MagneticFieldUnit::Gausses:
                return value_ * static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligausses:
                return (value_ * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        un_scalar_t value_;
    };
}
