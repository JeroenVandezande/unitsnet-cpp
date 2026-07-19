#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricApparentPowerUnit : std::uint8_t
    {
        Voltamperes,
        Microvoltamperes,
        Millivoltamperes,
        Kilovoltamperes,
        Megavoltamperes,
        Gigavoltamperes,
    };

    /// <summary>Power engineers measure apparent power as the magnitude of the vector sum of active and reactive power. It is the product of the root mean square voltage (in volts) and the root mean square current (in amperes).</summary>
    class ElectricApparentPower : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricApparentPower(
            const un_scalar_t value,
            const ElectricApparentPowerUnit unit = ElectricApparentPowerUnit::Voltamperes)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricApparentPowerUnit::Voltamperes)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricApparentPowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator+(const ElectricApparentPower& other) const noexcept
        {
            return ElectricApparentPower(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentPower operator-(const ElectricApparentPower& other)const noexcept
        {
            return ElectricApparentPower(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentPower operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentPower(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentPower(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricApparentPower& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricApparentPower& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricApparentPower& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t voltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Voltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_voltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Voltamperes);
        }


        [[nodiscard]] constexpr un_scalar_t microvoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Microvoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_microvoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Microvoltamperes);
        }


        [[nodiscard]] constexpr un_scalar_t millivoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Millivoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_millivoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Millivoltamperes);
        }


        [[nodiscard]] constexpr un_scalar_t kilovoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Kilovoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_kilovoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Kilovoltamperes);
        }


        [[nodiscard]] constexpr un_scalar_t megavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Megavoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_megavoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Megavoltamperes);
        }


        [[nodiscard]] constexpr un_scalar_t gigavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Gigavoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_gigavoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Gigavoltamperes);
        }


        [[nodiscard]] static constexpr ElectricApparentPower from_invalid()
        {
            return ElectricApparentPower(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricApparentPowerUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltamperes:
                return value;

            case ElectricApparentPowerUnit::Microvoltamperes:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricApparentPowerUnit::Millivoltamperes:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricApparentPowerUnit::Kilovoltamperes:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricApparentPowerUnit::Megavoltamperes:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricApparentPowerUnit::Gigavoltamperes:
                return (value * static_cast<un_scalar_t>(1e9));

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricApparentPowerUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltamperes:
                return base_value_;

            case ElectricApparentPowerUnit::Microvoltamperes:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricApparentPowerUnit::Millivoltamperes:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricApparentPowerUnit::Kilovoltamperes:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricApparentPowerUnit::Megavoltamperes:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricApparentPowerUnit::Gigavoltamperes:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        un_scalar_t value_;
        ElectricApparentPowerUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
