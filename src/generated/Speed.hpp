#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpeedUnit : std::uint8_t
    {
        MetersPerSecond,
        NanometersPerSecond,
        MicrometersPerSecond,
        MillimetersPerSecond,
        CentimetersPerSecond,
        DecimetersPerSecond,
        KilometersPerSecond,
        MetersPerMinute,
        NanometersPerMinute,
        MicrometersPerMinute,
        MillimetersPerMinute,
        CentimetersPerMinute,
        DecimetersPerMinute,
        KilometersPerMinute,
        MetersPerHour,
        MillimetersPerHour,
        CentimetersPerHour,
        KilometersPerHour,
        FeetPerSecond,
        FeetPerMinute,
        FeetPerHour,
        UsSurveyFeetPerSecond,
        UsSurveyFeetPerMinute,
        UsSurveyFeetPerHour,
        InchesPerSecond,
        InchesPerMinute,
        InchesPerHour,
        YardsPerSecond,
        YardsPerMinute,
        YardsPerHour,
        Knots,
        MilesPerHour,
        Mach,
    };

    /// <summary>In everyday use and in kinematics, the speed of an object is the magnitude of its velocity (the rate of change of its position); it is thus a scalar quantity.[1] The average speed of an object in an interval of time is the distance travelled by the object divided by the duration of the interval;[2] the instantaneous speed is the limit of the average speed as the duration of the time interval approaches zero.</summary>
    class Speed : public UnitsNetBase
    {
    public:
        constexpr explicit Speed(
            const un_scalar_t value,
            const SpeedUnit unit = SpeedUnit::MetersPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpeedUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Speed operator+(const Speed& other) const noexcept
        {
            return Speed(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Speed operator-(const Speed& other)const noexcept
        {
            return Speed(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Speed operator*(const un_scalar_t scalar) const noexcept
        {
            return Speed(base_value() * scalar);
        }

        [[nodiscard]] constexpr Speed operator/(const un_scalar_t scalar) const noexcept
        {
            return Speed(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Speed& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Speed& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Speed& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_second() const
        {
            return convert_from_base(SpeedUnit::MetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MetersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_second() const
        {
            return convert_from_base(SpeedUnit::NanometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::NanometersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_second() const
        {
            return convert_from_base(SpeedUnit::MicrometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MicrometersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimetersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimetersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::DecimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::DecimetersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_second() const
        {
            return convert_from_base(SpeedUnit::KilometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MetersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::NanometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::NanometersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::MicrometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MicrometersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimetersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimetersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::DecimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::DecimetersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::KilometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometersPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MetersPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimetersPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimetersPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_hour() const
        {
            return convert_from_base(SpeedUnit::KilometersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometersPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_second() const
        {
            return convert_from_base(SpeedUnit::FeetPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FeetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::FeetPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FeetPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::FeetPerHour);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FeetPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_second() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerHour);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_second() const
        {
            return convert_from_base(SpeedUnit::InchesPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchesPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_minute() const
        {
            return convert_from_base(SpeedUnit::InchesPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchesPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_hour() const
        {
            return convert_from_base(SpeedUnit::InchesPerHour);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchesPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_second() const
        {
            return convert_from_base(SpeedUnit::YardsPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_minute() const
        {
            return convert_from_base(SpeedUnit::YardsPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_hour() const
        {
            return convert_from_base(SpeedUnit::YardsPerHour);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardsPerHour);
        }

        /// <summary>The knot, by definition, is a unit of speed equals to 1 nautical mile per hour, which is exactly 1852.000 metres per hour. The length of the internationally agreed nautical mile is 1852 m. The US adopted the international definition in 1954, the UK adopted the international nautical mile definition in 1970.</summary>
        [[nodiscard]] constexpr un_scalar_t knots() const
        {
            return convert_from_base(SpeedUnit::Knots);
        }

        /// <summary>The knot, by definition, is a unit of speed equals to 1 nautical mile per hour, which is exactly 1852.000 metres per hour. The length of the internationally agreed nautical mile is 1852 m. The US adopted the international definition in 1954, the UK adopted the international nautical mile definition in 1970.</summary>
        [[nodiscard]] static constexpr Speed from_knots(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::Knots);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_hour() const
        {
            return convert_from_base(SpeedUnit::MilesPerHour);
        }

        [[nodiscard]] static constexpr Speed from_miles_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MilesPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t mach() const
        {
            return convert_from_base(SpeedUnit::Mach);
        }

        [[nodiscard]] static constexpr Speed from_mach(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::Mach);
        }

        [[nodiscard]] static constexpr Speed from_invalid()
        {
            return Speed(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpeedUnit unit)
        {
            switch (unit)
            {

            case SpeedUnit::MetersPerSecond:
                return value;

            case SpeedUnit::NanometersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case SpeedUnit::MicrometersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case SpeedUnit::MillimetersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case SpeedUnit::CentimetersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case SpeedUnit::DecimetersPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case SpeedUnit::KilometersPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpeedUnit::MetersPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case SpeedUnit::NanometersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MicrometersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MillimetersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::CentimetersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::DecimetersPerMinute:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::KilometersPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MetersPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case SpeedUnit::MillimetersPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::CentimetersPerHour:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::KilometersPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::FeetPerSecond:
                return value * static_cast<un_scalar_t>(0.3048);

            case SpeedUnit::FeetPerMinute:
                return value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(60);

            case SpeedUnit::FeetPerHour:
                return value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::UsSurveyFeetPerSecond:
                return value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case SpeedUnit::UsSurveyFeetPerMinute:
                return (value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::UsSurveyFeetPerHour:
                return (value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::InchesPerSecond:
                return value * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchesPerMinute:
                return (value / static_cast<un_scalar_t>(60)) * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchesPerHour:
                return (value / static_cast<un_scalar_t>(3600)) * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::YardsPerSecond:
                return value * static_cast<un_scalar_t>(0.9144);

            case SpeedUnit::YardsPerMinute:
                return value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(60);

            case SpeedUnit::YardsPerHour:
                return value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::Knots:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case SpeedUnit::MilesPerHour:
                return value * static_cast<un_scalar_t>(0.44704);

            case SpeedUnit::Mach:
                return value * static_cast<un_scalar_t>(340.29);

            }

            throw std::invalid_argument("Unknown Speed unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpeedUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpeedUnit::MetersPerSecond:
                return base_value;

            case SpeedUnit::NanometersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case SpeedUnit::MicrometersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case SpeedUnit::MillimetersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimetersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::DecimetersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case SpeedUnit::KilometersPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::MetersPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case SpeedUnit::NanometersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-9);

            case SpeedUnit::MicrometersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-6);

            case SpeedUnit::MillimetersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimetersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::DecimetersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-1);

            case SpeedUnit::KilometersPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::MetersPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case SpeedUnit::MillimetersPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimetersPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::KilometersPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::FeetPerSecond:
                return base_value / static_cast<un_scalar_t>(0.3048);

            case SpeedUnit::FeetPerMinute:
                return base_value / static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(60);

            case SpeedUnit::FeetPerHour:
                return base_value / static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::UsSurveyFeetPerSecond:
                return base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case SpeedUnit::UsSurveyFeetPerMinute:
                return (base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200)) * static_cast<un_scalar_t>(60);

            case SpeedUnit::UsSurveyFeetPerHour:
                return (base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200)) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::InchesPerSecond:
                return base_value / static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchesPerMinute:
                return (base_value / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(60);

            case SpeedUnit::InchesPerHour:
                return (base_value / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::YardsPerSecond:
                return base_value / static_cast<un_scalar_t>(0.9144);

            case SpeedUnit::YardsPerMinute:
                return base_value / static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(60);

            case SpeedUnit::YardsPerHour:
                return base_value / static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::Knots:
                return base_value / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case SpeedUnit::MilesPerHour:
                return base_value / static_cast<un_scalar_t>(0.44704);

            case SpeedUnit::Mach:
                return base_value / static_cast<un_scalar_t>(340.29);

            }

            throw std::invalid_argument("Unknown Speed unit.");
        }

        un_scalar_t value_;
        SpeedUnit value_unit_type_;       
    };
}
