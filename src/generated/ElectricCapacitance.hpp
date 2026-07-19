#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricCapacitanceUnit : std::uint8_t
    {
        Farads,
        Picofarads,
        Nanofarads,
        Microfarads,
        Millifarads,
        Kilofarads,
        Megafarads,
    };

    /// <summary>Capacitance is the capacity of a material object or device to store electric charge.</summary>
    class ElectricCapacitance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCapacitance(
            const un_scalar_t value,
            const ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farads)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricCapacitanceUnit::Farads)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCapacitanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator+(const ElectricCapacitance& other) const noexcept
        {
            return ElectricCapacitance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCapacitance operator-(const ElectricCapacitance& other)const noexcept
        {
            return ElectricCapacitance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCapacitance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCapacitance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCapacitance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCapacitance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t farads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Farads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_farads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Farads);
        }


        [[nodiscard]] constexpr un_scalar_t picofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Picofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_picofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Picofarads);
        }


        [[nodiscard]] constexpr un_scalar_t nanofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Nanofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_nanofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Nanofarads);
        }


        [[nodiscard]] constexpr un_scalar_t microfarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Microfarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_microfarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Microfarads);
        }


        [[nodiscard]] constexpr un_scalar_t millifarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Millifarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_millifarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Millifarads);
        }


        [[nodiscard]] constexpr un_scalar_t kilofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Kilofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_kilofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Kilofarads);
        }


        [[nodiscard]] constexpr un_scalar_t megafarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Megafarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_megafarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Megafarads);
        }


        [[nodiscard]] static constexpr ElectricCapacitance from_invalid()
        {
            return ElectricCapacitance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCapacitanceUnit unit)
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return value;

            case ElectricCapacitanceUnit::Picofarads:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricCapacitanceUnit::Nanofarads:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricCapacitanceUnit::Microfarads:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricCapacitanceUnit::Millifarads:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCapacitanceUnit::Kilofarads:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricCapacitanceUnit::Megafarads:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCapacitanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return base_value_;

            case ElectricCapacitanceUnit::Picofarads:
                return (base_value_) / static_cast<un_scalar_t>(1e-12);

            case ElectricCapacitanceUnit::Nanofarads:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricCapacitanceUnit::Microfarads:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricCapacitanceUnit::Millifarads:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricCapacitanceUnit::Kilofarads:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricCapacitanceUnit::Megafarads:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        un_scalar_t value_;
        ElectricCapacitanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
