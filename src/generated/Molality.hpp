#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MolalityUnit : std::uint8_t
    {
        MolesPerKilogram,
        MillimolesPerKilogram,
        MolesPerGram,
    };

    /// <summary>Molality is a measure of the amount of solute in a solution relative to a given mass of solvent.</summary>
    class Molality : public UnitsNetBase
    {
    public:
        constexpr explicit Molality(
            const un_scalar_t value,
            const MolalityUnit unit = MolalityUnit::MolesPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == MolalityUnit::MolesPerKilogram)
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
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolalityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Molality operator+(const Molality& other) const noexcept
        {
            return Molality(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Molality operator-(const Molality& other)const noexcept
        {
            return Molality(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Molality operator*(const un_scalar_t scalar) const noexcept
        {
            return Molality(base_value() * scalar);
        }

        [[nodiscard]] constexpr Molality operator/(const un_scalar_t scalar) const noexcept
        {
            return Molality(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Molality& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Molality& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Molality& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolesPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t millimoles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MillimolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_millimoles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MillimolesPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_gram() const
        {
            return convert_from_base(MolalityUnit::MolesPerGram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_gram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolesPerGram);
        }


        [[nodiscard]] static constexpr Molality from_invalid()
        {
            return Molality(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolalityUnit unit)
        {
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return value;

            case MolalityUnit::MillimolesPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MolalityUnit::MolesPerGram:
                return value / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolalityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return base_value_;

            case MolalityUnit::MillimolesPerKilogram:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case MolalityUnit::MolesPerGram:
                return base_value_ * static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        un_scalar_t value_;
        MolalityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
