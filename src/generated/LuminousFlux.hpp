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
    enum class LuminousFluxUnit : std::uint8_t
    {
        Lumen,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of LuminousFlux.</summary>
    class LuminousFluxDto
    {
    public:
        constexpr LuminousFluxDto() noexcept
            : value{}, unit(LuminousFluxUnit::Lumen)
        {
        }

        constexpr LuminousFluxDto(
            const un_scalar_t value,
            const LuminousFluxUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LuminousFluxUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LuminousFluxUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LuminousFluxUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown LuminousFlux unit name.");
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
        [[nodiscard]] static LuminousFluxDto from_json(const nlohmann::json& json)
        {
            return LuminousFluxDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In photometry, luminous flux or luminous power is the measure of the perceived power of light.</summary>
    class LuminousFlux : public UnitsNetBase
    {
    public:
        constexpr explicit LuminousFlux(
            const un_scalar_t value,
            const LuminousFluxUnit unit = LuminousFluxUnit::Lumen)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminousFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LuminousFluxDto to_dto(
            const LuminousFluxUnit unit = LuminousFluxUnit::Lumen) const
        {
            return LuminousFluxDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr LuminousFlux from_dto(const LuminousFluxDto& dto)
        {
            return LuminousFlux(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LuminousFluxUnit unit = LuminousFluxUnit::Lumen) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static LuminousFlux from_json(const nlohmann::json& json)
        {
            return from_dto(LuminousFluxDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr LuminousFlux operator+(const LuminousFlux& other) const noexcept
        {
            return LuminousFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LuminousFlux operator-(const LuminousFlux& other)const noexcept
        {
            return LuminousFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LuminousFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr LuminousFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LuminousFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LuminousFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t lumens() const
        {
            return convert_from_base(LuminousFluxUnit::Lumen);
        }

        [[nodiscard]] static constexpr LuminousFlux from_lumens(const un_scalar_t value)
        {
            return LuminousFlux(value, LuminousFluxUnit::Lumen);
        }

        [[nodiscard]] static constexpr LuminousFlux from_invalid()
        {
            return LuminousFlux(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminousFluxUnit unit)
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumen:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminousFluxUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LuminousFluxUnit::Lumen:
                return base_value;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        un_scalar_t value_;
        LuminousFluxUnit value_unit_type_;       
    };
}
