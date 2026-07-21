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
    enum class IlluminanceUnit : std::uint8_t
    {
        Lux,
        Millilux,
        Kilolux,
        Megalux,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Illuminance.</summary>
    class IlluminanceDto
    {
    public:
        constexpr IlluminanceDto() noexcept
            : value{}, unit(IlluminanceUnit::Lux)
        {
        }

        constexpr IlluminanceDto(
            const un_scalar_t value,
            const IlluminanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        IlluminanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr IlluminanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<IlluminanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Illuminance unit name.");
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
        [[nodiscard]] static IlluminanceDto from_json(const nlohmann::json& json)
        {
            return IlluminanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In photometry, illuminance is the total luminous flux incident on a surface, per unit area.</summary>
    class Illuminance : public UnitsNetBase
    {
    public:
        constexpr explicit Illuminance(
            const un_scalar_t value,
            const IlluminanceUnit unit = IlluminanceUnit::Lux)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const IlluminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr IlluminanceDto to_dto(
            const IlluminanceUnit unit = IlluminanceUnit::Lux) const
        {
            return IlluminanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Illuminance from_dto(const IlluminanceDto& dto)
        {
            return Illuminance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const IlluminanceUnit unit = IlluminanceUnit::Lux) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Illuminance from_json(const nlohmann::json& json)
        {
            return from_dto(IlluminanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Illuminance operator+(const Illuminance& other) const noexcept
        {
            return Illuminance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Illuminance operator-(const Illuminance& other)const noexcept
        {
            return Illuminance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Illuminance operator*(const un_scalar_t scalar) const noexcept
        {
            return Illuminance(base_value() * scalar);
        }

        [[nodiscard]] constexpr Illuminance operator/(const un_scalar_t scalar) const noexcept
        {
            return Illuminance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Illuminance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Illuminance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Illuminance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t lux() const
        {
            return convert_from_base(IlluminanceUnit::Lux);
        }

        [[nodiscard]] static constexpr Illuminance from_lux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Lux);
        }

        [[nodiscard]] constexpr un_scalar_t millilux() const
        {
            return convert_from_base(IlluminanceUnit::Millilux);
        }

        [[nodiscard]] static constexpr Illuminance from_millilux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Millilux);
        }

        [[nodiscard]] constexpr un_scalar_t kilolux() const
        {
            return convert_from_base(IlluminanceUnit::Kilolux);
        }

        [[nodiscard]] static constexpr Illuminance from_kilolux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Kilolux);
        }

        [[nodiscard]] constexpr un_scalar_t megalux() const
        {
            return convert_from_base(IlluminanceUnit::Megalux);
        }

        [[nodiscard]] static constexpr Illuminance from_megalux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Megalux);
        }

        [[nodiscard]] static constexpr Illuminance from_invalid()
        {
            return Illuminance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IlluminanceUnit unit)
        {
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return value;

            case IlluminanceUnit::Millilux:
                return (value * static_cast<un_scalar_t>(1e-3));

            case IlluminanceUnit::Kilolux:
                return (value * static_cast<un_scalar_t>(1e3));

            case IlluminanceUnit::Megalux:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IlluminanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return base_value;

            case IlluminanceUnit::Millilux:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case IlluminanceUnit::Kilolux:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case IlluminanceUnit::Megalux:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        un_scalar_t value_;
        IlluminanceUnit value_unit_type_;       
    };
}
