#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AmplitudeRatioUnit : std::uint16_t
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
            double value,
            AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AmplitudeRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator+(AmplitudeRatio other) const noexcept
        {
            return AmplitudeRatio(value_ + other.value_);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator-(AmplitudeRatio other) const noexcept
        {
            return AmplitudeRatio(value_ - other.value_);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator*(double scalar) const noexcept
        {
            return AmplitudeRatio(value_ * scalar);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator/(double scalar) const noexcept
        {
            return AmplitudeRatio(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(AmplitudeRatio other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(AmplitudeRatio other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decibel_volts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelVolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_volts(double value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelVolts);
        }


        [[nodiscard]] constexpr double decibel_microvolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMicrovolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_microvolts(double value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMicrovolts);
        }


        [[nodiscard]] constexpr double decibel_millivolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMillivolts);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_millivolts(double value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMillivolts);
        }


        [[nodiscard]] constexpr double decibels_unloaded() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelsUnloaded);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibels_unloaded(double value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelsUnloaded);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AmplitudeRatioUnit unit)
        {
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolts:
                return value;

            case AmplitudeRatioUnit::DecibelMicrovolts:
                return value - 120;

            case AmplitudeRatioUnit::DecibelMillivolts:
                return value - 60;

            case AmplitudeRatioUnit::DecibelsUnloaded:
                return value - 2.218487499;

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AmplitudeRatioUnit unit) const
        {
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolts:
                return value_;

            case AmplitudeRatioUnit::DecibelMicrovolts:
                return value_ + 120;

            case AmplitudeRatioUnit::DecibelMillivolts:
                return value_ + 60;

            case AmplitudeRatioUnit::DecibelsUnloaded:
                return value_ + 2.218487499;

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        double value_;
    };
}
