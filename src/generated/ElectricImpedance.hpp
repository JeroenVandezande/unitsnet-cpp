#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricImpedanceUnit : std::uint8_t
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

    /// <summary>Electric impedance is the opposition to alternating current presented by the combined effect of resistance and reactance in a circuit. It is defined as the inverse of admittance. The SI unit of impedance is the ohm (symbol Ω).</summary>
    class ElectricImpedance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricImpedance(
            const un_scalar_t value,
            const ElectricImpedanceUnit unit = ElectricImpedanceUnit::Ohms)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricImpedanceUnit::Ohms)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricImpedanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricImpedance operator+(const ElectricImpedance& other) const noexcept
        {
            return ElectricImpedance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricImpedance operator-(const ElectricImpedance& other)const noexcept
        {
            return ElectricImpedance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricImpedance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricImpedance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricImpedance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricImpedance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricImpedance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricImpedance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricImpedance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_ohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Ohms);
        }


        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_nanoohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_microohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Microohms);
        }


        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_milliohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_kiloohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_megaohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_gigaohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_teraohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Teraohms);
        }


        [[nodiscard]] static constexpr ElectricImpedance from_invalid()
        {
            return ElectricImpedance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricImpedanceUnit unit)
        {
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohms:
                return value;

            case ElectricImpedanceUnit::Nanoohms:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricImpedanceUnit::Microohms:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricImpedanceUnit::Milliohms:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricImpedanceUnit::Kiloohms:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricImpedanceUnit::Megaohms:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricImpedanceUnit::Gigaohms:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricImpedanceUnit::Teraohms:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricImpedanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohms:
                return base_value_;

            case ElectricImpedanceUnit::Nanoohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricImpedanceUnit::Microohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricImpedanceUnit::Milliohms:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricImpedanceUnit::Kiloohms:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricImpedanceUnit::Megaohms:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricImpedanceUnit::Gigaohms:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case ElectricImpedanceUnit::Teraohms:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        un_scalar_t value_;
        ElectricImpedanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
