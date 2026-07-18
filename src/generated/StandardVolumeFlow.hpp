#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class StandardVolumeFlowUnit : std::uint16_t
    {
        StandardCubicMetersPerSecond,
        StandardCubicMetersPerMinute,
        StandardCubicMetersPerHour,
        StandardCubicMetersPerDay,
        StandardCubicCentimetersPerMinute,
        StandardLitersPerMinute,
        StandardCubicFeetPerSecond,
        StandardCubicFeetPerMinute,
        StandardCubicFeetPerHour,
    };

    /// <summary>The molar flow rate of a gas corrected to standardized conditions of temperature and pressure thus representing a fixed number of moles of gas regardless of composition and actual flow conditions.</summary>
    class StandardVolumeFlow
    {
    public:
        constexpr explicit StandardVolumeFlow(
            double value,
            StandardVolumeFlowUnit unit = StandardVolumeFlowUnit::StandardCubicMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(StandardVolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator+(StandardVolumeFlow other) const noexcept
        {
            return StandardVolumeFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator-(StandardVolumeFlow other) const noexcept
        {
            return StandardVolumeFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator*(double scalar) const noexcept
        {
            return StandardVolumeFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator/(double scalar) const noexcept
        {
            return StandardVolumeFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(StandardVolumeFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(StandardVolumeFlow other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double standard_cubic_meters_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_second(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerSecond);
        }


        [[nodiscard]] constexpr double standard_cubic_meters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_minute(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerMinute);
        }


        [[nodiscard]] constexpr double standard_cubic_meters_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_hour(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerHour);
        }


        [[nodiscard]] constexpr double standard_cubic_meters_per_day() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerDay);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_day(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerDay);
        }


        [[nodiscard]] constexpr double standard_cubic_centimeters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_centimeters_per_minute(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute);
        }


        [[nodiscard]] constexpr double standard_liters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardLitersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_liters_per_minute(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardLitersPerMinute);
        }


        [[nodiscard]] constexpr double standard_cubic_feet_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_second(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerSecond);
        }


        [[nodiscard]] constexpr double standard_cubic_feet_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_minute(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerMinute);
        }


        [[nodiscard]] constexpr double standard_cubic_feet_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_hour(double value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, StandardVolumeFlowUnit unit)
        {
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMetersPerSecond:
                return value;

            case StandardVolumeFlowUnit::StandardCubicMetersPerMinute:
                return value / 60;

            case StandardVolumeFlowUnit::StandardCubicMetersPerHour:
                return value / 3600;

            case StandardVolumeFlowUnit::StandardCubicMetersPerDay:
                return value / 86400;

            case StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute:
                return value / 6e7;

            case StandardVolumeFlowUnit::StandardLitersPerMinute:
                return value / 60000;

            case StandardVolumeFlowUnit::StandardCubicFeetPerSecond:
                return value * 0.028316846592;

            case StandardVolumeFlowUnit::StandardCubicFeetPerMinute:
                return value * 0.028316846592 / 60;

            case StandardVolumeFlowUnit::StandardCubicFeetPerHour:
                return value * 0.028316846592 / 3600;

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(StandardVolumeFlowUnit unit) const
        {
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMetersPerSecond:
                return value_;

            case StandardVolumeFlowUnit::StandardCubicMetersPerMinute:
                return value_ * 60;

            case StandardVolumeFlowUnit::StandardCubicMetersPerHour:
                return value_ * 3600;

            case StandardVolumeFlowUnit::StandardCubicMetersPerDay:
                return value_ * 86400;

            case StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute:
                return value_ * 6e7;

            case StandardVolumeFlowUnit::StandardLitersPerMinute:
                return value_ * 60000;

            case StandardVolumeFlowUnit::StandardCubicFeetPerSecond:
                return value_ / 0.028316846592;

            case StandardVolumeFlowUnit::StandardCubicFeetPerMinute:
                return value_ / (0.028316846592 / 60);

            case StandardVolumeFlowUnit::StandardCubicFeetPerHour:
                return value_ / (0.028316846592 / 3600);

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        double value_;
    };
}
