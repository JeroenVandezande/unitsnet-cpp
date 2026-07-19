#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class FluidResistanceUnit : std::uint8_t
    {
        PascalSecondsPerLiter,
        PascalMinutesPerLiter,
        PascalSecondsPerMilliliter,
        PascalMinutesPerMilliliter,
        PascalSecondsPerCubicMeter,
        MegapascalSecondsPerCubicMeter,
        PascalMinutesPerCubicMeter,
        PascalSecondsPerCubicCentimeter,
        PascalMinutesPerCubicCentimeter,
        DyneSecondsPerCentimeterToTheFifth,
        MillimeterMercurySecondsPerLiter,
        MillimeterMercuryMinutesPerLiter,
        MillimeterMercurySecondsPerMilliliter,
        MillimeterMercuryMinutesPerMilliliter,
        MillimeterMercurySecondsPerCubicCentimeter,
        MillimeterMercuryMinutesPerCubicCentimeter,
        MillimeterMercurySecondsPerCubicMeter,
        MillimeterMercuryMinutesPerCubicMeter,
        WoodUnits,
    };

    /// <summary>Fluid Resistance is a force acting opposite to the relative motion of any object moving with respect to a surrounding fluid. Fluid Resistance is sometimes referred to as drag or fluid friction.</summary>
    class FluidResistance : public UnitsNetBase
    {
    public:
        constexpr explicit FluidResistance(
            const un_scalar_t value,
            const FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondsPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == FluidResistanceUnit::PascalSecondsPerCubicMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const FluidResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr FluidResistance operator+(const FluidResistance& other) const noexcept
        {
            return FluidResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr FluidResistance operator-(const FluidResistance& other)const noexcept
        {
            return FluidResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr FluidResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr FluidResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const FluidResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const FluidResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const FluidResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megapascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_megapascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t dyne_seconds_per_centimeter_to_the_fifth() const
        {
            return convert_from_base(FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }

        [[nodiscard]] static constexpr FluidResistance from_dyne_seconds_per_centimeter_to_the_fifth(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t wood_units() const
        {
            return convert_from_base(FluidResistanceUnit::WoodUnits);
        }

        [[nodiscard]] static constexpr FluidResistance from_wood_units(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::WoodUnits);
        }


        [[nodiscard]] static constexpr FluidResistance from_invalid()
        {
            return FluidResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FluidResistanceUnit unit)
        {
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondsPerLiter:
                return value * static_cast<un_scalar_t>(1e3);

            case FluidResistanceUnit::PascalMinutesPerLiter:
                return value * static_cast<un_scalar_t>(6e4);

            case FluidResistanceUnit::PascalSecondsPerMilliliter:
                return value * static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerMilliliter:
                return value * static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::PascalSecondsPerCubicMeter:
                return value;

            case FluidResistanceUnit::MegapascalSecondsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case FluidResistanceUnit::PascalMinutesPerCubicMeter:
                return value * static_cast<un_scalar_t>(60);

            case FluidResistanceUnit::PascalSecondsPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth:
                return value * static_cast<un_scalar_t>(1e5);

            case FluidResistanceUnit::MillimeterMercurySecondsPerLiter:
                return value * static_cast<un_scalar_t>(1.33322368e5);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerLiter:
                return value * static_cast<un_scalar_t>(7.99934208e6);

            case FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter:
                return value * static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter:
                return value * static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter:
                return value * static_cast<un_scalar_t>(133.322368);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter:
                return value * static_cast<un_scalar_t>(7.99934208e3);

            case FluidResistanceUnit::WoodUnits:
                return value * static_cast<un_scalar_t>(7.99934208e6);

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FluidResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondsPerLiter:
                return base_value_ / static_cast<un_scalar_t>(1e3);

            case FluidResistanceUnit::PascalMinutesPerLiter:
                return base_value_ / static_cast<un_scalar_t>(6e4);

            case FluidResistanceUnit::PascalSecondsPerMilliliter:
                return base_value_ / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerMilliliter:
                return base_value_ / static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::PascalSecondsPerCubicMeter:
                return base_value_;

            case FluidResistanceUnit::MegapascalSecondsPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerCubicMeter:
                return base_value_ / static_cast<un_scalar_t>(60);

            case FluidResistanceUnit::PascalSecondsPerCubicCentimeter:
                return base_value_ / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerCubicCentimeter:
                return base_value_ / static_cast<un_scalar_t>(6e7);

            case FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth:
                return base_value_ / static_cast<un_scalar_t>(1e5);

            case FluidResistanceUnit::MillimeterMercurySecondsPerLiter:
                return base_value_ / static_cast<un_scalar_t>(1.33322368e5);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerLiter:
                return base_value_ / static_cast<un_scalar_t>(7.99934208e6);

            case FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter:
                return base_value_ / static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter:
                return base_value_ / static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter:
                return base_value_ / static_cast<un_scalar_t>(1.33322368e8);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter:
                return base_value_ / static_cast<un_scalar_t>(7.99934208e9);

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter:
                return base_value_ / static_cast<un_scalar_t>(133.322368);

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter:
                return base_value_ / static_cast<un_scalar_t>(7.99934208e3);

            case FluidResistanceUnit::WoodUnits:
                return base_value_ / static_cast<un_scalar_t>(7.99934208e6);

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        un_scalar_t value_;
        FluidResistanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
