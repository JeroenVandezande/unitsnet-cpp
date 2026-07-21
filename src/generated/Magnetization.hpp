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
    enum class MagnetizationUnit : std::uint8_t
    {
        AmperePerMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Magnetization.</summary>
    class MagnetizationDto
    {
    public:
        constexpr MagnetizationDto() noexcept
            : value{}, unit(MagnetizationUnit::AmperePerMeter)
        {
        }

        constexpr MagnetizationDto(
            const un_scalar_t value,
            const MagnetizationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MagnetizationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MagnetizationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MagnetizationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Magnetization unit name.");
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
        [[nodiscard]] static MagnetizationDto from_json(const nlohmann::json& json)
        {
            return MagnetizationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In classical electromagnetism, magnetization is the vector field that expresses the density of permanent or induced magnetic dipole moments in a magnetic material.</summary>
    class Magnetization : public UnitsNetBase
    {
    public:
        constexpr explicit Magnetization(
            const un_scalar_t value,
            const MagnetizationUnit unit = MagnetizationUnit::AmperePerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagnetizationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MagnetizationDto to_dto(
            const MagnetizationUnit unit = MagnetizationUnit::AmperePerMeter) const
        {
            return MagnetizationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Magnetization from_dto(const MagnetizationDto& dto)
        {
            return Magnetization(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MagnetizationUnit unit = MagnetizationUnit::AmperePerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Magnetization from_json(const nlohmann::json& json)
        {
            return from_dto(MagnetizationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Magnetization operator+(const Magnetization& other) const noexcept
        {
            return Magnetization(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Magnetization operator-(const Magnetization& other)const noexcept
        {
            return Magnetization(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Magnetization operator*(const un_scalar_t scalar) const noexcept
        {
            return Magnetization(base_value() * scalar);
        }

        [[nodiscard]] constexpr Magnetization operator/(const un_scalar_t scalar) const noexcept
        {
            return Magnetization(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Magnetization& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Magnetization& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Magnetization& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_meter() const
        {
            return convert_from_base(MagnetizationUnit::AmperePerMeter);
        }

        [[nodiscard]] static constexpr Magnetization from_amperes_per_meter(const un_scalar_t value)
        {
            return Magnetization(value, MagnetizationUnit::AmperePerMeter);
        }

        [[nodiscard]] static constexpr Magnetization from_invalid()
        {
            return Magnetization(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagnetizationUnit unit)
        {
            switch (unit)
            {

            case MagnetizationUnit::AmperePerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagnetizationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MagnetizationUnit::AmperePerMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        un_scalar_t value_;
        MagnetizationUnit value_unit_type_;       
    };
}
