#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class JerkUnit : std::uint8_t
    {
        MetersPerSecondCubed,
        NanometersPerSecondCubed,
        MicrometersPerSecondCubed,
        MillimetersPerSecondCubed,
        CentimetersPerSecondCubed,
        DecimetersPerSecondCubed,
        KilometersPerSecondCubed,
        InchesPerSecondCubed,
        FeetPerSecondCubed,
        StandardGravitiesPerSecond,
        MillistandardGravitiesPerSecond,
    };

    /// <summary></summary>
    class Jerk : public UnitsNetBase
    {
    public:
        constexpr explicit Jerk(
            const un_scalar_t value,
            const JerkUnit unit = JerkUnit::MetersPerSecondCubed)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == JerkUnit::MetersPerSecondCubed)
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

        [[nodiscard]] constexpr un_scalar_t value(const JerkUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Jerk operator+(const Jerk& other) const noexcept
        {
            return Jerk(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Jerk operator-(const Jerk& other)const noexcept
        {
            return Jerk(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Jerk operator*(const un_scalar_t scalar) const noexcept
        {
            return Jerk(base_value() * scalar);
        }

        [[nodiscard]] constexpr Jerk operator/(const un_scalar_t scalar) const noexcept
        {
            return Jerk(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Jerk& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Jerk& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Jerk& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t meters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_meters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MetersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t nanometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::NanometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_nanometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::NanometersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t micrometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MicrometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_micrometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MicrometersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MillimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_millimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MillimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::CentimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_centimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::CentimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::DecimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_decimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::DecimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t kilometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::KilometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_kilometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::KilometersPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t inches_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::InchesPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_inches_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::InchesPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t feet_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::FeetPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_feet_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::FeetPerSecondCubed);
        }


        [[nodiscard]] constexpr un_scalar_t standard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::StandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_standard_gravities_per_second(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::StandardGravitiesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millistandard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::MillistandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_millistandard_gravities_per_second(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MillistandardGravitiesPerSecond);
        }


        [[nodiscard]] static constexpr Jerk from_invalid()
        {
            return Jerk(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, JerkUnit unit)
        {
            switch (unit)
            {

            case JerkUnit::MetersPerSecondCubed:
                return value;

            case JerkUnit::NanometersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-9));

            case JerkUnit::MicrometersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-6));

            case JerkUnit::MillimetersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-3));

            case JerkUnit::CentimetersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-2));

            case JerkUnit::DecimetersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-1));

            case JerkUnit::KilometersPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e3));

            case JerkUnit::InchesPerSecondCubed:
                return value * static_cast<un_scalar_t>(0.0254);

            case JerkUnit::FeetPerSecondCubed:
                return value * static_cast<un_scalar_t>(0.304800);

            case JerkUnit::StandardGravitiesPerSecond:
                return value * static_cast<un_scalar_t>(9.80665);

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665);

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const JerkUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case JerkUnit::MetersPerSecondCubed:
                return base_value_;

            case JerkUnit::NanometersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case JerkUnit::MicrometersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case JerkUnit::MillimetersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case JerkUnit::CentimetersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e-2);

            case JerkUnit::DecimetersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e-1);

            case JerkUnit::KilometersPerSecondCubed:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case JerkUnit::InchesPerSecondCubed:
                return base_value_ / static_cast<un_scalar_t>(0.0254);

            case JerkUnit::FeetPerSecondCubed:
                return base_value_ / static_cast<un_scalar_t>(0.304800);

            case JerkUnit::StandardGravitiesPerSecond:
                return base_value_ / static_cast<un_scalar_t>(9.80665);

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(9.80665)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        un_scalar_t value_;
        JerkUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
