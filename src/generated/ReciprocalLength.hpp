#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ReciprocalLengthUnit : std::uint8_t
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
            const un_scalar_t value,
            const ReciprocalLengthUnit unit = ReciprocalLengthUnit::InverseMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ReciprocalLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ReciprocalLength operator+(const ReciprocalLength other) const noexcept
        {
            return ReciprocalLength(value_ + other.value_);
        }

        [[nodiscard]] constexpr ReciprocalLength operator-(const ReciprocalLength other) const noexcept
        {
            return ReciprocalLength(value_ - other.value_);
        }

        [[nodiscard]] constexpr ReciprocalLength operator*(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalLength(value_ * scalar);
        }

        [[nodiscard]] constexpr ReciprocalLength operator/(const un_scalar_t scalar) const noexcept
        {
            return ReciprocalLength(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ReciprocalLength other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ReciprocalLength other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t inverse_meters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_meters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_centimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseCentimeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_centimeters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_millimeters() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMillimeters);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_millimeters(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_miles() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMiles);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_miles(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMiles);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_yards() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseYards);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_yards(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseYards);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseFeet);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_feet(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseFeet);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_us_survey_feet() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseUsSurveyFeet);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_us_survey_feet(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseUsSurveyFeet);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_inches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseInches);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_inches(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseInches);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_mils() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMils);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_mils(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMils);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_microinches() const
        {
            return convert_from_base(ReciprocalLengthUnit::InverseMicroinches);
        }

        [[nodiscard]] static constexpr ReciprocalLength from_inverse_microinches(const un_scalar_t value)
        {
            return ReciprocalLength(value, ReciprocalLengthUnit::InverseMicroinches);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ReciprocalLengthUnit unit)
        {
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeters:
                return value;

            case ReciprocalLengthUnit::InverseCentimeters:
                return value * static_cast<un_scalar_t>(1e2);

            case ReciprocalLengthUnit::InverseMillimeters:
                return value * static_cast<un_scalar_t>(1e3);

            case ReciprocalLengthUnit::InverseMiles:
                return value / static_cast<un_scalar_t>(1609.344);

            case ReciprocalLengthUnit::InverseYards:
                return value / static_cast<un_scalar_t>(0.9144);

            case ReciprocalLengthUnit::InverseFeet:
                return value / static_cast<un_scalar_t>(0.3048);

            case ReciprocalLengthUnit::InverseUsSurveyFeet:
                return value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case ReciprocalLengthUnit::InverseInches:
                return value / static_cast<un_scalar_t>(2.54e-2);

            case ReciprocalLengthUnit::InverseMils:
                return value / static_cast<un_scalar_t>(2.54e-5);

            case ReciprocalLengthUnit::InverseMicroinches:
                return value / static_cast<un_scalar_t>(2.54e-8);

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ReciprocalLengthUnit unit) const
        {
            switch (unit)
            {

            case ReciprocalLengthUnit::InverseMeters:
                return value_;

            case ReciprocalLengthUnit::InverseCentimeters:
                return value_ / static_cast<un_scalar_t>(1e2);

            case ReciprocalLengthUnit::InverseMillimeters:
                return value_ / static_cast<un_scalar_t>(1e3);

            case ReciprocalLengthUnit::InverseMiles:
                return value_ * static_cast<un_scalar_t>(1609.344);

            case ReciprocalLengthUnit::InverseYards:
                return value_ * static_cast<un_scalar_t>(0.9144);

            case ReciprocalLengthUnit::InverseFeet:
                return value_ * static_cast<un_scalar_t>(0.3048);

            case ReciprocalLengthUnit::InverseUsSurveyFeet:
                return value_ * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case ReciprocalLengthUnit::InverseInches:
                return value_ * static_cast<un_scalar_t>(2.54e-2);

            case ReciprocalLengthUnit::InverseMils:
                return value_ * static_cast<un_scalar_t>(2.54e-5);

            case ReciprocalLengthUnit::InverseMicroinches:
                return value_ * static_cast<un_scalar_t>(2.54e-8);

            }

            throw std::invalid_argument("Unknown ReciprocalLength unit.");
        }

        un_scalar_t value_;
    };
}
