#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class HeatTransferCoefficientUnit : std::uint16_t
    {
        WattsPerSquareMeterKelvin,
        WattsPerSquareMeterCelsius,
        BtusPerHourSquareFootDegreeFahrenheit,
        BtusPerSecondSquareInchDegreeFahrenheit,
        CaloriesPerHourSquareMeterDegreeCelsius,
        KilocaloriesPerHourSquareMeterDegreeCelsius,
    };

    /// <summary>The heat transfer coefficient or film coefficient, or film effectiveness, in thermodynamics and in mechanics is the proportionality constant between the heat flux and the thermodynamic driving force for the flow of heat (i.e., the temperature difference, ΔT)</summary>
    class HeatTransferCoefficient
    {
    public:
        constexpr explicit HeatTransferCoefficient(
            double value,
            HeatTransferCoefficientUnit unit = HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(HeatTransferCoefficientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator+(HeatTransferCoefficient other) const noexcept
        {
            return HeatTransferCoefficient(value_ + other.value_);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator-(HeatTransferCoefficient other) const noexcept
        {
            return HeatTransferCoefficient(value_ - other.value_);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator*(double scalar) const noexcept
        {
            return HeatTransferCoefficient(value_ * scalar);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator/(double scalar) const noexcept
        {
            return HeatTransferCoefficient(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(HeatTransferCoefficient other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(HeatTransferCoefficient other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_square_meter_kelvin() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_kelvin(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin);
        }


        [[nodiscard]] constexpr double watts_per_square_meter_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_celsius(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius);
        }


        [[nodiscard]] constexpr double btus_per_hour_square_foot_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_hour_square_foot_degree_fahrenheit(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit);
        }


        [[nodiscard]] constexpr double btus_per_second_square_inch_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_second_square_inch_degree_fahrenheit(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit);
        }


        [[nodiscard]] constexpr double calories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_calories_per_hour_square_meter_degree_celsius(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double kilocalories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_kilocalories_per_hour_square_meter_degree_celsius(double value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, HeatTransferCoefficientUnit unit)
        {
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin:
                return value;

            case HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius:
                return value;

            case HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit:
                return value * ((1055.05585262 / (0.3048 * 0.3048 * 3600)) * 1.8);

            case HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit:
                return value * ((1055.05585262 / (2.54e-2 * 2.54e-2)) * 1.8);

            case HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius:
                return (value * 4.184) / 3600;

            case HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius:
                return ((value * 1e3) * 4.184) / 3600;

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(HeatTransferCoefficientUnit unit) const
        {
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin:
                return value_;

            case HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius:
                return value_;

            case HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit:
                return value_ / ((1055.05585262 / (0.3048 * 0.3048 * 3600)) * 1.8);

            case HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit:
                return value_ / ((1055.05585262 / (2.54e-2 * 2.54e-2)) * 1.8);

            case HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius:
                return (value_ / 4.184) * 3600;

            case HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius:
                return ((value_ / 4.184) * 3600) / 1e3;

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        double value_;
    };
}
