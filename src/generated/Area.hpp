#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class AreaUnit : std::uint8_t
    {
        SquareKilometers,
        SquareMeters,
        SquareDecimeters,
        SquareCentimeters,
        SquareMillimeters,
        SquareMicrometers,
        SquareMiles,
        SquareYards,
        SquareFeet,
        UsSurveySquareFeet,
        SquareInches,
        Acres,
        Hectares,
        SquareNauticalMiles,
    };

    /// <summary>Area is a quantity that expresses the extent of a two-dimensional surface or shape, or planar lamina, in the plane. Area can be understood as the amount of material with a given thickness that would be necessary to fashion a model of the shape, or the amount of paint necessary to cover the surface with a single coat.[1] It is the two-dimensional analog of the length of a curve (a one-dimensional concept) or the volume of a solid (a three-dimensional concept).</summary>
    class Area : public UnitsNetBase
    {
    public:
        constexpr explicit Area(
            const un_scalar_t value,
            const AreaUnit unit = AreaUnit::SquareMeters)
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
            return convert_from_base(AreaUnit::SquareKilometers);
        }

        [[nodiscard]] static constexpr Area from_square_kilometers(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareKilometers);
        }

        [[nodiscard]] constexpr un_scalar_t square_meters() const
        {
            return convert_from_base(AreaUnit::SquareMeters);
        }

        [[nodiscard]] static constexpr Area from_square_meters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t square_decimeters() const
        {
            return convert_from_base(AreaUnit::SquareDecimeters);
        }

        [[nodiscard]] static constexpr Area from_square_decimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeters() const
        {
            return convert_from_base(AreaUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr Area from_square_centimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t square_millimeters() const
        {
            return convert_from_base(AreaUnit::SquareMillimeters);
        }

        [[nodiscard]] static constexpr Area from_square_millimeters(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t square_micrometers() const
        {
            return convert_from_base(AreaUnit::SquareMicrometers);
        }

        [[nodiscard]] static constexpr Area from_square_micrometers(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMicrometers);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] constexpr un_scalar_t square_miles() const
        {
            return convert_from_base(AreaUnit::SquareMiles);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] static constexpr Area from_square_miles(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMiles);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t square_yards() const
        {
            return convert_from_base(AreaUnit::SquareYards);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Area from_square_yards(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareYards);
        }

        [[nodiscard]] constexpr un_scalar_t square_feet() const
        {
            return convert_from_base(AreaUnit::SquareFeet);
        }

        [[nodiscard]] static constexpr Area from_square_feet(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareFeet);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t us_survey_square_feet() const
        {
            return convert_from_base(AreaUnit::UsSurveySquareFeet);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] static constexpr Area from_us_survey_square_feet(const un_scalar_t value)
        {
            return Area(value, AreaUnit::UsSurveySquareFeet);
        }

        [[nodiscard]] constexpr un_scalar_t square_inches() const
        {
            return convert_from_base(AreaUnit::SquareInches);
        }

        [[nodiscard]] static constexpr Area from_square_inches(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareInches);
        }

        /// <summary>Based upon the international yard and pound agreement of 1959, an acre may be declared as exactly 4,046.8564224 square metres.</summary>
        [[nodiscard]] constexpr un_scalar_t acres() const
        {
            return convert_from_base(AreaUnit::Acres);
        }

        /// <summary>Based upon the international yard and pound agreement of 1959, an acre may be declared as exactly 4,046.8564224 square metres.</summary>
        [[nodiscard]] static constexpr Area from_acres(const un_scalar_t value)
        {
            return Area(value, AreaUnit::Acres);
        }

        [[nodiscard]] constexpr un_scalar_t hectares() const
        {
            return convert_from_base(AreaUnit::Hectares);
        }

        [[nodiscard]] static constexpr Area from_hectares(const un_scalar_t value)
        {
            return Area(value, AreaUnit::Hectares);
        }

        [[nodiscard]] constexpr un_scalar_t square_nautical_miles() const
        {
            return convert_from_base(AreaUnit::SquareNauticalMiles);
        }

        [[nodiscard]] static constexpr Area from_square_nautical_miles(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareNauticalMiles);
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

            case AreaUnit::SquareKilometers:
                return value * static_cast<un_scalar_t>(1e6);

            case AreaUnit::SquareMeters:
                return value;

            case AreaUnit::SquareDecimeters:
                return value * static_cast<un_scalar_t>(1e-2);

            case AreaUnit::SquareCentimeters:
                return value * static_cast<un_scalar_t>(1e-4);

            case AreaUnit::SquareMillimeters:
                return value * static_cast<un_scalar_t>(1e-6);

            case AreaUnit::SquareMicrometers:
                return value * static_cast<un_scalar_t>(1e-12);

            case AreaUnit::SquareMiles:
                return value * static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344);

            case AreaUnit::SquareYards:
                return value * static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144);

            case AreaUnit::SquareFeet:
                return value * static_cast<un_scalar_t>(9.290304e-2);

            case AreaUnit::UsSurveySquareFeet:
                return value * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case AreaUnit::SquareInches:
                return value * static_cast<un_scalar_t>(0.00064516);

            case AreaUnit::Acres:
                return value * static_cast<un_scalar_t>(4046.8564224);

            case AreaUnit::Hectares:
                return value * static_cast<un_scalar_t>(1e4);

            case AreaUnit::SquareNauticalMiles:
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

            case AreaUnit::SquareKilometers:
                return base_value / static_cast<un_scalar_t>(1e6);

            case AreaUnit::SquareMeters:
                return base_value;

            case AreaUnit::SquareDecimeters:
                return base_value / static_cast<un_scalar_t>(1e-2);

            case AreaUnit::SquareCentimeters:
                return base_value / static_cast<un_scalar_t>(1e-4);

            case AreaUnit::SquareMillimeters:
                return base_value / static_cast<un_scalar_t>(1e-6);

            case AreaUnit::SquareMicrometers:
                return base_value / static_cast<un_scalar_t>(1e-12);

            case AreaUnit::SquareMiles:
                return base_value / static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(1609.344);

            case AreaUnit::SquareYards:
                return base_value / static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(0.9144);

            case AreaUnit::SquareFeet:
                return base_value / static_cast<un_scalar_t>(9.290304e-2);

            case AreaUnit::UsSurveySquareFeet:
                return base_value / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case AreaUnit::SquareInches:
                return base_value / static_cast<un_scalar_t>(0.00064516);

            case AreaUnit::Acres:
                return base_value / static_cast<un_scalar_t>(4046.8564224);

            case AreaUnit::Hectares:
                return base_value / static_cast<un_scalar_t>(1e4);

            case AreaUnit::SquareNauticalMiles:
                return base_value / static_cast<un_scalar_t>(3429904);

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        un_scalar_t value_;
        AreaUnit value_unit_type_;       
    };
}
