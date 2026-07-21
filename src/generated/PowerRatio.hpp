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
    enum class PowerRatioUnit : std::uint8_t
    {
        DecibelWatt,
        DecibelMilliwatt,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of PowerRatio.</summary>
    class PowerRatioDto
    {
    public:
        constexpr PowerRatioDto() noexcept
            : value{}, unit(PowerRatioUnit::DecibelWatt)
        {
        }

        constexpr PowerRatioDto(
            const un_scalar_t value,
            const PowerRatioUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PowerRatioUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PowerRatioUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PowerRatioUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown PowerRatio unit name.");
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
        [[nodiscard]] static PowerRatioDto from_json(const nlohmann::json& json)
        {
            return PowerRatioDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one watt.</summary>
    class PowerRatio : public UnitsNetBase
    {
    public:
        constexpr explicit PowerRatio(
            const un_scalar_t value,
            const PowerRatioUnit unit = PowerRatioUnit::DecibelWatt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PowerRatioDto to_dto(
            const PowerRatioUnit unit = PowerRatioUnit::DecibelWatt) const
        {
            return PowerRatioDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr PowerRatio from_dto(const PowerRatioDto& dto)
        {
            return PowerRatio(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PowerRatioUnit unit = PowerRatioUnit::DecibelWatt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static PowerRatio from_json(const nlohmann::json& json)
        {
            return from_dto(PowerRatioDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr PowerRatio operator+(const PowerRatio& other) const noexcept
        {
            return PowerRatio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PowerRatio operator-(const PowerRatio& other)const noexcept
        {
            return PowerRatio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PowerRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(base_value() * scalar);
        }

        [[nodiscard]] constexpr PowerRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PowerRatio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PowerRatio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PowerRatio& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decibel_watts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelWatt);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_watts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelWatt);
        }

        [[nodiscard]] constexpr un_scalar_t decibel_milliwatts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelMilliwatt);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_milliwatts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelMilliwatt);
        }

        [[nodiscard]] static constexpr PowerRatio from_invalid()
        {
            return PowerRatio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerRatioUnit unit)
        {
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatt:
                return value;

            case PowerRatioUnit::DecibelMilliwatt:
                return value - static_cast<un_scalar_t>(30);

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerRatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatt:
                return base_value;

            case PowerRatioUnit::DecibelMilliwatt:
                return base_value + static_cast<un_scalar_t>(30);

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        un_scalar_t value_;
        PowerRatioUnit value_unit_type_;       
    };
}
