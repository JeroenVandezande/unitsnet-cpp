#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpecificEntropyUnit : std::uint8_t
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
    class SpecificEntropy : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificEntropy(
            const un_scalar_t value,
            const SpecificEntropyUnit unit = SpecificEntropyUnit::JoulesPerKilogramKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificEntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificEntropy operator+(const SpecificEntropy& other) const noexcept
        {
            return SpecificEntropy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificEntropy operator-(const SpecificEntropy& other)const noexcept
        {
            return SpecificEntropy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificEntropy operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificEntropy(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificEntropy operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificEntropy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificEntropy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificEntropy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificEntropy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::JoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulesPerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulesPerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulesPerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulesPerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::CaloriesPerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_calories_per_gram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::CaloriesPerGramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilocaloriesPerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilocalories_per_gram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilocaloriesPerGramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_pound_fahrenheit() const
        {
            return convert_from_base(SpecificEntropyUnit::BtusPerPoundFahrenheit);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_btus_per_pound_fahrenheit(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::BtusPerPoundFahrenheit);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_invalid()
        {
            return SpecificEntropy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificEntropyUnit unit)
        {
            switch (unit)
            {

            case SpecificEntropyUnit::JoulesPerKilogramKelvin:
                return value;

            case SpecificEntropyUnit::KilojoulesPerKilogramKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEntropyUnit::MegajoulesPerKilogramKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius:
                return value;

            case SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEntropyUnit::CaloriesPerGramKelvin:
                return value * static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::KilocaloriesPerGramKelvin:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::BtusPerPoundFahrenheit:
                return value * static_cast<un_scalar_t>(4.1868e3);

            }

            throw std::invalid_argument("Unknown SpecificEntropy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificEntropyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificEntropyUnit::JoulesPerKilogramKelvin:
                return base_value;

            case SpecificEntropyUnit::KilojoulesPerKilogramKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::MegajoulesPerKilogramKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEntropyUnit::JoulesPerKilogramDegreeCelsius:
                return base_value;

            case SpecificEntropyUnit::KilojoulesPerKilogramDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::MegajoulesPerKilogramDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEntropyUnit::CaloriesPerGramKelvin:
                return base_value / static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::KilocaloriesPerGramKelvin:
                return (base_value / static_cast<un_scalar_t>(4.184e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::BtusPerPoundFahrenheit:
                return base_value / static_cast<un_scalar_t>(4.1868e3);

            }

            throw std::invalid_argument("Unknown SpecificEntropy unit.");
        }

        un_scalar_t value_;
        SpecificEntropyUnit value_unit_type_;       
    };
}
