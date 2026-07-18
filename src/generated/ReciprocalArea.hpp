#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ReciprocalAreaUnit : std::uint16_t
    {
        InverseSquareMeters,
        InverseSquareKilometers,
        InverseSquareDecimeters,
        InverseSquareCentimeters,
        InverseSquareMillimeters,
        InverseSquareMicrometers,
        InverseSquareMiles,
        InverseSquareYards,
        InverseSquareFeet,
        InverseUsSurveySquareFeet,
        InverseSquareInches,
    };

    /// <summary>Reciprocal area (Inverse-square) quantity is used to specify a physical quantity inversely proportional to the square of the distance.</summary>
    class ReciprocalArea
    {
    public:
        constexpr explicit ReciprocalArea(
            double value,
            ReciprocalAreaUnit unit = ReciprocalAreaUnit::InverseSquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ReciprocalAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ReciprocalArea operator+(ReciprocalArea other) const noexcept
        {
            return ReciprocalArea(value_ + other.value_);
        }

        [[nodiscard]] constexpr ReciprocalArea operator-(ReciprocalArea other) const noexcept
        {
            return ReciprocalArea(value_ - other.value_);
        }

        [[nodiscard]] constexpr ReciprocalArea operator*(double scalar) const noexcept
        {
            return ReciprocalArea(value_ * scalar);
        }

        [[nodiscard]] constexpr ReciprocalArea operator/(double scalar) const noexcept
        {
            return ReciprocalArea(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ReciprocalArea other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ReciprocalArea other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double inverse_square_meters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_meters(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMeters);
        }


        [[nodiscard]] constexpr double inverse_square_kilometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareKilometers);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_kilometers(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareKilometers);
        }


        [[nodiscard]] constexpr double inverse_square_decimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareDecimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_decimeters(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareDecimeters);
        }


        [[nodiscard]] constexpr double inverse_square_centimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareCentimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_centimeters(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareCentimeters);
        }


        [[nodiscard]] constexpr double inverse_square_millimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMillimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_millimeters(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMillimeters);
        }


        [[nodiscard]] constexpr double inverse_square_micrometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMicrometers);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_micrometers(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMicrometers);
        }


        [[nodiscard]] constexpr double inverse_square_miles() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMiles);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_miles(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMiles);
        }


        [[nodiscard]] constexpr double inverse_square_yards() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareYards);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_yards(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareYards);
        }


        [[nodiscard]] constexpr double inverse_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareFeet);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_feet(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareFeet);
        }


        [[nodiscard]] constexpr double inverse_us_survey_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseUsSurveySquareFeet);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_us_survey_square_feet(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseUsSurveySquareFeet);
        }


        [[nodiscard]] constexpr double inverse_square_inches() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareInches);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_inches(double value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareInches);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ReciprocalAreaUnit unit)
        {
            switch (unit)
            {

            case ReciprocalAreaUnit::InverseSquareMeters:
                return value;

            case ReciprocalAreaUnit::InverseSquareKilometers:
                return value / 1e6;

            case ReciprocalAreaUnit::InverseSquareDecimeters:
                return value / 1e-2;

            case ReciprocalAreaUnit::InverseSquareCentimeters:
                return value / 1e-4;

            case ReciprocalAreaUnit::InverseSquareMillimeters:
                return value / 1e-6;

            case ReciprocalAreaUnit::InverseSquareMicrometers:
                return value / 1e-12;

            case ReciprocalAreaUnit::InverseSquareMiles:
                return value / (1609.344 * 1609.344);

            case ReciprocalAreaUnit::InverseSquareYards:
                return value / (0.9144 * 0.9144);

            case ReciprocalAreaUnit::InverseSquareFeet:
                return value / 9.290304e-2;

            case ReciprocalAreaUnit::InverseUsSurveySquareFeet:
                return value / (1200.0 / 3937.0) / (1200.0 / 3937.0);

            case ReciprocalAreaUnit::InverseSquareInches:
                return value / 0.00064516;

            }

            throw std::invalid_argument("Unknown ReciprocalArea unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ReciprocalAreaUnit unit) const
        {
            switch (unit)
            {

            case ReciprocalAreaUnit::InverseSquareMeters:
                return value_;

            case ReciprocalAreaUnit::InverseSquareKilometers:
                return value_ * 1e6;

            case ReciprocalAreaUnit::InverseSquareDecimeters:
                return value_ * 1e-2;

            case ReciprocalAreaUnit::InverseSquareCentimeters:
                return value_ * 1e-4;

            case ReciprocalAreaUnit::InverseSquareMillimeters:
                return value_ * 1e-6;

            case ReciprocalAreaUnit::InverseSquareMicrometers:
                return value_ * 1e-12;

            case ReciprocalAreaUnit::InverseSquareMiles:
                return value_ * (1609.344 * 1609.344);

            case ReciprocalAreaUnit::InverseSquareYards:
                return value_ * (0.9144 * 0.9144);

            case ReciprocalAreaUnit::InverseSquareFeet:
                return value_ * 9.290304e-2;

            case ReciprocalAreaUnit::InverseUsSurveySquareFeet:
                return value_ * (1200.0 / 3937.0) * (1200.0 / 3937.0);

            case ReciprocalAreaUnit::InverseSquareInches:
                return value_ * 0.00064516;

            }

            throw std::invalid_argument("Unknown ReciprocalArea unit.");
        }

        double value_;
    };
}
