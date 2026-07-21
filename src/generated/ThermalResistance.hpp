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
    enum class ThermalResistanceUnit : std::uint8_t
    {
        KelvinPerWatt,
        DegreeCelsiusPerWatt,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ThermalResistance.</summary>
    class ThermalResistanceDto
    {
    public:
        constexpr ThermalResistanceDto() noexcept
            : value{}, unit(ThermalResistanceUnit::KelvinPerWatt)
        {
        }

        constexpr ThermalResistanceDto(
            const un_scalar_t value,
            const ThermalResistanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ThermalResistanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ThermalResistanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ThermalResistanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ThermalResistance unit name.");
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
        [[nodiscard]] static ThermalResistanceDto from_json(const nlohmann::json& json)
        {
            return ThermalResistanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Thermal resistance (R) measures the opposition to the heat current in a material or system. It is measured in units of kelvins per watt (K/W) and indicates how much temperature difference (in kelvins) is required to transfer a unit of heat current (in watts) through the material or object. It is essential to optimize the building insulation, evaluate the efficiency of electronic devices, and enhance the performance of heat sinks in various applications.</summary>
    class ThermalResistance : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalResistance(
            const un_scalar_t value,
            const ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinPerWatt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ThermalResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ThermalResistanceDto to_dto(
            const ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinPerWatt) const
        {
            return ThermalResistanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ThermalResistance from_dto(const ThermalResistanceDto& dto)
        {
            return ThermalResistance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinPerWatt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ThermalResistance from_json(const nlohmann::json& json)
        {
            return from_dto(ThermalResistanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ThermalResistance operator+(const ThermalResistance& other) const noexcept
        {
            return ThermalResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalResistance operator-(const ThermalResistance& other)const noexcept
        {
            return ThermalResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::KelvinPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::KelvinPerWatt);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::DegreeCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_degrees_celsius_per_watt(const un_scalar_t value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::DegreeCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_invalid()
        {
            return ThermalResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalResistanceUnit unit)
        {
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinPerWatt:
                return value;

            case ThermalResistanceUnit::DegreeCelsiusPerWatt:
                return value;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinPerWatt:
                return base_value;

            case ThermalResistanceUnit::DegreeCelsiusPerWatt:
                return base_value;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        un_scalar_t value_;
        ThermalResistanceUnit value_unit_type_;       
    };
}
