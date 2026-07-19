#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MassFlowUnit : std::uint8_t
    {
        GramsPerSecond,
        NanogramsPerSecond,
        MicrogramsPerSecond,
        MilligramsPerSecond,
        CentigramsPerSecond,
        DecigramsPerSecond,
        DecagramsPerSecond,
        HectogramsPerSecond,
        KilogramsPerSecond,
        GramsPerDay,
        NanogramsPerDay,
        MicrogramsPerDay,
        MilligramsPerDay,
        CentigramsPerDay,
        DecigramsPerDay,
        DecagramsPerDay,
        HectogramsPerDay,
        KilogramsPerDay,
        MegagramsPerDay,
        GramsPerHour,
        KilogramsPerHour,
        KilogramsPerMinute,
        TonnesPerHour,
        PoundsPerDay,
        MegapoundsPerDay,
        PoundsPerHour,
        MegapoundsPerHour,
        PoundsPerMinute,
        MegapoundsPerMinute,
        PoundsPerSecond,
        MegapoundsPerSecond,
        TonnesPerDay,
        ShortTonsPerHour,
    };

    /// <summary>Mass flow is the ratio of the mass change to the time during which the change occurred (value of mass changes per unit time).</summary>
    class MassFlow : public UnitsNetBase
    {
    public:
        constexpr explicit MassFlow(
            const un_scalar_t value,
            const MassFlowUnit unit = MassFlowUnit::GramsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "MassFlow"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case MassFlowUnit::GramsPerSecond:
                return "GramsPerSecond";

            case MassFlowUnit::NanogramsPerSecond:
                return "NanogramsPerSecond";

            case MassFlowUnit::MicrogramsPerSecond:
                return "MicrogramsPerSecond";

            case MassFlowUnit::MilligramsPerSecond:
                return "MilligramsPerSecond";

            case MassFlowUnit::CentigramsPerSecond:
                return "CentigramsPerSecond";

            case MassFlowUnit::DecigramsPerSecond:
                return "DecigramsPerSecond";

            case MassFlowUnit::DecagramsPerSecond:
                return "DecagramsPerSecond";

            case MassFlowUnit::HectogramsPerSecond:
                return "HectogramsPerSecond";

            case MassFlowUnit::KilogramsPerSecond:
                return "KilogramsPerSecond";

            case MassFlowUnit::GramsPerDay:
                return "GramsPerDay";

            case MassFlowUnit::NanogramsPerDay:
                return "NanogramsPerDay";

            case MassFlowUnit::MicrogramsPerDay:
                return "MicrogramsPerDay";

            case MassFlowUnit::MilligramsPerDay:
                return "MilligramsPerDay";

            case MassFlowUnit::CentigramsPerDay:
                return "CentigramsPerDay";

            case MassFlowUnit::DecigramsPerDay:
                return "DecigramsPerDay";

            case MassFlowUnit::DecagramsPerDay:
                return "DecagramsPerDay";

            case MassFlowUnit::HectogramsPerDay:
                return "HectogramsPerDay";

            case MassFlowUnit::KilogramsPerDay:
                return "KilogramsPerDay";

            case MassFlowUnit::MegagramsPerDay:
                return "MegagramsPerDay";

            case MassFlowUnit::GramsPerHour:
                return "GramsPerHour";

            case MassFlowUnit::KilogramsPerHour:
                return "KilogramsPerHour";

            case MassFlowUnit::KilogramsPerMinute:
                return "KilogramsPerMinute";

            case MassFlowUnit::TonnesPerHour:
                return "TonnesPerHour";

            case MassFlowUnit::PoundsPerDay:
                return "PoundsPerDay";

            case MassFlowUnit::MegapoundsPerDay:
                return "MegapoundsPerDay";

            case MassFlowUnit::PoundsPerHour:
                return "PoundsPerHour";

            case MassFlowUnit::MegapoundsPerHour:
                return "MegapoundsPerHour";

            case MassFlowUnit::PoundsPerMinute:
                return "PoundsPerMinute";

            case MassFlowUnit::MegapoundsPerMinute:
                return "MegapoundsPerMinute";

            case MassFlowUnit::PoundsPerSecond:
                return "PoundsPerSecond";

            case MassFlowUnit::MegapoundsPerSecond:
                return "MegapoundsPerSecond";

            case MassFlowUnit::TonnesPerDay:
                return "TonnesPerDay";

            case MassFlowUnit::ShortTonsPerHour:
                return "ShortTonsPerHour";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassFlow operator+(const MassFlow& other) const noexcept
        {
            return MassFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassFlow operator-(const MassFlow& other)const noexcept
        {
            return MassFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_second() const
        {
            return convert_from_base(MassFlowUnit::GramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::NanogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::NanogramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::MicrogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::MilligramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MilligramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::CentigramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::CentigramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecigramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecigramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecagramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecagramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::HectogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::HectogramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_day() const
        {
            return convert_from_base(MassFlowUnit::GramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::NanogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::NanogramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::MicrogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MilligramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MilligramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::CentigramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::CentigramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecigramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecigramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecagramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecagramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::HectogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::HectogramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegagramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megagrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegagramsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_hour() const
        {
            return convert_from_base(MassFlowUnit::GramsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_minute() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_hour() const
        {
            return convert_from_base(MassFlowUnit::TonnesPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::TonnesPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_day() const
        {
            return convert_from_base(MassFlowUnit::TonnesPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::TonnesPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t short_tons_per_hour() const
        {
            return convert_from_base(MassFlowUnit::ShortTonsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_short_tons_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::ShortTonsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_invalid()
        {
            return MassFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFlowUnit unit)
        {
            switch (unit)
            {

            case MassFlowUnit::GramsPerSecond:
                return value;

            case MassFlowUnit::NanogramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassFlowUnit::MicrogramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassFlowUnit::MilligramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassFlowUnit::CentigramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassFlowUnit::DecigramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassFlowUnit::DecagramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case MassFlowUnit::HectogramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e2));

            case MassFlowUnit::KilogramsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassFlowUnit::GramsPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::NanogramsPerDay:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MicrogramsPerDay:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MilligramsPerDay:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::CentigramsPerDay:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::DecigramsPerDay:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::DecagramsPerDay:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::HectogramsPerDay:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::KilogramsPerDay:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MegagramsPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::GramsPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::KilogramsPerHour:
                return value / static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::KilogramsPerMinute:
                return value / static_cast<un_scalar_t>(0.06);

            case MassFlowUnit::TonnesPerHour:
                return value * static_cast<un_scalar_t>(1000) / static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::PoundsPerDay:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MegapoundsPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::PoundsPerHour:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::MegapoundsPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::PoundsPerMinute:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(60);

            case MassFlowUnit::MegapoundsPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(60);

            case MassFlowUnit::PoundsPerSecond:
                return value * static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::TonnesPerDay:
                return value / static_cast<un_scalar_t>(0.0864000);

            case MassFlowUnit::ShortTonsPerHour:
                return value * static_cast<un_scalar_t>(907.18474) / static_cast<un_scalar_t>(3.6);

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassFlowUnit::GramsPerSecond:
                return base_value;

            case MassFlowUnit::NanogramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MassFlowUnit::MicrogramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MassFlowUnit::MilligramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MassFlowUnit::CentigramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case MassFlowUnit::DecigramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case MassFlowUnit::DecagramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case MassFlowUnit::HectogramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case MassFlowUnit::KilogramsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MassFlowUnit::GramsPerDay:
                return base_value * static_cast<un_scalar_t>(86400);

            case MassFlowUnit::NanogramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-9);

            case MassFlowUnit::MicrogramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-6);

            case MassFlowUnit::MilligramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-3);

            case MassFlowUnit::CentigramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-2);

            case MassFlowUnit::DecigramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-1);

            case MassFlowUnit::DecagramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e1);

            case MassFlowUnit::HectogramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e2);

            case MassFlowUnit::KilogramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e3);

            case MassFlowUnit::MegagramsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::GramsPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case MassFlowUnit::KilogramsPerHour:
                return base_value * static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::KilogramsPerMinute:
                return base_value * static_cast<un_scalar_t>(0.06);

            case MassFlowUnit::TonnesPerHour:
                return base_value * static_cast<un_scalar_t>(3.6) / static_cast<un_scalar_t>(1000);

            case MassFlowUnit::PoundsPerDay:
                return base_value * static_cast<un_scalar_t>(86400) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundsPerDay:
                return (base_value * static_cast<un_scalar_t>(86400) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundsPerHour:
                return base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundsPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundsPerMinute:
                return base_value * static_cast<un_scalar_t>(60) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundsPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundsPerSecond:
                return base_value / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundsPerSecond:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::TonnesPerDay:
                return base_value * static_cast<un_scalar_t>(0.0864000);

            case MassFlowUnit::ShortTonsPerHour:
                return base_value * static_cast<un_scalar_t>(3.6) / static_cast<un_scalar_t>(907.18474);

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        un_scalar_t value_;
        MassFlowUnit value_unit_type_;       
    };
}
