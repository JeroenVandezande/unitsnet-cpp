#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MagnetizationUnit : std::uint16_t
    {
        AmperesPerMeter,
    };

    /// <summary>In classical electromagnetism, magnetization is the vector field that expresses the density of permanent or induced magnetic dipole moments in a magnetic material.</summary>
    class Magnetization
    {
    public:
        constexpr explicit Magnetization(
            double value,
            MagnetizationUnit unit = MagnetizationUnit::AmperesPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MagnetizationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Magnetization operator+(Magnetization other) const noexcept
        {
            return Magnetization(value_ + other.value_);
        }

        [[nodiscard]] constexpr Magnetization operator-(Magnetization other) const noexcept
        {
            return Magnetization(value_ - other.value_);
        }

        [[nodiscard]] constexpr Magnetization operator*(double scalar) const noexcept
        {
            return Magnetization(value_ * scalar);
        }

        [[nodiscard]] constexpr Magnetization operator/(double scalar) const noexcept
        {
            return Magnetization(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Magnetization other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Magnetization other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double amperes_per_meter() const
        {
            return convert_from_base(MagnetizationUnit::AmperesPerMeter);
        }

        [[nodiscard]] static constexpr Magnetization from_amperes_per_meter(double value)
        {
            return Magnetization(value, MagnetizationUnit::AmperesPerMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MagnetizationUnit unit)
        {
            switch (unit)
            {

            case MagnetizationUnit::AmperesPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MagnetizationUnit unit) const
        {
            switch (unit)
            {

            case MagnetizationUnit::AmperesPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        double value_;
    };
}
