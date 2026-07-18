#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PowerRatioUnit : std::uint16_t
    {
        DecibelWatts,
        DecibelMilliwatts,
    };

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one watt.</summary>
    class PowerRatio
    {
    public:
        constexpr explicit PowerRatio(
            double value,
            PowerRatioUnit unit = PowerRatioUnit::DecibelWatts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PowerRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PowerRatio operator+(PowerRatio other) const noexcept
        {
            return PowerRatio(value_ + other.value_);
        }

        [[nodiscard]] constexpr PowerRatio operator-(PowerRatio other) const noexcept
        {
            return PowerRatio(value_ - other.value_);
        }

        [[nodiscard]] constexpr PowerRatio operator*(double scalar) const noexcept
        {
            return PowerRatio(value_ * scalar);
        }

        [[nodiscard]] constexpr PowerRatio operator/(double scalar) const noexcept
        {
            return PowerRatio(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(PowerRatio other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(PowerRatio other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decibel_watts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelWatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_watts(double value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelWatts);
        }


        [[nodiscard]] constexpr double decibel_milliwatts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelMilliwatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_milliwatts(double value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelMilliwatts);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PowerRatioUnit unit)
        {
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatts:
                return value;

            case PowerRatioUnit::DecibelMilliwatts:
                return value - 30;

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PowerRatioUnit unit) const
        {
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatts:
                return value_;

            case PowerRatioUnit::DecibelMilliwatts:
                return value_ + 30;

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        double value_;
    };
}
