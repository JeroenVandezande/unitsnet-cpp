#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MagneticFluxUnit : std::uint8_t
    {
        Webers,
    };

    /// <summary>In physics, specifically electromagnetism, the magnetic flux through a surface is the surface integral of the normal component of the magnetic field B passing through that surface.</summary>
    class MagneticFlux
    {
    public:
        constexpr explicit MagneticFlux(
            const un_scalar_t value,
            const MagneticFluxUnit unit = MagneticFluxUnit::Webers)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticFlux operator+(const MagneticFlux other) const noexcept
        {
            return MagneticFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr MagneticFlux operator-(const MagneticFlux other) const noexcept
        {
            return MagneticFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr MagneticFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr MagneticFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MagneticFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t webers() const
        {
            return convert_from_base(MagneticFluxUnit::Webers);
        }

        [[nodiscard]] static constexpr MagneticFlux from_webers(const un_scalar_t value)
        {
            return MagneticFlux(value, MagneticFluxUnit::Webers);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagneticFluxUnit unit)
        {
            switch (unit)
            {

            case MagneticFluxUnit::Webers:
                return value;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagneticFluxUnit unit) const
        {
            switch (unit)
            {

            case MagneticFluxUnit::Webers:
                return value_;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        un_scalar_t value_;
    };
}
