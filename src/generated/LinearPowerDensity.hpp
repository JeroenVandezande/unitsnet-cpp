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
    enum class LinearPowerDensityUnit : std::uint8_t
    {
        WattPerMeter,
        MilliwattPerMeter,
        KilowattPerMeter,
        MegawattPerMeter,
        GigawattPerMeter,
        WattPerCentimeter,
        MilliwattPerCentimeter,
        KilowattPerCentimeter,
        MegawattPerCentimeter,
        GigawattPerCentimeter,
        WattPerMillimeter,
        MilliwattPerMillimeter,
        KilowattPerMillimeter,
        MegawattPerMillimeter,
        GigawattPerMillimeter,
        WattPerInch,
        MilliwattPerInch,
        KilowattPerInch,
        MegawattPerInch,
        GigawattPerInch,
        WattPerFoot,
        MilliwattPerFoot,
        KilowattPerFoot,
        MegawattPerFoot,
        GigawattPerFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of LinearPowerDensity.</summary>
    class LinearPowerDensityDto
    {
    public:
        constexpr LinearPowerDensityDto() noexcept
            : value{}, unit(LinearPowerDensityUnit::WattPerMeter)
        {
        }

        constexpr LinearPowerDensityDto(
            const un_scalar_t value,
            const LinearPowerDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LinearPowerDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LinearPowerDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LinearPowerDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit name.");
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
        [[nodiscard]] static LinearPowerDensityDto from_json(const nlohmann::json& json)
        {
            return LinearPowerDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The Linear Power Density of a substance is its power per unit length.  The term linear density is most often used when describing the characteristics of one-dimensional objects, although linear density can also be used to describe the density of a three-dimensional quantity along one particular dimension.</summary>
    class LinearPowerDensity : public UnitsNetBase
    {
    public:
        constexpr explicit LinearPowerDensity(
            const un_scalar_t value,
            const LinearPowerDensityUnit unit = LinearPowerDensityUnit::WattPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LinearPowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LinearPowerDensityDto to_dto(
            const LinearPowerDensityUnit unit = LinearPowerDensityUnit::WattPerMeter) const
        {
            return LinearPowerDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr LinearPowerDensity from_dto(const LinearPowerDensityDto& dto)
        {
            return LinearPowerDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LinearPowerDensityUnit unit = LinearPowerDensityUnit::WattPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static LinearPowerDensity from_json(const nlohmann::json& json)
        {
            return from_dto(LinearPowerDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr LinearPowerDensity operator+(const LinearPowerDensity& other) const noexcept
        {
            return LinearPowerDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LinearPowerDensity operator-(const LinearPowerDensity& other)const noexcept
        {
            return LinearPowerDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LinearPowerDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LinearPowerDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LinearPowerDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LinearPowerDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LinearPowerDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LinearPowerDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_invalid()
        {
            return LinearPowerDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LinearPowerDensityUnit unit)
        {
            switch (unit)
            {

            case LinearPowerDensityUnit::WattPerMeter:
                return value;

            case LinearPowerDensityUnit::MilliwattPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LinearPowerDensityUnit::KilowattPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LinearPowerDensityUnit::MegawattPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case LinearPowerDensityUnit::GigawattPerMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case LinearPowerDensityUnit::WattPerCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MilliwattPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::KilowattPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MegawattPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::GigawattPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::WattPerMillimeter:
                return value * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MilliwattPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::KilowattPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::GigawattPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::WattPerInch:
                return value / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MilliwattPerInch:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::KilowattPerInch:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MegawattPerInch:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::GigawattPerInch:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::WattPerFoot:
                return value / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MilliwattPerFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::KilowattPerFoot:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MegawattPerFoot:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::GigawattPerFoot:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LinearPowerDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LinearPowerDensityUnit::WattPerMeter:
                return base_value;

            case LinearPowerDensityUnit::MilliwattPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MilliwattPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattPerMillimeter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MilliwattPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattPerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MilliwattPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MilliwattPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        un_scalar_t value_;
        LinearPowerDensityUnit value_unit_type_;       
    };
}
