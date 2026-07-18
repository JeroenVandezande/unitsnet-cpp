#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ReciprocalLengthUnit : std::uint16_t
    {
        InverseMeters,
        InverseCentimeters,
        InverseMillimeters,
        InverseMiles,
        InverseYards,
        InverseFeet,
        InverseUsSurveyFeet,
        InverseInches,
        InverseMils,
        InverseMicroinches,
    };

    /// <summary>Reciprocal (Inverse) Length is used in various fields of science and mathematics. It is defined as the inverse value of a length unit.</summary>
    class ReciprocalLength
    {
    public:
        constexpr explicit ReciprocalLength(
            double value,
            ReciprocalLengthUnit unit = ReciprocalLengthUnit::InverseMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ReciprocalLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ReciprocalLength operator+(ReciprocalLength other) const noexcept
        {
            return ReciprocalLength(value_ + other.value_);
        }

        [[nodiscard]] constexpr ReciprocalLength operator-(ReciprocalLength other) const noexcept
        {
            return ReciprocalLength(value_ - other.value_);
        }

        [[nodiscard]] constexpr ReciprocalLength operator*(double scalar) const noexcept
        {
            return ReciprocalLength(value_ * scalar);
        }

        [[nodiscard]] constexpr ReciprocalLength operator/(double scalar) const noexcept
        {
            return ReciprocalLength(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ReciprocalLength other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ReciprocalLength other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double inverse_meters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_meters(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMeters);
        }


        [[nodiscard]] constexpr double inverse_centimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseCentimeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_centimeters(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseCentimeters);
        }


        [[nodiscard]] constexpr double inverse_millimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMillimeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_millimeters(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMillimeters);
        }


        [[nodiscard]] constexpr double inverse_miles() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMiles);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_miles(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMiles);
        }


        [[nodiscard]] constexpr double inverse_yards() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseYards);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_yards(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseYards);
        }


        [[nodiscard]] constexpr double inverse_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseFeet);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_feet(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseFeet);
        }


        [[nodiscard]] constexpr double inverse_us_survey_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseUsSurveyFeet);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_us_survey_feet(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseUsSurveyFeet);
        }


        [[nodiscard]] constexpr double inverse_inches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseInches);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_inches(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseInches);
        }


        [[nodiscard]] constexpr double inverse_mils() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMils);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_mils(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMils);
        }


        [[nodiscard]] constexpr double inverse_microinches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMicroinches);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_microinches(double value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMicroinches);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ReciprocalLengthUnit unit)
        {
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeters:
                return value;

            case ReciprocalLengthUnit::InverseCentimeters:
                return value * 1e2;

            case ReciprocalLengthUnit::InverseMillimeters:
                return value * 1e3;

            case ReciprocalLengthUnit::InverseMiles:
                return value / 1609.344;

            case ReciprocalLengthUnit::InverseYards:
                return value / 0.9144;

            case ReciprocalLengthUnit::InverseFeet:
                return value / 0.3048;

            case ReciprocalLengthUnit::InverseUsSurveyFeet:
                return value * 3937 / 1200;

            case ReciprocalLengthUnit::InverseInches:
                return value / 2.54e-2;

            case ReciprocalLengthUnit::InverseMils:
                return value / 2.54e-5;

            case ReciprocalLengthUnit::InverseMicroinches:
                return value / 2.54e-8;

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ReciprocalLengthUnit unit) const
        {
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeters:
                return value_;

            case ReciprocalLengthUnit::InverseCentimeters:
                return value_ / 1e2;

            case ReciprocalLengthUnit::InverseMillimeters:
                return value_ / 1e3;

            case ReciprocalLengthUnit::InverseMiles:
                return value_ * 1609.344;

            case ReciprocalLengthUnit::InverseYards:
                return value_ * 0.9144;

            case ReciprocalLengthUnit::InverseFeet:
                return value_ * 0.3048;

            case ReciprocalLengthUnit::InverseUsSurveyFeet:
                return value_ * 1200 / 3937;

            case ReciprocalLengthUnit::InverseInches:
                return value_ * 2.54e-2;

            case ReciprocalLengthUnit::InverseMils:
                return value_ * 2.54e-5;

            case ReciprocalLengthUnit::InverseMicroinches:
                return value_ * 2.54e-8;

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        double value_;
    };
}
