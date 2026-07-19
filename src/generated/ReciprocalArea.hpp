#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ReciprocalAreaUnit : std::uint8_t
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
    class ReciprocalArea : public UnitsNetBase
    {
    public:
        constexpr explicit ReciprocalArea(
            const un_scalar_t value,
            const ReciprocalAreaUnit unit = ReciprocalAreaUnit::InverseSquareMeters)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ReciprocalAreaUnit::InverseSquareMeters)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ReciprocalAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

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
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_meters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_kilometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareKilometers);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_kilometers(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareKilometers);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_decimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareDecimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_decimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_centimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareCentimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_centimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_millimeters() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMillimeters);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_millimeters(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_micrometers() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMicrometers);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_micrometers(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_miles() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareMiles);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_miles(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareMiles);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_yards() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareYards);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_yards(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareYards);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareFeet);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_feet(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareFeet);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_us_survey_square_feet() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseUsSurveySquareFeet);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_us_survey_square_feet(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseUsSurveySquareFeet);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_square_inches() const
        {
            return convert_from_base(ReciprocalAreaUnit::InverseSquareInches);
        }

        [[nodiscard]] static constexpr ReciprocalArea from_inverse_square_inches(const un_scalar_t value)
        {
            return ReciprocalArea(value, ReciprocalAreaUnit::InverseSquareInches);
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

            case ReciprocalAreaUnit::InverseSquareMeters:
                return value;

            case ReciprocalAreaUnit::InverseSquareKilometers:
                return value / static_cast<un_scalar_t>(1e6);

            case ReciprocalAreaUnit::InverseSquareDecimeters:
                return value / static_cast<un_scalar_t>(1e-2);

            case ReciprocalAreaUnit::InverseSquareCentimeters:
                return value / static_cast<un_scalar_t>(1e-4);

            case ReciprocalAreaUnit::InverseSquareMillimeters:
                return value / static_cast<un_scalar_t>(1e-6);

            case ReciprocalAreaUnit::InverseSquareMicrometers:
                return value / static_cast<un_scalar_t>(1e-12);

            case ReciprocalAreaUnit::InverseSquareMiles:
                return value / (static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344));

            case ReciprocalAreaUnit::InverseSquareYards:
                return value / (static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144));

            case ReciprocalAreaUnit::InverseSquareFeet:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            case ReciprocalAreaUnit::InverseUsSurveySquareFeet:
                return value / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) / (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case ReciprocalAreaUnit::InverseSquareInches:
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
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ReciprocalAreaUnit::InverseSquareMeters:
                return base_value_;

            case ReciprocalAreaUnit::InverseSquareKilometers:
                return base_value_ * static_cast<un_scalar_t>(1e6);

            case ReciprocalAreaUnit::InverseSquareDecimeters:
                return base_value_ * static_cast<un_scalar_t>(1e-2);

            case ReciprocalAreaUnit::InverseSquareCentimeters:
                return base_value_ * static_cast<un_scalar_t>(1e-4);

            case ReciprocalAreaUnit::InverseSquareMillimeters:
                return base_value_ * static_cast<un_scalar_t>(1e-6);

            case ReciprocalAreaUnit::InverseSquareMicrometers:
                return base_value_ * static_cast<un_scalar_t>(1e-12);

            case ReciprocalAreaUnit::InverseSquareMiles:
                return base_value_ * (static_cast<un_scalar_t>(1609.344) * static_cast<un_scalar_t>(1609.344));

            case ReciprocalAreaUnit::InverseSquareYards:
                return base_value_ * (static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(0.9144));

            case ReciprocalAreaUnit::InverseSquareFeet:
                return base_value_ * static_cast<un_scalar_t>(9.290304e-2);

            case ReciprocalAreaUnit::InverseUsSurveySquareFeet:
                return base_value_ * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0)) * (static_cast<un_scalar_t>(1200.0) / static_cast<un_scalar_t>(3937.0));

            case ReciprocalAreaUnit::InverseSquareInches:
                return base_value_ * static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ReciprocalArea unit.");
        }

        un_scalar_t value_;
        ReciprocalAreaUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
