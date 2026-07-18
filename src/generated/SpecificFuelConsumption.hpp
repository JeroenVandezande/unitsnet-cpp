#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpecificFuelConsumptionUnit : std::uint16_t
    {
        PoundsMassPerPoundForceHour,
        KilogramsPerKilogramForceHour,
        GramsPerKilonewtonSecond,
        KilogramsPerKilonewtonSecond,
    };

    /// <summary>SFC is the fuel efficiency of an engine design with respect to thrust output</summary>
    class SpecificFuelConsumption
    {
    public:
        constexpr explicit SpecificFuelConsumption(
            double value,
            SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator+(SpecificFuelConsumption other) const noexcept
        {
            return SpecificFuelConsumption(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator-(SpecificFuelConsumption other) const noexcept
        {
            return SpecificFuelConsumption(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator*(double scalar) const noexcept
        {
            return SpecificFuelConsumption(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator/(double scalar) const noexcept
        {
            return SpecificFuelConsumption(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SpecificFuelConsumption other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SpecificFuelConsumption other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double pounds_mass_per_pound_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_pounds_mass_per_pound_force_hour(double value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour);
        }


        [[nodiscard]] constexpr double kilograms_per_kilogram_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilogram_force_hour(double value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour);
        }


        [[nodiscard]] constexpr double grams_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_grams_per_kilonewton_second(double value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond);
        }


        [[nodiscard]] constexpr double kilograms_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilonewton_second(double value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour:
                return value * 1000 / (9.80665e-3 * 3600);

            case SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour:
                return value * 1000 / (9.80665e-3 * 3600);

            case SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond:
                return value;

            case SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond:
                return (value * 1e3);

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpecificFuelConsumptionUnit unit) const
        {
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundsMassPerPoundForceHour:
                return value_ * 9.80665e-3 * 3600 / 1000;

            case SpecificFuelConsumptionUnit::KilogramsPerKilogramForceHour:
                return value_ * 9.80665e-3 * 3600 / 1000;

            case SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond:
                return value_;

            case SpecificFuelConsumptionUnit::KilogramsPerKilonewtonSecond:
                return (value_) / 1e3;

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        double value_;
    };
}
