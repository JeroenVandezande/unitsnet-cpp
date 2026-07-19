#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricApparentEnergyUnit : std::uint8_t
    {
        VoltampereHours,
        KilovoltampereHours,
        MegavoltampereHours,
    };

    /// <summary>A unit for expressing the integral of apparent power over time, equal to the product of 1 volt-ampere and 1 hour, or to 3600 joules.</summary>
    class ElectricApparentEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricApparentEnergy(
            const un_scalar_t value,
            const ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHours)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "ElectricApparentEnergy"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return "VoltampereHours";

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return "KilovoltampereHours";

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return "MegavoltampereHours";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricApparentEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator+(const ElectricApparentEnergy& other) const noexcept
        {
            return ElectricApparentEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator-(const ElectricApparentEnergy& other)const noexcept
        {
            return ElectricApparentEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t voltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::VoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_voltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::VoltampereHours);
        }

        [[nodiscard]] constexpr un_scalar_t kilovoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::KilovoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_kilovoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::KilovoltampereHours);
        }

        [[nodiscard]] constexpr un_scalar_t megavoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::MegavoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_megavoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::MegavoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_invalid()
        {
            return ElectricApparentEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricApparentEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return value;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricApparentEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return base_value;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        un_scalar_t value_;
        ElectricApparentEnergyUnit value_unit_type_;       
    };
}
