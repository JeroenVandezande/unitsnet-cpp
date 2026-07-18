#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ThermalConductivityUnit : std::uint16_t
    {
        WattsPerMeterKelvin,
        BtusPerHourFootFahrenheit,
        BtusPerSecondInchFahrenheit,
    };

    /// <summary>Thermal conductivity is the property of a material to conduct heat.</summary>
    class ThermalConductivity
    {
    public:
        constexpr explicit ThermalConductivity(
            double value,
            ThermalConductivityUnit unit = ThermalConductivityUnit::WattsPerMeterKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ThermalConductivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalConductivity operator+(ThermalConductivity other) const noexcept
        {
            return ThermalConductivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ThermalConductivity operator-(ThermalConductivity other) const noexcept
        {
            return ThermalConductivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ThermalConductivity operator*(double scalar) const noexcept
        {
            return ThermalConductivity(value_ * scalar);
        }

        [[nodiscard]] constexpr ThermalConductivity operator/(double scalar) const noexcept
        {
            return ThermalConductivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ThermalConductivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ThermalConductivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_meter_kelvin() const
        {
            return convert_from_base(ThermalConductivityUnit::WattsPerMeterKelvin);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_watts_per_meter_kelvin(double value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::WattsPerMeterKelvin);
        }


        [[nodiscard]] constexpr double btus_per_hour_foot_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtusPerHourFootFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_hour_foot_fahrenheit(double value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtusPerHourFootFahrenheit);
        }


        [[nodiscard]] constexpr double btus_per_second_inch_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtusPerSecondInchFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_second_inch_fahrenheit(double value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtusPerSecondInchFahrenheit);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ThermalConductivityUnit unit)
        {
            switch (unit)
            {

            case ThermalConductivityUnit::WattsPerMeterKelvin:
                return value;

            case ThermalConductivityUnit::BtusPerHourFootFahrenheit:
                return value * ((1055.05585262 / (0.3048 * 3600)) * 1.8);

            case ThermalConductivityUnit::BtusPerSecondInchFahrenheit:
                return value * ((1055.05585262 / 2.54e-2) * 1.8);

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ThermalConductivityUnit unit) const
        {
            switch (unit)
            {

            case ThermalConductivityUnit::WattsPerMeterKelvin:
                return value_;

            case ThermalConductivityUnit::BtusPerHourFootFahrenheit:
                return value_ / ((1055.05585262 / (0.3048 * 3600)) * 1.8);

            case ThermalConductivityUnit::BtusPerSecondInchFahrenheit:
                return value_ / ((1055.05585262 / 2.54e-2) * 1.8);

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        double value_;
    };
}
