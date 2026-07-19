#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class AmplitudeRatio
    {
    public:
        constexpr explicit AmplitudeRatio(
            const un_scalar_t value,
            const AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolts)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit AmplitudeRatio(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const AmplitudeRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator+(const AmplitudeRatio other) const noexcept
        {
            return AmplitudeRatio(value_ + other.value_);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator-(const AmplitudeRatio other) const noexcept
        {
            return AmplitudeRatio(value_ - other.value_);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(value_ * scalar);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AmplitudeRatio other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const AmplitudeRatio other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const AmplitudeRatio other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolts:
                return value_;

            case AmplitudeRatioUnit::DecibelMicrovolts:
                return value_ + static_cast<un_scalar_t>(120);

            case AmplitudeRatioUnit::DecibelMillivolts:
                return value_ + static_cast<un_scalar_t>(60);

            case AmplitudeRatioUnit::DecibelsUnloaded:
                return value_ + static_cast<un_scalar_t>(2.218487499);

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        un_scalar_t value_;
    };
}
