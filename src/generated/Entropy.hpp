#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class EntropyUnit : std::uint8_t
    {
        JoulesPerKelvin,
        KilojoulesPerKelvin,
        MegajoulesPerKelvin,
        CaloriesPerKelvin,
        KilocaloriesPerKelvin,
        JoulesPerDegreeCelsius,
        KilojoulesPerDegreeCelsius,
    };

    /// <summary>Entropy is an important concept in the branch of science known as thermodynamics. The idea of "irreversibility" is central to the understanding of entropy.  It is often said that entropy is an expression of the disorder, or randomness of a system, or of our lack of information about it. Entropy is an extensive property. It has the dimension of energy divided by temperature, which has a unit of joules per kelvin (J/K) in the International System of Units</summary>
    class Entropy
    {
    public:
        constexpr explicit Entropy(
            const un_scalar_t value,
            const EntropyUnit unit = EntropyUnit::JoulesPerKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const EntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Entropy operator+(const Entropy other) const noexcept
        {
            return Entropy(value_ + other.value_);
        }

        [[nodiscard]] constexpr Entropy operator-(const Entropy other) const noexcept
        {
            return Entropy(value_ - other.value_);
        }

        [[nodiscard]] constexpr Entropy operator*(const un_scalar_t scalar) const noexcept
        {
            return Entropy(value_ * scalar);
        }

        [[nodiscard]] constexpr Entropy operator/(const un_scalar_t scalar) const noexcept
        {
            return Entropy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Entropy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Entropy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::JoulesPerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_joules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::JoulesPerKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::KilojoulesPerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_kilojoules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilojoulesPerKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::MegajoulesPerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_megajoules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::MegajoulesPerKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t calories_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::CaloriesPerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_calories_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::CaloriesPerKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::KilocaloriesPerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_kilocalories_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilocaloriesPerKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_degree_celsius() const
        {
            return convert_from_base(EntropyUnit::JoulesPerDegreeCelsius);
        }

        [[nodiscard]] static constexpr Entropy from_joules_per_degree_celsius(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::JoulesPerDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_degree_celsius() const
        {
            return convert_from_base(EntropyUnit::KilojoulesPerDegreeCelsius);
        }

        [[nodiscard]] static constexpr Entropy from_kilojoules_per_degree_celsius(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilojoulesPerDegreeCelsius);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EntropyUnit unit)
        {
            switch (unit)
            {

            case EntropyUnit::JoulesPerKelvin:
                return value;

            case EntropyUnit::KilojoulesPerKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case EntropyUnit::MegajoulesPerKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case EntropyUnit::CaloriesPerKelvin:
                return value * static_cast<un_scalar_t>(4.184);

            case EntropyUnit::KilocaloriesPerKelvin:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184);

            case EntropyUnit::JoulesPerDegreeCelsius:
                return value;

            case EntropyUnit::KilojoulesPerDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            }

            throw std::invalid_argument("Unknown Entropy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EntropyUnit unit) const
        {
            switch (unit)
            {

            case EntropyUnit::JoulesPerKelvin:
                return value_;

            case EntropyUnit::KilojoulesPerKelvin:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case EntropyUnit::MegajoulesPerKelvin:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case EntropyUnit::CaloriesPerKelvin:
                return value_ / static_cast<un_scalar_t>(4.184);

            case EntropyUnit::KilocaloriesPerKelvin:
                return (value_ / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e3);

            case EntropyUnit::JoulesPerDegreeCelsius:
                return value_;

            case EntropyUnit::KilojoulesPerDegreeCelsius:
                return (value_) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown Entropy unit.");
        }

        un_scalar_t value_;
    };
}
