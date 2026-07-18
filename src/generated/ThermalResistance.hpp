#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ThermalResistanceUnit : std::uint16_t
    {
        KelvinsPerWatt,
        DegreesCelsiusPerWatt,
    };

    /// <summary>Thermal resistance (R) measures the opposition to the heat current in a material or system. It is measured in units of kelvins per watt (K/W) and indicates how much temperature difference (in kelvins) is required to transfer a unit of heat current (in watts) through the material or object. It is essential to optimize the building insulation, evaluate the efficiency of electronic devices, and enhance the performance of heat sinks in various applications.</summary>
    class ThermalResistance
    {
    public:
        constexpr explicit ThermalResistance(
            double value,
            ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinsPerWatt)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ThermalResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalResistance operator+(ThermalResistance other) const noexcept
        {
            return ThermalResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ThermalResistance operator-(ThermalResistance other) const noexcept
        {
            return ThermalResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ThermalResistance operator*(double scalar) const noexcept
        {
            return ThermalResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr ThermalResistance operator/(double scalar) const noexcept
        {
            return ThermalResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ThermalResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ThermalResistance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double kelvins_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::KelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_kelvins_per_watt(double value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::KelvinsPerWatt);
        }


        [[nodiscard]] constexpr double degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::DegreesCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_degrees_celsius_per_watt(double value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::DegreesCelsiusPerWatt);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ThermalResistanceUnit unit)
        {
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinsPerWatt:
                return value;

            case ThermalResistanceUnit::DegreesCelsiusPerWatt:
                return value;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ThermalResistanceUnit unit) const
        {
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinsPerWatt:
                return value_;

            case ThermalResistanceUnit::DegreesCelsiusPerWatt:
                return value_;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        double value_;
    };
}
