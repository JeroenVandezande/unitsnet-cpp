#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RotationalSpeedUnit : std::uint8_t
    {
        RadiansPerSecond,
        NanoradiansPerSecond,
        MicroradiansPerSecond,
        MilliradiansPerSecond,
        CentiradiansPerSecond,
        DeciradiansPerSecond,
        DegreesPerSecond,
        NanodegreesPerSecond,
        MicrodegreesPerSecond,
        MillidegreesPerSecond,
        DegreesPerMinute,
        RevolutionsPerSecond,
        RevolutionsPerMinute,
    };

    /// <summary>Rotational speed (sometimes called speed of revolution) is the number of complete rotations, revolutions, cycles, or turns per time unit. Rotational speed is a cyclic frequency, measured in radians per second or in hertz in the SI System by scientists, or in revolutions per minute (rpm or min-1) or revolutions per second in everyday life. The symbol for rotational speed is ω (the Greek lowercase letter "omega").</summary>
    class RotationalSpeed
    {
    public:
        constexpr explicit RotationalSpeed(
            const un_scalar_t value,
            const RotationalSpeedUnit unit = RotationalSpeedUnit::RadiansPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalSpeedUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalSpeed operator+(const RotationalSpeed other) const noexcept
        {
            return RotationalSpeed(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalSpeed operator-(const RotationalSpeed other) const noexcept
        {
            return RotationalSpeed(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalSpeed operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalSpeed(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalSpeed operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalSpeed(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalSpeed other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RotationalSpeed other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t radians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RadiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_radians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RadiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanoradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanoradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanoradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanoradiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicroradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicroradiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t milliradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MilliradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_milliradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MilliradiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t centiradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::CentiradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_centiradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::CentiradiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t deciradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DeciradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_deciradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DeciradiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanodegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanodegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanodegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanodegreesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microdegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicrodegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microdegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicrodegreesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millidegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MillidegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_millidegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MillidegreesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreesPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_minute(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreesPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t revolutions_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionsPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t revolutions_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionsPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_minute(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionsPerMinute);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalSpeedUnit unit)
        {
            switch (unit)
            {

            case RotationalSpeedUnit::RadiansPerSecond:
                return value;

            case RotationalSpeedUnit::NanoradiansPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RotationalSpeedUnit::MicroradiansPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RotationalSpeedUnit::MilliradiansPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RotationalSpeedUnit::CentiradiansPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case RotationalSpeedUnit::DeciradiansPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case RotationalSpeedUnit::DegreesPerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * value;

            case RotationalSpeedUnit::NanodegreesPerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-9));

            case RotationalSpeedUnit::MicrodegreesPerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-6));

            case RotationalSpeedUnit::MillidegreesPerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-3));

            case RotationalSpeedUnit::DegreesPerMinute:
                return (std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(180) * static_cast<un_scalar_t>(60))) * value;

            case RotationalSpeedUnit::RevolutionsPerSecond:
                return value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>;

            case RotationalSpeedUnit::RevolutionsPerMinute:
                return (value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalSpeedUnit unit) const
        {
            switch (unit)
            {

            case RotationalSpeedUnit::RadiansPerSecond:
                return value_;

            case RotationalSpeedUnit::NanoradiansPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case RotationalSpeedUnit::MicroradiansPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case RotationalSpeedUnit::MilliradiansPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case RotationalSpeedUnit::CentiradiansPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case RotationalSpeedUnit::DeciradiansPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case RotationalSpeedUnit::DegreesPerSecond:
                return (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * value_;

            case RotationalSpeedUnit::NanodegreesPerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * value_) / static_cast<un_scalar_t>(1e-9);

            case RotationalSpeedUnit::MicrodegreesPerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * value_) / static_cast<un_scalar_t>(1e-6);

            case RotationalSpeedUnit::MillidegreesPerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * value_) / static_cast<un_scalar_t>(1e-3);

            case RotationalSpeedUnit::DegreesPerMinute:
                return (static_cast<un_scalar_t>(180) * static_cast<un_scalar_t>(60) / std::numbers::pi_v<un_scalar_t>) * value_;

            case RotationalSpeedUnit::RevolutionsPerSecond:
                return value_ / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case RotationalSpeedUnit::RevolutionsPerMinute:
                return (value_ / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        un_scalar_t value_;
    };
}
