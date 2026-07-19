#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MagneticFluxUnit : std::uint8_t
    {
        Webers,
    };

    /// <summary>In physics, specifically electromagnetism, the magnetic flux through a surface is the surface integral of the normal component of the magnetic field B passing through that surface.</summary>
    class MagneticFlux : public UnitsNetBase
    {
    public:
        constexpr explicit MagneticFlux(
            const un_scalar_t value,
            const MagneticFluxUnit unit = MagneticFluxUnit::Webers)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticFlux operator+(const MagneticFlux& other) const noexcept
        {
            return MagneticFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MagneticFlux operator-(const MagneticFlux& other)const noexcept
        {
            return MagneticFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MagneticFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr MagneticFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MagneticFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MagneticFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t webers() const
        {
            return convert_from_base(MagneticFluxUnit::Webers);
        }

        [[nodiscard]] static constexpr MagneticFlux from_webers(const un_scalar_t value)
        {
            return MagneticFlux(value, MagneticFluxUnit::Webers);
        }

        [[nodiscard]] static constexpr MagneticFlux from_invalid()
        {
            return MagneticFlux(false);
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
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MagneticFluxUnit::Webers:
                return base_value;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        un_scalar_t value_;
        MagneticFluxUnit value_unit_type_;       
    };
}
