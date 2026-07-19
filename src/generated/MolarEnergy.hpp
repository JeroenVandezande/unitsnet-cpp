#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MolarEnergyUnit : std::uint8_t
    {
        JoulesPerMole,
        KilojoulesPerMole,
        MegajoulesPerMole,
    };

    /// <summary>Molar energy is the amount of energy stored in 1 mole of a substance.</summary>
    class MolarEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit MolarEnergy(
            const un_scalar_t value,
            const MolarEnergyUnit unit = MolarEnergyUnit::JoulesPerMole)
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
           return "MolarEnergy"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return "JoulesPerMole";

            case MolarEnergyUnit::KilojoulesPerMole:
                return "KilojoulesPerMole";

            case MolarEnergyUnit::MegajoulesPerMole:
                return "MegajoulesPerMole";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarEnergy operator+(const MolarEnergy& other) const noexcept
        {
            return MolarEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarEnergy operator-(const MolarEnergy& other)const noexcept
        {
            return MolarEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::JoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_joules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::JoulesPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::KilojoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_kilojoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::KilojoulesPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::MegajoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_megajoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::MegajoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_invalid()
        {
            return MolarEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarEnergyUnit unit)
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return value;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarEnergyUnit::MegajoulesPerMole:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return base_value;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarEnergyUnit::MegajoulesPerMole:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        un_scalar_t value_;
        MolarEnergyUnit value_unit_type_;       
    };
}
