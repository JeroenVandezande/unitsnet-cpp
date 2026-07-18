#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RatioChangeRateUnit : std::uint16_t
    {
        PercentsPerSecond,
        DecimalFractionsPerSecond,
    };

    /// <summary>The change in ratio per unit of time.</summary>
    class RatioChangeRate
    {
    public:
        constexpr explicit RatioChangeRate(
            double value,
            RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RatioChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RatioChangeRate operator+(RatioChangeRate other) const noexcept
        {
            return RatioChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr RatioChangeRate operator-(RatioChangeRate other) const noexcept
        {
            return RatioChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr RatioChangeRate operator*(double scalar) const noexcept
        {
            return RatioChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr RatioChangeRate operator/(double scalar) const noexcept
        {
            return RatioChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RatioChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RatioChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double percents_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::PercentsPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_percents_per_second(double value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::PercentsPerSecond);
        }


        [[nodiscard]] constexpr double decimal_fractions_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::DecimalFractionsPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_decimal_fractions_per_second(double value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::DecimalFractionsPerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RatioChangeRateUnit unit)
        {
            switch (unit)
            {

            case RatioChangeRateUnit::PercentsPerSecond:
                return value / 1e2;

            case RatioChangeRateUnit::DecimalFractionsPerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RatioChangeRateUnit unit) const
        {
            switch (unit)
            {

            case RatioChangeRateUnit::PercentsPerSecond:
                return value_ * 1e2;

            case RatioChangeRateUnit::DecimalFractionsPerSecond:
                return value_;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        double value_;
    };
}
