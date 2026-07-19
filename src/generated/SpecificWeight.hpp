#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class SpecificWeightUnit : std::uint8_t
    {
        NewtonsPerCubicMillimeter,
        KilonewtonsPerCubicMillimeter,
        NewtonsPerCubicCentimeter,
        KilonewtonsPerCubicCentimeter,
        NewtonsPerCubicMeter,
        KilonewtonsPerCubicMeter,
        MeganewtonsPerCubicMeter,
        KilogramsForcePerCubicMillimeter,
        KilogramsForcePerCubicCentimeter,
        KilogramsForcePerCubicMeter,
        PoundsForcePerCubicInch,
        KilopoundsForcePerCubicInch,
        PoundsForcePerCubicFoot,
        KilopoundsForcePerCubicFoot,
        TonnesForcePerCubicMillimeter,
        TonnesForcePerCubicCentimeter,
        TonnesForcePerCubicMeter,
    };

    /// <summary>The SpecificWeight, or more precisely, the volumetric weight density, of a substance is its weight per unit volume.</summary>
    class SpecificWeight
    {
    public:
        constexpr explicit SpecificWeight(
            const un_scalar_t value,
            const SpecificWeightUnit unit = SpecificWeightUnit::NewtonsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit SpecificWeight(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const SpecificWeightUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificWeight operator+(const SpecificWeight other) const noexcept
        {
            return SpecificWeight(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificWeight operator-(const SpecificWeight other) const noexcept
        {
            return SpecificWeight(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificWeight operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificWeight(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificWeight operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificWeight(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificWeight other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const SpecificWeight other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificWeight other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::MeganewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_meganewtons_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::MeganewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::PoundsForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_inch(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundsForcePerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundsForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_inch(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundsForcePerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::PoundsForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_foot(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundsForcePerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundsForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_foot(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundsForcePerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_millimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_centimeter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_meter(const un_scalar_t value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicMeter);
        }


        [[nodiscard]] static constexpr SpecificWeight from_invalid()
        {
            return SpecificWeight(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificWeightUnit unit)
        {
            switch (unit)
            {

            case SpecificWeightUnit::NewtonsPerCubicMillimeter:
                return value * static_cast<un_scalar_t>(1000000000);

            case SpecificWeightUnit::KilonewtonsPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1000000000);

            case SpecificWeightUnit::NewtonsPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(1000000);

            case SpecificWeightUnit::KilonewtonsPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1000000);

            case SpecificWeightUnit::NewtonsPerCubicMeter:
                return value;

            case SpecificWeightUnit::KilonewtonsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificWeightUnit::MeganewtonsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificWeightUnit::KilogramsForcePerCubicMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::KilogramsForcePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case SpecificWeightUnit::KilogramsForcePerCubicMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case SpecificWeightUnit::PoundsForcePerCubicInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(1.6387064e-5);

            case SpecificWeightUnit::KilopoundsForcePerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(1.6387064e-5);

            case SpecificWeightUnit::PoundsForcePerCubicFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.028316846592);

            case SpecificWeightUnit::KilopoundsForcePerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.028316846592);

            case SpecificWeightUnit::TonnesForcePerCubicMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e12);

            case SpecificWeightUnit::TonnesForcePerCubicCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::TonnesForcePerCubicMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificWeightUnit unit) const
        {
            switch (unit)
            {

            case SpecificWeightUnit::NewtonsPerCubicMillimeter:
                return value_ * static_cast<un_scalar_t>(0.000000001);

            case SpecificWeightUnit::KilonewtonsPerCubicMillimeter:
                return (value_ * static_cast<un_scalar_t>(0.000000001)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::NewtonsPerCubicCentimeter:
                return value_ * static_cast<un_scalar_t>(0.000001);

            case SpecificWeightUnit::KilonewtonsPerCubicCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.000001)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::NewtonsPerCubicMeter:
                return value_;

            case SpecificWeightUnit::KilonewtonsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::MeganewtonsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case SpecificWeightUnit::KilogramsForcePerCubicMillimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::KilogramsForcePerCubicCentimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e6);

            case SpecificWeightUnit::KilogramsForcePerCubicMeter:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case SpecificWeightUnit::PoundsForcePerCubicInch:
                return value_ * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(4.4482216152605);

            case SpecificWeightUnit::KilopoundsForcePerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::PoundsForcePerCubicFoot:
                return value_ * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(4.4482216152605);

            case SpecificWeightUnit::KilopoundsForcePerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case SpecificWeightUnit::TonnesForcePerCubicMillimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e12);

            case SpecificWeightUnit::TonnesForcePerCubicCentimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e9);

            case SpecificWeightUnit::TonnesForcePerCubicMeter:
                return value_ / static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        un_scalar_t value_;
    };
}
