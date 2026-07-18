#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class CoefficientOfThermalExpansionUnit : std::uint16_t
    {
        PerKelvin,
        PerDegreeCelsius,
        PerDegreeFahrenheit,
        PpmPerKelvin,
        PpmPerDegreeCelsius,
        PpmPerDegreeFahrenheit,
    };

    /// <summary>A unit that represents a fractional change in size in response to a change in temperature.</summary>
    class CoefficientOfThermalExpansion
    {
    public:
        constexpr explicit CoefficientOfThermalExpansion(
            double value,
            CoefficientOfThermalExpansionUnit unit = CoefficientOfThermalExpansionUnit::PerKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(CoefficientOfThermalExpansionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator+(CoefficientOfThermalExpansion other) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ + other.value_);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator-(CoefficientOfThermalExpansion other) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ - other.value_);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator*(double scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ * scalar);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator/(double scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(CoefficientOfThermalExpansion other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(CoefficientOfThermalExpansion other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double per_kelvin() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerKelvin);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_kelvin(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerKelvin);
        }


        [[nodiscard]] constexpr double per_degree_celsius() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerDegreeCelsius);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_degree_celsius(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerDegreeCelsius);
        }


        [[nodiscard]] constexpr double per_degree_fahrenheit() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_degree_fahrenheit(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit);
        }


        [[nodiscard]] constexpr double ppm_per_kelvin() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerKelvin);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_kelvin(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerKelvin);
        }


        [[nodiscard]] constexpr double ppm_per_degree_celsius() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_degree_celsius(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius);
        }


        [[nodiscard]] constexpr double ppm_per_degree_fahrenheit() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_degree_fahrenheit(double value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, CoefficientOfThermalExpansionUnit unit)
        {
            switch (unit)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return value;

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return value;

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return value * 9 / 5;

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return value / 1e6;

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return value / 1e6;

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return value * 9 / 5e6;

            }

            throw std::invalid_argument("Unknown CoefficientOfThermalExpansion unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(CoefficientOfThermalExpansionUnit unit) const
        {
            switch (unit)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return value_;

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return value_;

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return value_ * 5 / 9;

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return value_ * 1e6;

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return value_ * 1e6;

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return value_ * 5e6 / 9;

            }

            throw std::invalid_argument("Unknown CoefficientOfThermalExpansion unit.");
        }

        double value_;
    };
}
