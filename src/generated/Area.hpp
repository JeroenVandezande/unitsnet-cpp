#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class Area
    {
    public:
        constexpr explicit Area(
            const un_scalar_t value,
            const AreaUnit unit = AreaUnit::SquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Area(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Area operator+(const Area other) const noexcept
        {
            return Area(value_ + other.value_);
        }

        [[nodiscard]] constexpr Area operator-(const Area other) const noexcept
        {
            return Area(value_ - other.value_);
        }

        [[nodiscard]] constexpr Area operator*(const un_scalar_t scalar) const noexcept
        {
            return Area(value_ * scalar);
        }

        [[nodiscard]] constexpr Area operator/(const un_scalar_t scalar) const noexcept
        {
            return Area(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Area other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Area other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Area other) const noexcept
        {
            return value_ > other.value_;
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


        [[nodiscard]] constexpr un_scalar_t square_miles() const
        {
            return convert_from_base(AreaUnit::SquareMiles);
        }

        [[nodiscard]] static constexpr Area from_square_miles(const un_scalar_t value)
        {
            return Area(value, AreaUnit::SquareMiles);
        }


        [[nodiscard]] constexpr un_scalar_t square_yards() const
        {
            return convert_from_base(AreaUnit::SquareYards);
        }

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


        [[nodiscard]] constexpr un_scalar_t us_survey_square_feet() const
        {
            return convert_from_base(AreaUnit::UsSurveySquareFeet);
        }

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


        [[nodiscard]] constexpr un_scalar_t acres() const
        {
            return convert_from_base(AreaUnit::Acres);
        }

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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case AreaUnit::SquareKilometers:
                return value_ / static_cast<un_scalar_t>(1e6);

            case AreaUnit::SquareMeters:
                return value_;

            case AreaUnit::SquareDecimeters:
                return value_ / static_cast<un_scalar_t>(1e-2);

            case AreaUnit::SquareCentimeters:
                return value_ / static_cast<un_scalar_t>(1e-4);

            case AreaUnit::SquareMillimeters:
                return value_ / static_cast<un_scalar_t>(1e-6);

            case AreaUnit::SquareMicrometers:
                return value_ / static_cast<un_scalar_t>(1e-12);

            case AreaUnit::SquareMiles:
                return value_ / static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(1609.344);

            case AreaUnit::SquareYards:
                return value_ / static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(0.9144);

            case AreaUnit::SquareFeet:
                return value_ / static_cast<un_scalar_t>(9.290304e-2);

            case AreaUnit::UsSurveySquareFeet:
                return value_ / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case AreaUnit::SquareInches:
                return value_ / static_cast<un_scalar_t>(0.00064516);

            case AreaUnit::Acres:
                return value_ / static_cast<un_scalar_t>(4046.8564224);

            case AreaUnit::Hectares:
                return value_ / static_cast<un_scalar_t>(1e4);

            case AreaUnit::SquareNauticalMiles:
                return value_ / static_cast<un_scalar_t>(3429904);

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        un_scalar_t value_;
    };
}
