#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class BrakeSpecificFuelConsumptionUnit : std::uint8_t
    {
        GramsPerKiloWattHour,
        KilogramsPerJoule,
        PoundsPerMechanicalHorsepowerHour,
    };

    /// <summary>Brake specific fuel consumption (BSFC) is a measure of the fuel efficiency of any prime mover that burns fuel and produces rotational, or shaft, power. It is typically used for comparing the efficiency of internal combustion engines with a shaft output.</summary>
    class BrakeSpecificFuelConsumption : public UnitsNetBase
    {
    public:
        constexpr explicit BrakeSpecificFuelConsumption(
            const un_scalar_t value,
            const BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule)
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

        [[nodiscard]] constexpr un_scalar_t value(const BrakeSpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator+(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator-(const BrakeSpecificFuelConsumption& other)const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() * scalar);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_kilo_watt_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_grams_per_kilo_watt_hour(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_joule() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_kilograms_per_joule(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule);
        }


        /// <summary>The pound per horse power hour uses mechanical horse power and the imperial pound</summary>
        [[nodiscard]] constexpr un_scalar_t pounds_per_mechanical_horsepower_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }

        /// <summary>The pound per horse power hour uses mechanical horse power and the imperial pound</summary>
        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_pounds_per_mechanical_horsepower_hour(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }


        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_invalid()
        {
            return BrakeSpecificFuelConsumption(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, BrakeSpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour:
                return value / static_cast<un_scalar_t>(3.6e9);

            case BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule:
                return value;

            case BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour:
                return value * (static_cast<un_scalar_t>(0.45359237) / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665)))/static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const BrakeSpecificFuelConsumptionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour:
                return base_value_ * static_cast<un_scalar_t>(3.6e9);

            case BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule:
                return base_value_;

            case BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour:
                return base_value_ * static_cast<un_scalar_t>(3600) / (static_cast<un_scalar_t>(0.45359237) / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665)));

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
        BrakeSpecificFuelConsumptionUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
