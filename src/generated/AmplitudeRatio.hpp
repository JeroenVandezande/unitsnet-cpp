#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class AmplitudeRatioUnit : std::uint8_t
    {
        DecibelVolts,
        DecibelMicrovolts,
        DecibelMillivolts,
        DecibelsUnloaded,
    };

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one volt RMS.</summary>
    class AmplitudeRatio : public UnitsNetBase
    {
    public:
        constexpr explicit AmplitudeRatio(
            const un_scalar_t value,
            const AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolts)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == AmplitudeRatioUnit::DecibelVolts)
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

        [[nodiscard]] constexpr un_scalar_t value(const AmplitudeRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator+(const AmplitudeRatio& other) const noexcept
        {
            return AmplitudeRatio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AmplitudeRatio operator-(const AmplitudeRatio& other)const noexcept
        {
            return AmplitudeRatio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AmplitudeRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(base_value() * scalar);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AmplitudeRatio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AmplitudeRatio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AmplitudeRatio& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t decibel_volts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelVolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_volts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelVolts);
        }


        [[nodiscard]] constexpr un_scalar_t decibel_microvolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMicrovolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_microvolts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMicrovolts);
        }


        [[nodiscard]] constexpr un_scalar_t decibel_millivolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMillivolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_millivolts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMillivolts);
        }


        [[nodiscard]] constexpr un_scalar_t decibels_unloaded() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelsUnloaded);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibels_unloaded(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelsUnloaded);
        }


        [[nodiscard]] static constexpr AmplitudeRatio from_invalid()
        {
            return AmplitudeRatio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AmplitudeRatioUnit unit)
        {
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolts:
                return value;

            case AmplitudeRatioUnit::DecibelMicrovolts:
                return value - static_cast<un_scalar_t>(120);

            case AmplitudeRatioUnit::DecibelMillivolts:
                return value - static_cast<un_scalar_t>(60);

            case AmplitudeRatioUnit::DecibelsUnloaded:
                return value - static_cast<un_scalar_t>(2.218487499);

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AmplitudeRatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolts:
                return base_value_;

            case AmplitudeRatioUnit::DecibelMicrovolts:
                return base_value_ + static_cast<un_scalar_t>(120);

            case AmplitudeRatioUnit::DecibelMillivolts:
                return base_value_ + static_cast<un_scalar_t>(60);

            case AmplitudeRatioUnit::DecibelsUnloaded:
                return base_value_ + static_cast<un_scalar_t>(2.218487499);

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        un_scalar_t value_;
        AmplitudeRatioUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
