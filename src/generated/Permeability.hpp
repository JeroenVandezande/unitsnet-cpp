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
    enum class PermeabilityUnit : std::uint8_t
    {
        HenryPerMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Permeability.</summary>
    class PermeabilityDto
    {
    public:
        constexpr PermeabilityDto() noexcept
            : value{}, unit(PermeabilityUnit::HenryPerMeter)
        {
        }

        constexpr PermeabilityDto(
            const un_scalar_t value,
            const PermeabilityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PermeabilityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PermeabilityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PermeabilityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Permeability unit name.");
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
        [[nodiscard]] static PermeabilityDto from_json(const nlohmann::json& json)
        {
            return PermeabilityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, permeability is the measure of the ability of a material to support the formation of a magnetic field within itself.</summary>
    class Permeability : public UnitsNetBase
    {
    public:
        constexpr explicit Permeability(
            const un_scalar_t value,
            const PermeabilityUnit unit = PermeabilityUnit::HenryPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PermeabilityDto to_dto(
            const PermeabilityUnit unit = PermeabilityUnit::HenryPerMeter) const
        {
            return PermeabilityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Permeability from_dto(const PermeabilityDto& dto)
        {
            return Permeability(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PermeabilityUnit unit = PermeabilityUnit::HenryPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Permeability from_json(const nlohmann::json& json)
        {
            return from_dto(PermeabilityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Permeability operator+(const Permeability& other) const noexcept
        {
            return Permeability(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Permeability operator-(const Permeability& other)const noexcept
        {
            return Permeability(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Permeability operator*(const un_scalar_t scalar) const noexcept
        {
            return Permeability(base_value() * scalar);
        }

        [[nodiscard]] constexpr Permeability operator/(const un_scalar_t scalar) const noexcept
        {
            return Permeability(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Permeability& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Permeability& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Permeability& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t henries_per_meter() const
        {
            return convert_from_base(PermeabilityUnit::HenryPerMeter);
        }

        [[nodiscard]] static constexpr Permeability from_henries_per_meter(const un_scalar_t value)
        {
            return Permeability(value, PermeabilityUnit::HenryPerMeter);
        }

        [[nodiscard]] static constexpr Permeability from_invalid()
        {
            return Permeability(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PermeabilityUnit unit)
        {
            switch (unit)
            {

            case PermeabilityUnit::HenryPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PermeabilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PermeabilityUnit::HenryPerMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        un_scalar_t value_;
        PermeabilityUnit value_unit_type_;       
    };
}
