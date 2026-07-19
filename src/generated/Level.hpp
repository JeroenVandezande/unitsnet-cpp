#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LevelUnit : std::uint8_t
    {
        Decibels,
        Nepers,
    };

    /// <summary>Level is the logarithm of the ratio of a quantity Q to a reference value of that quantity, Q₀, expressed in dimensionless units.</summary>
    class Level
    {
    public:
        constexpr explicit Level(
            const un_scalar_t value,
            const LevelUnit unit = LevelUnit::Decibels)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const LevelUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Level operator+(const Level other) const noexcept
        {
            return Level(value_ + other.value_);
        }

        [[nodiscard]] constexpr Level operator-(const Level other) const noexcept
        {
            return Level(value_ - other.value_);
        }

        [[nodiscard]] constexpr Level operator*(const un_scalar_t scalar) const noexcept
        {
            return Level(value_ * scalar);
        }

        [[nodiscard]] constexpr Level operator/(const un_scalar_t scalar) const noexcept
        {
            return Level(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Level other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Level other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t decibels() const
        {
            return convert_from_base(LevelUnit::Decibels);
        }

        [[nodiscard]] static constexpr Level from_decibels(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Decibels);
        }


        [[nodiscard]] constexpr un_scalar_t nepers() const
        {
            return convert_from_base(LevelUnit::Nepers);
        }

        [[nodiscard]] static constexpr Level from_nepers(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Nepers);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LevelUnit unit)
        {
            switch (unit)
            {

            case LevelUnit::Decibels:
                return value;

            case LevelUnit::Nepers:
                return (1 / 0.115129254) * value;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LevelUnit unit) const
        {
            switch (unit)
            {

            case LevelUnit::Decibels:
                return value_;

            case LevelUnit::Nepers:
                return 0.115129254 * value_;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        un_scalar_t value_;
    };
}
