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
    enum class ReciprocalLengthUnit : std::uint8_t
    {
        InverseMeter,
        InverseCentimeter,
        InverseMillimeter,
        InverseMile,
        InverseYard,
        InverseFoot,
        InverseUsSurveyFoot,
        InverseInch,
        InverseMil,
        InverseMicroinch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ReciprocalLength.</summary>
    class ReciprocalLengthDto
    {
    public:
        constexpr ReciprocalLengthDto() noexcept
            : value{}, unit(ReciprocalLengthUnit::InverseMeter)
        {
        }

        constexpr ReciprocalLengthDto(
            const un_scalar_t value,
            const ReciprocalLengthUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ReciprocalLengthUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ReciprocalLengthUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ReciprocalLengthUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ReciprocalLength unit name.");
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
        [[nodiscard]] static ReciprocalLengthDto from_json(const nlohmann::json& json)
        {
            return ReciprocalLengthDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Reciprocal (Inverse) Length is used in various fields of science and mathematics. It is defined as the inverse value of a length unit.</summary>
    class ReciprocalLength : public UnitsNetBase
    {
    public:
        constexpr explicit ReciprocalLength(
            const un_scalar_t value,
            const ReciprocalLengthUnit unit = ReciprocalLengthUnit::InverseMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ReciprocalLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ReciprocalLengthDto to_dto(
            const ReciprocalLengthUnit unit = ReciprocalLengthUnit::InverseMeter) const
        {
            return ReciprocalLengthDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ReciprocalLength from_dto(const ReciprocalLengthDto& dto)
        {
            return ReciprocalLength(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ReciprocalLengthUnit unit = ReciprocalLengthUnit::InverseMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ReciprocalLength from_json(const nlohmann::json& json)
        {
            return from_dto(ReciprocalLengthDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ReciprocalLength operator+(const ReciprocalLength& other) const noexcept
        {
            return ReciprocalLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ReciprocalLength operator-(const ReciprocalLength& other)const noexcept
        {
            return ReciprocalLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ReciprocalLength operator*(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr ReciprocalLength operator/(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ReciprocalLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ReciprocalLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ReciprocalLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t inverse_meters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMeter);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_meters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_centimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseCentimeter);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_centimeters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_millimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMillimeter);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_millimeters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_miles() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMile);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_miles(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMile);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_yards() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseYard);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_yards(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseYard);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseFoot);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_feet(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseFoot);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_us_survey_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseUsSurveyFoot);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_us_survey_feet(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseUsSurveyFoot);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_inches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseInch);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_inches(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseInch);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_mils() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMil);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_mils(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMil);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_microinches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMicroinch);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_microinches(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMicroinch);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_invalid()
        {
            return ReciprocalLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ReciprocalLengthUnit unit)
        {
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeter:
                return value;

            case ReciprocalLengthUnit::InverseCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case ReciprocalLengthUnit::InverseMillimeter:
                return value * static_cast<un_scalar_t>(1e3);

            case ReciprocalLengthUnit::InverseMile:
                return value / static_cast<un_scalar_t>(1609.344);

            case ReciprocalLengthUnit::InverseYard:
                return value / static_cast<un_scalar_t>(0.9144);

            case ReciprocalLengthUnit::InverseFoot:
                return value / static_cast<un_scalar_t>(0.3048);

            case ReciprocalLengthUnit::InverseUsSurveyFoot:
                return value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case ReciprocalLengthUnit::InverseInch:
                return value / static_cast<un_scalar_t>(2.54e-2);

            case ReciprocalLengthUnit::InverseMil:
                return value / static_cast<un_scalar_t>(2.54e-5);

            case ReciprocalLengthUnit::InverseMicroinch:
                return value / static_cast<un_scalar_t>(2.54e-8);

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ReciprocalLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeter:
                return base_value;

            case ReciprocalLengthUnit::InverseCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case ReciprocalLengthUnit::InverseMillimeter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case ReciprocalLengthUnit::InverseMile:
                return base_value * static_cast<un_scalar_t>(1609.344);

            case ReciprocalLengthUnit::InverseYard:
                return base_value * static_cast<un_scalar_t>(0.9144);

            case ReciprocalLengthUnit::InverseFoot:
                return base_value * static_cast<un_scalar_t>(0.3048);

            case ReciprocalLengthUnit::InverseUsSurveyFoot:
                return base_value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case ReciprocalLengthUnit::InverseInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2);

            case ReciprocalLengthUnit::InverseMil:
                return base_value * static_cast<un_scalar_t>(2.54e-5);

            case ReciprocalLengthUnit::InverseMicroinch:
                return base_value * static_cast<un_scalar_t>(2.54e-8);

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        un_scalar_t value_;
        ReciprocalLengthUnit value_unit_type_;       
    };
}
