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
    enum class FluidResistanceUnit : std::uint8_t
    {
        PascalSecondPerLiter,
        PascalMinutePerLiter,
        PascalSecondPerMilliliter,
        PascalMinutePerMilliliter,
        PascalSecondPerCubicMeter,
        MegapascalSecondPerCubicMeter,
        PascalMinutePerCubicMeter,
        PascalSecondPerCubicCentimeter,
        PascalMinutePerCubicCentimeter,
        DyneSecondPerCentimeterToTheFifth,
        MillimeterMercurySecondPerLiter,
        MillimeterMercuryMinutePerLiter,
        MillimeterMercurySecondPerMilliliter,
        MillimeterMercuryMinutePerMilliliter,
        MillimeterMercurySecondPerCubicCentimeter,
        MillimeterMercuryMinutePerCubicCentimeter,
        MillimeterMercurySecondPerCubicMeter,
        MillimeterMercuryMinutePerCubicMeter,
        WoodUnit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of FluidResistance.</summary>
    class FluidResistanceDto
    {
    public:
        constexpr FluidResistanceDto() noexcept
            : value{}, unit(FluidResistanceUnit::PascalSecondPerCubicMeter)
        {
        }

        constexpr FluidResistanceDto(
            const un_scalar_t value,
            const FluidResistanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        FluidResistanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr FluidResistanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<FluidResistanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown FluidResistance unit name.");
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
        [[nodiscard]] static FluidResistanceDto from_json(const nlohmann::json& json)
        {
            return FluidResistanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Fluid Resistance is a force acting opposite to the relative motion of any object moving with respect to a surrounding fluid. Fluid Resistance is sometimes referred to as drag or fluid friction.</summary>
    class FluidResistance : public UnitsNetBase
    {
    public:
        constexpr explicit FluidResistance(
            const un_scalar_t value,
            const FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const FluidResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr FluidResistanceDto to_dto(
            const FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondPerCubicMeter) const
        {
            return FluidResistanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr FluidResistance from_dto(const FluidResistanceDto& dto)
        {
            return FluidResistance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static FluidResistance from_json(const nlohmann::json& json)
        {
            return from_dto(FluidResistanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr FluidResistance operator+(const FluidResistance& other) const noexcept
        {
            return FluidResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr FluidResistance operator-(const FluidResistance& other)const noexcept
        {
            return FluidResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr FluidResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr FluidResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const FluidResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const FluidResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const FluidResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutePerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutePerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutePerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megapascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MegapascalSecondPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_megapascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MegapascalSecondPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutePerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t dyne_seconds_per_centimeter_to_the_fifth() const
        {
            return convert_from_base(FluidResistanceUnit::DyneSecondPerCentimeterToTheFifth);
        }

        [[nodiscard]] static constexpr FluidResistance from_dyne_seconds_per_centimeter_to_the_fifth(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::DyneSecondPerCentimeterToTheFifth);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutePerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutePerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutePerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutePerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t wood_units() const
        {
            return convert_from_base(FluidResistanceUnit::WoodUnit);
        }

        [[nodiscard]] static constexpr FluidResistance from_wood_units(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::WoodUnit);
        }

        [[nodiscard]] static constexpr FluidResistance from_invalid()
        {
            return FluidResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FluidResistanceUnit unit)
        {
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondPerLiter:
                return value * static_cast<un_scalar_t>(1e3);

            case FluidResistanceUnit::PascalMinutePerLiter:
                return value * static_cast<un_scalar_t>(6e4);

            case FluidResistanceUnit::PascalSecondPerMilliliter:
                return value * static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutePerMilliliter:
                return value * static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::PascalSecondPerCubicMeter:
                return value;

            case FluidResistanceUnit::MegapascalSecondPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case FluidResistanceUnit::PascalMinutePerCubicMeter:
                return value * static_cast<un_scalar_t>(60);

            case FluidResistanceUnit::PascalSecondPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::DyneSecondPerCentimeterToTheFifth:
                return value * static_cast<un_scalar_t>(1e5);

            case FluidResistanceUnit::MillimeterMercurySecondPerLiter:
                return value * static_cast<un_scalar_t>(1.33322368e5);

            case FluidResistanceUnit::MillimeterMercuryMinutePerLiter:
                return value * static_cast<un_scalar_t>(7.99934208e6);

            case FluidResistanceUnit::MillimeterMercurySecondPerMilliliter:
                return value * static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutePerMilliliter:
                return value * static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondPerCubicMeter:
                return value * static_cast<un_scalar_t>(133.322368);

            case FluidResistanceUnit::MillimeterMercuryMinutePerCubicMeter:
                return value * static_cast<un_scalar_t>(7.99934208e3);

            case FluidResistanceUnit::WoodUnit:
                return value * static_cast<un_scalar_t>(7.99934208e6);

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FluidResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondPerLiter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case FluidResistanceUnit::PascalMinutePerLiter:
                return base_value / static_cast<un_scalar_t>(6e4);

            case FluidResistanceUnit::PascalSecondPerMilliliter:
                return base_value / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutePerMilliliter:
                return base_value / static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::PascalSecondPerCubicMeter:
                return base_value;

            case FluidResistanceUnit::MegapascalSecondPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutePerCubicMeter:
                return base_value / static_cast<un_scalar_t>(60);

            case FluidResistanceUnit::PascalSecondPerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutePerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::DyneSecondPerCentimeterToTheFifth:
                return base_value / static_cast<un_scalar_t>(1e5);

            case FluidResistanceUnit::MillimeterMercurySecondPerLiter:
                return base_value / static_cast<un_scalar_t>(1.33322368e5);

            case FluidResistanceUnit::MillimeterMercuryMinutePerLiter:
                return base_value / static_cast<un_scalar_t>(7.99934208e6);

            case FluidResistanceUnit::MillimeterMercurySecondPerMilliliter:
                return base_value / static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutePerMilliliter:
                return base_value / static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondPerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutePerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondPerCubicMeter:
                return base_value / static_cast<un_scalar_t>(133.322368);

            case FluidResistanceUnit::MillimeterMercuryMinutePerCubicMeter:
                return base_value / static_cast<un_scalar_t>(7.99934208e3);

            case FluidResistanceUnit::WoodUnit:
                return base_value / static_cast<un_scalar_t>(7.99934208e6);

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        un_scalar_t value_;
        FluidResistanceUnit value_unit_type_;       
    };
}
