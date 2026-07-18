#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LevelUnit : std::uint16_t
    {
        Decibels,
        Nepers,
    };

    /// <summary>Level is the logarithm of the ratio of a quantity Q to a reference value of that quantity, Q₀, expressed in dimensionless units.</summary>
    class Level
    {
    public:
        constexpr explicit Level(
            double value,
            LevelUnit unit = LevelUnit::Decibels)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LevelUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Level operator+(Level other) const noexcept
        {
            return Level(value_ + other.value_);
        }

        [[nodiscard]] constexpr Level operator-(Level other) const noexcept
        {
            return Level(value_ - other.value_);
        }

        [[nodiscard]] constexpr Level operator*(double scalar) const noexcept
        {
            return Level(value_ * scalar);
        }

        [[nodiscard]] constexpr Level operator/(double scalar) const noexcept
        {
            return Level(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Level other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Level other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decibels() const
        {
            return convert_from_base(LevelUnit::Decibels);
        }

        [[nodiscard]] static constexpr Level from_decibels(double value)
        {
            return Level(value, LevelUnit::Decibels);
        }


        [[nodiscard]] constexpr double nepers() const
        {
            return convert_from_base(LevelUnit::Nepers);
        }

        [[nodiscard]] static constexpr Level from_nepers(double value)
        {
            return Level(value, LevelUnit::Nepers);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LevelUnit unit)
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

        [[nodiscard]] constexpr double convert_from_base(LevelUnit unit) const
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

        double value_;
    };
}
