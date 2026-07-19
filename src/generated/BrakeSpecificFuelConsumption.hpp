#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class BrakeSpecificFuelConsumptionUnit : std::uint8_t
    {
        GramsPerKiloWattHour,
        KilogramsPerJoule,
        PoundsPerMechanicalHorsepowerHour,
    };

    /// <summary>Brake specific fuel consumption (BSFC) is a measure of the fuel efficiency of any prime mover that burns fuel and produces rotational, or shaft, power. It is typically used for comparing the efficiency of internal combustion engines with a shaft output.</summary>
    class BrakeSpecificFuelConsumption
    {
    public:
        constexpr explicit BrakeSpecificFuelConsumption(
            const un_scalar_t value,
            const BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit BrakeSpecificFuelConsumption(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const BrakeSpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator+(const BrakeSpecificFuelConsumption other) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ + other.value_);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator-(const BrakeSpecificFuelConsumption other) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ - other.value_);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ * scalar);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const BrakeSpecificFuelConsumption other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const BrakeSpecificFuelConsumption other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const BrakeSpecificFuelConsumption other) const noexcept
        {
            return value_ > other.value_;
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


        [[nodiscard]] constexpr un_scalar_t pounds_per_mechanical_horsepower_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_pounds_per_mechanical_horsepower_hour(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }


        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_invalid()
        {
            return BrakeSpecificFuelConsumption(false);
        }
    private:
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour:
                return value_ * static_cast<un_scalar_t>(3.6e9);

            case BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule:
                return value_;

            case BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour:
                return value_ * static_cast<un_scalar_t>(3600) / (static_cast<un_scalar_t>(0.45359237) / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665)));

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
    };
}
