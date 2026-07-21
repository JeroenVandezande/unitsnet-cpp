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
    enum class RotationalStiffnessPerLengthUnit : std::uint8_t
    {
        NewtonMeterPerRadianPerMeter,
        KilonewtonMeterPerRadianPerMeter,
        MeganewtonMeterPerRadianPerMeter,
        PoundForceFootPerDegreesPerFoot,
        KilopoundForceFootPerDegreesPerFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RotationalStiffnessPerLength.</summary>
    class RotationalStiffnessPerLengthDto
    {
    public:
        constexpr RotationalStiffnessPerLengthDto() noexcept
            : value{}, unit(RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter)
        {
        }

        constexpr RotationalStiffnessPerLengthDto(
            const un_scalar_t value,
            const RotationalStiffnessPerLengthUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RotationalStiffnessPerLengthUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RotationalStiffnessPerLengthUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RotationalStiffnessPerLengthUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit name.");
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
        [[nodiscard]] static RotationalStiffnessPerLengthDto from_json(const nlohmann::json& json)
        {
            return RotationalStiffnessPerLengthDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffnessPerLength : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalStiffnessPerLength(
            const un_scalar_t value,
            const RotationalStiffnessPerLengthUnit unit = RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalStiffnessPerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RotationalStiffnessPerLengthDto to_dto(
            const RotationalStiffnessPerLengthUnit unit = RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter) const
        {
            return RotationalStiffnessPerLengthDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_dto(const RotationalStiffnessPerLengthDto& dto)
        {
            return RotationalStiffnessPerLength(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RotationalStiffnessPerLengthUnit unit = RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RotationalStiffnessPerLength from_json(const nlohmann::json& json)
        {
            return from_dto(RotationalStiffnessPerLengthDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator+(const RotationalStiffnessPerLength& other) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator-(const RotationalStiffnessPerLength& other)const noexcept
        {
            return RotationalStiffnessPerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_newton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilonewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilonewton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilonewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::MeganewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_meganewton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::MeganewtonMeterPerRadianPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::PoundForceFootPerDegreesPerFoot);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_pound_force_feet_per_degrees_per_feet(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::PoundForceFootPerDegreesPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilopoundForceFootPerDegreesPerFoot);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilopound_force_feet_per_degrees_per_feet(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilopoundForceFootPerDegreesPerFoot);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_invalid()
        {
            return RotationalStiffnessPerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalStiffnessPerLengthUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter:
                return value;

            case RotationalStiffnessPerLengthUnit::KilonewtonMeterPerRadianPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case RotationalStiffnessPerLengthUnit::MeganewtonMeterPerRadianPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case RotationalStiffnessPerLengthUnit::PoundForceFootPerDegreesPerFoot:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFootPerDegreesPerFoot:
                return value * (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalStiffnessPerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMeterPerRadianPerMeter:
                return base_value;

            case RotationalStiffnessPerLengthUnit::KilonewtonMeterPerRadianPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessPerLengthUnit::MeganewtonMeterPerRadianPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessPerLengthUnit::PoundForceFootPerDegreesPerFoot:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFootPerDegreesPerFoot:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        un_scalar_t value_;
        RotationalStiffnessPerLengthUnit value_unit_type_;       
    };
}
