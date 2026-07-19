#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricPotentialUnit : std::uint8_t
    {
        Volts,
        Nanovolts,
        Microvolts,
        Millivolts,
        Kilovolts,
        Megavolts,
    };

    /// <summary>In classical electromagnetism, the electric potential (a scalar quantity denoted by Φ, ΦE or V and also called the electric field potential or the electrostatic potential) at a point is the amount of electric potential energy that a unitary point charge would have when located at that point.</summary>
    class ElectricPotential : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricPotential(
            const un_scalar_t value,
            const ElectricPotentialUnit unit = ElectricPotentialUnit::Volts)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricPotentialUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricPotential operator+(const ElectricPotential& other) const noexcept
        {
            return ElectricPotential(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotential operator-(const ElectricPotential& other)const noexcept
        {
            return ElectricPotential(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotential operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotential(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricPotential operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotential(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricPotential& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricPotential& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricPotential& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t volts() const
        {
            return convert_from_base(ElectricPotentialUnit::Volts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_volts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Volts);
        }

        [[nodiscard]] constexpr un_scalar_t nanovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Nanovolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_nanovolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Nanovolts);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Microvolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_microvolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Microvolts);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Millivolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_millivolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Millivolts);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Kilovolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_kilovolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Kilovolts);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Megavolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_megavolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Megavolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_invalid()
        {
            return ElectricPotential(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricPotentialUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialUnit::Volts:
                return value;

            case ElectricPotentialUnit::Nanovolts:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricPotentialUnit::Microvolts:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricPotentialUnit::Millivolts:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricPotentialUnit::Kilovolts:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricPotentialUnit::Megavolts:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricPotentialUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricPotentialUnit::Volts:
                return base_value;

            case ElectricPotentialUnit::Nanovolts:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricPotentialUnit::Microvolts:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialUnit::Millivolts:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialUnit::Kilovolts:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialUnit::Megavolts:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        un_scalar_t value_;
        ElectricPotentialUnit value_unit_type_;       
    };
}
