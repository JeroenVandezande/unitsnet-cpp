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
    enum class SolidAngleUnit : std::uint8_t
    {
        Steradian,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SolidAngle.</summary>
    class SolidAngleDto
    {
    public:
        constexpr SolidAngleDto() noexcept
            : value{}, unit(SolidAngleUnit::Steradian)
        {
        }

        constexpr SolidAngleDto(
            const un_scalar_t value,
            const SolidAngleUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SolidAngleUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SolidAngleUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SolidAngleUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SolidAngle unit name.");
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
        [[nodiscard]] static SolidAngleDto from_json(const nlohmann::json& json)
        {
            return SolidAngleDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In geometry, a solid angle is the two-dimensional angle in three-dimensional space that an object subtends at a point.</summary>
    class SolidAngle : public UnitsNetBase
    {
    public:
        constexpr explicit SolidAngle(
            const un_scalar_t value,
            const SolidAngleUnit unit = SolidAngleUnit::Steradian)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SolidAngleUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SolidAngleDto to_dto(
            const SolidAngleUnit unit = SolidAngleUnit::Steradian) const
        {
            return SolidAngleDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SolidAngle from_dto(const SolidAngleDto& dto)
        {
            return SolidAngle(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SolidAngleUnit unit = SolidAngleUnit::Steradian) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SolidAngle from_json(const nlohmann::json& json)
        {
            return from_dto(SolidAngleDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr SolidAngle operator+(const SolidAngle& other) const noexcept
        {
            return SolidAngle(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SolidAngle operator-(const SolidAngle& other)const noexcept
        {
            return SolidAngle(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SolidAngle operator*(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(base_value() * scalar);
        }

        [[nodiscard]] constexpr SolidAngle operator/(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SolidAngle& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SolidAngle& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SolidAngle& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t steradians() const
        {
            return convert_from_base(SolidAngleUnit::Steradian);
        }

        [[nodiscard]] static constexpr SolidAngle from_steradians(const un_scalar_t value)
        {
            return SolidAngle(value, SolidAngleUnit::Steradian);
        }

        [[nodiscard]] static constexpr SolidAngle from_invalid()
        {
            return SolidAngle(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SolidAngleUnit unit)
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradian:
                return value;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SolidAngleUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SolidAngleUnit::Steradian:
                return base_value;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        un_scalar_t value_;
        SolidAngleUnit value_unit_type_;       
    };
}
