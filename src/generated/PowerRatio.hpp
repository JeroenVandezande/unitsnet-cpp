#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PowerRatioUnit : std::uint8_t
    {
        DecibelWatts,
        DecibelMilliwatts,
    };

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one watt.</summary>
    class PowerRatio
    {
    public:
        constexpr explicit PowerRatio(
            const un_scalar_t value,
            const PowerRatioUnit unit = PowerRatioUnit::DecibelWatts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PowerRatio operator+(const PowerRatio other) const noexcept
        {
            return PowerRatio(value_ + other.value_);
        }

        [[nodiscard]] constexpr PowerRatio operator-(const PowerRatio other) const noexcept
        {
            return PowerRatio(value_ - other.value_);
        }

        [[nodiscard]] constexpr PowerRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(value_ * scalar);
        }

        [[nodiscard]] constexpr PowerRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PowerRatio other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const PowerRatio other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t decibel_watts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelWatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_watts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelWatts);
        }


        [[nodiscard]] constexpr un_scalar_t decibel_milliwatts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelMilliwatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_milliwatts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelMilliwatts);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerRatioUnit unit)
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

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerRatioUnit unit) const
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

        un_scalar_t value_;
    };
}
