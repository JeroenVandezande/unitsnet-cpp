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
    enum class SpecificWeightUnit : std::uint8_t
    {
        NewtonPerCubicMillimeter,
        KilonewtonPerCubicMillimeter,
        NewtonPerCubicCentimeter,
        KilonewtonPerCubicCentimeter,
        NewtonPerCubicMeter,
        KilonewtonPerCubicMeter,
        MeganewtonPerCubicMeter,
        KilogramForcePerCubicMillimeter,
        KilogramForcePerCubicCentimeter,
        KilogramForcePerCubicMeter,
        PoundForcePerCubicInch,
        KilopoundForcePerCubicInch,
        PoundForcePerCubicFoot,
        KilopoundForcePerCubicFoot,
        TonneForcePerCubicMillimeter,
        TonneForcePerCubicCentimeter,
        TonneForcePerCubicMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SpecificWeight.</summary>
    class SpecificWeightDto
    {
    public:
        constexpr SpecificWeightDto() noexcept
            : value{}, unit(SpecificWeightUnit::NewtonPerCubicMeter)
        {
        }

        constexpr SpecificWeightDto(
            const un_scalar_t value,
            const SpecificWeightUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpecificWeightUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpecificWeightUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpecificWeightUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SpecificWeight unit name.");
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
        [[nodiscard]] static SpecificWeightDto from_json(const nlohmann::json& json)
        {
            return SpecificWeightDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The SpecificWeight, or more precisely, the volumetric weight density, of a substance is its weight per unit volume.</summary>
    class SpecificWeight : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificWeight(
            const un_scalar_t value,
            const SpecificWeightUnit unit = SpecificWeightUnit::NewtonPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificWeightUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpecificWeightDto to_dto(
            const SpecificWeightUnit unit = SpecificWeightUnit::NewtonPerCubicMeter) const
        {
            return SpecificWeightDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SpecificWeight from_dto(const SpecificWeightDto& dto)
        {
            return SpecificWeight(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpecificWeightUnit unit = SpecificWeightUnit::NewtonPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificWeight from_json(const nlohmann::json& json)
        {
            return from_dto(SpecificWeightDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr SpecificWeight operator+(const SpecificWeight& other) const noexcept
        {
            return SpecificWeight(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificWeight operator-(const SpecificWeight& other)const noexcept
        {
            return SpecificWeight(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificWeight operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificWeight(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificWeight operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificWeight(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificWeight& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificWeight& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificWeight& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::MeganewtonPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_meganewtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::MeganewtonPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramForcePerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramForcePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramForcePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::PoundForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_inch(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundForcePerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_inch(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundForcePerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::PoundForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_foot(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundForcePerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_foot(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundForcePerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonneForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonneForcePerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonneForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonneForcePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::TonneForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonneForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_invalid()
        {
            return SpecificWeight(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificWeightUnit unit)
        {
            switch (unit)
            {

            case SpecificWeightUnit::NewtonPerCubicMillimeter:
                return value * static_cast<un_scalar_t>(1000000000);

            case SpecificWeightUnit::KilonewtonPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1000000000);

            case SpecificWeightUnit::NewtonPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1000000);

            case SpecificWeightUnit::KilonewtonPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1000000);

            case SpecificWeightUnit::NewtonPerCubicMeter:
                return value;

            case SpecificWeightUnit::KilonewtonPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificWeightUnit::MeganewtonPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificWeightUnit::KilogramForcePerCubicMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::KilogramForcePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case SpecificWeightUnit::KilogramForcePerCubicMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case SpecificWeightUnit::PoundForcePerCubicInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(1.6387064e-5);

            case SpecificWeightUnit::KilopoundForcePerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(1.6387064e-5);

            case SpecificWeightUnit::PoundForcePerCubicFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.028316846592);

            case SpecificWeightUnit::KilopoundForcePerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.028316846592);

            case SpecificWeightUnit::TonneForcePerCubicMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e12);

            case SpecificWeightUnit::TonneForcePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::TonneForcePerCubicMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificWeightUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificWeightUnit::NewtonPerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(0.000000001);

            case SpecificWeightUnit::KilonewtonPerCubicMillimeter:
                return (base_value * static_cast<un_scalar_t>(0.000000001)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::NewtonPerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(0.000001);

            case SpecificWeightUnit::KilonewtonPerCubicCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.000001)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::NewtonPerCubicMeter:
                return base_value;

            case SpecificWeightUnit::KilonewtonPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::MeganewtonPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificWeightUnit::KilogramForcePerCubicMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::KilogramForcePerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e6);

            case SpecificWeightUnit::KilogramForcePerCubicMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case SpecificWeightUnit::PoundForcePerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(4.4482216152605);

            case SpecificWeightUnit::KilopoundForcePerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::PoundForcePerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(4.4482216152605);

            case SpecificWeightUnit::KilopoundForcePerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::TonneForcePerCubicMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e12);

            case SpecificWeightUnit::TonneForcePerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::TonneForcePerCubicMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        un_scalar_t value_;
        SpecificWeightUnit value_unit_type_;       
    };
}
