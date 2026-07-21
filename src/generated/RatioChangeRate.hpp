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
    enum class RatioChangeRateUnit : std::uint8_t
    {
        PercentPerSecond,
        DecimalFractionPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RatioChangeRate.</summary>
    class RatioChangeRateDto
    {
    public:
        constexpr RatioChangeRateDto() noexcept
            : value{}, unit(RatioChangeRateUnit::DecimalFractionPerSecond)
        {
        }

        constexpr RatioChangeRateDto(
            const un_scalar_t value,
            const RatioChangeRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RatioChangeRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RatioChangeRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RatioChangeRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RatioChangeRate unit name.");
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
        [[nodiscard]] static RatioChangeRateDto from_json(const nlohmann::json& json)
        {
            return RatioChangeRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The change in ratio per unit of time.</summary>
    class RatioChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit RatioChangeRate(
            const un_scalar_t value,
            const RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RatioChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RatioChangeRateDto to_dto(
            const RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionPerSecond) const
        {
            return RatioChangeRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RatioChangeRate from_dto(const RatioChangeRateDto& dto)
        {
            return RatioChangeRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RatioChangeRate from_json(const nlohmann::json& json)
        {
            return from_dto(RatioChangeRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RatioChangeRate operator+(const RatioChangeRate& other) const noexcept
        {
            return RatioChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RatioChangeRate operator-(const RatioChangeRate& other)const noexcept
        {
            return RatioChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RatioChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr RatioChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RatioChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RatioChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RatioChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t percents_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::PercentPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_percents_per_second(const un_scalar_t value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::PercentPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::DecimalFractionPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_decimal_fractions_per_second(const un_scalar_t value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::DecimalFractionPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_invalid()
        {
            return RatioChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RatioChangeRateUnit unit)
        {
            switch (unit)
            {

            case RatioChangeRateUnit::PercentPerSecond:
                return value / static_cast<un_scalar_t>(1e2);

            case RatioChangeRateUnit::DecimalFractionPerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RatioChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RatioChangeRateUnit::PercentPerSecond:
                return base_value * static_cast<un_scalar_t>(1e2);

            case RatioChangeRateUnit::DecimalFractionPerSecond:
                return base_value;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        un_scalar_t value_;
        RatioChangeRateUnit value_unit_type_;       
    };
}
