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
    enum class ElectricFieldUnit : std::uint8_t
    {
        VoltPerMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricField.</summary>
    class ElectricFieldDto
    {
    public:
        constexpr ElectricFieldDto() noexcept
            : value{}, unit(ElectricFieldUnit::VoltPerMeter)
        {
        }

        constexpr ElectricFieldDto(
            const un_scalar_t value,
            const ElectricFieldUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricFieldUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricFieldUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricFieldUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricField unit name.");
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
        [[nodiscard]] static ElectricFieldDto from_json(const nlohmann::json& json)
        {
            return ElectricFieldDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>An electric field is a force field that surrounds electric charges that attracts or repels other electric charges.</summary>
    class ElectricField : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricField(
            const un_scalar_t value,
            const ElectricFieldUnit unit = ElectricFieldUnit::VoltPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricFieldDto to_dto(
            const ElectricFieldUnit unit = ElectricFieldUnit::VoltPerMeter) const
        {
            return ElectricFieldDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricField from_dto(const ElectricFieldDto& dto)
        {
            return ElectricField(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricFieldUnit unit = ElectricFieldUnit::VoltPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricField from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricFieldDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricField operator+(const ElectricField& other) const noexcept
        {
            return ElectricField(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricField operator-(const ElectricField& other)const noexcept
        {
            return ElectricField(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricField operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricField operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricField& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricField& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricField& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_meter() const
        {
            return convert_from_base(ElectricFieldUnit::VoltPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_volts_per_meter(const un_scalar_t value)
        {
            return ElectricField(value, ElectricFieldUnit::VoltPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_invalid()
        {
            return ElectricField(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricFieldUnit unit)
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricFieldUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricFieldUnit::VoltPerMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        un_scalar_t value_;
        ElectricFieldUnit value_unit_type_;       
    };
}
