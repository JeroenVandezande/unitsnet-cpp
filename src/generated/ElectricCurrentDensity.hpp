#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricCurrentDensityUnit : std::uint16_t
    {
        AmperesPerSquareMeter,
        AmperesPerSquareInch,
        AmperesPerSquareFoot,
    };

    /// <summary>In electromagnetism, current density is the electric current per unit area of cross section.</summary>
    class ElectricCurrentDensity
    {
    public:
        constexpr explicit ElectricCurrentDensity(
            double value,
            ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperesPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricCurrentDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator+(ElectricCurrentDensity other) const noexcept
        {
            return ElectricCurrentDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator-(ElectricCurrentDensity other) const noexcept
        {
            return ElectricCurrentDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator*(double scalar) const noexcept
        {
            return ElectricCurrentDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator/(double scalar) const noexcept
        {
            return ElectricCurrentDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricCurrentDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricCurrentDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double amperes_per_square_meter() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_meter(double value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareMeter);
        }


        [[nodiscard]] constexpr double amperes_per_square_inch() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_inch(double value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareInch);
        }


        [[nodiscard]] constexpr double amperes_per_square_foot() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareFoot);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_foot(double value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricCurrentDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return value;

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return value / 0.00064516;

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return value / 9.290304e-2;

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricCurrentDensityUnit unit) const
        {
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return value_;

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return value_ * 0.00064516;

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return value_ * 9.290304e-2;

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        double value_;
    };
}
