#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class BrakeSpecificFuelConsumptionUnit : std::uint16_t
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
            double value,
            BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(BrakeSpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator+(BrakeSpecificFuelConsumption other) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ + other.value_);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator-(BrakeSpecificFuelConsumption other) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ - other.value_);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator*(double scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ * scalar);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator/(double scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(BrakeSpecificFuelConsumption other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(BrakeSpecificFuelConsumption other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grams_per_kilo_watt_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_grams_per_kilo_watt_hour(double value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour);
        }


        [[nodiscard]] constexpr double kilograms_per_joule() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_kilograms_per_joule(double value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule);
        }


        [[nodiscard]] constexpr double pounds_per_mechanical_horsepower_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_pounds_per_mechanical_horsepower_hour(double value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, BrakeSpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour:
                return value / 3.6e9;

            case BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule:
                return value;

            case BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour:
                return value * (0.45359237 / (76.0402249 * 9.80665))/3600;

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(BrakeSpecificFuelConsumptionUnit unit) const
        {
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramsPerKiloWattHour:
                return value_ * 3.6e9;

            case BrakeSpecificFuelConsumptionUnit::KilogramsPerJoule:
                return value_;

            case BrakeSpecificFuelConsumptionUnit::PoundsPerMechanicalHorsepowerHour:
                return value_ * 3600 / (0.45359237 / (76.0402249 * 9.80665));

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        double value_;
    };
}
