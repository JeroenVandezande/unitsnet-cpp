#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class Force
    {
    public:
        constexpr explicit Force(
            const un_scalar_t value,
            const ForceUnit unit = ForceUnit::Newtons)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Force(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ForceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Force operator+(const Force other) const noexcept
        {
            return Force(value_ + other.value_);
        }

        [[nodiscard]] constexpr Force operator-(const Force other) const noexcept
        {
            return Force(value_ - other.value_);
        }

        [[nodiscard]] constexpr Force operator*(const un_scalar_t scalar) const noexcept
        {
            return Force(value_ * scalar);
        }

        [[nodiscard]] constexpr Force operator/(const un_scalar_t scalar) const noexcept
        {
            return Force(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Force other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Force other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Force other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t dyne() const
        {
            return convert_from_base(ForceUnit::Dyne);
        }

        [[nodiscard]] static constexpr Force from_dyne(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Dyne);
        }


        [[nodiscard]] constexpr un_scalar_t grams_force() const
        {
            return convert_from_base(ForceUnit::GramsForce);
        }

        [[nodiscard]] static constexpr Force from_grams_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::GramsForce);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force() const
        {
            return convert_from_base(ForceUnit::KilogramsForce);
        }

        [[nodiscard]] static constexpr Force from_kilograms_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilogramsForce);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force() const
        {
            return convert_from_base(ForceUnit::TonnesForce);
        }

        [[nodiscard]] static constexpr Force from_tonnes_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::TonnesForce);
        }


        [[nodiscard]] constexpr un_scalar_t newtons() const
        {
            return convert_from_base(ForceUnit::Newtons);
        }

        [[nodiscard]] static constexpr Force from_newtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Newtons);
        }


        [[nodiscard]] constexpr un_scalar_t micronewtons() const
        {
            return convert_from_base(ForceUnit::Micronewtons);
        }

        [[nodiscard]] static constexpr Force from_micronewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Micronewtons);
        }


        [[nodiscard]] constexpr un_scalar_t millinewtons() const
        {
            return convert_from_base(ForceUnit::Millinewtons);
        }

        [[nodiscard]] static constexpr Force from_millinewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Millinewtons);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons() const
        {
            return convert_from_base(ForceUnit::Decanewtons);
        }

        [[nodiscard]] static constexpr Force from_decanewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Decanewtons);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons() const
        {
            return convert_from_base(ForceUnit::Kilonewtons);
        }

        [[nodiscard]] static constexpr Force from_kilonewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kilonewtons);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons() const
        {
            return convert_from_base(ForceUnit::Meganewtons);
        }

        [[nodiscard]] static constexpr Force from_meganewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Meganewtons);
        }


        [[nodiscard]] constexpr un_scalar_t kiloponds() const
        {
            return convert_from_base(ForceUnit::Kiloponds);
        }

        [[nodiscard]] static constexpr Force from_kiloponds(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kiloponds);
        }


        [[nodiscard]] constexpr un_scalar_t poundals() const
        {
            return convert_from_base(ForceUnit::Poundals);
        }

        [[nodiscard]] static constexpr Force from_poundals(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Poundals);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force() const
        {
            return convert_from_base(ForceUnit::PoundsForce);
        }

        [[nodiscard]] static constexpr Force from_pounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::PoundsForce);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force() const
        {
            return convert_from_base(ForceUnit::KilopoundsForce);
        }

        [[nodiscard]] static constexpr Force from_kilopounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilopoundsForce);
        }


        [[nodiscard]] constexpr un_scalar_t ounce_force() const
        {
            return convert_from_base(ForceUnit::OunceForce);
        }

        [[nodiscard]] static constexpr Force from_ounce_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::OunceForce);
        }


        [[nodiscard]] constexpr un_scalar_t short_tons_force() const
        {
            return convert_from_base(ForceUnit::ShortTonsForce);
        }

        [[nodiscard]] static constexpr Force from_short_tons_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::ShortTonsForce);
        }


        [[nodiscard]] static constexpr Force from_invalid()
        {
            return Force(false);
        }
    private:
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case ForceUnit::Dyne:
                return value_ * static_cast<un_scalar_t>(1e5);

            case ForceUnit::GramsForce:
                return value_ / static_cast<un_scalar_t>(9.80665e-3);

            case ForceUnit::KilogramsForce:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::TonnesForce:
                return value_ / (static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(1000));

            case ForceUnit::Newtons:
                return value_;

            case ForceUnit::Micronewtons:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ForceUnit::Millinewtons:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ForceUnit::Decanewtons:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case ForceUnit::Kilonewtons:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::Meganewtons:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ForceUnit::Kiloponds:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::Poundals:
                return value_ / static_cast<un_scalar_t>(0.138254954376);

            case ForceUnit::PoundsForce:
                return value_ / static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::KilopoundsForce:
                return (value_ / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::OunceForce:
                return value_ / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(16));

            case ForceUnit::ShortTonsForce:
                return value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2000));

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        un_scalar_t value_;
    };
}
