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
    enum class RotationalAccelerationUnit : std::uint8_t
    {
        RadianPerSecondSquared,
        DegreePerSecondSquared,
        RevolutionPerMinutePerSecond,
        RevolutionPerSecondSquared,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RotationalAcceleration.</summary>
    class RotationalAccelerationDto
    {
    public:
        constexpr RotationalAccelerationDto() noexcept
            : value{}, unit(RotationalAccelerationUnit::RadianPerSecondSquared)
        {
        }

        constexpr RotationalAccelerationDto(
            const un_scalar_t value,
            const RotationalAccelerationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RotationalAccelerationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RotationalAccelerationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RotationalAccelerationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit name.");
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
        [[nodiscard]] static RotationalAccelerationDto from_json(const nlohmann::json& json)
        {
            return RotationalAccelerationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Angular acceleration is the rate of change of rotational speed.</summary>
    class RotationalAcceleration : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalAcceleration(
            const un_scalar_t value,
            const RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadianPerSecondSquared)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalAccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RotationalAccelerationDto to_dto(
            const RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadianPerSecondSquared) const
        {
            return RotationalAccelerationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RotationalAcceleration from_dto(const RotationalAccelerationDto& dto)
        {
            return RotationalAcceleration(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadianPerSecondSquared) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RotationalAcceleration from_json(const nlohmann::json& json)
        {
            return from_dto(RotationalAccelerationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RotationalAcceleration operator+(const RotationalAcceleration& other) const noexcept
        {
            return RotationalAcceleration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalAcceleration operator-(const RotationalAcceleration& other)const noexcept
        {
            return RotationalAcceleration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalAcceleration operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalAcceleration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalAcceleration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalAcceleration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t radians_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RadianPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_radians_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RadianPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::DegreePerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_degrees_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::DegreePerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_minute_per_second() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionPerMinutePerSecond);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_minute_per_second(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionPerMinutePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_invalid()
        {
            return RotationalAcceleration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalAccelerationUnit unit)
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadianPerSecondSquared:
                return value;

            case RotationalAccelerationUnit::DegreePerSecondSquared:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * value;

            case RotationalAccelerationUnit::RevolutionPerMinutePerSecond:
                return ((static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(60)) * value;

            case RotationalAccelerationUnit::RevolutionPerSecondSquared:
                return (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) * value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalAccelerationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalAccelerationUnit::RadianPerSecondSquared:
                return base_value;

            case RotationalAccelerationUnit::DegreePerSecondSquared:
                return (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value;

            case RotationalAccelerationUnit::RevolutionPerMinutePerSecond:
                return (static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * base_value;

            case RotationalAccelerationUnit::RevolutionPerSecondSquared:
                return (static_cast<un_scalar_t>(1) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * base_value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        un_scalar_t value_;
        RotationalAccelerationUnit value_unit_type_;       
    };
}
