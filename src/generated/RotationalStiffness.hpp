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
    enum class RotationalStiffnessUnit : std::uint8_t
    {
        NewtonMeterPerRadian,
        KilonewtonMeterPerRadian,
        MeganewtonMeterPerRadian,
        PoundForceFootPerDegrees,
        KilopoundForceFootPerDegrees,
        NewtonMillimeterPerDegree,
        NanonewtonMillimeterPerDegree,
        MicronewtonMillimeterPerDegree,
        MillinewtonMillimeterPerDegree,
        CentinewtonMillimeterPerDegree,
        DecinewtonMillimeterPerDegree,
        DecanewtonMillimeterPerDegree,
        KilonewtonMillimeterPerDegree,
        MeganewtonMillimeterPerDegree,
        NewtonMeterPerDegree,
        NanonewtonMeterPerDegree,
        MicronewtonMeterPerDegree,
        MillinewtonMeterPerDegree,
        CentinewtonMeterPerDegree,
        DecinewtonMeterPerDegree,
        DecanewtonMeterPerDegree,
        KilonewtonMeterPerDegree,
        MeganewtonMeterPerDegree,
        NewtonMillimeterPerRadian,
        NanonewtonMillimeterPerRadian,
        MicronewtonMillimeterPerRadian,
        MillinewtonMillimeterPerRadian,
        CentinewtonMillimeterPerRadian,
        DecinewtonMillimeterPerRadian,
        DecanewtonMillimeterPerRadian,
        KilonewtonMillimeterPerRadian,
        MeganewtonMillimeterPerRadian,
        PoundForceFeetPerRadian,
        KilopoundForceFootPerRadian,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RotationalStiffness.</summary>
    class RotationalStiffnessDto
    {
    public:
        constexpr RotationalStiffnessDto() noexcept
            : value{}, unit(RotationalStiffnessUnit::NewtonMeterPerRadian)
        {
        }

        constexpr RotationalStiffnessDto(
            const un_scalar_t value,
            const RotationalStiffnessUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RotationalStiffnessUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RotationalStiffnessUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RotationalStiffnessUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RotationalStiffness unit name.");
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
        [[nodiscard]] static RotationalStiffnessDto from_json(const nlohmann::json& json)
        {
            return RotationalStiffnessDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffness : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalStiffness(
            const un_scalar_t value,
            const RotationalStiffnessUnit unit = RotationalStiffnessUnit::NewtonMeterPerRadian)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalStiffnessUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RotationalStiffnessDto to_dto(
            const RotationalStiffnessUnit unit = RotationalStiffnessUnit::NewtonMeterPerRadian) const
        {
            return RotationalStiffnessDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RotationalStiffness from_dto(const RotationalStiffnessDto& dto)
        {
            return RotationalStiffness(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RotationalStiffnessUnit unit = RotationalStiffnessUnit::NewtonMeterPerRadian) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RotationalStiffness from_json(const nlohmann::json& json)
        {
            return from_dto(RotationalStiffnessDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RotationalStiffness operator+(const RotationalStiffness& other) const noexcept
        {
            return RotationalStiffness(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffness operator-(const RotationalStiffness& other)const noexcept
        {
            return RotationalStiffness(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffness operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffness operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalStiffness& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalStiffness& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalStiffness& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFootPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFootPerDegrees);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFootPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFootPerDegrees);
        }

        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMeterPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMeterPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimeterPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimeterPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFootPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFootPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_invalid()
        {
            return RotationalStiffness(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalStiffnessUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMeterPerRadian:
                return value;

            case RotationalStiffnessUnit::KilonewtonMeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e3));

            case RotationalStiffnessUnit::MeganewtonMeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e6));

            case RotationalStiffnessUnit::PoundForceFootPerDegrees:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFootPerDegrees:
                return value * (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimeterPerDegree:
                return value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NanonewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MicronewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MillinewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::CentinewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecinewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecanewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::KilonewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MeganewtonMillimeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NewtonMeterPerDegree:
                return value * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MicronewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MillinewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::CentinewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecinewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecanewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilonewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MeganewtonMeterPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimeterPerRadian:
                return value * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NanonewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MicronewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MillinewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::CentinewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecinewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecanewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::KilonewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MeganewtonMillimeterPerRadian:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case RotationalStiffnessUnit::KilopoundForceFootPerRadian:
                return value * static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalStiffnessUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMeterPerRadian:
                return base_value;

            case RotationalStiffnessUnit::KilonewtonMeterPerRadian:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMeterPerRadian:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFootPerDegrees:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFootPerDegrees:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimeterPerDegree:
                return base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000);

            case RotationalStiffnessUnit::NanonewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimeterPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMeterPerDegree:
                return base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMeterPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMillimeterPerRadian:
                return base_value * static_cast<un_scalar_t>(1000);

            case RotationalStiffnessUnit::NanonewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimeterPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048));

            case RotationalStiffnessUnit::KilopoundForceFootPerRadian:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        un_scalar_t value_;
        RotationalStiffnessUnit value_unit_type_;       
    };
}
