#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RotationalSpeedUnit : std::uint16_t
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
            double value,
            RotationalSpeedUnit unit = RotationalSpeedUnit::RadiansPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RotationalSpeedUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalSpeed operator+(RotationalSpeed other) const noexcept
        {
            return RotationalSpeed(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalSpeed operator-(RotationalSpeed other) const noexcept
        {
            return RotationalSpeed(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalSpeed operator*(double scalar) const noexcept
        {
            return RotationalSpeed(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalSpeed operator/(double scalar) const noexcept
        {
            return RotationalSpeed(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RotationalSpeed other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RotationalSpeed other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double radians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RadiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_radians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RadiansPerSecond);
        }


        [[nodiscard]] constexpr double nanoradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanoradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanoradians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanoradiansPerSecond);
        }


        [[nodiscard]] constexpr double microradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicroradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microradians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicroradiansPerSecond);
        }


        [[nodiscard]] constexpr double milliradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MilliradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_milliradians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MilliradiansPerSecond);
        }


        [[nodiscard]] constexpr double centiradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::CentiradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_centiradians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::CentiradiansPerSecond);
        }


        [[nodiscard]] constexpr double deciradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DeciradiansPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_deciradians_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DeciradiansPerSecond);
        }


        [[nodiscard]] constexpr double degrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreesPerSecond);
        }


        [[nodiscard]] constexpr double nanodegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanodegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanodegrees_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanodegreesPerSecond);
        }


        [[nodiscard]] constexpr double microdegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicrodegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microdegrees_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicrodegreesPerSecond);
        }


        [[nodiscard]] constexpr double millidegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MillidegreesPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_millidegrees_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MillidegreesPerSecond);
        }


        [[nodiscard]] constexpr double degrees_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreesPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_minute(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreesPerMinute);
        }


        [[nodiscard]] constexpr double revolutions_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionsPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_second(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionsPerSecond);
        }


        [[nodiscard]] constexpr double revolutions_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionsPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_minute(double value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionsPerMinute);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RotationalSpeedUnit unit)
        {
            switch (unit)
            {

            case RotationalSpeedUnit::RadiansPerSecond:
                return value;

            case RotationalSpeedUnit::NanoradiansPerSecond:
                return (value * 1e-9);

            case RotationalSpeedUnit::MicroradiansPerSecond:
                return (value * 1e-6);

            case RotationalSpeedUnit::MilliradiansPerSecond:
                return (value * 1e-3);

            case RotationalSpeedUnit::CentiradiansPerSecond:
                return (value * 1e-2);

            case RotationalSpeedUnit::DeciradiansPerSecond:
                return (value * 1e-1);

            case RotationalSpeedUnit::DegreesPerSecond:
                return (std::numbers::pi / 180) * value;

            case RotationalSpeedUnit::NanodegreesPerSecond:
                return (std::numbers::pi / 180) * (value * 1e-9);

            case RotationalSpeedUnit::MicrodegreesPerSecond:
                return (std::numbers::pi / 180) * (value * 1e-6);

            case RotationalSpeedUnit::MillidegreesPerSecond:
                return (std::numbers::pi / 180) * (value * 1e-3);

            case RotationalSpeedUnit::DegreesPerMinute:
                return (std::numbers::pi / (180 * 60)) * value;

            case RotationalSpeedUnit::RevolutionsPerSecond:
                return value * 2 * std::numbers::pi;

            case RotationalSpeedUnit::RevolutionsPerMinute:
                return (value * 2 * std::numbers::pi) / 60;

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RotationalSpeedUnit unit) const
        {
            switch (unit)
            {

            case RotationalSpeedUnit::RadiansPerSecond:
                return value_;

            case RotationalSpeedUnit::NanoradiansPerSecond:
                return (value_) / 1e-9;

            case RotationalSpeedUnit::MicroradiansPerSecond:
                return (value_) / 1e-6;

            case RotationalSpeedUnit::MilliradiansPerSecond:
                return (value_) / 1e-3;

            case RotationalSpeedUnit::CentiradiansPerSecond:
                return (value_) / 1e-2;

            case RotationalSpeedUnit::DeciradiansPerSecond:
                return (value_) / 1e-1;

            case RotationalSpeedUnit::DegreesPerSecond:
                return (180 / std::numbers::pi) * value_;

            case RotationalSpeedUnit::NanodegreesPerSecond:
                return ((180 / std::numbers::pi) * value_) / 1e-9;

            case RotationalSpeedUnit::MicrodegreesPerSecond:
                return ((180 / std::numbers::pi) * value_) / 1e-6;

            case RotationalSpeedUnit::MillidegreesPerSecond:
                return ((180 / std::numbers::pi) * value_) / 1e-3;

            case RotationalSpeedUnit::DegreesPerMinute:
                return (180 * 60 / std::numbers::pi) * value_;

            case RotationalSpeedUnit::RevolutionsPerSecond:
                return value_ / (2 * std::numbers::pi);

            case RotationalSpeedUnit::RevolutionsPerMinute:
                return (value_ / (2 * std::numbers::pi)) * 60;

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        double value_;
    };
}
