#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpeedUnit : std::uint8_t
    {
        MeterPerSecond,
        NanometerPerSecond,
        MicrometerPerSecond,
        MillimeterPerSecond,
        CentimeterPerSecond,
        DecimeterPerSecond,
        KilometerPerSecond,
        MeterPerMinute,
        NanometerPerMinute,
        MicrometerPerMinute,
        MillimeterPerMinute,
        CentimeterPerMinute,
        DecimeterPerMinute,
        KilometerPerMinute,
        MeterPerHour,
        MillimeterPerHour,
        CentimeterPerHour,
        KilometerPerHour,
        FootPerSecond,
        FootPerMinute,
        FootPerHour,
        UsSurveyFootPerSecond,
        UsSurveyFootPerMinute,
        UsSurveyFootPerHour,
        InchPerSecond,
        InchPerMinute,
        InchPerHour,
        YardPerSecond,
        YardPerMinute,
        YardPerHour,
        Knot,
        MilePerHour,
        Mach,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Speed.</summary>
    class SpeedDto
    {
    public:
        constexpr SpeedDto() noexcept
            : value{}, unit(SpeedUnit::MeterPerSecond)
        {
        }

        constexpr SpeedDto(
            const un_scalar_t value,
            const SpeedUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpeedUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpeedUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpeedUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Speed unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpeedDto from_json(const nlohmann::json& json)
        {
            return SpeedDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In everyday use and in kinematics, the speed of an object is the magnitude of its velocity (the rate of change of its position); it is thus a scalar quantity.[1] The average speed of an object in an interval of time is the distance travelled by the object divided by the duration of the interval;[2] the instantaneous speed is the limit of the average speed as the duration of the time interval approaches zero.</summary>
    class Speed : public UnitsNetBase
    {
    public:
        constexpr explicit Speed(
            const un_scalar_t value,
            const SpeedUnit unit = SpeedUnit::MeterPerSecond)
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

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpeedDto to_dto(
            const SpeedUnit unit = SpeedUnit::MeterPerSecond) const
        {
            return SpeedDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Speed from_dto(const SpeedDto& dto)
        {
            return Speed(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpeedUnit unit = SpeedUnit::MeterPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Speed from_json(const nlohmann::json& json)
        {
            return from_dto(SpeedDto::from_json(json));
        }
#endif
#endif

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
            return convert_from_base(SpeedUnit::MeterPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_second() const
        {
            return convert_from_base(SpeedUnit::NanometerPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::NanometerPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_second() const
        {
            return convert_from_base(SpeedUnit::MicrometerPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MicrometerPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::MillimeterPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::CentimeterPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_second() const
        {
            return convert_from_base(SpeedUnit::DecimeterPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::DecimeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_second() const
        {
            return convert_from_base(SpeedUnit::KilometerPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometerPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MeterPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::NanometerPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_nanometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::NanometerPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::MicrometerPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_micrometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MicrometerPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::MillimeterPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::CentimeterPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_minute() const
        {
            return convert_from_base(SpeedUnit::DecimeterPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_decimeters_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::DecimeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_minute() const
        {
            return convert_from_base(SpeedUnit::KilometerPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometerPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MeterPerHour);
        }

        [[nodiscard]] static constexpr Speed from_meters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MeterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::MillimeterPerHour);
        }

        [[nodiscard]] static constexpr Speed from_millimeters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MillimeterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_hour() const
        {
            return convert_from_base(SpeedUnit::CentimeterPerHour);
        }

        [[nodiscard]] static constexpr Speed from_centimeters_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::CentimeterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_hour() const
        {
            return convert_from_base(SpeedUnit::KilometerPerHour);
        }

        [[nodiscard]] static constexpr Speed from_kilometers_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::KilometerPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_second() const
        {
            return convert_from_base(SpeedUnit::FootPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::FootPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FootPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::FootPerHour);
        }

        [[nodiscard]] static constexpr Speed from_feet_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::FootPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_second() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFootPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_minute() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFootPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFootPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t us_survey_feet_per_hour() const
        {
            return convert_from_base(SpeedUnit::UsSurveyFootPerHour);
        }

        [[nodiscard]] static constexpr Speed from_us_survey_feet_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::UsSurveyFootPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_second() const
        {
            return convert_from_base(SpeedUnit::InchPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_minute() const
        {
            return convert_from_base(SpeedUnit::InchPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_hour() const
        {
            return convert_from_base(SpeedUnit::InchPerHour);
        }

        [[nodiscard]] static constexpr Speed from_inches_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::InchPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_second() const
        {
            return convert_from_base(SpeedUnit::YardPerSecond);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_second(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_minute() const
        {
            return convert_from_base(SpeedUnit::YardPerMinute);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_minute(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t yards_per_hour() const
        {
            return convert_from_base(SpeedUnit::YardPerHour);
        }

        [[nodiscard]] static constexpr Speed from_yards_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::YardPerHour);
        }

        /// <summary>The knot, by definition, is a unit of speed equals to 1 nautical mile per hour, which is exactly 1852.000 metres per hour. The length of the internationally agreed nautical mile is 1852 m. The US adopted the international definition in 1954, the UK adopted the international nautical mile definition in 1970.</summary>
        [[nodiscard]] constexpr un_scalar_t knots() const
        {
            return convert_from_base(SpeedUnit::Knot);
        }

        /// <summary>The knot, by definition, is a unit of speed equals to 1 nautical mile per hour, which is exactly 1852.000 metres per hour. The length of the internationally agreed nautical mile is 1852 m. The US adopted the international definition in 1954, the UK adopted the international nautical mile definition in 1970.</summary>
        [[nodiscard]] static constexpr Speed from_knots(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::Knot);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_hour() const
        {
            return convert_from_base(SpeedUnit::MilePerHour);
        }

        [[nodiscard]] static constexpr Speed from_miles_per_hour(const un_scalar_t value)
        {
            return Speed(value, SpeedUnit::MilePerHour);
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

            case SpeedUnit::MeterPerSecond:
                return value;

            case SpeedUnit::NanometerPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case SpeedUnit::MicrometerPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case SpeedUnit::MillimeterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case SpeedUnit::CentimeterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case SpeedUnit::DecimeterPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case SpeedUnit::KilometerPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpeedUnit::MeterPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case SpeedUnit::NanometerPerMinute:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MicrometerPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MillimeterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::CentimeterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::DecimeterPerMinute:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::KilometerPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::MeterPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case SpeedUnit::MillimeterPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::CentimeterPerHour:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::KilometerPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::FootPerSecond:
                return value * static_cast<un_scalar_t>(0.3048);

            case SpeedUnit::FootPerMinute:
                return value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(60);

            case SpeedUnit::FootPerHour:
                return value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::UsSurveyFootPerSecond:
                return value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case SpeedUnit::UsSurveyFootPerMinute:
                return (value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937)) / static_cast<un_scalar_t>(60);

            case SpeedUnit::UsSurveyFootPerHour:
                return (value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937)) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::InchPerSecond:
                return value * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchPerMinute:
                return (value / static_cast<un_scalar_t>(60)) * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchPerHour:
                return (value / static_cast<un_scalar_t>(3600)) * static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::YardPerSecond:
                return value * static_cast<un_scalar_t>(0.9144);

            case SpeedUnit::YardPerMinute:
                return value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(60);

            case SpeedUnit::YardPerHour:
                return value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(3600);

            case SpeedUnit::Knot:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case SpeedUnit::MilePerHour:
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

            case SpeedUnit::MeterPerSecond:
                return base_value;

            case SpeedUnit::NanometerPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case SpeedUnit::MicrometerPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case SpeedUnit::MillimeterPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimeterPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::DecimeterPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case SpeedUnit::KilometerPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::MeterPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case SpeedUnit::NanometerPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-9);

            case SpeedUnit::MicrometerPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-6);

            case SpeedUnit::MillimeterPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimeterPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::DecimeterPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-1);

            case SpeedUnit::KilometerPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::MeterPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case SpeedUnit::MillimeterPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case SpeedUnit::CentimeterPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-2);

            case SpeedUnit::KilometerPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case SpeedUnit::FootPerSecond:
                return base_value / static_cast<un_scalar_t>(0.3048);

            case SpeedUnit::FootPerMinute:
                return base_value / static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(60);

            case SpeedUnit::FootPerHour:
                return base_value / static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::UsSurveyFootPerSecond:
                return base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case SpeedUnit::UsSurveyFootPerMinute:
                return (base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200)) * static_cast<un_scalar_t>(60);

            case SpeedUnit::UsSurveyFootPerHour:
                return (base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200)) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::InchPerSecond:
                return base_value / static_cast<un_scalar_t>(2.54e-2);

            case SpeedUnit::InchPerMinute:
                return (base_value / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(60);

            case SpeedUnit::InchPerHour:
                return (base_value / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::YardPerSecond:
                return base_value / static_cast<un_scalar_t>(0.9144);

            case SpeedUnit::YardPerMinute:
                return base_value / static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(60);

            case SpeedUnit::YardPerHour:
                return base_value / static_cast<un_scalar_t>(0.9144) * static_cast<un_scalar_t>(3600);

            case SpeedUnit::Knot:
                return base_value / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case SpeedUnit::MilePerHour:
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
