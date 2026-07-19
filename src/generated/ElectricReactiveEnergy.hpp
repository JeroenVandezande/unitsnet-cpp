#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricReactiveEnergyUnit : std::uint8_t
    {
        VoltampereReactiveHours,
        KilovoltampereReactiveHours,
        MegavoltampereReactiveHours,
    };

    /// <summary>The volt-ampere reactive hour (expressed as varh) is the reactive power of one Volt-ampere reactive produced in one hour.</summary>
    class ElectricReactiveEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricReactiveEnergy(
            const un_scalar_t value,
            const ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHours)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricReactiveEnergyUnit::VoltampereReactiveHours)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactiveEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator+(const ElectricReactiveEnergy& other) const noexcept
        {
            return ElectricReactiveEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator-(const ElectricReactiveEnergy& other)const noexcept
        {
            return ElectricReactiveEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t voltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_voltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }


        [[nodiscard]] constexpr un_scalar_t kilovoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_kilovoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }


        [[nodiscard]] constexpr un_scalar_t megavoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_megavoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }


        [[nodiscard]] static constexpr ElectricReactiveEnergy from_invalid()
        {
            return ElectricReactiveEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactiveEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return value;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactiveEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return base_value_;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        un_scalar_t value_;
        ElectricReactiveEnergyUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
