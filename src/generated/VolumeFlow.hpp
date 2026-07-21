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
    enum class VolumeFlowUnit : std::uint8_t
    {
        CubicMeterPerSecond,
        CubicMeterPerMinute,
        CubicMeterPerHour,
        CubicMeterPerDay,
        CubicFootPerSecond,
        CubicFootPerMinute,
        CubicFootPerHour,
        CubicYardPerSecond,
        CubicYardPerMinute,
        CubicYardPerHour,
        CubicYardPerDay,
        MillionUsGallonPerDay,
        UsGallonPerDay,
        MegausGallonPerDay,
        LiterPerSecond,
        NanoliterPerSecond,
        MicroliterPerSecond,
        MilliliterPerSecond,
        CentiliterPerSecond,
        DeciliterPerSecond,
        DecaliterPerSecond,
        HectoliterPerSecond,
        KiloliterPerSecond,
        MegaliterPerSecond,
        LiterPerMinute,
        NanoliterPerMinute,
        MicroliterPerMinute,
        MilliliterPerMinute,
        CentiliterPerMinute,
        DeciliterPerMinute,
        DecaliterPerMinute,
        HectoliterPerMinute,
        KiloliterPerMinute,
        MegaliterPerMinute,
        LiterPerHour,
        NanoliterPerHour,
        MicroliterPerHour,
        MilliliterPerHour,
        CentiliterPerHour,
        DeciliterPerHour,
        DecaliterPerHour,
        HectoliterPerHour,
        KiloliterPerHour,
        MegaliterPerHour,
        LiterPerDay,
        NanoliterPerDay,
        MicroliterPerDay,
        MilliliterPerDay,
        CentiliterPerDay,
        DeciliterPerDay,
        DecaliterPerDay,
        HectoliterPerDay,
        KiloliterPerDay,
        MegaliterPerDay,
        UsGallonPerSecond,
        UsGallonPerMinute,
        UkGallonPerDay,
        MegaukGallonPerDay,
        UkGallonPerHour,
        UkGallonPerMinute,
        UkGallonPerSecond,
        MegaukGallonPerSecond,
        KilousGallonPerMinute,
        UsGallonPerHour,
        CubicDecimeterPerMinute,
        OilBarrelPerDay,
        OilBarrelPerMinute,
        OilBarrelPerHour,
        OilBarrelPerSecond,
        CubicMillimeterPerSecond,
        AcreFootPerSecond,
        AcreFootPerMinute,
        AcreFootPerHour,
        AcreFootPerDay,
        CubicCentimeterPerMinute,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VolumeFlow.</summary>
    class VolumeFlowDto
    {
    public:
        constexpr VolumeFlowDto() noexcept
            : value{}, unit(VolumeFlowUnit::CubicMeterPerSecond)
        {
        }

        constexpr VolumeFlowDto(
            const un_scalar_t value,
            const VolumeFlowUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumeFlowUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumeFlowUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumeFlowUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VolumeFlow unit name.");
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
        [[nodiscard]] static VolumeFlowDto from_json(const nlohmann::json& json)
        {
            return VolumeFlowDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In physics and engineering, in particular fluid dynamics and hydrometry, the volumetric flow rate, (also known as volume flow rate, rate of fluid flow or volume velocity) is the volume of fluid which passes through a given surface per unit time. The SI unit is m³/s (cubic meters per second). In US Customary Units and British Imperial Units, volumetric flow rate is often expressed as ft³/s (cubic feet per second). It is usually represented by the symbol Q.</summary>
    class VolumeFlow : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeFlow(
            const un_scalar_t value,
            const VolumeFlowUnit unit = VolumeFlowUnit::CubicMeterPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumeFlowDto to_dto(
            const VolumeFlowUnit unit = VolumeFlowUnit::CubicMeterPerSecond) const
        {
            return VolumeFlowDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VolumeFlow from_dto(const VolumeFlowDto& dto)
        {
            return VolumeFlow(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumeFlowUnit unit = VolumeFlowUnit::CubicMeterPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VolumeFlow from_json(const nlohmann::json& json)
        {
            return from_dto(VolumeFlowDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VolumeFlow operator+(const VolumeFlow& other) const noexcept
        {
            return VolumeFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlow operator-(const VolumeFlow& other)const noexcept
        {
            return VolumeFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMeterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMeterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMeterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMeterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMeterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_meters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMeterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFootPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFootPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFootPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicFootPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_feet_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicFootPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CubicYardPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_yards_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicYardPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t million_us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MillionUsGallonPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_million_us_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MillionUsGallonPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megaus_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegausGallonPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaus_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegausGallonPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::LiterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LiterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::NanoliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanoliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MicroliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicroliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MilliliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MilliliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CentiliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentiliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DeciliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DeciliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::DecaliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecaliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t hectoliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::HectoliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectoliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kiloliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::KiloliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KiloliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megaliters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegaliterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaliterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::LiterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LiterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::NanoliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanoliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MicroliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicroliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MilliliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MilliliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CentiliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentiliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DeciliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DeciliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t decaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::DecaliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecaliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t hectoliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::HectoliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectoliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kiloliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KiloliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KiloliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megaliters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::MegaliterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaliterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::LiterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LiterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::NanoliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanoliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MicroliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicroliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MilliliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MilliliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::CentiliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentiliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DeciliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DeciliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t decaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::DecaliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecaliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t hectoliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::HectoliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectoliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kiloliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::KiloliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KiloliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megaliters_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::MegaliterPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaliterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::LiterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_liters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::LiterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::NanoliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_nanoliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::NanoliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MicroliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_microliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MicroliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MilliliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_milliliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MilliliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::CentiliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_centiliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CentiliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DeciliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_deciliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DeciliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t decaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::DecaliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_decaliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::DecaliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t hectoliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::HectoliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_hectoliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::HectoliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t kiloliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::KiloliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kiloliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KiloliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megaliters_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegaliterPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megaliters_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaliterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megauk_gallons_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t uk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::UkGallonPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_uk_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UkGallonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megauk_gallons_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::MegaukGallonPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_megauk_gallons_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::MegaukGallonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilous_gallons_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::KilousGallonPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_kilous_gallons_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::KilousGallonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::UsGallonPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_us_gallons_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::UsGallonPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_decimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicDecimeterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_decimeters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicDecimeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::OilBarrelPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_oil_barrels_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::OilBarrelPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_millimeters_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::CubicMillimeterPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_millimeters_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicMillimeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t acre_feet_per_second() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFootPerSecond);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_second(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t acre_feet_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFootPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFootPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t acre_feet_per_hour() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFootPerHour);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_hour(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFootPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t acre_feet_per_day() const
        {
            return convert_from_base(VolumeFlowUnit::AcreFootPerDay);
        }

        [[nodiscard]] static constexpr VolumeFlow from_acre_feet_per_day(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::AcreFootPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_centimeters_per_minute() const
        {
            return convert_from_base(VolumeFlowUnit::CubicCentimeterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_cubic_centimeters_per_minute(const un_scalar_t value)
        {
            return VolumeFlow(value, VolumeFlowUnit::CubicCentimeterPerMinute);
        }

        [[nodiscard]] static constexpr VolumeFlow from_invalid()
        {
            return VolumeFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeFlowUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowUnit::CubicMeterPerSecond:
                return value;

            case VolumeFlowUnit::CubicMeterPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicMeterPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicMeterPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicFootPerSecond:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case VolumeFlowUnit::CubicFootPerMinute:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicFootPerHour:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicYardPerSecond:
                return value * static_cast<un_scalar_t>(0.764554857984);

            case VolumeFlowUnit::CubicYardPerMinute:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicYardPerHour:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicYardPerDay:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MillionUsGallonPerDay:
                return value * static_cast<un_scalar_t>(1e6) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::UsGallonPerDay:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MegausGallonPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::LiterPerSecond:
                return value / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::NanoliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MicroliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MilliliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::CentiliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::DeciliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::DecaliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::HectoliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::KiloliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::MegaliterPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::LiterPerMinute:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::NanoliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MicroliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MilliliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CentiliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::DeciliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::DecaliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::HectoliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::KiloliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::MegaliterPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::LiterPerHour:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::NanoliterPerHour:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MicroliterPerHour:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MilliliterPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CentiliterPerHour:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::DeciliterPerHour:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::DecaliterPerHour:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::HectoliterPerHour:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::KiloliterPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::MegaliterPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::LiterPerDay:
                return value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::NanoliterPerDay:
                return (value * static_cast<un_scalar_t>(1e-9)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MicroliterPerDay:
                return (value * static_cast<un_scalar_t>(1e-6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MilliliterPerDay:
                return (value * static_cast<un_scalar_t>(1e-3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::CentiliterPerDay:
                return (value * static_cast<un_scalar_t>(1e-2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::DeciliterPerDay:
                return (value * static_cast<un_scalar_t>(1e-1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::DecaliterPerDay:
                return (value * static_cast<un_scalar_t>(1e1)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::HectoliterPerDay:
                return (value * static_cast<un_scalar_t>(1e2)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::KiloliterPerDay:
                return (value * static_cast<un_scalar_t>(1e3)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegaliterPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::UsGallonPerSecond:
                return value * static_cast<un_scalar_t>(0.003785411784);

            case VolumeFlowUnit::UsGallonPerMinute:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UkGallonPerDay:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::MegaukGallonPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::UkGallonPerHour:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::UkGallonPerMinute:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UkGallonPerSecond:
                return value * static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::MegaukGallonPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::KilousGallonPerMinute:
                return value * static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::UsGallonPerHour:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicDecimeterPerMinute:
                return value / static_cast<un_scalar_t>(60000.00000);

            case VolumeFlowUnit::OilBarrelPerDay:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::OilBarrelPerMinute:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::OilBarrelPerHour:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::OilBarrelPerSecond:
                return value * static_cast<un_scalar_t>(0.158987294928);

            case VolumeFlowUnit::CubicMillimeterPerSecond:
                return value * static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::AcreFootPerSecond:
                return value * static_cast<un_scalar_t>(1233.48183754752);

            case VolumeFlowUnit::AcreFootPerMinute:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::AcreFootPerHour:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::AcreFootPerDay:
                return value * static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicCentimeterPerMinute:
                return value * static_cast<un_scalar_t>(1e-6) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeFlowUnit::CubicMeterPerSecond:
                return base_value;

            case VolumeFlowUnit::CubicMeterPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case VolumeFlowUnit::CubicMeterPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case VolumeFlowUnit::CubicMeterPerDay:
                return base_value * static_cast<un_scalar_t>(86400);

            case VolumeFlowUnit::CubicFootPerSecond:
                return base_value / static_cast<un_scalar_t>(0.028316846592);

            case VolumeFlowUnit::CubicFootPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CubicFootPerHour:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicYardPerSecond:
                return base_value / static_cast<un_scalar_t>(0.764554857984);

            case VolumeFlowUnit::CubicYardPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::CubicYardPerHour:
                return base_value / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicYardPerDay:
                return base_value / (static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MillionUsGallonPerDay:
                return base_value / (static_cast<un_scalar_t>(1e6) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::UsGallonPerDay:
                return base_value / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegausGallonPerDay:
                return (base_value / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LiterPerSecond:
                return base_value * static_cast<un_scalar_t>(1000);

            case VolumeFlowUnit::NanoliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicroliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MilliliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentiliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DeciliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecaliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectoliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KiloliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegaliterPerSecond:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LiterPerMinute:
                return base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::NanoliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicroliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MilliliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentiliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DeciliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecaliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectoliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KiloliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegaliterPerMinute:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(60))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LiterPerHour:
                return base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::NanoliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicroliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MilliliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentiliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DeciliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecaliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectoliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KiloliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegaliterPerHour:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(3600))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::LiterPerDay:
                return base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::NanoliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::MicroliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-6);

            case VolumeFlowUnit::MilliliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-3);

            case VolumeFlowUnit::CentiliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-2);

            case VolumeFlowUnit::DeciliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e-1);

            case VolumeFlowUnit::DecaliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e1);

            case VolumeFlowUnit::HectoliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e2);

            case VolumeFlowUnit::KiloliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e3);

            case VolumeFlowUnit::MegaliterPerDay:
                return (base_value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::UsGallonPerSecond:
                return base_value / static_cast<un_scalar_t>(0.003785411784);

            case VolumeFlowUnit::UsGallonPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UkGallonPerDay:
                return base_value / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::MegaukGallonPerDay:
                return (base_value / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(86400))) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::UkGallonPerHour:
                return base_value / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::UkGallonPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UkGallonPerSecond:
                return base_value / static_cast<un_scalar_t>(0.00454609);

            case VolumeFlowUnit::MegaukGallonPerSecond:
                return (base_value / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e6);

            case VolumeFlowUnit::KilousGallonPerMinute:
                return base_value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::UsGallonPerHour:
                return base_value / (static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::CubicDecimeterPerMinute:
                return base_value * static_cast<un_scalar_t>(60000.00000);

            case VolumeFlowUnit::OilBarrelPerDay:
                return base_value / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::OilBarrelPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::OilBarrelPerHour:
                return base_value / (static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::OilBarrelPerSecond:
                return base_value / static_cast<un_scalar_t>(0.158987294928);

            case VolumeFlowUnit::CubicMillimeterPerSecond:
                return base_value / static_cast<un_scalar_t>(1e-9);

            case VolumeFlowUnit::AcreFootPerSecond:
                return base_value / static_cast<un_scalar_t>(1233.48183754752);

            case VolumeFlowUnit::AcreFootPerMinute:
                return base_value / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(60));

            case VolumeFlowUnit::AcreFootPerHour:
                return base_value / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(3600));

            case VolumeFlowUnit::AcreFootPerDay:
                return base_value / (static_cast<un_scalar_t>(1233.48183754752) / static_cast<un_scalar_t>(86400));

            case VolumeFlowUnit::CubicCentimeterPerMinute:
                return base_value / (static_cast<un_scalar_t>(1e-6) / static_cast<un_scalar_t>(60));

            }

            throw std::invalid_argument("Unknown VolumeFlow unit.");
        }

        un_scalar_t value_;
        VolumeFlowUnit value_unit_type_;       
    };
}
