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
    enum class AreaUnit : std::uint8_t
    {
        SquareKilometer,
        SquareMeter,
        SquareDecimeter,
        SquareCentimeter,
        SquareMillimeter,
        SquareMicrometer,
        SquareMile,
        SquareYard,
        SquareFoot,
        UsSurveySquareFoot,
        SquareInch,
        Acre,
        Hectare,
        SquareNauticalMile,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Area.</summary>
    class AreaDto
    {
    public:
        constexpr AreaDto() noexcept
            : value{}, unit(AreaUnit::SquareMeter)
        {
        }

        constexpr AreaDto(
            const un_scalar_t value,
            const AreaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AreaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AreaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AreaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Area unit name.");
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
        [[nodiscard]] static AreaDto from_json(const nlohmann::json& json)
        {
            return AreaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Area is a quantity that expresses the extent of a two-dimensional surface or shape, or planar lamina, in the plane. Area can be understood as the amount of material with a given thickness that would be necessary to fashion a model of the shape, or the amount of paint necessary to cover the surface with a single coat.[1] It is the two-dimensional analog of the length of a curve (a one-dimensional concept) or the volume of a solid (a three-dimensional concept).</summary>
    class Area : public UnitsNetBase
    {
    public:
        constexpr explicit Area(
            const un_scalar_t value,
            const AreaUnit unit = AreaUnit::SquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AreaDto to_dto(
            const AreaUnit unit = AreaUnit::SquareMeter) const
        {
            return AreaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Area from_dto(const AreaDto& dto)
        {
            return Area(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AreaUnit unit = AreaUnit::SquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Area from_json(const nlohmann::json& json)
        {
            return from_dto(AreaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Area operator+(const Area& other) const noexcept
        {
            return Area(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Area operator-(const Area& other)const noexcept
        {
            return Area(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Area operator*(const un_scalar_t scalar) const noexcept
        {
            return Area(base_value() * scalar);
        }

        [[nodiscard]] constexpr Area operator/(const un_scalar_t scalar) const noexcept
        {
            return Area(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Area& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Area& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Area& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t square_kilometers() const
        {
            return convert_from_base(AreaUnit::SquareKilometer);
        }

        [[nodiscard]] static constexpr Area from_square_kilometers(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareKilometer);
        }

        [[nodiscard]] constexpr un_scalar_t square_meters() const
        {
            return convert_from_base(AreaUnit::SquareMeter);
        }

        [[nodiscard]] static constexpr Area from_square_meters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t square_decimeters() const
        {
            return convert_from_base(AreaUnit::SquareDecimeter);
        }

        [[nodiscard]] static constexpr Area from_square_decimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeters() const
        {
            return convert_from_base(AreaUnit::SquareCentimeter);
        }

        [[nodiscard]] static constexpr Area from_square_centimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t square_millimeters() const
        {
            return convert_from_base(AreaUnit::SquareMillimeter);
        }

        [[nodiscard]] static constexpr Area from_square_millimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t square_micrometers() const
        {
            return convert_from_base(AreaUnit::SquareMicrometer);
        }

        [[nodiscard]] static constexpr Area from_square_micrometers(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMicrometer);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] constexpr un_scalar_t square_miles() const
        {
            return convert_from_base(AreaUnit::SquareMile);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] static constexpr Area from_square_miles(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMile);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t square_yards() const
        {
            return convert_from_base(AreaUnit::SquareYard);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Area from_square_yards(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareYard);
        }

        [[nodiscard]] constexpr un_scalar_t square_feet() const
        {
            return convert_from_base(AreaUnit::SquareFoot);
        }

        [[nodiscard]] static constexpr Area from_square_feet(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareFoot);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t us_survey_square_feet() const
        {
            return convert_from_base(AreaUnit::UsSurveySquareFoot);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] static constexpr Area from_us_survey_square_feet(const un_scalar_t value)
        {
            return Area(value, AreaUnit::UsSurveySquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t square_inches() const
        {
            return convert_from_base(AreaUnit::SquareInch);
        }

        [[nodiscard]] static constexpr Area from_square_inches(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareInch);
        }

        /// <summary>Based upon the international yard and pound agreement of 1959, an acre may be declared as exactly 4,046.8564224 square metres.</summary>
        [[nodiscard]] constexpr un_scalar_t acres() const
        {
            return convert_from_base(AreaUnit::Acre);
        }

        /// <summary>Based upon the international yard and pound agreement of 1959, an acre may be declared as exactly 4,046.8564224 square metres.</summary>
        [[nodiscard]] static constexpr Area from_acres(const un_scalar_t value)
        {
            return Area(value, AreaUnit::Acre);
        }

        [[nodiscard]] constexpr un_scalar_t hectares() const
        {
            return convert_from_base(AreaUnit::Hectare);
        }

        [[nodiscard]] static constexpr Area from_hectares(const un_scalar_t value)
        {
            return Area(value, AreaUnit::Hectare);
        }

        [[nodiscard]] constexpr un_scalar_t square_nautical_miles() const
        {
            return convert_from_base(AreaUnit::SquareNauticalMile);
        }

        [[nodiscard]] static constexpr Area from_square_nautical_miles(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareNauticalMile);
        }

        [[nodiscard]] static constexpr Area from_invalid()
        {
            return Area(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaUnit unit)
        {
            switch (unit)
            {

            case AreaUnit::SquareKilometer:
                return value * static_cast<un_scalar_t>(1e6);

            case AreaUnit::SquareMeter:
                return value;

            case AreaUnit::SquareDecimeter:
                return value * static_cast<un_scalar_t>(1e-2);

            case AreaUnit::SquareCentimeter:
                return value * static_cast<un_scalar_t>(1e-4);

            case AreaUnit::SquareMillimeter:
                return value * static_cast<un_scalar_t>(1e-6);

            case AreaUnit::SquareMicrometer:
                return value * static_cast<un_scalar_t>(1e-12);

            case AreaUnit::SquareMile:
                return value * static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344);

            case AreaUnit::SquareYard:
                return value * static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144);

            case AreaUnit::SquareFoot:
                return value * static_cast<un_scalar_t>(9.290304e-2);

            case AreaUnit::UsSurveySquareFoot:
                return value * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case AreaUnit::SquareInch:
                return value * static_cast<un_scalar_t>(0.00064516);

            case AreaUnit::Acre:
                return value * static_cast<un_scalar_t>(4046.8564224);

            case AreaUnit::Hectare:
                return value * static_cast<un_scalar_t>(1e4);

            case AreaUnit::SquareNauticalMile:
                return value * static_cast<un_scalar_t>(3429904);

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AreaUnit::SquareKilometer:
                return base_value / static_cast<un_scalar_t>(1e6);

            case AreaUnit::SquareMeter:
                return base_value;

            case AreaUnit::SquareDecimeter:
                return base_value / static_cast<un_scalar_t>(1e-2);

            case AreaUnit::SquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1e-4);

            case AreaUnit::SquareMillimeter:
                return base_value / static_cast<un_scalar_t>(1e-6);

            case AreaUnit::SquareMicrometer:
                return base_value / static_cast<un_scalar_t>(1e-12);

            case AreaUnit::SquareMile:
                return base_value / static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(1609.344);

            case AreaUnit::SquareYard:
                return base_value / static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(0.9144);

            case AreaUnit::SquareFoot:
                return base_value / static_cast<un_scalar_t>(9.290304e-2);

            case AreaUnit::UsSurveySquareFoot:
                return base_value / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case AreaUnit::SquareInch:
                return base_value / static_cast<un_scalar_t>(0.00064516);

            case AreaUnit::Acre:
                return base_value / static_cast<un_scalar_t>(4046.8564224);

            case AreaUnit::Hectare:
                return base_value / static_cast<un_scalar_t>(1e4);

            case AreaUnit::SquareNauticalMile:
                return base_value / static_cast<un_scalar_t>(3429904);

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        un_scalar_t value_;
        AreaUnit value_unit_type_;       
    };
}
