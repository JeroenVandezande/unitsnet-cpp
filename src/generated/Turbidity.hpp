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
    enum class TurbidityUnit : std::uint8_t
    {
        NTU,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Turbidity.</summary>
    class TurbidityDto
    {
    public:
        constexpr TurbidityDto() noexcept
            : value{}, unit(TurbidityUnit::NTU)
        {
        }

        constexpr TurbidityDto(
            const un_scalar_t value,
            const TurbidityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TurbidityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TurbidityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TurbidityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Turbidity unit name.");
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
        [[nodiscard]] static TurbidityDto from_json(const nlohmann::json& json)
        {
            return TurbidityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Turbidity is the cloudiness or haziness of a fluid caused by large numbers of individual particles that are generally invisible to the naked eye, similar to smoke in air. The measurement of turbidity is a key test of water quality.</summary>
    class Turbidity : public UnitsNetBase
    {
    public:
        constexpr explicit Turbidity(
            const un_scalar_t value,
            const TurbidityUnit unit = TurbidityUnit::NTU)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TurbidityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TurbidityDto to_dto(
            const TurbidityUnit unit = TurbidityUnit::NTU) const
        {
            return TurbidityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Turbidity from_dto(const TurbidityDto& dto)
        {
            return Turbidity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TurbidityUnit unit = TurbidityUnit::NTU) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Turbidity from_json(const nlohmann::json& json)
        {
            return from_dto(TurbidityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Turbidity operator+(const Turbidity& other) const noexcept
        {
            return Turbidity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Turbidity operator-(const Turbidity& other)const noexcept
        {
            return Turbidity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Turbidity operator*(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Turbidity operator/(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Turbidity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Turbidity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Turbidity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t n_t_u() const
        {
            return convert_from_base(TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_n_t_u(const un_scalar_t value)
        {
            return Turbidity(value, TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_invalid()
        {
            return Turbidity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TurbidityUnit unit)
        {
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return value;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TurbidityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return base_value;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        un_scalar_t value_;
        TurbidityUnit value_unit_type_;       
    };
}
