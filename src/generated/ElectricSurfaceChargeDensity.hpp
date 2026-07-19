#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricSurfaceChargeDensityUnit : std::uint8_t
    {
        CoulombsPerSquareMeter,
        CoulombsPerSquareCentimeter,
        CoulombsPerSquareInch,
    };

    /// <summary>In electromagnetism, surface charge density is a measure of the amount of electric charge per surface area.</summary>
    class ElectricSurfaceChargeDensity
    {
    public:
        constexpr explicit ElectricSurfaceChargeDensity(
            const un_scalar_t value,
            const ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricSurfaceChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator+(const ElectricSurfaceChargeDensity other) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator-(const ElectricSurfaceChargeDensity other) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricSurfaceChargeDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricSurfaceChargeDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_meter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_meter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_centimeter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_centimeter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_inch() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_inch(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricSurfaceChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter:
                return value;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter:
                return value * 1.0e4;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch:
                return value / 0.00064516;

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricSurfaceChargeDensityUnit unit) const
        {
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter:
                return value_;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter:
                return value_ / 1.0e4;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch:
                return value_ * 0.00064516;

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        un_scalar_t value_;
    };
}
