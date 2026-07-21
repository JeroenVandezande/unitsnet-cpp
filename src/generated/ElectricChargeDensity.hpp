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
    enum class ElectricChargeDensityUnit : std::uint8_t
    {
        CoulombPerCubicMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricChargeDensity.</summary>
    class ElectricChargeDensityDto
    {
    public:
        constexpr ElectricChargeDensityDto() noexcept
            : value{}, unit(ElectricChargeDensityUnit::CoulombPerCubicMeter)
        {
        }

        constexpr ElectricChargeDensityDto(
            const un_scalar_t value,
            const ElectricChargeDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricChargeDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricChargeDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricChargeDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit name.");
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
        [[nodiscard]] static ElectricChargeDensityDto from_json(const nlohmann::json& json)
        {
            return ElectricChargeDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, charge density is a measure of the amount of electric charge per volume.</summary>
    class ElectricChargeDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricChargeDensity(
            const un_scalar_t value,
            const ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricChargeDensityDto to_dto(
            const ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombPerCubicMeter) const
        {
            return ElectricChargeDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricChargeDensity from_dto(const ElectricChargeDensityDto& dto)
        {
            return ElectricChargeDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricChargeDensity from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricChargeDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricChargeDensity operator+(const ElectricChargeDensity& other) const noexcept
        {
            return ElectricChargeDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator-(const ElectricChargeDensity& other)const noexcept
        {
            return ElectricChargeDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_cubic_meter() const
        {
            return convert_from_base(ElectricChargeDensityUnit::CoulombPerCubicMeter);
        }

        [[nodiscard]] static constexpr ElectricChargeDensity from_coulombs_per_cubic_meter(const un_scalar_t value)
        {
            return ElectricChargeDensity(value, ElectricChargeDensityUnit::CoulombPerCubicMeter);
        }

        [[nodiscard]] static constexpr ElectricChargeDensity from_invalid()
        {
            return ElectricChargeDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombPerCubicMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricChargeDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombPerCubicMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        un_scalar_t value_;
        ElectricChargeDensityUnit value_unit_type_;       
    };
}
