#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpecificEntropyUnit : std::uint8_t
    {
        JoulePerKilogramKelvin,
        KilojoulePerKilogramKelvin,
        MegajoulePerKilogramKelvin,
        JoulePerKilogramDegreeCelsius,
        KilojoulePerKilogramDegreeCelsius,
        MegajoulePerKilogramDegreeCelsius,
        CaloriePerGramKelvin,
        KilocaloriePerGramKelvin,
        BtuPerPoundFahrenheit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SpecificEntropy.</summary>
    class SpecificEntropyDto
    {
    public:
        constexpr SpecificEntropyDto() noexcept
            : value{}, unit(SpecificEntropyUnit::JoulePerKilogramKelvin)
        {
        }

        constexpr SpecificEntropyDto(
            const un_scalar_t value,
            const SpecificEntropyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpecificEntropyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpecificEntropyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpecificEntropyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SpecificEntropy unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificEntropyDto from_json(const nlohmann::json& json)
        {
            return SpecificEntropyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Specific entropy is an amount of energy required to raise temperature of a substance by 1 Kelvin per unit mass.</summary>
    class SpecificEntropy : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificEntropy(
            const un_scalar_t value,
            const SpecificEntropyUnit unit = SpecificEntropyUnit::JoulePerKilogramKelvin)
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

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpecificEntropyDto to_dto(
            const SpecificEntropyUnit unit = SpecificEntropyUnit::JoulePerKilogramKelvin) const
        {
            return SpecificEntropyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SpecificEntropy from_dto(const SpecificEntropyDto& dto)
        {
            return SpecificEntropy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpecificEntropyUnit unit = SpecificEntropyUnit::JoulePerKilogramKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificEntropy from_json(const nlohmann::json& json)
        {
            return from_dto(SpecificEntropyDto::from_json(json));
        }
#endif
#endif

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
            return convert_from_base(SpecificEntropyUnit::JoulePerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulePerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulePerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulePerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulePerKilogramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulePerKilogramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::JoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_joules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::JoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::KilojoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilojoules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilojoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram_degree_celsius() const
        {
            return convert_from_base(SpecificEntropyUnit::MegajoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_megajoules_per_kilogram_degree_celsius(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::MegajoulePerKilogramDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::CaloriePerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_calories_per_gram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::CaloriePerGramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_gram_kelvin() const
        {
            return convert_from_base(SpecificEntropyUnit::KilocaloriePerGramKelvin);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_kilocalories_per_gram_kelvin(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::KilocaloriePerGramKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_pound_fahrenheit() const
        {
            return convert_from_base(SpecificEntropyUnit::BtuPerPoundFahrenheit);
        }

        [[nodiscard]] static constexpr SpecificEntropy from_btus_per_pound_fahrenheit(const un_scalar_t value)
        {
            return SpecificEntropy(value, SpecificEntropyUnit::BtuPerPoundFahrenheit);
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

            case SpecificEntropyUnit::JoulePerKilogramKelvin:
                return value;

            case SpecificEntropyUnit::KilojoulePerKilogramKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEntropyUnit::MegajoulePerKilogramKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEntropyUnit::JoulePerKilogramDegreeCelsius:
                return value;

            case SpecificEntropyUnit::KilojoulePerKilogramDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEntropyUnit::MegajoulePerKilogramDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEntropyUnit::CaloriePerGramKelvin:
                return value * static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::KilocaloriePerGramKelvin:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::BtuPerPoundFahrenheit:
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

            case SpecificEntropyUnit::JoulePerKilogramKelvin:
                return base_value;

            case SpecificEntropyUnit::KilojoulePerKilogramKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::MegajoulePerKilogramKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEntropyUnit::JoulePerKilogramDegreeCelsius:
                return base_value;

            case SpecificEntropyUnit::KilojoulePerKilogramDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::MegajoulePerKilogramDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEntropyUnit::CaloriePerGramKelvin:
                return base_value / static_cast<un_scalar_t>(4.184e3);

            case SpecificEntropyUnit::KilocaloriePerGramKelvin:
                return (base_value / static_cast<un_scalar_t>(4.184e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEntropyUnit::BtuPerPoundFahrenheit:
                return base_value / static_cast<un_scalar_t>(4.1868e3);

            }

            throw std::invalid_argument("Unknown SpecificEntropy unit.");
        }

        un_scalar_t value_;
        SpecificEntropyUnit value_unit_type_;       
    };
}
