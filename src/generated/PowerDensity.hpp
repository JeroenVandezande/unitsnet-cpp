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
    enum class PowerDensityUnit : std::uint8_t
    {
        WattPerCubicMeter,
        PicowattPerCubicMeter,
        NanowattPerCubicMeter,
        MicrowattPerCubicMeter,
        MilliwattPerCubicMeter,
        DeciwattPerCubicMeter,
        DecawattPerCubicMeter,
        KilowattPerCubicMeter,
        MegawattPerCubicMeter,
        GigawattPerCubicMeter,
        TerawattPerCubicMeter,
        WattPerCubicInch,
        PicowattPerCubicInch,
        NanowattPerCubicInch,
        MicrowattPerCubicInch,
        MilliwattPerCubicInch,
        DeciwattPerCubicInch,
        DecawattPerCubicInch,
        KilowattPerCubicInch,
        MegawattPerCubicInch,
        GigawattPerCubicInch,
        TerawattPerCubicInch,
        WattPerCubicFoot,
        PicowattPerCubicFoot,
        NanowattPerCubicFoot,
        MicrowattPerCubicFoot,
        MilliwattPerCubicFoot,
        DeciwattPerCubicFoot,
        DecawattPerCubicFoot,
        KilowattPerCubicFoot,
        MegawattPerCubicFoot,
        GigawattPerCubicFoot,
        TerawattPerCubicFoot,
        WattPerLiter,
        PicowattPerLiter,
        NanowattPerLiter,
        MicrowattPerLiter,
        MilliwattPerLiter,
        DeciwattPerLiter,
        DecawattPerLiter,
        KilowattPerLiter,
        MegawattPerLiter,
        GigawattPerLiter,
        TerawattPerLiter,
        BtuPerSecondCubicInch,
        BtuPerSecondCubicFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of PowerDensity.</summary>
    class PowerDensityDto
    {
    public:
        constexpr PowerDensityDto() noexcept
            : value{}, unit(PowerDensityUnit::WattPerCubicMeter)
        {
        }

        constexpr PowerDensityDto(
            const un_scalar_t value,
            const PowerDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PowerDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PowerDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PowerDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown PowerDensity unit name.");
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
        [[nodiscard]] static PowerDensityDto from_json(const nlohmann::json& json)
        {
            return PowerDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The amount of power in a volume.</summary>
    class PowerDensity : public UnitsNetBase
    {
    public:
        constexpr explicit PowerDensity(
            const un_scalar_t value,
            const PowerDensityUnit unit = PowerDensityUnit::WattPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PowerDensityDto to_dto(
            const PowerDensityUnit unit = PowerDensityUnit::WattPerCubicMeter) const
        {
            return PowerDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr PowerDensity from_dto(const PowerDensityDto& dto)
        {
            return PowerDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PowerDensityUnit unit = PowerDensityUnit::WattPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static PowerDensity from_json(const nlohmann::json& json)
        {
            return from_dto(PowerDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr PowerDensity operator+(const PowerDensity& other) const noexcept
        {
            return PowerDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PowerDensity operator-(const PowerDensity& other)const noexcept
        {
            return PowerDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PowerDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return PowerDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr PowerDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return PowerDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PowerDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PowerDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PowerDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::WattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::WattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::PicowattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::NanowattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DecawattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::KilowattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MegawattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::GigawattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::TerawattPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::WattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::PicowattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::NanowattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DecawattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::KilowattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MegawattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::GigawattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::TerawattPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::WattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::BtuPerSecondCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::BtuPerSecondCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::BtuPerSecondCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::BtuPerSecondCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_invalid()
        {
            return PowerDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerDensityUnit unit)
        {
            switch (unit)
            {

            case PowerDensityUnit::WattPerCubicMeter:
                return value;

            case PowerDensityUnit::PicowattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case PowerDensityUnit::NanowattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case PowerDensityUnit::MicrowattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PowerDensityUnit::MilliwattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PowerDensityUnit::DeciwattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case PowerDensityUnit::DecawattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e1));

            case PowerDensityUnit::KilowattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case PowerDensityUnit::MegawattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case PowerDensityUnit::GigawattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case PowerDensityUnit::TerawattPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12));

            case PowerDensityUnit::WattPerCubicInch:
                return value / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::PicowattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::NanowattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MicrowattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MilliwattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::DeciwattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::DecawattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::KilowattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MegawattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::GigawattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::TerawattPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e12)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::WattPerCubicFoot:
                return value / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::PicowattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::NanowattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MicrowattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MilliwattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::DeciwattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::DecawattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::KilowattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MegawattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::GigawattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::TerawattPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e12)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::WattPerLiter:
                return value * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::PicowattPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::NanowattPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MicrowattPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MilliwattPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::DeciwattPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::DecawattPerLiter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::KilowattPerLiter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MegawattPerLiter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::GigawattPerLiter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::TerawattPerLiter:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::BtuPerSecondCubicInch:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case PowerDensityUnit::BtuPerSecondCubicFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PowerDensityUnit::WattPerCubicMeter:
                return base_value;

            case PowerDensityUnit::PicowattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattPerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::PicowattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattPerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::PicowattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattPerLiter:
                return base_value / static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::PicowattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattPerLiter:
                return (base_value / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::BtuPerSecondCubicInch:
                return base_value / static_cast<un_scalar_t>(1055.05585262) * (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case PowerDensityUnit::BtuPerSecondCubicFoot:
                return base_value / static_cast<un_scalar_t>(1055.05585262) * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        un_scalar_t value_;
        PowerDensityUnit value_unit_type_;       
    };
}
