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
    enum class ForcePerLengthUnit : std::uint8_t
    {
        NewtonPerMeter,
        NanonewtonPerMeter,
        MicronewtonPerMeter,
        MillinewtonPerMeter,
        CentinewtonPerMeter,
        DecinewtonPerMeter,
        DecanewtonPerMeter,
        KilonewtonPerMeter,
        MeganewtonPerMeter,
        NewtonPerCentimeter,
        NanonewtonPerCentimeter,
        MicronewtonPerCentimeter,
        MillinewtonPerCentimeter,
        CentinewtonPerCentimeter,
        DecinewtonPerCentimeter,
        DecanewtonPerCentimeter,
        KilonewtonPerCentimeter,
        MeganewtonPerCentimeter,
        NewtonPerMillimeter,
        NanonewtonPerMillimeter,
        MicronewtonPerMillimeter,
        MillinewtonPerMillimeter,
        CentinewtonPerMillimeter,
        DecinewtonPerMillimeter,
        DecanewtonPerMillimeter,
        KilonewtonPerMillimeter,
        MeganewtonPerMillimeter,
        KilogramForcePerMeter,
        KilogramForcePerCentimeter,
        KilogramForcePerMillimeter,
        TonneForcePerMeter,
        TonneForcePerCentimeter,
        TonneForcePerMillimeter,
        PoundForcePerFoot,
        PoundForcePerInch,
        PoundForcePerYard,
        KilopoundForcePerFoot,
        KilopoundForcePerInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ForcePerLength.</summary>
    class ForcePerLengthDto
    {
    public:
        constexpr ForcePerLengthDto() noexcept
            : value{}, unit(ForcePerLengthUnit::NewtonPerMeter)
        {
        }

        constexpr ForcePerLengthDto(
            const un_scalar_t value,
            const ForcePerLengthUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ForcePerLengthUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ForcePerLengthUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ForcePerLengthUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ForcePerLength unit name.");
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
        [[nodiscard]] static ForcePerLengthDto from_json(const nlohmann::json& json)
        {
            return ForcePerLengthDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The magnitude of force per unit length.</summary>
    class ForcePerLength : public UnitsNetBase
    {
    public:
        constexpr explicit ForcePerLength(
            const un_scalar_t value,
            const ForcePerLengthUnit unit = ForcePerLengthUnit::NewtonPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ForcePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ForcePerLengthDto to_dto(
            const ForcePerLengthUnit unit = ForcePerLengthUnit::NewtonPerMeter) const
        {
            return ForcePerLengthDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ForcePerLength from_dto(const ForcePerLengthDto& dto)
        {
            return ForcePerLength(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ForcePerLengthUnit unit = ForcePerLengthUnit::NewtonPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ForcePerLength from_json(const nlohmann::json& json)
        {
            return from_dto(ForcePerLengthDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ForcePerLength operator+(const ForcePerLength& other) const noexcept
        {
            return ForcePerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ForcePerLength operator-(const ForcePerLength& other)const noexcept
        {
            return ForcePerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ForcePerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr ForcePerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ForcePerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ForcePerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ForcePerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramForcePerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramForcePerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramForcePerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonneForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonneForcePerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonneForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonneForcePerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonneForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonneForcePerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundForcePerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundForcePerInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_yard() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundForcePerYard);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_yard(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundForcePerYard);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundForcePerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_invalid()
        {
            return ForcePerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForcePerLengthUnit unit)
        {
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonPerMeter:
                return value;

            case ForcePerLengthUnit::NanonewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ForcePerLengthUnit::MicronewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForcePerLengthUnit::MillinewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForcePerLengthUnit::CentinewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ForcePerLengthUnit::DecinewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ForcePerLengthUnit::DecanewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForcePerLengthUnit::KilonewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForcePerLengthUnit::MeganewtonPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case ForcePerLengthUnit::NewtonPerCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NanonewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MicronewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MillinewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::CentinewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::DecinewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::DecanewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::KilonewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MeganewtonPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NewtonPerMillimeter:
                return value * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::NanonewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MicronewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MillinewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::CentinewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::DecinewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::DecanewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::KilonewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::KilogramForcePerMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForcePerLengthUnit::KilogramForcePerCentimeter:
                return value * static_cast<un_scalar_t>(980.665);

            case ForcePerLengthUnit::KilogramForcePerMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonneForcePerMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonneForcePerCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e5);

            case ForcePerLengthUnit::TonneForcePerMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case ForcePerLengthUnit::PoundForcePerFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.3048);

            case ForcePerLengthUnit::PoundForcePerInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(2.54e-2);

            case ForcePerLengthUnit::PoundForcePerYard:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.9144);

            case ForcePerLengthUnit::KilopoundForcePerFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.3048e-3);

            case ForcePerLengthUnit::KilopoundForcePerInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(2.54e-5);

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForcePerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonPerMeter:
                return base_value;

            case ForcePerLengthUnit::NanonewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NanonewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonPerMillimeter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::NanonewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::KilogramForcePerMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case ForcePerLengthUnit::KilogramForcePerCentimeter:
                return base_value / static_cast<un_scalar_t>(980.665);

            case ForcePerLengthUnit::KilogramForcePerMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonneForcePerMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonneForcePerCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e5);

            case ForcePerLengthUnit::TonneForcePerMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e6);

            case ForcePerLengthUnit::PoundForcePerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::PoundForcePerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::PoundForcePerYard:
                return base_value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::KilopoundForcePerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048e-3) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::KilopoundForcePerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-5) / static_cast<un_scalar_t>(4.4482216152605);

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        un_scalar_t value_;
        ForcePerLengthUnit value_unit_type_;       
    };
}
