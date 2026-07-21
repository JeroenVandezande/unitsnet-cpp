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
    enum class ThermalConductivityUnit : std::uint8_t
    {
        WattPerMeterKelvin,
        BtuPerHourFootFahrenheit,
        BtuPerSecondInchFahrenheit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ThermalConductivity.</summary>
    class ThermalConductivityDto
    {
    public:
        constexpr ThermalConductivityDto() noexcept
            : value{}, unit(ThermalConductivityUnit::WattPerMeterKelvin)
        {
        }

        constexpr ThermalConductivityDto(
            const un_scalar_t value,
            const ThermalConductivityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ThermalConductivityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ThermalConductivityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ThermalConductivityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ThermalConductivity unit name.");
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
        [[nodiscard]] static ThermalConductivityDto from_json(const nlohmann::json& json)
        {
            return ThermalConductivityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Thermal conductivity is the property of a material to conduct heat.</summary>
    class ThermalConductivity : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalConductivity(
            const un_scalar_t value,
            const ThermalConductivityUnit unit = ThermalConductivityUnit::WattPerMeterKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ThermalConductivityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ThermalConductivityDto to_dto(
            const ThermalConductivityUnit unit = ThermalConductivityUnit::WattPerMeterKelvin) const
        {
            return ThermalConductivityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ThermalConductivity from_dto(const ThermalConductivityDto& dto)
        {
            return ThermalConductivity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ThermalConductivityUnit unit = ThermalConductivityUnit::WattPerMeterKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ThermalConductivity from_json(const nlohmann::json& json)
        {
            return from_dto(ThermalConductivityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ThermalConductivity operator+(const ThermalConductivity& other) const noexcept
        {
            return ThermalConductivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalConductivity operator-(const ThermalConductivity& other)const noexcept
        {
            return ThermalConductivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalConductivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalConductivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalConductivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalConductivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalConductivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalConductivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalConductivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_meter_kelvin() const
        {
            return convert_from_base(ThermalConductivityUnit::WattPerMeterKelvin);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_watts_per_meter_kelvin(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::WattPerMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_hour_foot_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtuPerHourFootFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_hour_foot_fahrenheit(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtuPerHourFootFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_inch_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtuPerSecondInchFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_second_inch_fahrenheit(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtuPerSecondInchFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_invalid()
        {
            return ThermalConductivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalConductivityUnit unit)
        {
            switch (unit)
            {

            case ThermalConductivityUnit::WattPerMeterKelvin:
                return value;

            case ThermalConductivityUnit::BtuPerHourFootFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case ThermalConductivityUnit::BtuPerSecondInchFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalConductivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ThermalConductivityUnit::WattPerMeterKelvin:
                return base_value;

            case ThermalConductivityUnit::BtuPerHourFootFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case ThermalConductivityUnit::BtuPerSecondInchFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        un_scalar_t value_;
        ThermalConductivityUnit value_unit_type_;       
    };
}
