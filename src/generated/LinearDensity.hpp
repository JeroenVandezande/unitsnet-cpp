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
    enum class LinearDensityUnit : std::uint8_t
    {
        GramPerMillimeter,
        MicrogramPerMillimeter,
        MilligramPerMillimeter,
        KilogramPerMillimeter,
        GramPerCentimeter,
        MicrogramPerCentimeter,
        MilligramPerCentimeter,
        KilogramPerCentimeter,
        GramPerMeter,
        MicrogramPerMeter,
        MilligramPerMeter,
        KilogramPerMeter,
        PoundPerInch,
        PoundPerFoot,
        GramPerFoot,
        MicrogramPerFoot,
        MilligramPerFoot,
        KilogramPerFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of LinearDensity.</summary>
    class LinearDensityDto
    {
    public:
        constexpr LinearDensityDto() noexcept
            : value{}, unit(LinearDensityUnit::KilogramPerMeter)
        {
        }

        constexpr LinearDensityDto(
            const un_scalar_t value,
            const LinearDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LinearDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LinearDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LinearDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown LinearDensity unit name.");
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
        [[nodiscard]] static LinearDensityDto from_json(const nlohmann::json& json)
        {
            return LinearDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The Linear Density, or more precisely, the linear mass density, of a substance is its mass per unit length.  The term linear density is most often used when describing the characteristics of one-dimensional objects, although linear density can also be used to describe the density of a three-dimensional quantity along one particular dimension.</summary>
    class LinearDensity : public UnitsNetBase
    {
    public:
        constexpr explicit LinearDensity(
            const un_scalar_t value,
            const LinearDensityUnit unit = LinearDensityUnit::KilogramPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LinearDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LinearDensityDto to_dto(
            const LinearDensityUnit unit = LinearDensityUnit::KilogramPerMeter) const
        {
            return LinearDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr LinearDensity from_dto(const LinearDensityDto& dto)
        {
            return LinearDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LinearDensityUnit unit = LinearDensityUnit::KilogramPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static LinearDensity from_json(const nlohmann::json& json)
        {
            return from_dto(LinearDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr LinearDensity operator+(const LinearDensity& other) const noexcept
        {
            return LinearDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LinearDensity operator-(const LinearDensity& other)const noexcept
        {
            return LinearDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LinearDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LinearDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr LinearDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LinearDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LinearDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LinearDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LinearDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_millimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_millimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::GramPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_centimeter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_centimeter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::GramPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::MilligramPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_meter() const
        {
            return convert_from_base(LinearDensityUnit::KilogramPerMeter);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_meter(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_inch() const
        {
            return convert_from_base(LinearDensityUnit::PoundPerInch);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_inch(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::PoundPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_pounds_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::PoundPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::GramPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_grams_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::GramPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MicrogramPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_micrograms_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MicrogramPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::MilligramPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_milligrams_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::MilligramPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_foot() const
        {
            return convert_from_base(LinearDensityUnit::KilogramPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_kilograms_per_foot(const un_scalar_t value)
        {
            return LinearDensity(value, LinearDensityUnit::KilogramPerFoot);
        }

        [[nodiscard]] static constexpr LinearDensity from_invalid()
        {
            return LinearDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LinearDensityUnit unit)
        {
            switch (unit)
            {

            case LinearDensityUnit::GramPerMillimeter:
                return value;

            case LinearDensityUnit::MicrogramPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LinearDensityUnit::MilligramPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LinearDensityUnit::KilogramPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LinearDensityUnit::GramPerCentimeter:
                return value * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MicrogramPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MilligramPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::KilogramPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::GramPerMeter:
                return value * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MicrogramPerMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MilligramPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramPerMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::PoundPerInch:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(2.54e-2);

            case LinearDensityUnit::PoundPerFoot:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.3048);

            case LinearDensityUnit::GramPerFoot:
                return value * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MicrogramPerFoot:
                return (value * static_cast<un_scalar_t>(1e-6)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MilligramPerFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::KilogramPerFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LinearDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LinearDensityUnit::GramPerMillimeter:
                return base_value;

            case LinearDensityUnit::MicrogramPerMillimeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramPerMillimeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramPerMillimeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::GramPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e-1);

            case LinearDensityUnit::MicrogramPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::GramPerMeter:
                return base_value / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::MicrogramPerMeter:
                return (base_value / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramPerMeter:
                return (base_value / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramPerMeter:
                return (base_value / static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case LinearDensityUnit::PoundPerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(0.45359237);

            case LinearDensityUnit::PoundPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.45359237);

            case LinearDensityUnit::GramPerFoot:
                return base_value / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) );

            case LinearDensityUnit::MicrogramPerFoot:
                return (base_value / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e-6);

            case LinearDensityUnit::MilligramPerFoot:
                return (base_value / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e-3);

            case LinearDensityUnit::KilogramPerFoot:
                return (base_value / ( static_cast<un_scalar_t>(1e-3) / static_cast<un_scalar_t>(0.3048) )) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown LinearDensity unit.");
        }

        un_scalar_t value_;
        LinearDensityUnit value_unit_type_;       
    };
}
