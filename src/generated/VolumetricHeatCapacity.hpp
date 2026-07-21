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
    enum class VolumetricHeatCapacityUnit : std::uint8_t
    {
        JoulePerCubicMeterKelvin,
        KilojoulePerCubicMeterKelvin,
        MegajoulePerCubicMeterKelvin,
        JoulePerCubicMeterDegreeCelsius,
        KilojoulePerCubicMeterDegreeCelsius,
        MegajoulePerCubicMeterDegreeCelsius,
        CaloriePerCubicCentimeterDegreeCelsius,
        KilocaloriePerCubicCentimeterDegreeCelsius,
        BtuPerCubicFootDegreeFahrenheit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VolumetricHeatCapacity.</summary>
    class VolumetricHeatCapacityDto
    {
    public:
        constexpr VolumetricHeatCapacityDto() noexcept
            : value{}, unit(VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin)
        {
        }

        constexpr VolumetricHeatCapacityDto(
            const un_scalar_t value,
            const VolumetricHeatCapacityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumetricHeatCapacityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumetricHeatCapacityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumetricHeatCapacityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit name.");
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
        [[nodiscard]] static VolumetricHeatCapacityDto from_json(const nlohmann::json& json)
        {
            return VolumetricHeatCapacityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The volumetric heat capacity is the amount of energy that must be added, in the form of heat, to one unit of volume of the material in order to cause an increase of one unit in its temperature.</summary>
    class VolumetricHeatCapacity : public UnitsNetBase
    {
    public:
        constexpr explicit VolumetricHeatCapacity(
            const un_scalar_t value,
            const VolumetricHeatCapacityUnit unit = VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumetricHeatCapacityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumetricHeatCapacityDto to_dto(
            const VolumetricHeatCapacityUnit unit = VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin) const
        {
            return VolumetricHeatCapacityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VolumetricHeatCapacity from_dto(const VolumetricHeatCapacityDto& dto)
        {
            return VolumetricHeatCapacity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumetricHeatCapacityUnit unit = VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VolumetricHeatCapacity from_json(const nlohmann::json& json)
        {
            return from_dto(VolumetricHeatCapacityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VolumetricHeatCapacity operator+(const VolumetricHeatCapacity& other) const noexcept
        {
            return VolumetricHeatCapacity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator-(const VolumetricHeatCapacity& other)const noexcept
        {
            return VolumetricHeatCapacity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumetricHeatCapacity(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumetricHeatCapacity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumetricHeatCapacity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumetricHeatCapacity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumetricHeatCapacity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulePerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulePerCubicMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulePerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulePerCubicMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulePerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::CaloriePerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_calories_per_cubic_centimeter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::CaloriePerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilocaloriePerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilocalories_per_cubic_centimeter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilocaloriePerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_cubic_foot_degree_fahrenheit() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::BtuPerCubicFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_btus_per_cubic_foot_degree_fahrenheit(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::BtuPerCubicFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_invalid()
        {
            return VolumetricHeatCapacity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumetricHeatCapacityUnit unit)
        {
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulePerCubicMeterKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumetricHeatCapacityUnit::MegajoulePerCubicMeterKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case VolumetricHeatCapacityUnit::JoulePerCubicMeterDegreeCelsius:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulePerCubicMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumetricHeatCapacityUnit::MegajoulePerCubicMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e6));

            case VolumetricHeatCapacityUnit::CaloriePerCubicCentimeterDegreeCelsius:
                return value * static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::KilocaloriePerCubicCentimeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::BtuPerCubicFootDegreeFahrenheit:
                return value * (static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.028316846592)) * static_cast<un_scalar_t>(1.8);

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumetricHeatCapacityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulePerCubicMeterKelvin:
                return base_value;

            case VolumetricHeatCapacityUnit::KilojoulePerCubicMeterKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::MegajoulePerCubicMeterKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case VolumetricHeatCapacityUnit::JoulePerCubicMeterDegreeCelsius:
                return base_value;

            case VolumetricHeatCapacityUnit::KilojoulePerCubicMeterDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::MegajoulePerCubicMeterDegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case VolumetricHeatCapacityUnit::CaloriePerCubicCentimeterDegreeCelsius:
                return base_value / static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::KilocaloriePerCubicCentimeterDegreeCelsius:
                return (base_value / static_cast<un_scalar_t>(4.184e6)) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::BtuPerCubicFootDegreeFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.028316846592)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        un_scalar_t value_;
        VolumetricHeatCapacityUnit value_unit_type_;       
    };
}
