#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class WarpingMomentOfInertiaUnit : std::uint8_t
    {
        MetersToTheSixth,
        DecimetersToTheSixth,
        CentimetersToTheSixth,
        MillimetersToTheSixth,
        FeetToTheSixth,
        InchesToTheSixth,
    };

    /// <summary>A geometric property of an area that is used to determine the warping stress.</summary>
    class WarpingMomentOfInertia : public UnitsNetBase
    {
    public:
        constexpr explicit WarpingMomentOfInertia(
            const un_scalar_t value,
            const WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MetersToTheSixth)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == WarpingMomentOfInertiaUnit::MetersToTheSixth)
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
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const WarpingMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator+(const WarpingMomentOfInertia& other) const noexcept
        {
            return WarpingMomentOfInertia(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator-(const WarpingMomentOfInertia& other)const noexcept
        {
            return WarpingMomentOfInertia(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(base_value() * scalar);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t meters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_meters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_decimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_centimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_millimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t feet_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_feet_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t inches_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_inches_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }


        [[nodiscard]] static constexpr WarpingMomentOfInertia from_invalid()
        {
            return WarpingMomentOfInertia(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, WarpingMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return value;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return value * static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return value * static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const WarpingMomentOfInertiaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return base_value_;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return base_value_ * static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return base_value_ * static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return base_value_ * static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return base_value_ / static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return base_value_ / static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        un_scalar_t value_;
        WarpingMomentOfInertiaUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
