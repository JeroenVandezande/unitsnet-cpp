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
    enum class ReciprocalAreaUnit : std::uint8_t
    {
        InverseSquareMeter,
        InverseSquareKilometer,
        InverseSquareDecimeter,
        InverseSquareCentimeter,
        InverseSquareMillimeter,
        InverseSquareMicrometer,
        InverseSquareMile,
        InverseSquareYard,
        InverseSquareFoot,
        InverseUsSurveySquareFoot,
        InverseSquareInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ReciprocalArea.</summary>
    class ReciprocalAreaDto
    {
    public:
        constexpr ReciprocalAreaDto() noexcept
            : value{}, unit(ReciprocalAreaUnit::InverseSquareMeter)
        {
        }

        constexpr ReciprocalAreaDto(
            const un_scalar_t value,
            const ReciprocalAreaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ReciprocalAreaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ReciprocalAreaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ReciprocalAreaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ReciprocalArea unit name.");
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
        [[nodiscard]] static ReciprocalAreaDto from_json(const nlohmann::json& json)
        {
            return ReciprocalAreaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Reciprocal area (Inverse-square) quantity is used to specify a physical quantity inversely proportional to the square of the distance.</summary>
    class ReciprocalArea : public UnitsNetBase
    {
    public:
        constexpr explicit ReciprocalArea(
            const un_scalar_t value,
            const ReciprocalAreaUnit unit = ReciprocalAreaUnit::InverseSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ReciprocalAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ReciprocalAreaDto to_dto(
            const ReciprocalAreaUnit unit = ReciprocalAreaUnit::InverseSquareMeter) const
        {
            return ReciprocalAreaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ReciprocalArea from_dto(const ReciprocalAreaDto& dto)
        {
            return ReciprocalArea(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ReciprocalAreaUnit unit = ReciprocalAreaUnit::InverseSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ReciprocalArea from_json(const nlohmann::json& json)
        {
            return from_dto(ReciprocalAreaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ReciprocalArea operator+(const ReciprocalArea& other) const noexcept
        {
            return ReciprocalArea(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ReciprocalArea operator-(const ReciprocalArea& other)const noexcept
        {
            return ReciprocalArea(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ReciprocalArea operator*(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalArea(base_value() * scalar);
        }

        [[nodiscard]] constexpr ReciprocalArea operator/(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalArea(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ReciprocalArea& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ReciprocalArea& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ReciprocalArea& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_meters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMeter);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_meters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_kilometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareKilometer);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_kilometers(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareKilometer);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_decimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareDecimeter);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_decimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_centimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareCentimeter);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_centimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_millimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMillimeter);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_millimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_micrometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMicrometer);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_micrometers(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMicrometer);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_miles() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMile);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_miles(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMile);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_yards() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareYard);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_yards(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareYard);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareFoot);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_feet(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_us_survey_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseUsSurveySquareFoot);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_us_survey_square_feet(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseUsSurveySquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_square_inches() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareInch);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_inches(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareInch);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_invalid()
        {
            return ReciprocalArea(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ReciprocalAreaUnit unit)
        {
            switch (unit)
            {

            case ReciprocalAreaUnit::InverseSquareMeter:
                return value;

            case ReciprocalAreaUnit::InverseSquareKilometer:
                return value / static_cast<un_scalar_t>(1e6);

            case ReciprocalAreaUnit::InverseSquareDecimeter:
                return value / static_cast<un_scalar_t>(1e-2);

            case ReciprocalAreaUnit::InverseSquareCentimeter:
                return value / static_cast<un_scalar_t>(1e-4);

            case ReciprocalAreaUnit::InverseSquareMillimeter:
                return value / static_cast<un_scalar_t>(1e-6);

            case ReciprocalAreaUnit::InverseSquareMicrometer:
                return value / static_cast<un_scalar_t>(1e-12);

            case ReciprocalAreaUnit::InverseSquareMile:
                return value / (static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344));

            case ReciprocalAreaUnit::InverseSquareYard:
                return value / (static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144));

            case ReciprocalAreaUnit::InverseSquareFoot:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            case ReciprocalAreaUnit::InverseUsSurveySquareFoot:
                return value / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case ReciprocalAreaUnit::InverseSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ReciprocalArea unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ReciprocalAreaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ReciprocalAreaUnit::InverseSquareMeter:
                return base_value;

            case ReciprocalAreaUnit::InverseSquareKilometer:
                return base_value * static_cast<un_scalar_t>(1e6);

            case ReciprocalAreaUnit::InverseSquareDecimeter:
                return base_value * static_cast<un_scalar_t>(1e-2);

            case ReciprocalAreaUnit::InverseSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-4);

            case ReciprocalAreaUnit::InverseSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-6);

            case ReciprocalAreaUnit::InverseSquareMicrometer:
                return base_value * static_cast<un_scalar_t>(1e-12);

            case ReciprocalAreaUnit::InverseSquareMile:
                return base_value * (static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344));

            case ReciprocalAreaUnit::InverseSquareYard:
                return base_value * (static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144));

            case ReciprocalAreaUnit::InverseSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2);

            case ReciprocalAreaUnit::InverseUsSurveySquareFoot:
                return base_value * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case ReciprocalAreaUnit::InverseSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ReciprocalArea unit.");
        }

        un_scalar_t value_;
        ReciprocalAreaUnit value_unit_type_;       
    };
}
