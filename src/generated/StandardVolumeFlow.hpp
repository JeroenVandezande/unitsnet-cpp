#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class StandardVolumeFlowUnit : std::uint8_t
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
            const un_scalar_t value,
            const StandardVolumeFlowUnit unit = StandardVolumeFlowUnit::StandardCubicMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit StandardVolumeFlow(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const StandardVolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator+(const StandardVolumeFlow other) const noexcept
        {
            return StandardVolumeFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator-(const StandardVolumeFlow other) const noexcept
        {
            return StandardVolumeFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return StandardVolumeFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return StandardVolumeFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const StandardVolumeFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const StandardVolumeFlow other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const StandardVolumeFlow other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_second(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_hour(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_day() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMetersPerDay);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_day(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMetersPerDay);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_centimeters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_centimeters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t standard_liters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardLitersPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_liters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardLitersPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_second(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFeetPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_hour(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFeetPerHour);
        }


        [[nodiscard]] static constexpr StandardVolumeFlow from_invalid()
        {
            return StandardVolumeFlow(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, StandardVolumeFlowUnit unit)
        {
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMetersPerSecond:
                return value;

            case StandardVolumeFlowUnit::StandardCubicMetersPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicMetersPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case StandardVolumeFlowUnit::StandardCubicMetersPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute:
                return value / static_cast<un_scalar_t>(6e7);

            case StandardVolumeFlowUnit::StandardLitersPerMinute:
                return value / static_cast<un_scalar_t>(60000);

            case StandardVolumeFlowUnit::StandardCubicFeetPerSecond:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case StandardVolumeFlowUnit::StandardCubicFeetPerMinute:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicFeetPerHour:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const StandardVolumeFlowUnit unit) const
        {
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMetersPerSecond:
                return value_;

            case StandardVolumeFlowUnit::StandardCubicMetersPerMinute:
                return value_ * static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicMetersPerHour:
                return value_ * static_cast<un_scalar_t>(3600);

            case StandardVolumeFlowUnit::StandardCubicMetersPerDay:
                return value_ * static_cast<un_scalar_t>(86400);

            case StandardVolumeFlowUnit::StandardCubicCentimetersPerMinute:
                return value_ * static_cast<un_scalar_t>(6e7);

            case StandardVolumeFlowUnit::StandardLitersPerMinute:
                return value_ * static_cast<un_scalar_t>(60000);

            case StandardVolumeFlowUnit::StandardCubicFeetPerSecond:
                return value_ / static_cast<un_scalar_t>(0.028316846592);

            case StandardVolumeFlowUnit::StandardCubicFeetPerMinute:
                return value_ / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            case StandardVolumeFlowUnit::StandardCubicFeetPerHour:
                return value_ / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        un_scalar_t value_;
    };
}
