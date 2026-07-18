#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MagneticFluxUnit : std::uint16_t
    {
        Webers,
    };

    /// <summary>In physics, specifically electromagnetism, the magnetic flux through a surface is the surface integral of the normal component of the magnetic field B passing through that surface.</summary>
    class MagneticFlux
    {
    public:
        constexpr explicit MagneticFlux(
            double value,
            MagneticFluxUnit unit = MagneticFluxUnit::Webers)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MagneticFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticFlux operator+(MagneticFlux other) const noexcept
        {
            return MagneticFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr MagneticFlux operator-(MagneticFlux other) const noexcept
        {
            return MagneticFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr MagneticFlux operator*(double scalar) const noexcept
        {
            return MagneticFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr MagneticFlux operator/(double scalar) const noexcept
        {
            return MagneticFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MagneticFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MagneticFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double webers() const
        {
            return convert_from_base(MagneticFluxUnit::Webers);
        }

        [[nodiscard]] static constexpr MagneticFlux from_webers(double value)
        {
            return MagneticFlux(value, MagneticFluxUnit::Webers);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MagneticFluxUnit unit)
        {
            switch (unit)
            {

            case MagneticFluxUnit::Webers:
                return value;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MagneticFluxUnit unit) const
        {
            switch (unit)
            {

            case MagneticFluxUnit::Webers:
                return value_;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        double value_;
    };
}
