#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RotationalStiffnessPerLengthUnit : std::uint8_t
    {
        NewtonMetersPerRadianPerMeter,
        KilonewtonMetersPerRadianPerMeter,
        MeganewtonMetersPerRadianPerMeter,
        PoundForceFeetPerDegreesPerFeet,
        KilopoundForceFeetPerDegreesPerFeet,
    };

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffnessPerLength : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalStiffnessPerLength(
            const un_scalar_t value,
            const RotationalStiffnessPerLengthUnit unit = RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const RotationalStiffnessPerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator+(const RotationalStiffnessPerLength& other) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator-(const RotationalStiffnessPerLength& other)const noexcept
        {
            return RotationalStiffnessPerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffnessPerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffnessPerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalStiffnessPerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t newton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_newton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilonewton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_radian_per_meter() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_meganewton_meters_per_radian_per_meter(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_pound_force_feet_per_degrees_per_feet(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_degrees_per_feet() const
        {
            return convert_from_base(RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet);
        }

        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_kilopound_force_feet_per_degrees_per_feet(const un_scalar_t value)
        {
            return RotationalStiffnessPerLength(value, RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet);
        }


        [[nodiscard]] static constexpr RotationalStiffnessPerLength from_invalid()
        {
            return RotationalStiffnessPerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalStiffnessPerLengthUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter:
                return value;

            case RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet:
                return value * (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalStiffnessPerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case RotationalStiffnessPerLengthUnit::NewtonMetersPerRadianPerMeter:
                return base_value_;

            case RotationalStiffnessPerLengthUnit::KilonewtonMetersPerRadianPerMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessPerLengthUnit::MeganewtonMetersPerRadianPerMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessPerLengthUnit::PoundForceFeetPerDegreesPerFeet:
                return base_value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessPerLengthUnit::KilopoundForceFeetPerDegreesPerFeet:
                return base_value_ / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown RotationalStiffnessPerLength unit.");
        }

        un_scalar_t value_;
        RotationalStiffnessPerLengthUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
