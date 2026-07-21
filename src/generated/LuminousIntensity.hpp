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
    enum class LuminousIntensityUnit : std::uint8_t
    {
        Candela,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of LuminousIntensity.</summary>
    class LuminousIntensityDto
    {
    public:
        constexpr LuminousIntensityDto() noexcept
            : value{}, unit(LuminousIntensityUnit::Candela)
        {
        }

        constexpr LuminousIntensityDto(
            const un_scalar_t value,
            const LuminousIntensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LuminousIntensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LuminousIntensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LuminousIntensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown LuminousIntensity unit name.");
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
        [[nodiscard]] static LuminousIntensityDto from_json(const nlohmann::json& json)
        {
            return LuminousIntensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In photometry, luminous intensity is a measure of the wavelength-weighted power emitted by a light source in a particular direction per unit solid angle, based on the luminosity function, a standardized model of the sensitivity of the human eye.</summary>
    class LuminousIntensity : public UnitsNetBase
    {
    public:
        constexpr explicit LuminousIntensity(
            const un_scalar_t value,
            const LuminousIntensityUnit unit = LuminousIntensityUnit::Candela)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminousIntensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LuminousIntensityDto to_dto(
            const LuminousIntensityUnit unit = LuminousIntensityUnit::Candela) const
        {
            return LuminousIntensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr LuminousIntensity from_dto(const LuminousIntensityDto& dto)
        {
            return LuminousIntensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LuminousIntensityUnit unit = LuminousIntensityUnit::Candela) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static LuminousIntensity from_json(const nlohmann::json& json)
        {
            return from_dto(LuminousIntensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr LuminousIntensity operator+(const LuminousIntensity& other) const noexcept
        {
            return LuminousIntensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LuminousIntensity operator-(const LuminousIntensity& other)const noexcept
        {
            return LuminousIntensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LuminousIntensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr LuminousIntensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousIntensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LuminousIntensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LuminousIntensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t candela() const
        {
            return convert_from_base(LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_candela(const un_scalar_t value)
        {
            return LuminousIntensity(value, LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_invalid()
        {
            return LuminousIntensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminousIntensityUnit unit)
        {
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminousIntensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return base_value;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        un_scalar_t value_;
        LuminousIntensityUnit value_unit_type_;       
    };
}
