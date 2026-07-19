#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricInductanceUnit : std::uint8_t
    {
        Henries,
        Picohenries,
        Nanohenries,
        Microhenries,
        Millihenries,
    };

    /// <summary>Inductance is a property of an electrical conductor which opposes a change in current.</summary>
    class ElectricInductance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricInductance(
            const un_scalar_t value,
            const ElectricInductanceUnit unit = ElectricInductanceUnit::Henries)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricInductanceUnit::Henries)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricInductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricInductance operator+(const ElectricInductance& other) const noexcept
        {
            return ElectricInductance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricInductance operator-(const ElectricInductance& other)const noexcept
        {
            return ElectricInductance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricInductance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricInductance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricInductance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricInductance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricInductance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricInductance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricInductance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t henries() const
        {
            return convert_from_base(ElectricInductanceUnit::Henries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_henries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Henries);
        }


        [[nodiscard]] constexpr un_scalar_t picohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Picohenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_picohenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Picohenries);
        }


        [[nodiscard]] constexpr un_scalar_t nanohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Nanohenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_nanohenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Nanohenries);
        }


        [[nodiscard]] constexpr un_scalar_t microhenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Microhenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_microhenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Microhenries);
        }


        [[nodiscard]] constexpr un_scalar_t millihenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Millihenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_millihenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Millihenries);
        }


        [[nodiscard]] static constexpr ElectricInductance from_invalid()
        {
            return ElectricInductance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricInductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricInductanceUnit::Henries:
                return value;

            case ElectricInductanceUnit::Picohenries:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricInductanceUnit::Nanohenries:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricInductanceUnit::Microhenries:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricInductanceUnit::Millihenries:
                return (value * static_cast<un_scalar_t>(1e-3));

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricInductanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricInductanceUnit::Henries:
                return base_value_;

            case ElectricInductanceUnit::Picohenries:
                return (base_value_) / static_cast<un_scalar_t>(1e-12);

            case ElectricInductanceUnit::Nanohenries:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricInductanceUnit::Microhenries:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricInductanceUnit::Millihenries:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        un_scalar_t value_;
        ElectricInductanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
