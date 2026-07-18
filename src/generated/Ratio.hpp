#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RatioUnit : std::uint16_t
    {
        DecimalFractions,
        Percent,
        PartsPerThousand,
        PartsPerMillion,
        PartsPerBillion,
        PartsPerTrillion,
    };

    /// <summary>In mathematics, a ratio is a relationship between two numbers of the same kind (e.g., objects, persons, students, spoonfuls, units of whatever identical dimension), usually expressed as "a to b" or a:b, sometimes expressed arithmetically as a dimensionless quotient of the two that explicitly indicates how many times the first number contains the second (not necessarily an integer).</summary>
    class Ratio
    {
    public:
        constexpr explicit Ratio(
            double value,
            RatioUnit unit = RatioUnit::DecimalFractions)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Ratio operator+(Ratio other) const noexcept
        {
            return Ratio(value_ + other.value_);
        }

        [[nodiscard]] constexpr Ratio operator-(Ratio other) const noexcept
        {
            return Ratio(value_ - other.value_);
        }

        [[nodiscard]] constexpr Ratio operator*(double scalar) const noexcept
        {
            return Ratio(value_ * scalar);
        }

        [[nodiscard]] constexpr Ratio operator/(double scalar) const noexcept
        {
            return Ratio(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Ratio other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Ratio other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decimal_fractions() const
        {
            return convert_from_base(RatioUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr Ratio from_decimal_fractions(double value)
        {
            return Ratio(value, RatioUnit::DecimalFractions);
        }


        [[nodiscard]] constexpr double percent() const
        {
            return convert_from_base(RatioUnit::Percent);
        }

        [[nodiscard]] static constexpr Ratio from_percent(double value)
        {
            return Ratio(value, RatioUnit::Percent);
        }


        [[nodiscard]] constexpr double parts_per_thousand() const
        {
            return convert_from_base(RatioUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_thousand(double value)
        {
            return Ratio(value, RatioUnit::PartsPerThousand);
        }


        [[nodiscard]] constexpr double parts_per_million() const
        {
            return convert_from_base(RatioUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_million(double value)
        {
            return Ratio(value, RatioUnit::PartsPerMillion);
        }


        [[nodiscard]] constexpr double parts_per_billion() const
        {
            return convert_from_base(RatioUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_billion(double value)
        {
            return Ratio(value, RatioUnit::PartsPerBillion);
        }


        [[nodiscard]] constexpr double parts_per_trillion() const
        {
            return convert_from_base(RatioUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_trillion(double value)
        {
            return Ratio(value, RatioUnit::PartsPerTrillion);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RatioUnit unit)
        {
            switch (unit)
            {

            case RatioUnit::DecimalFractions:
                return value;

            case RatioUnit::Percent:
                return value / 1e2;

            case RatioUnit::PartsPerThousand:
                return value / 1e3;

            case RatioUnit::PartsPerMillion:
                return value / 1e6;

            case RatioUnit::PartsPerBillion:
                return value / 1e9;

            case RatioUnit::PartsPerTrillion:
                return value / 1e12;

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RatioUnit unit) const
        {
            switch (unit)
            {

            case RatioUnit::DecimalFractions:
                return value_;

            case RatioUnit::Percent:
                return value_ * 1e2;

            case RatioUnit::PartsPerThousand:
                return value_ * 1e3;

            case RatioUnit::PartsPerMillion:
                return value_ * 1e6;

            case RatioUnit::PartsPerBillion:
                return value_ * 1e9;

            case RatioUnit::PartsPerTrillion:
                return value_ * 1e12;

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        double value_;
    };
}
