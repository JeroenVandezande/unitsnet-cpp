#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricReactanceUnit : std::uint8_t
    {
        Ohms,
        Nanoohms,
        Microohms,
        Milliohms,
        Kiloohms,
        Megaohms,
        Gigaohms,
        Teraohms,
    };

    /// <summary>In electrical circuits, reactance is the opposition presented to alternating current by inductance and capacitance. Along with resistance, it is one of two elements of impedance.</summary>
    class ElectricReactance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricReactance(
            const un_scalar_t value,
            const ElectricReactanceUnit unit = ElectricReactanceUnit::Ohms)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricReactanceUnit::Ohms)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactance operator+(const ElectricReactance& other) const noexcept
        {
            return ElectricReactance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactance operator-(const ElectricReactance& other)const noexcept
        {
            return ElectricReactance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricReactance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_ohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Ohms);
        }


        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_nanoohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_microohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Microohms);
        }


        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_milliohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_kiloohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_megaohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_gigaohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_teraohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Teraohms);
        }


        [[nodiscard]] static constexpr ElectricReactance from_invalid()
        {
            return ElectricReactance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactanceUnit unit)
        {
            switch (unit)
            {

            case ElectricReactanceUnit::Ohms:
                return value;

            case ElectricReactanceUnit::Nanoohms:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricReactanceUnit::Microohms:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricReactanceUnit::Milliohms:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricReactanceUnit::Kiloohms:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactanceUnit::Megaohms:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricReactanceUnit::Gigaohms:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricReactanceUnit::Teraohms:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricReactanceUnit::Ohms:
                return base_value_;

            case ElectricReactanceUnit::Nanoohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricReactanceUnit::Microohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricReactanceUnit::Milliohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricReactanceUnit::Kiloohms:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricReactanceUnit::Megaohms:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricReactanceUnit::Gigaohms:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case ElectricReactanceUnit::Teraohms:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        un_scalar_t value_;
        ElectricReactanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
