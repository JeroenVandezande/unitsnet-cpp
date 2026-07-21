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
    enum class PermittivityUnit : std::uint8_t
    {
        FaradPerMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Permittivity.</summary>
    class PermittivityDto
    {
    public:
        constexpr PermittivityDto() noexcept
            : value{}, unit(PermittivityUnit::FaradPerMeter)
        {
        }

        constexpr PermittivityDto(
            const un_scalar_t value,
            const PermittivityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PermittivityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PermittivityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PermittivityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Permittivity unit name.");
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
        [[nodiscard]] static PermittivityDto from_json(const nlohmann::json& json)
        {
            return PermittivityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, permittivity is the measure of resistance that is encountered when forming an electric field in a particular medium.</summary>
    class Permittivity : public UnitsNetBase
    {
    public:
        constexpr explicit Permittivity(
            const un_scalar_t value,
            const PermittivityUnit unit = PermittivityUnit::FaradPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PermittivityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PermittivityDto to_dto(
            const PermittivityUnit unit = PermittivityUnit::FaradPerMeter) const
        {
            return PermittivityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Permittivity from_dto(const PermittivityDto& dto)
        {
            return Permittivity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PermittivityUnit unit = PermittivityUnit::FaradPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Permittivity from_json(const nlohmann::json& json)
        {
            return from_dto(PermittivityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Permittivity operator+(const Permittivity& other) const noexcept
        {
            return Permittivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Permittivity operator-(const Permittivity& other)const noexcept
        {
            return Permittivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Permittivity operator*(const un_scalar_t scalar) const noexcept
        {
            return Permittivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Permittivity operator/(const un_scalar_t scalar) const noexcept
        {
            return Permittivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Permittivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Permittivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Permittivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t farads_per_meter() const
        {
            return convert_from_base(PermittivityUnit::FaradPerMeter);
        }

        [[nodiscard]] static constexpr Permittivity from_farads_per_meter(const un_scalar_t value)
        {
            return Permittivity(value, PermittivityUnit::FaradPerMeter);
        }

        [[nodiscard]] static constexpr Permittivity from_invalid()
        {
            return Permittivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PermittivityUnit unit)
        {
            switch (unit)
            {

            case PermittivityUnit::FaradPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PermittivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PermittivityUnit::FaradPerMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        un_scalar_t value_;
        PermittivityUnit value_unit_type_;       
    };
}
