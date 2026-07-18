#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpecificEntropyUnit : std::uint16_t
    {
        JoulesPerKilogramKelvin,
        KilojoulesPerKilogramKelvin,
        MegajoulesPerKilogramKelvin,
        JoulesPerKilogramDegreeCelsius,
        KilojoulesPerKilogramDegreeCelsius,
        MegajoulesPerKilogramDegreeCelsius,
        CaloriesPerGramKelvin,
        KilocaloriesPerGramKelvin,
        BtusPerPoundFahrenheit,
    };

    /// <summary>Specific entropy is an amount of energy required to raise temperature of a substance by 1 Kelvin per unit mass.</summary>
    class SpecificEntropy
    {
    public:
        constexpr explicit SpecificEntropy(
            double value,
            SpecificEntropyUnit unit = SpecificEntropyUnit::JoulesPerKilogramKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpecificEntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificEntropy operator+(SpecificEntropy other) const noexcept
        {
            return SpecificEntropy(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificEntropy operator-(SpecificEntropy other) const noexcept
        {
            return SpecificEntropy(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificEntropy operator*(double scalar) const noexcept
        {
            return SpecificEntropy(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificEntropy operator/(double scalar) const noexcept
        {
            return SpecificEntropy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SpecificEntropy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SpecificEntropy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::JoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_kelvin(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulesPerKilogramKelvin);
        }


        [[nodiscard]] constexpr double kilojoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_kelvin(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulesPerKilogramKelvin);
        }


        [[nodiscard]] constexpr double megajoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_kelvin(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulesPerKilogramKelvin);
        }


        [[nodiscard]] constexpr double joules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_degree_celsius(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius);
        }


        [[nodiscard]] constexpr double kilojoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_degree_celsius(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius);
        }


        [[nodiscard]] constexpr double megajoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_degree_celsius(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius);
        }


        [[nodiscard]] constexpr double calories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::CaloriesPerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_calories_per_gram_kelvin(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::CaloriesPerGramKelvin);
        }


        [[nodiscard]] constexpr double kilocalories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilocaloriesPerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilocalories_per_gram_kelvin(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilocaloriesPerGramKelvin);
        }


        [[nodiscard]] constexpr double btus_per_pound_fahrenheit() const
        {
            return convert_from_base(SpecificEntropyUnit::BtusPerPoundFahrenheit);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_btus_per_pound_fahrenheit(double value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::BtusPerPoundFahrenheit);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpecificEntropyUnit unit)
        {
            switch (unit)
            {

            case SpecificEntropyUnit::JoulesPerKilogramKelvin:
                return value;

            case SpecificEntropyUnit::KilojoulesPerKilogramKelvin:
                return (value * 1e3);

            case SpecificEntropyUnit::MegajoulesPerKilogramKelvin:
                return (value * 1e6);

            case SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius:
                return value;

            case SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius:
                return (value * 1e3);

            case SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius:
                return (value * 1e6);

            case SpecificEntropyUnit::CaloriesPerGramKelvin:
                return value * 4.184e3;

            case SpecificEntropyUnit::KilocaloriesPerGramKelvin:
                return (value * 1e3) * 4.184e3;

            case SpecificEntropyUnit::BtusPerPoundFahrenheit:
                return value * 4.1868e3;

            }

            throw std::invalid_argument("Unknown SpecificEntropy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpecificEntropyUnit unit) const
        {
            switch (unit)
            {

            case SpecificEntropyUnit::JoulesPerKilogramKelvin:
                return value_;

            case SpecificEntropyUnit::KilojoulesPerKilogramKelvin:
                return (value_) / 1e3;

            case SpecificEntropyUnit::MegajoulesPerKilogramKelvin:
                return (value_) / 1e6;

            case SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius:
                return value_;

            case SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius:
                return (value_) / 1e3;

            case SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius:
                return (value_) / 1e6;

            case SpecificEntropyUnit::CaloriesPerGramKelvin:
                return value_ / 4.184e3;

            case SpecificEntropyUnit::KilocaloriesPerGramKelvin:
                return (value_ / 4.184e3) / 1e3;

            case SpecificEntropyUnit::BtusPerPoundFahrenheit:
                return value_ / 4.1868e3;

            }

            throw std::invalid_argument("Unknown SpecificEntropy unit.");
        }

        double value_;
    };
}
