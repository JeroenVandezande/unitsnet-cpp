#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpecificFuelConsumptionUnit : std::uint8_t
    {
        PoundsMassPerPoundForceHour,
        KilogramsPerKilogramForceHour,
        GramsPerKilonewtonSecond,
        KilogramsPerKilonewtonSecond,
    };

    /// <summary>SFC is the fuel efficiency of an engine design with respect to thrust output</summary>
    class SpecificFuelConsumption : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificFuelConsumption(
            const un_scalar_t value,
            const SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond)
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

        [[nodiscard]] constexpr un_scalar_t value(const SpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator+(const SpecificFuelConsumption& other) const noexcept
        {
            return SpecificFuelConsumption(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator-(const SpecificFuelConsumption& other)const noexcept
        {
            return SpecificFuelConsumption(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t pounds_mass_per_pound_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_pounds_mass_per_pound_force_hour(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilogram_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilogram_force_hour(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_grams_per_kilonewton_second(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilonewton_second(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond);
        }


        [[nodiscard]] static constexpr SpecificFuelConsumption from_invalid()
        {
            return SpecificFuelConsumption(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour:
                return value * static_cast<un_scalar_t>(1000) / (static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600));

            case SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour:
                return value * static_cast<un_scalar_t>(1000) / (static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600));

            case SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond:
                return value;

            case SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificFuelConsumptionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour:
                return base_value_ * static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1000);

            case SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour:
                return base_value_ * static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1000);

            case SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond:
                return base_value_;

            case SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
        SpecificFuelConsumptionUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
