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
    enum class RelativeHumidityUnit : std::uint8_t
    {
        Percent,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RelativeHumidity.</summary>
    class RelativeHumidityDto
    {
    public:
        constexpr RelativeHumidityDto() noexcept
            : value{}, unit(RelativeHumidityUnit::Percent)
        {
        }

        constexpr RelativeHumidityDto(
            const un_scalar_t value,
            const RelativeHumidityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RelativeHumidityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RelativeHumidityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RelativeHumidityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RelativeHumidity unit name.");
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
        [[nodiscard]] static RelativeHumidityDto from_json(const nlohmann::json& json)
        {
            return RelativeHumidityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Relative humidity is a ratio of the actual water vapor present in the air to the maximum water vapor in the air at the given temperature.</summary>
    class RelativeHumidity : public UnitsNetBase
    {
    public:
        constexpr explicit RelativeHumidity(
            const un_scalar_t value,
            const RelativeHumidityUnit unit = RelativeHumidityUnit::Percent)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RelativeHumidityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RelativeHumidityDto to_dto(
            const RelativeHumidityUnit unit = RelativeHumidityUnit::Percent) const
        {
            return RelativeHumidityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RelativeHumidity from_dto(const RelativeHumidityDto& dto)
        {
            return RelativeHumidity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RelativeHumidityUnit unit = RelativeHumidityUnit::Percent) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RelativeHumidity from_json(const nlohmann::json& json)
        {
            return from_dto(RelativeHumidityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RelativeHumidity operator+(const RelativeHumidity& other) const noexcept
        {
            return RelativeHumidity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RelativeHumidity operator-(const RelativeHumidity& other)const noexcept
        {
            return RelativeHumidity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RelativeHumidity operator*(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(base_value() * scalar);
        }

        [[nodiscard]] constexpr RelativeHumidity operator/(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RelativeHumidity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RelativeHumidity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RelativeHumidity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(RelativeHumidityUnit::Percent);
        }

        [[nodiscard]] static constexpr RelativeHumidity from_percent(const un_scalar_t value)
        {
            return RelativeHumidity(value, RelativeHumidityUnit::Percent);
        }

        [[nodiscard]] static constexpr RelativeHumidity from_invalid()
        {
            return RelativeHumidity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RelativeHumidityUnit unit)
        {
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return value;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RelativeHumidityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return base_value;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        un_scalar_t value_;
        RelativeHumidityUnit value_unit_type_;       
    };
}
