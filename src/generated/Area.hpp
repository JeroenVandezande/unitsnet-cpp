#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AreaUnit : std::uint16_t
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
            double value,
            AreaUnit unit = AreaUnit::SquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AreaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Area operator+(Area other) const noexcept
        {
            return Area(value_ + other.value_);
        }

        [[nodiscard]] constexpr Area operator-(Area other) const noexcept
        {
            return Area(value_ - other.value_);
        }

        [[nodiscard]] constexpr Area operator*(double scalar) const noexcept
        {
            return Area(value_ * scalar);
        }

        [[nodiscard]] constexpr Area operator/(double scalar) const noexcept
        {
            return Area(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Area other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Area other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double square_kilometers() const
        {
            return convert_from_base(AreaUnit::SquareKilometers);
        }

        [[nodiscard]] static constexpr Area from_square_kilometers(double value)
        {
            return Area(value, AreaUnit::SquareKilometers);
        }


        [[nodiscard]] constexpr double square_meters() const
        {
            return convert_from_base(AreaUnit::SquareMeters);
        }

        [[nodiscard]] static constexpr Area from_square_meters(double value)
        {
            return Area(value, AreaUnit::SquareMeters);
        }


        [[nodiscard]] constexpr double square_decimeters() const
        {
            return convert_from_base(AreaUnit::SquareDecimeters);
        }

        [[nodiscard]] static constexpr Area from_square_decimeters(double value)
        {
            return Area(value, AreaUnit::SquareDecimeters);
        }


        [[nodiscard]] constexpr double square_centimeters() const
        {
            return convert_from_base(AreaUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr Area from_square_centimeters(double value)
        {
            return Area(value, AreaUnit::SquareCentimeters);
        }


        [[nodiscard]] constexpr double square_millimeters() const
        {
            return convert_from_base(AreaUnit::SquareMillimeters);
        }

        [[nodiscard]] static constexpr Area from_square_millimeters(double value)
        {
            return Area(value, AreaUnit::SquareMillimeters);
        }


        [[nodiscard]] constexpr double square_micrometers() const
        {
            return convert_from_base(AreaUnit::SquareMicrometers);
        }

        [[nodiscard]] static constexpr Area from_square_micrometers(double value)
        {
            return Area(value, AreaUnit::SquareMicrometers);
        }


        [[nodiscard]] constexpr double square_miles() const
        {
            return convert_from_base(AreaUnit::SquareMiles);
        }

        [[nodiscard]] static constexpr Area from_square_miles(double value)
        {
            return Area(value, AreaUnit::SquareMiles);
        }


        [[nodiscard]] constexpr double square_yards() const
        {
            return convert_from_base(AreaUnit::SquareYards);
        }

        [[nodiscard]] static constexpr Area from_square_yards(double value)
        {
            return Area(value, AreaUnit::SquareYards);
        }


        [[nodiscard]] constexpr double square_feet() const
        {
            return convert_from_base(AreaUnit::SquareFeet);
        }

        [[nodiscard]] static constexpr Area from_square_feet(double value)
        {
            return Area(value, AreaUnit::SquareFeet);
        }


        [[nodiscard]] constexpr double us_survey_square_feet() const
        {
            return convert_from_base(AreaUnit::UsSurveySquareFeet);
        }

        [[nodiscard]] static constexpr Area from_us_survey_square_feet(double value)
        {
            return Area(value, AreaUnit::UsSurveySquareFeet);
        }


        [[nodiscard]] constexpr double square_inches() const
        {
            return convert_from_base(AreaUnit::SquareInches);
        }

        [[nodiscard]] static constexpr Area from_square_inches(double value)
        {
            return Area(value, AreaUnit::SquareInches);
        }


        [[nodiscard]] constexpr double acres() const
        {
            return convert_from_base(AreaUnit::Acres);
        }

        [[nodiscard]] static constexpr Area from_acres(double value)
        {
            return Area(value, AreaUnit::Acres);
        }


        [[nodiscard]] constexpr double hectares() const
        {
            return convert_from_base(AreaUnit::Hectares);
        }

        [[nodiscard]] static constexpr Area from_hectares(double value)
        {
            return Area(value, AreaUnit::Hectares);
        }


        [[nodiscard]] constexpr double square_nautical_miles() const
        {
            return convert_from_base(AreaUnit::SquareNauticalMiles);
        }

        [[nodiscard]] static constexpr Area from_square_nautical_miles(double value)
        {
            return Area(value, AreaUnit::SquareNauticalMiles);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AreaUnit unit)
        {
            switch (unit)
            {

            case AreaUnit::SquareKilometers:
                return value * 1e6;

            case AreaUnit::SquareMeters:
                return value;

            case AreaUnit::SquareDecimeters:
                return value * 1e-2;

            case AreaUnit::SquareCentimeters:
                return value * 1e-4;

            case AreaUnit::SquareMillimeters:
                return value * 1e-6;

            case AreaUnit::SquareMicrometers:
                return value * 1e-12;

            case AreaUnit::SquareMiles:
                return value * 1609.344 * 1609.344;

            case AreaUnit::SquareYards:
                return value * 0.9144 * 0.9144;

            case AreaUnit::SquareFeet:
                return value * 9.290304e-2;

            case AreaUnit::UsSurveySquareFeet:
                return value * (1200.0 / 3937.0) * (1200.0 / 3937.0);

            case AreaUnit::SquareInches:
                return value * 0.00064516;

            case AreaUnit::Acres:
                return value * 4046.8564224;

            case AreaUnit::Hectares:
                return value * 1e4;

            case AreaUnit::SquareNauticalMiles:
                return value * 3429904;

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AreaUnit unit) const
        {
            switch (unit)
            {

            case AreaUnit::SquareKilometers:
                return value_ / 1e6;

            case AreaUnit::SquareMeters:
                return value_;

            case AreaUnit::SquareDecimeters:
                return value_ / 1e-2;

            case AreaUnit::SquareCentimeters:
                return value_ / 1e-4;

            case AreaUnit::SquareMillimeters:
                return value_ / 1e-6;

            case AreaUnit::SquareMicrometers:
                return value_ / 1e-12;

            case AreaUnit::SquareMiles:
                return value_ / 1609.344 / 1609.344;

            case AreaUnit::SquareYards:
                return value_ / 0.9144 / 0.9144;

            case AreaUnit::SquareFeet:
                return value_ / 9.290304e-2;

            case AreaUnit::UsSurveySquareFeet:
                return value_ / (1200.0 / 3937.0) / (1200.0 / 3937.0);

            case AreaUnit::SquareInches:
                return value_ / 0.00064516;

            case AreaUnit::Acres:
                return value_ / 4046.8564224;

            case AreaUnit::Hectares:
                return value_ / 1e4;

            case AreaUnit::SquareNauticalMiles:
                return value_ / 3429904;

            }

            throw std::invalid_argument("Unknown Area unit.");
        }

        double value_;
    };
}
