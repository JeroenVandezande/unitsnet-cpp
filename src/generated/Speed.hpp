#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpeedUnit : std::uint16_t
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
    class Speed
    {
    public:
        constexpr explicit Speed(
            double value,
            SpeedUnit unit = SpeedUnit::MetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpeedUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Speed operator+(Speed other) const noexcept
        {
            return Speed(value_ + other.value_);
        }

        [[nodiscard]] constexpr Speed operator-(Speed other) const noexcept
        {
            return Speed(value_ - other.value_);
        }

        [[nodiscard]] constexpr Speed operator*(double scalar) const noexcept
        {
            return Speed(value_ * scalar);
        }

        [[nodiscard]] constexpr Speed operator/(double scalar) const noexcept
        {
            return Speed(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Speed other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Speed other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters_per_second() const
        {
            return convert_from_base(SpeedUnit::MetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_second(double value)
        {
            return Speed(value, SpeedUnit::MetersPerSecond);
        }


        [[nodiscard]] constexpr double nanometers_per_second() const
        {
            return convert_from_base(SpeedUnit::NanometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_second(double value)
        {
            return Speed(value, SpeedUnit::NanometersPerSecond);
        }


        [[nodiscard]] constexpr double micrometers_per_second() const
        {
            return convert_from_base(SpeedUnit::MicrometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_second(double value)
        {
            return Speed(value, SpeedUnit::MicrometersPerSecond);
        }


        [[nodiscard]] constexpr double millimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_second(double value)
        {
            return Speed(value, SpeedUnit::MillimetersPerSecond);
        }


        [[nodiscard]] constexpr double centimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_second(double value)
        {
            return Speed(value, SpeedUnit::CentimetersPerSecond);
        }


        [[nodiscard]] constexpr double decimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::DecimetersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_second(double value)
        {
            return Speed(value, SpeedUnit::DecimetersPerSecond);
        }


        [[nodiscard]] constexpr double kilometers_per_second() const
        {
            return convert_from_base(SpeedUnit::KilometersPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_second(double value)
        {
            return Speed(value, SpeedUnit::KilometersPerSecond);
        }


        [[nodiscard]] constexpr double meters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_minute(double value)
        {
            return Speed(value, SpeedUnit::MetersPerMinute);
        }


        [[nodiscard]] constexpr double nanometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::NanometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_minute(double value)
        {
            return Speed(value, SpeedUnit::NanometersPerMinute);
        }


        [[nodiscard]] constexpr double micrometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::MicrometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_minute(double value)
        {
            return Speed(value, SpeedUnit::MicrometersPerMinute);
        }


        [[nodiscard]] constexpr double millimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_minute(double value)
        {
            return Speed(value, SpeedUnit::MillimetersPerMinute);
        }


        [[nodiscard]] constexpr double centimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_minute(double value)
        {
            return Speed(value, SpeedUnit::CentimetersPerMinute);
        }


        [[nodiscard]] constexpr double decimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::DecimetersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_minute(double value)
        {
            return Speed(value, SpeedUnit::DecimetersPerMinute);
        }


        [[nodiscard]] constexpr double kilometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::KilometersPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_minute(double value)
        {
            return Speed(value, SpeedUnit::KilometersPerMinute);
        }


        [[nodiscard]] constexpr double meters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_hour(double value)
        {
            return Speed(value, SpeedUnit::MetersPerHour);
        }


        [[nodiscard]] constexpr double millimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MillimetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_hour(double value)
        {
            return Speed(value, SpeedUnit::MillimetersPerHour);
        }


        [[nodiscard]] constexpr double centimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::CentimetersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_hour(double value)
        {
            return Speed(value, SpeedUnit::CentimetersPerHour);
        }


        [[nodiscard]] constexpr double kilometers_per_hour() const
        {
            return convert_from_base(SpeedUnit::KilometersPerHour);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_hour(double value)
        {
            return Speed(value, SpeedUnit::KilometersPerHour);
        }


        [[nodiscard]] constexpr double feet_per_second() const
        {
            return convert_from_base(SpeedUnit::FeetPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_second(double value)
        {
            return Speed(value, SpeedUnit::FeetPerSecond);
        }


        [[nodiscard]] constexpr double feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::FeetPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_minute(double value)
        {
            return Speed(value, SpeedUnit::FeetPerMinute);
        }


        [[nodiscard]] constexpr double feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::FeetPerHour);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_hour(double value)
        {
            return Speed(value, SpeedUnit::FeetPerHour);
        }


        [[nodiscard]] constexpr double us_survey_feet_per_second() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_second(double value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerSecond);
        }


        [[nodiscard]] constexpr double us_survey_feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_minute(double value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerMinute);
        }


        [[nodiscard]] constexpr double us_survey_feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFeetPerHour);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_hour(double value)
        {
            return Speed(value, SpeedUnit::UsSurveyFeetPerHour);
        }


        [[nodiscard]] constexpr double inches_per_second() const
        {
            return convert_from_base(SpeedUnit::InchesPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_second(double value)
        {
            return Speed(value, SpeedUnit::InchesPerSecond);
        }


        [[nodiscard]] constexpr double inches_per_minute() const
        {
            return convert_from_base(SpeedUnit::InchesPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_minute(double value)
        {
            return Speed(value, SpeedUnit::InchesPerMinute);
        }


        [[nodiscard]] constexpr double inches_per_hour() const
        {
            return convert_from_base(SpeedUnit::InchesPerHour);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_hour(double value)
        {
            return Speed(value, SpeedUnit::InchesPerHour);
        }


        [[nodiscard]] constexpr double yards_per_second() const
        {
            return convert_from_base(SpeedUnit::YardsPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_second(double value)
        {
            return Speed(value, SpeedUnit::YardsPerSecond);
        }


        [[nodiscard]] constexpr double yards_per_minute() const
        {
            return convert_from_base(SpeedUnit::YardsPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_minute(double value)
        {
            return Speed(value, SpeedUnit::YardsPerMinute);
        }


        [[nodiscard]] constexpr double yards_per_hour() const
        {
            return convert_from_base(SpeedUnit::YardsPerHour);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_hour(double value)
        {
            return Speed(value, SpeedUnit::YardsPerHour);
        }


        [[nodiscard]] constexpr double knots() const
        {
            return convert_from_base(SpeedUnit::Knots);
        }

        [[nodiscard]] static constexpr Speed from_knots(double value)
        {
            return Speed(value, SpeedUnit::Knots);
        }


        [[nodiscard]] constexpr double miles_per_hour() const
        {
            return convert_from_base(SpeedUnit::MilesPerHour);
        }

        [[nodiscard]] static constexpr Speed from_miles_per_hour(double value)
        {
            return Speed(value, SpeedUnit::MilesPerHour);
        }


        [[nodiscard]] constexpr double mach() const
        {
            return convert_from_base(SpeedUnit::Mach);
        }

        [[nodiscard]] static constexpr Speed from_mach(double value)
        {
            return Speed(value, SpeedUnit::Mach);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpeedUnit unit)
        {
            switch (unit)
            {

            case SpeedUnit::MetersPerSecond:
                return value;

            case SpeedUnit::NanometersPerSecond:
                return (value * 1e-9);

            case SpeedUnit::MicrometersPerSecond:
                return (value * 1e-6);

            case SpeedUnit::MillimetersPerSecond:
                return (value * 1e-3);

            case SpeedUnit::CentimetersPerSecond:
                return (value * 1e-2);

            case SpeedUnit::DecimetersPerSecond:
                return (value * 1e-1);

            case SpeedUnit::KilometersPerSecond:
                return (value * 1e3);

            case SpeedUnit::MetersPerMinute:
                return value / 60;

            case SpeedUnit::NanometersPerMinute:
                return (value * 1e-9) / 60;

            case SpeedUnit::MicrometersPerMinute:
                return (value * 1e-6) / 60;

            case SpeedUnit::MillimetersPerMinute:
                return (value * 1e-3) / 60;

            case SpeedUnit::CentimetersPerMinute:
                return (value * 1e-2) / 60;

            case SpeedUnit::DecimetersPerMinute:
                return (value * 1e-1) / 60;

            case SpeedUnit::KilometersPerMinute:
                return (value * 1e3) / 60;

            case SpeedUnit::MetersPerHour:
                return value / 3600;

            case SpeedUnit::MillimetersPerHour:
                return (value * 1e-3) / 3600;

            case SpeedUnit::CentimetersPerHour:
                return (value * 1e-2) / 3600;

            case SpeedUnit::KilometersPerHour:
                return (value * 1e3) / 3600;

            case SpeedUnit::FeetPerSecond:
                return value * 0.3048;

            case SpeedUnit::FeetPerMinute:
                return value * 0.3048 / 60;

            case SpeedUnit::FeetPerHour:
                return value * 0.3048 / 3600;

            case SpeedUnit::UsSurveyFeetPerSecond:
                return value * 1200 / 3937;

            case SpeedUnit::UsSurveyFeetPerMinute:
                return (value * 1200 / 3937) / 60;

            case SpeedUnit::UsSurveyFeetPerHour:
                return (value * 1200 / 3937) / 3600;

            case SpeedUnit::InchesPerSecond:
                return value * 2.54e-2;

            case SpeedUnit::InchesPerMinute:
                return (value / 60) * 2.54e-2;

            case SpeedUnit::InchesPerHour:
                return (value / 3600) * 2.54e-2;

            case SpeedUnit::YardsPerSecond:
                return value * 0.9144;

            case SpeedUnit::YardsPerMinute:
                return value * 0.9144 / 60;

            case SpeedUnit::YardsPerHour:
                return value * 0.9144 / 3600;

            case SpeedUnit::Knots:
                return value * (1852.0 / 3600.0);

            case SpeedUnit::MilesPerHour:
                return value * 0.44704;

            case SpeedUnit::Mach:
                return value * 340.29;

            }

            throw std::invalid_argument("Unknown Speed unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpeedUnit unit) const
        {
            switch (unit)
            {

            case SpeedUnit::MetersPerSecond:
                return value_;

            case SpeedUnit::NanometersPerSecond:
                return (value_) / 1e-9;

            case SpeedUnit::MicrometersPerSecond:
                return (value_) / 1e-6;

            case SpeedUnit::MillimetersPerSecond:
                return (value_) / 1e-3;

            case SpeedUnit::CentimetersPerSecond:
                return (value_) / 1e-2;

            case SpeedUnit::DecimetersPerSecond:
                return (value_) / 1e-1;

            case SpeedUnit::KilometersPerSecond:
                return (value_) / 1e3;

            case SpeedUnit::MetersPerMinute:
                return value_ * 60;

            case SpeedUnit::NanometersPerMinute:
                return (value_ * 60) / 1e-9;

            case SpeedUnit::MicrometersPerMinute:
                return (value_ * 60) / 1e-6;

            case SpeedUnit::MillimetersPerMinute:
                return (value_ * 60) / 1e-3;

            case SpeedUnit::CentimetersPerMinute:
                return (value_ * 60) / 1e-2;

            case SpeedUnit::DecimetersPerMinute:
                return (value_ * 60) / 1e-1;

            case SpeedUnit::KilometersPerMinute:
                return (value_ * 60) / 1e3;

            case SpeedUnit::MetersPerHour:
                return value_ * 3600;

            case SpeedUnit::MillimetersPerHour:
                return (value_ * 3600) / 1e-3;

            case SpeedUnit::CentimetersPerHour:
                return (value_ * 3600) / 1e-2;

            case SpeedUnit::KilometersPerHour:
                return (value_ * 3600) / 1e3;

            case SpeedUnit::FeetPerSecond:
                return value_ / 0.3048;

            case SpeedUnit::FeetPerMinute:
                return value_ / 0.3048 * 60;

            case SpeedUnit::FeetPerHour:
                return value_ / 0.3048 * 3600;

            case SpeedUnit::UsSurveyFeetPerSecond:
                return value_ * 3937 / 1200;

            case SpeedUnit::UsSurveyFeetPerMinute:
                return (value_ * 3937 / 1200) * 60;

            case SpeedUnit::UsSurveyFeetPerHour:
                return (value_ * 3937 / 1200) * 3600;

            case SpeedUnit::InchesPerSecond:
                return value_ / 2.54e-2;

            case SpeedUnit::InchesPerMinute:
                return (value_ / 2.54e-2) * 60;

            case SpeedUnit::InchesPerHour:
                return (value_ / 2.54e-2) * 3600;

            case SpeedUnit::YardsPerSecond:
                return value_ / 0.9144;

            case SpeedUnit::YardsPerMinute:
                return value_ / 0.9144 * 60;

            case SpeedUnit::YardsPerHour:
                return value_ / 0.9144 * 3600;

            case SpeedUnit::Knots:
                return value_ / (1852.0 / 3600.0);

            case SpeedUnit::MilesPerHour:
                return value_ / 0.44704;

            case SpeedUnit::Mach:
                return value_ / 340.29;

            }

            throw std::invalid_argument("Unknown Speed unit.");
        }

        double value_;
    };
}
