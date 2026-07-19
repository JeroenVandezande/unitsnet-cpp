#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ForceUnit : std::uint8_t
    {
        Dyne,
        GramsForce,
        KilogramsForce,
        TonnesForce,
        Newtons,
        Micronewtons,
        Millinewtons,
        Decanewtons,
        Kilonewtons,
        Meganewtons,
        Kiloponds,
        Poundals,
        PoundsForce,
        KilopoundsForce,
        OunceForce,
        ShortTonsForce,
    };

    /// <summary>In physics, a force is any influence that causes an object to undergo a certain change, either concerning its movement, direction, or geometrical construction. In other words, a force can cause an object with mass to change its velocity (which includes to begin moving from a state of rest), i.e., to accelerate, or a flexible object to deform, or both. Force can also be described by intuitive concepts such as a push or a pull. A force has both magnitude and direction, making it a vector quantity. It is measured in the SI unit of newtons and represented by the symbol F.</summary>
    class Force : public UnitsNetBase
    {
    public:
        constexpr explicit Force(
            const un_scalar_t value,
            const ForceUnit unit = ForceUnit::Newtons)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ForceUnit::Newtons)
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

        [[nodiscard]] constexpr un_scalar_t value(const ForceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Force operator+(const Force& other) const noexcept
        {
            return Force(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Force operator-(const Force& other)const noexcept
        {
            return Force(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Force operator*(const un_scalar_t scalar) const noexcept
        {
            return Force(base_value() * scalar);
        }

        [[nodiscard]] constexpr Force operator/(const un_scalar_t scalar) const noexcept
        {
            return Force(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Force& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Force& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Force& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        /// <summary>One dyne is equal to 10 micronewtons, 10e−5 N or to 10 nsn (nanosthenes) in the old metre–tonne–second system of units.</summary>
        [[nodiscard]] constexpr un_scalar_t dyne() const
        {
            return convert_from_base(ForceUnit::Dyne);
        }

        /// <summary>One dyne is equal to 10 micronewtons, 10e−5 N or to 10 nsn (nanosthenes) in the old metre–tonne–second system of units.</summary>
        [[nodiscard]] static constexpr Force from_dyne(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Dyne);
        }


        /// <summary>The gram-force is a unit of force equal to the magnitude of force exerted by a gram of mass in standard gravity (9.80665 m/s²). It is equal to 9.80665 × 10⁻³ N.</summary>
        [[nodiscard]] constexpr un_scalar_t grams_force() const
        {
            return convert_from_base(ForceUnit::GramsForce);
        }

        /// <summary>The gram-force is a unit of force equal to the magnitude of force exerted by a gram of mass in standard gravity (9.80665 m/s²). It is equal to 9.80665 × 10⁻³ N.</summary>
        [[nodiscard]] static constexpr Force from_grams_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::GramsForce);
        }


        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kilograms_force() const
        {
            return convert_from_base(ForceUnit::KilogramsForce);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] static constexpr Force from_kilograms_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilogramsForce);
        }


        /// <summary>The tonne-force, metric ton-force, megagram-force, and megapond (Mp) are each 1000 kilograms-force.</summary>
        [[nodiscard]] constexpr un_scalar_t tonnes_force() const
        {
            return convert_from_base(ForceUnit::TonnesForce);
        }

        /// <summary>The tonne-force, metric ton-force, megagram-force, and megapond (Mp) are each 1000 kilograms-force.</summary>
        [[nodiscard]] static constexpr Force from_tonnes_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::TonnesForce);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t newtons() const
        {
            return convert_from_base(ForceUnit::Newtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_newtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Newtons);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t micronewtons() const
        {
            return convert_from_base(ForceUnit::Micronewtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_micronewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Micronewtons);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millinewtons() const
        {
            return convert_from_base(ForceUnit::Millinewtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_millinewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Millinewtons);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t decanewtons() const
        {
            return convert_from_base(ForceUnit::Decanewtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_decanewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Decanewtons);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilonewtons() const
        {
            return convert_from_base(ForceUnit::Kilonewtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_kilonewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kilonewtons);
        }


        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t meganewtons() const
        {
            return convert_from_base(ForceUnit::Meganewtons);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_meganewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Meganewtons);
        }


        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloponds() const
        {
            return convert_from_base(ForceUnit::Kiloponds);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] static constexpr Force from_kiloponds(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kiloponds);
        }


        /// <summary>The poundal is defined as the force necessary to accelerate 1 pound-mass at 1 foot per second per second. 1 pdl = 0.138254954376 N exactly.</summary>
        [[nodiscard]] constexpr un_scalar_t poundals() const
        {
            return convert_from_base(ForceUnit::Poundals);
        }

        /// <summary>The poundal is defined as the force necessary to accelerate 1 pound-mass at 1 foot per second per second. 1 pdl = 0.138254954376 N exactly.</summary>
        [[nodiscard]] static constexpr Force from_poundals(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Poundals);
        }


        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] constexpr un_scalar_t pounds_force() const
        {
            return convert_from_base(ForceUnit::PoundsForce);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] static constexpr Force from_pounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::PoundsForce);
        }


        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kilopounds_force() const
        {
            return convert_from_base(ForceUnit::KilopoundsForce);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] static constexpr Force from_kilopounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilopoundsForce);
        }


        /// <summary>An ounce-force is 1⁄16 of a pound-force, or about 0.2780139 newtons.</summary>
        [[nodiscard]] constexpr un_scalar_t ounce_force() const
        {
            return convert_from_base(ForceUnit::OunceForce);
        }

        /// <summary>An ounce-force is 1⁄16 of a pound-force, or about 0.2780139 newtons.</summary>
        [[nodiscard]] static constexpr Force from_ounce_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::OunceForce);
        }


        /// <summary>The short ton-force is a unit of force equal to 2,000 pounds-force (907.18474 kgf), that is most commonly used in the United States – known there simply as the ton or US ton.</summary>
        [[nodiscard]] constexpr un_scalar_t short_tons_force() const
        {
            return convert_from_base(ForceUnit::ShortTonsForce);
        }

        /// <summary>The short ton-force is a unit of force equal to 2,000 pounds-force (907.18474 kgf), that is most commonly used in the United States – known there simply as the ton or US ton.</summary>
        [[nodiscard]] static constexpr Force from_short_tons_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::ShortTonsForce);
        }


        [[nodiscard]] static constexpr Force from_invalid()
        {
            return Force(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForceUnit unit)
        {
            switch (unit)
            {

            case ForceUnit::Dyne:
                return value / static_cast<un_scalar_t>(1e5);

            case ForceUnit::GramsForce:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case ForceUnit::KilogramsForce:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForceUnit::TonnesForce:
                return value * (static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(1000));

            case ForceUnit::Newtons:
                return value;

            case ForceUnit::Micronewtons:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForceUnit::Millinewtons:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForceUnit::Decanewtons:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForceUnit::Kilonewtons:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForceUnit::Meganewtons:
                return (value * static_cast<un_scalar_t>(1e6));

            case ForceUnit::Kiloponds:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForceUnit::Poundals:
                return value * static_cast<un_scalar_t>(0.138254954376);

            case ForceUnit::PoundsForce:
                return value * static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::KilopoundsForce:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::OunceForce:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(16));

            case ForceUnit::ShortTonsForce:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2000));

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ForceUnit::Dyne:
                return base_value_ * static_cast<un_scalar_t>(1e5);

            case ForceUnit::GramsForce:
                return base_value_ / static_cast<un_scalar_t>(9.80665e-3);

            case ForceUnit::KilogramsForce:
                return base_value_ / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::TonnesForce:
                return base_value_ / (static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(1000));

            case ForceUnit::Newtons:
                return base_value_;

            case ForceUnit::Micronewtons:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ForceUnit::Millinewtons:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ForceUnit::Decanewtons:
                return (base_value_) / static_cast<un_scalar_t>(1e1);

            case ForceUnit::Kilonewtons:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::Meganewtons:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ForceUnit::Kiloponds:
                return base_value_ / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::Poundals:
                return base_value_ / static_cast<un_scalar_t>(0.138254954376);

            case ForceUnit::PoundsForce:
                return base_value_ / static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::KilopoundsForce:
                return (base_value_ / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::OunceForce:
                return base_value_ / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(16));

            case ForceUnit::ShortTonsForce:
                return base_value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2000));

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        un_scalar_t value_;
        ForceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
