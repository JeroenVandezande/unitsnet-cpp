#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricResistanceUnit : std::uint8_t
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

    /// <summary>The electrical resistance of an object is a measure of its opposition to the flow of electric current. Along with reactance, it is one of two elements of impedance. Its reciprocal quantity is electrical conductance.</summary>
    class ElectricResistance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricResistance(
            const un_scalar_t value,
            const ElectricResistanceUnit unit = ElectricResistanceUnit::Ohms)
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
           return "ElectricResistance"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricResistanceUnit::Ohms:
                return "Ohms";

            case ElectricResistanceUnit::Nanoohms:
                return "Nanoohms";

            case ElectricResistanceUnit::Microohms:
                return "Microohms";

            case ElectricResistanceUnit::Milliohms:
                return "Milliohms";

            case ElectricResistanceUnit::Kiloohms:
                return "Kiloohms";

            case ElectricResistanceUnit::Megaohms:
                return "Megaohms";

            case ElectricResistanceUnit::Gigaohms:
                return "Gigaohms";

            case ElectricResistanceUnit::Teraohms:
                return "Teraohms";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistance operator+(const ElectricResistance& other) const noexcept
        {
            return ElectricResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistance operator-(const ElectricResistance& other)const noexcept
        {
            return ElectricResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_ohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Ohms);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_nanoohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Nanoohms);
        }

        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_microohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Microohms);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_milliohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Milliohms);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_kiloohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Kiloohms);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_megaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Megaohms);
        }

        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_gigaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Gigaohms);
        }

        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_teraohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_invalid()
        {
            return ElectricResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistanceUnit unit)
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return value;

            case ElectricResistanceUnit::Nanoohms:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistanceUnit::Microohms:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistanceUnit::Milliohms:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistanceUnit::Kiloohms:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistanceUnit::Megaohms:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistanceUnit::Gigaohms:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricResistanceUnit::Teraohms:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return base_value;

            case ElectricResistanceUnit::Nanoohms:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistanceUnit::Microohms:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistanceUnit::Milliohms:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistanceUnit::Kiloohms:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricResistanceUnit::Megaohms:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricResistanceUnit::Gigaohms:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricResistanceUnit::Teraohms:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        un_scalar_t value_;
        ElectricResistanceUnit value_unit_type_;       
    };
}
