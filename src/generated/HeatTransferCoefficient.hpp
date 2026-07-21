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
    enum class HeatTransferCoefficientUnit : std::uint8_t
    {
        WattPerSquareMeterKelvin,
        WattPerSquareMeterCelsius,
        BtuPerHourSquareFootDegreeFahrenheit,
        BtuPerSecondSquareInchDegreeFahrenheit,
        CaloriePerHourSquareMeterDegreeCelsius,
        KilocaloriePerHourSquareMeterDegreeCelsius,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of HeatTransferCoefficient.</summary>
    class HeatTransferCoefficientDto
    {
    public:
        constexpr HeatTransferCoefficientDto() noexcept
            : value{}, unit(HeatTransferCoefficientUnit::WattPerSquareMeterKelvin)
        {
        }

        constexpr HeatTransferCoefficientDto(
            const un_scalar_t value,
            const HeatTransferCoefficientUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        HeatTransferCoefficientUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr HeatTransferCoefficientUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<HeatTransferCoefficientUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit name.");
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
        [[nodiscard]] static HeatTransferCoefficientDto from_json(const nlohmann::json& json)
        {
            return HeatTransferCoefficientDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The heat transfer coefficient or film coefficient, or film effectiveness, in thermodynamics and in mechanics is the proportionality constant between the heat flux and the thermodynamic driving force for the flow of heat (i.e., the temperature difference, ΔT)</summary>
    class HeatTransferCoefficient : public UnitsNetBase
    {
    public:
        constexpr explicit HeatTransferCoefficient(
            const un_scalar_t value,
            const HeatTransferCoefficientUnit unit = HeatTransferCoefficientUnit::WattPerSquareMeterKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const HeatTransferCoefficientUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr HeatTransferCoefficientDto to_dto(
            const HeatTransferCoefficientUnit unit = HeatTransferCoefficientUnit::WattPerSquareMeterKelvin) const
        {
            return HeatTransferCoefficientDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr HeatTransferCoefficient from_dto(const HeatTransferCoefficientDto& dto)
        {
            return HeatTransferCoefficient(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const HeatTransferCoefficientUnit unit = HeatTransferCoefficientUnit::WattPerSquareMeterKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static HeatTransferCoefficient from_json(const nlohmann::json& json)
        {
            return from_dto(HeatTransferCoefficientDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr HeatTransferCoefficient operator+(const HeatTransferCoefficient& other) const noexcept
        {
            return HeatTransferCoefficient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator-(const HeatTransferCoefficient& other)const noexcept
        {
            return HeatTransferCoefficient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator*(const un_scalar_t scalar) const noexcept
        {
            return HeatTransferCoefficient(base_value() * scalar);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator/(const un_scalar_t scalar) const noexcept
        {
            return HeatTransferCoefficient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter_kelvin() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattPerSquareMeterKelvin);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_kelvin(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattPerSquareMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattPerSquareMeterCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattPerSquareMeterCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_hour_square_foot_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtuPerHourSquareFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_hour_square_foot_degree_fahrenheit(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtuPerHourSquareFootDegreeFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_inch_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtuPerSecondSquareInchDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_second_square_inch_degree_fahrenheit(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtuPerSecondSquareInchDegreeFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::CaloriePerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_calories_per_hour_square_meter_degree_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::CaloriePerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::KilocaloriePerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_kilocalories_per_hour_square_meter_degree_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::KilocaloriePerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_invalid()
        {
            return HeatTransferCoefficient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, HeatTransferCoefficientUnit unit)
        {
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattPerSquareMeterKelvin:
                return value;

            case HeatTransferCoefficientUnit::WattPerSquareMeterCelsius:
                return value;

            case HeatTransferCoefficientUnit::BtuPerHourSquareFootDegreeFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::BtuPerSecondSquareInchDegreeFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::CaloriePerHourSquareMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(3600);

            case HeatTransferCoefficientUnit::KilocaloriePerHourSquareMeterDegreeCelsius:
                return ((value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const HeatTransferCoefficientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattPerSquareMeterKelvin:
                return base_value;

            case HeatTransferCoefficientUnit::WattPerSquareMeterCelsius:
                return base_value;

            case HeatTransferCoefficientUnit::BtuPerHourSquareFootDegreeFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::BtuPerSecondSquareInchDegreeFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::CaloriePerHourSquareMeterDegreeCelsius:
                return (base_value / static_cast<un_scalar_t>(4.184)) * static_cast<un_scalar_t>(3600);

            case HeatTransferCoefficientUnit::KilocaloriePerHourSquareMeterDegreeCelsius:
                return ((base_value / static_cast<un_scalar_t>(4.184)) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        un_scalar_t value_;
        HeatTransferCoefficientUnit value_unit_type_;       
    };
}
