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
    enum class MagneticFluxUnit : std::uint8_t
    {
        Weber,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MagneticFlux.</summary>
    class MagneticFluxDto
    {
    public:
        constexpr MagneticFluxDto() noexcept
            : value{}, unit(MagneticFluxUnit::Weber)
        {
        }

        constexpr MagneticFluxDto(
            const un_scalar_t value,
            const MagneticFluxUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MagneticFluxUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MagneticFluxUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MagneticFluxUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MagneticFlux unit name.");
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
        [[nodiscard]] static MagneticFluxDto from_json(const nlohmann::json& json)
        {
            return MagneticFluxDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In physics, specifically electromagnetism, the magnetic flux through a surface is the surface integral of the normal component of the magnetic field B passing through that surface.</summary>
    class MagneticFlux : public UnitsNetBase
    {
    public:
        constexpr explicit MagneticFlux(
            const un_scalar_t value,
            const MagneticFluxUnit unit = MagneticFluxUnit::Weber)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MagneticFluxDto to_dto(
            const MagneticFluxUnit unit = MagneticFluxUnit::Weber) const
        {
            return MagneticFluxDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MagneticFlux from_dto(const MagneticFluxDto& dto)
        {
            return MagneticFlux(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MagneticFluxUnit unit = MagneticFluxUnit::Weber) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MagneticFlux from_json(const nlohmann::json& json)
        {
            return from_dto(MagneticFluxDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MagneticFlux operator+(const MagneticFlux& other) const noexcept
        {
            return MagneticFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MagneticFlux operator-(const MagneticFlux& other)const noexcept
        {
            return MagneticFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MagneticFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr MagneticFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MagneticFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MagneticFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t webers() const
        {
            return convert_from_base(MagneticFluxUnit::Weber);
        }

        [[nodiscard]] static constexpr MagneticFlux from_webers(const un_scalar_t value)
        {
            return MagneticFlux(value, MagneticFluxUnit::Weber);
        }

        [[nodiscard]] static constexpr MagneticFlux from_invalid()
        {
            return MagneticFlux(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagneticFluxUnit unit)
        {
            switch (unit)
            {

            case MagneticFluxUnit::Weber:
                return value;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagneticFluxUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MagneticFluxUnit::Weber:
                return base_value;

            }

            throw std::invalid_argument("Unknown MagneticFlux unit.");
        }

        un_scalar_t value_;
        MagneticFluxUnit value_unit_type_;       
    };
}
