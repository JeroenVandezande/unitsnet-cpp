#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class SpecificFuelConsumption
    {
    public:
        constexpr explicit SpecificFuelConsumption(
            const un_scalar_t value,
            const SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramsPerKilonewtonSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator+(const SpecificFuelConsumption other) const noexcept
        {
            return SpecificFuelConsumption(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator-(const SpecificFuelConsumption other) const noexcept
        {
            return SpecificFuelConsumption(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificFuelConsumption other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const SpecificFuelConsumption other) const noexcept
        {
            return value_ < other.value_;
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


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificFuelConsumptionUnit unit)
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
                return (value * static_cast<un_scalar_t>(1e3));

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificFuelConsumptionUnit unit) const
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
                return (value_) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
    };
}
