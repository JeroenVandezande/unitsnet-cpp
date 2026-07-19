#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricChargeDensityUnit : std::uint8_t
    {
        CoulombsPerCubicMeter,
    };

    /// <summary>In electromagnetism, charge density is a measure of the amount of electric charge per volume.</summary>
    class ElectricChargeDensity
    {
    public:
        constexpr explicit ElectricChargeDensity(
            const un_scalar_t value,
            const ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator+(const ElectricChargeDensity other) const noexcept
        {
            return ElectricChargeDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator-(const ElectricChargeDensity other) const noexcept
        {
            return ElectricChargeDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricChargeDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricChargeDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_cubic_meter() const
        {
            return convert_from_base(ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }

        [[nodiscard]] static constexpr ElectricChargeDensity from_coulombs_per_cubic_meter(const un_scalar_t value)
        {
            return ElectricChargeDensity(value, ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricChargeDensityUnit unit) const
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        un_scalar_t value_;
    };
}
