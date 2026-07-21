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
    enum class LevelUnit : std::uint8_t
    {
        Decibel,
        Neper,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Level.</summary>
    class LevelDto
    {
    public:
        constexpr LevelDto() noexcept
            : value{}, unit(LevelUnit::Decibel)
        {
        }

        constexpr LevelDto(
            const un_scalar_t value,
            const LevelUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LevelUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LevelUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LevelUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Level unit name.");
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
        [[nodiscard]] static LevelDto from_json(const nlohmann::json& json)
        {
            return LevelDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Level is the logarithm of the ratio of a quantity Q to a reference value of that quantity, Q₀, expressed in dimensionless units.</summary>
    class Level : public UnitsNetBase
    {
    public:
        constexpr explicit Level(
            const un_scalar_t value,
            const LevelUnit unit = LevelUnit::Decibel)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LevelUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LevelDto to_dto(
            const LevelUnit unit = LevelUnit::Decibel) const
        {
            return LevelDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Level from_dto(const LevelDto& dto)
        {
            return Level(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LevelUnit unit = LevelUnit::Decibel) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Level from_json(const nlohmann::json& json)
        {
            return from_dto(LevelDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Level operator+(const Level& other) const noexcept
        {
            return Level(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Level operator-(const Level& other)const noexcept
        {
            return Level(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Level operator*(const un_scalar_t scalar) const noexcept
        {
            return Level(base_value() * scalar);
        }

        [[nodiscard]] constexpr Level operator/(const un_scalar_t scalar) const noexcept
        {
            return Level(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Level& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Level& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Level& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decibels() const
        {
            return convert_from_base(LevelUnit::Decibel);
        }

        [[nodiscard]] static constexpr Level from_decibels(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Decibel);
        }

        [[nodiscard]] constexpr un_scalar_t nepers() const
        {
            return convert_from_base(LevelUnit::Neper);
        }

        [[nodiscard]] static constexpr Level from_nepers(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Neper);
        }

        [[nodiscard]] static constexpr Level from_invalid()
        {
            return Level(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LevelUnit unit)
        {
            switch (unit)
            {

            case LevelUnit::Decibel:
                return value;

            case LevelUnit::Neper:
                return (static_cast<un_scalar_t>(1) / static_cast<un_scalar_t>(0.115129254)) * value;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LevelUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LevelUnit::Decibel:
                return base_value;

            case LevelUnit::Neper:
                return static_cast<un_scalar_t>(0.115129254) * base_value;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        un_scalar_t value_;
        LevelUnit value_unit_type_;       
    };
}
