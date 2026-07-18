#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricSurfaceChargeDensityUnit : std::uint16_t
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
            double value,
            ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricSurfaceChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator+(ElectricSurfaceChargeDensity other) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator-(ElectricSurfaceChargeDensity other) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator*(double scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator/(double scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricSurfaceChargeDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricSurfaceChargeDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double coulombs_per_square_meter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_meter(double value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }


        [[nodiscard]] constexpr double coulombs_per_square_centimeter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_centimeter(double value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double coulombs_per_square_inch() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_inch(double value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricSurfaceChargeDensityUnit unit)
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

        [[nodiscard]] constexpr double convert_from_base(ElectricSurfaceChargeDensityUnit unit) const
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

        double value_;
    };
}
