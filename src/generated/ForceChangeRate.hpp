#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ForceChangeRateUnit : std::uint8_t
    {
        NewtonsPerMinute,
        DecanewtonsPerMinute,
        KilonewtonsPerMinute,
        NewtonsPerSecond,
        NanonewtonsPerSecond,
        MicronewtonsPerSecond,
        MillinewtonsPerSecond,
        CentinewtonsPerSecond,
        DecinewtonsPerSecond,
        DecanewtonsPerSecond,
        KilonewtonsPerSecond,
        PoundsForcePerMinute,
        KilopoundsForcePerMinute,
        PoundsForcePerSecond,
        KilopoundsForcePerSecond,
    };

    /// <summary>Force change rate is the ratio of the force change to the time during which the change occurred (value of force changes per unit time).</summary>
    class ForceChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit ForceChangeRate(
            const un_scalar_t value,
            const ForceChangeRateUnit unit = ForceChangeRateUnit::NewtonsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ForceChangeRateUnit::NewtonsPerSecond)
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

        [[nodiscard]] constexpr un_scalar_t value(const ForceChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ForceChangeRate operator+(const ForceChangeRate& other) const noexcept
        {
            return ForceChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ForceChangeRate operator-(const ForceChangeRate& other)const noexcept
        {
            return ForceChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ForceChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return ForceChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr ForceChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return ForceChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ForceChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ForceChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ForceChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NanonewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_nanonewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NanonewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t micronewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MicronewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_micronewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MicronewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MillinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_millinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MillinewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t centinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::CentinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_centinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::CentinewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecinewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundsForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundsForcePerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundsForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundsForcePerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundsForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundsForcePerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundsForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundsForcePerSecond);
        }


        [[nodiscard]] static constexpr ForceChangeRate from_invalid()
        {
            return ForceChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForceChangeRateUnit unit)
        {
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonsPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::DecanewtonsPerMinute:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilonewtonsPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::NewtonsPerSecond:
                return value;

            case ForceChangeRateUnit::NanonewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ForceChangeRateUnit::MicronewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForceChangeRateUnit::MillinewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForceChangeRateUnit::CentinewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ForceChangeRateUnit::DecinewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ForceChangeRateUnit::DecanewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForceChangeRateUnit::KilonewtonsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForceChangeRateUnit::PoundsForcePerMinute:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilopoundsForcePerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::PoundsForcePerSecond:
                return value * static_cast<un_scalar_t>(4.4482216152605);

            case ForceChangeRateUnit::KilopoundsForcePerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605);

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForceChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonsPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::DecanewtonsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e1);

            case ForceChangeRateUnit::KilonewtonsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::NewtonsPerSecond:
                return base_value_;

            case ForceChangeRateUnit::NanonewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ForceChangeRateUnit::MicronewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ForceChangeRateUnit::MillinewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ForceChangeRateUnit::CentinewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-2);

            case ForceChangeRateUnit::DecinewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-1);

            case ForceChangeRateUnit::DecanewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e1);

            case ForceChangeRateUnit::KilonewtonsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::PoundsForcePerMinute:
                return base_value_ / static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilopoundsForcePerMinute:
                return (base_value_ / static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::PoundsForcePerSecond:
                return base_value_ / static_cast<un_scalar_t>(4.4482216152605);

            case ForceChangeRateUnit::KilopoundsForcePerSecond:
                return (base_value_ / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        un_scalar_t value_;
        ForceChangeRateUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
