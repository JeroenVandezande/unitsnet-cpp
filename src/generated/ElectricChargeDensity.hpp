#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricChargeDensityUnit : std::uint16_t
    {
        CoulombsPerCubicMeter,
    };

    /// <summary>In electromagnetism, charge density is a measure of the amount of electric charge per volume.</summary>
    class ElectricChargeDensity
    {
    public:
        constexpr explicit ElectricChargeDensity(
            double value,
            ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator+(ElectricChargeDensity other) const noexcept
        {
            return ElectricChargeDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator-(ElectricChargeDensity other) const noexcept
        {
            return ElectricChargeDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator*(double scalar) const noexcept
        {
            return ElectricChargeDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator/(double scalar) const noexcept
        {
            return ElectricChargeDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricChargeDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricChargeDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double coulombs_per_cubic_meter() const
        {
            return convert_from_base(ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }

        [[nodiscard]] static constexpr ElectricChargeDensity from_coulombs_per_cubic_meter(double value)
        {
            return ElectricChargeDensity(value, ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricChargeDensityUnit unit) const
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        double value_;
    };
}
