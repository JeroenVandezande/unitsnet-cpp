#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class AreaMomentOfInertiaUnit : std::uint8_t
    {
        MetersToTheFourth,
        DecimetersToTheFourth,
        CentimetersToTheFourth,
        MillimetersToTheFourth,
        FeetToTheFourth,
        InchesToTheFourth,
    };

    /// <summary>A geometric property of an area that reflects how its points are distributed with regard to an axis.</summary>
    class AreaMomentOfInertia
    {
    public:
        constexpr explicit AreaMomentOfInertia(
            const un_scalar_t value,
            const AreaMomentOfInertiaUnit unit = AreaMomentOfInertiaUnit::MetersToTheFourth)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit AreaMomentOfInertia(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const AreaMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator+(const AreaMomentOfInertia other) const noexcept
        {
            return AreaMomentOfInertia(value_ + other.value_);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator-(const AreaMomentOfInertia other) const noexcept
        {
            return AreaMomentOfInertia(value_ - other.value_);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return AreaMomentOfInertia(value_ * scalar);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return AreaMomentOfInertia(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AreaMomentOfInertia other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const AreaMomentOfInertia other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const AreaMomentOfInertia other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t meters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_meters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MetersToTheFourth);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::DecimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_decimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::DecimetersToTheFourth);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::CentimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_centimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::CentimetersToTheFourth);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MillimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_millimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MillimetersToTheFourth);
        }


        [[nodiscard]] constexpr un_scalar_t feet_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::FeetToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_feet_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::FeetToTheFourth);
        }


        [[nodiscard]] constexpr un_scalar_t inches_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::InchesToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_inches_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::InchesToTheFourth);
        }


        [[nodiscard]] static constexpr AreaMomentOfInertia from_invalid()
        {
            return AreaMomentOfInertia(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MetersToTheFourth:
                return value;

            case AreaMomentOfInertiaUnit::DecimetersToTheFourth:
                return value / static_cast<un_scalar_t>(1e4);

            case AreaMomentOfInertiaUnit::CentimetersToTheFourth:
                return value / static_cast<un_scalar_t>(1e8);

            case AreaMomentOfInertiaUnit::MillimetersToTheFourth:
                return value / static_cast<un_scalar_t>(1e12);

            case AreaMomentOfInertiaUnit::FeetToTheFourth:
                return value * static_cast<un_scalar_t>(0.0086309748412416);

            case AreaMomentOfInertiaUnit::InchesToTheFourth:
                return value * static_cast<un_scalar_t>(0.0000004162314256);

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaMomentOfInertiaUnit unit) const
        {
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MetersToTheFourth:
                return value_;

            case AreaMomentOfInertiaUnit::DecimetersToTheFourth:
                return value_ * static_cast<un_scalar_t>(1e4);

            case AreaMomentOfInertiaUnit::CentimetersToTheFourth:
                return value_ * static_cast<un_scalar_t>(1e8);

            case AreaMomentOfInertiaUnit::MillimetersToTheFourth:
                return value_ * static_cast<un_scalar_t>(1e12);

            case AreaMomentOfInertiaUnit::FeetToTheFourth:
                return value_ / static_cast<un_scalar_t>(0.0086309748412416);

            case AreaMomentOfInertiaUnit::InchesToTheFourth:
                return value_ / static_cast<un_scalar_t>(0.0000004162314256);

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        un_scalar_t value_;
    };
}
