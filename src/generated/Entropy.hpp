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
    enum class EntropyUnit : std::uint8_t
    {
        JoulePerKelvin,
        KilojoulePerKelvin,
        MegajoulePerKelvin,
        CaloriePerKelvin,
        KilocaloriePerKelvin,
        JoulePerDegreeCelsius,
        KilojoulePerDegreeCelsius,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Entropy.</summary>
    class EntropyDto
    {
    public:
        constexpr EntropyDto() noexcept
            : value{}, unit(EntropyUnit::JoulePerKelvin)
        {
        }

        constexpr EntropyDto(
            const un_scalar_t value,
            const EntropyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        EntropyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr EntropyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<EntropyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Entropy unit name.");
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
        [[nodiscard]] static EntropyDto from_json(const nlohmann::json& json)
        {
            return EntropyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Entropy is an important concept in the branch of science known as thermodynamics. The idea of "irreversibility" is central to the understanding of entropy.  It is often said that entropy is an expression of the disorder, or randomness of a system, or of our lack of information about it. Entropy is an extensive property. It has the dimension of energy divided by temperature, which has a unit of joules per kelvin (J/K) in the International System of Units</summary>
    class Entropy : public UnitsNetBase
    {
    public:
        constexpr explicit Entropy(
            const un_scalar_t value,
            const EntropyUnit unit = EntropyUnit::JoulePerKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const EntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr EntropyDto to_dto(
            const EntropyUnit unit = EntropyUnit::JoulePerKelvin) const
        {
            return EntropyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Entropy from_dto(const EntropyDto& dto)
        {
            return Entropy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const EntropyUnit unit = EntropyUnit::JoulePerKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Entropy from_json(const nlohmann::json& json)
        {
            return from_dto(EntropyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Entropy operator+(const Entropy& other) const noexcept
        {
            return Entropy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Entropy operator-(const Entropy& other)const noexcept
        {
            return Entropy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Entropy operator*(const un_scalar_t scalar) const noexcept
        {
            return Entropy(base_value() * scalar);
        }

        [[nodiscard]] constexpr Entropy operator/(const un_scalar_t scalar) const noexcept
        {
            return Entropy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Entropy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Entropy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Entropy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::JoulePerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_joules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::JoulePerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::KilojoulePerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_kilojoules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilojoulePerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::MegajoulePerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_megajoules_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::MegajoulePerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::CaloriePerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_calories_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::CaloriePerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_kelvin() const
        {
            return convert_from_base(EntropyUnit::KilocaloriePerKelvin);
        }

        [[nodiscard]] static constexpr Entropy from_kilocalories_per_kelvin(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilocaloriePerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_degree_celsius() const
        {
            return convert_from_base(EntropyUnit::JoulePerDegreeCelsius);
        }

        [[nodiscard]] static constexpr Entropy from_joules_per_degree_celsius(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::JoulePerDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_degree_celsius() const
        {
            return convert_from_base(EntropyUnit::KilojoulePerDegreeCelsius);
        }

        [[nodiscard]] static constexpr Entropy from_kilojoules_per_degree_celsius(const un_scalar_t value)
        {
            return Entropy(value, EntropyUnit::KilojoulePerDegreeCelsius);
        }

        [[nodiscard]] static constexpr Entropy from_invalid()
        {
            return Entropy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EntropyUnit unit)
        {
            switch (unit)
            {

            case EntropyUnit::JoulePerKelvin:
                return value;

            case EntropyUnit::KilojoulePerKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case EntropyUnit::MegajoulePerKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case EntropyUnit::CaloriePerKelvin:
                return value * static_cast<un_scalar_t>(4.184);

            case EntropyUnit::KilocaloriePerKelvin:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184);

            case EntropyUnit::JoulePerDegreeCelsius:
                return value;

            case EntropyUnit::KilojoulePerDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            }

            throw std::invalid_argument("Unknown Entropy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EntropyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case EntropyUnit::JoulePerKelvin:
                return base_value;

            case EntropyUnit::KilojoulePerKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case EntropyUnit::MegajoulePerKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case EntropyUnit::CaloriePerKelvin:
                return base_value / static_cast<un_scalar_t>(4.184);

            case EntropyUnit::KilocaloriePerKelvin:
                return (base_value / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e3);

            case EntropyUnit::JoulePerDegreeCelsius:
                return base_value;

            case EntropyUnit::KilojoulePerDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown Entropy unit.");
        }

        un_scalar_t value_;
        EntropyUnit value_unit_type_;       
    };
}
