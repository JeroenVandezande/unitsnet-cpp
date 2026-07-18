#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class TurbidityUnit : std::uint16_t
    {
        NTU,
    };

    /// <summary>Turbidity is the cloudiness or haziness of a fluid caused by large numbers of individual particles that are generally invisible to the naked eye, similar to smoke in air. The measurement of turbidity is a key test of water quality.</summary>
    class Turbidity
    {
    public:
        constexpr explicit Turbidity(
            double value,
            TurbidityUnit unit = TurbidityUnit::NTU)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(TurbidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Turbidity operator+(Turbidity other) const noexcept
        {
            return Turbidity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Turbidity operator-(Turbidity other) const noexcept
        {
            return Turbidity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Turbidity operator*(double scalar) const noexcept
        {
            return Turbidity(value_ * scalar);
        }

        [[nodiscard]] constexpr Turbidity operator/(double scalar) const noexcept
        {
            return Turbidity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Turbidity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Turbidity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double n_t_u() const
        {
            return convert_from_base(TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_n_t_u(double value)
        {
            return Turbidity(value, TurbidityUnit::NTU);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, TurbidityUnit unit)
        {
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return value;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(TurbidityUnit unit) const
        {
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return value_;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        double value_;
    };
}
