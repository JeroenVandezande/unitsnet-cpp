#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MassFlowUnit : std::uint16_t
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
    class MassFlow
    {
    public:
        constexpr explicit MassFlow(
            double value,
            MassFlowUnit unit = MassFlowUnit::GramsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MassFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassFlow operator+(MassFlow other) const noexcept
        {
            return MassFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr MassFlow operator-(MassFlow other) const noexcept
        {
            return MassFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr MassFlow operator*(double scalar) const noexcept
        {
            return MassFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr MassFlow operator/(double scalar) const noexcept
        {
            return MassFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MassFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MassFlow other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grams_per_second() const
        {
            return convert_from_base(MassFlowUnit::GramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerSecond);
        }


        [[nodiscard]] constexpr double nanograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::NanogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::NanogramsPerSecond);
        }


        [[nodiscard]] constexpr double micrograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::MicrogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramsPerSecond);
        }


        [[nodiscard]] constexpr double milligrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::MilligramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::MilligramsPerSecond);
        }


        [[nodiscard]] constexpr double centigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::CentigramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::CentigramsPerSecond);
        }


        [[nodiscard]] constexpr double decigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecigramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::DecigramsPerSecond);
        }


        [[nodiscard]] constexpr double decagrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecagramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::DecagramsPerSecond);
        }


        [[nodiscard]] constexpr double hectograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::HectogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::HectogramsPerSecond);
        }


        [[nodiscard]] constexpr double kilograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerSecond);
        }


        [[nodiscard]] constexpr double grams_per_day() const
        {
            return convert_from_base(MassFlowUnit::GramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerDay);
        }


        [[nodiscard]] constexpr double nanograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::NanogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::NanogramsPerDay);
        }


        [[nodiscard]] constexpr double micrograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::MicrogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramsPerDay);
        }


        [[nodiscard]] constexpr double milligrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MilligramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::MilligramsPerDay);
        }


        [[nodiscard]] constexpr double centigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::CentigramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::CentigramsPerDay);
        }


        [[nodiscard]] constexpr double decigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecigramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::DecigramsPerDay);
        }


        [[nodiscard]] constexpr double decagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecagramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::DecagramsPerDay);
        }


        [[nodiscard]] constexpr double hectograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::HectogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::HectogramsPerDay);
        }


        [[nodiscard]] constexpr double kilograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerDay);
        }


        [[nodiscard]] constexpr double megagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegagramsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megagrams_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::MegagramsPerDay);
        }


        [[nodiscard]] constexpr double grams_per_hour() const
        {
            return convert_from_base(MassFlowUnit::GramsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::GramsPerHour);
        }


        [[nodiscard]] constexpr double kilograms_per_hour() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerHour);
        }


        [[nodiscard]] constexpr double kilograms_per_minute() const
        {
            return convert_from_base(MassFlowUnit::KilogramsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_minute(double value)
        {
            return MassFlow(value, MassFlowUnit::KilogramsPerMinute);
        }


        [[nodiscard]] constexpr double tonnes_per_hour() const
        {
            return convert_from_base(MassFlowUnit::TonnesPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::TonnesPerHour);
        }


        [[nodiscard]] constexpr double pounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerDay);
        }


        [[nodiscard]] constexpr double megapounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerDay);
        }


        [[nodiscard]] constexpr double pounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerHour);
        }


        [[nodiscard]] constexpr double megapounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerHour);
        }


        [[nodiscard]] constexpr double pounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_minute(double value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerMinute);
        }


        [[nodiscard]] constexpr double megapounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_minute(double value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerMinute);
        }


        [[nodiscard]] constexpr double pounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::PoundsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::PoundsPerSecond);
        }


        [[nodiscard]] constexpr double megapounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::MegapoundsPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_second(double value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundsPerSecond);
        }


        [[nodiscard]] constexpr double tonnes_per_day() const
        {
            return convert_from_base(MassFlowUnit::TonnesPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_day(double value)
        {
            return MassFlow(value, MassFlowUnit::TonnesPerDay);
        }


        [[nodiscard]] constexpr double short_tons_per_hour() const
        {
            return convert_from_base(MassFlowUnit::ShortTonsPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_short_tons_per_hour(double value)
        {
            return MassFlow(value, MassFlowUnit::ShortTonsPerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MassFlowUnit unit)
        {
            switch (unit)
            {

            case MassFlowUnit::GramsPerSecond:
                return value;

            case MassFlowUnit::NanogramsPerSecond:
                return (value * 1e-9);

            case MassFlowUnit::MicrogramsPerSecond:
                return (value * 1e-6);

            case MassFlowUnit::MilligramsPerSecond:
                return (value * 1e-3);

            case MassFlowUnit::CentigramsPerSecond:
                return (value * 1e-2);

            case MassFlowUnit::DecigramsPerSecond:
                return (value * 1e-1);

            case MassFlowUnit::DecagramsPerSecond:
                return (value * 1e1);

            case MassFlowUnit::HectogramsPerSecond:
                return (value * 1e2);

            case MassFlowUnit::KilogramsPerSecond:
                return (value * 1e3);

            case MassFlowUnit::GramsPerDay:
                return value / 86400;

            case MassFlowUnit::NanogramsPerDay:
                return (value * 1e-9) / 86400;

            case MassFlowUnit::MicrogramsPerDay:
                return (value * 1e-6) / 86400;

            case MassFlowUnit::MilligramsPerDay:
                return (value * 1e-3) / 86400;

            case MassFlowUnit::CentigramsPerDay:
                return (value * 1e-2) / 86400;

            case MassFlowUnit::DecigramsPerDay:
                return (value * 1e-1) / 86400;

            case MassFlowUnit::DecagramsPerDay:
                return (value * 1e1) / 86400;

            case MassFlowUnit::HectogramsPerDay:
                return (value * 1e2) / 86400;

            case MassFlowUnit::KilogramsPerDay:
                return (value * 1e3) / 86400;

            case MassFlowUnit::MegagramsPerDay:
                return (value * 1e6) / 86400;

            case MassFlowUnit::GramsPerHour:
                return value / 3600;

            case MassFlowUnit::KilogramsPerHour:
                return value / 3.6;

            case MassFlowUnit::KilogramsPerMinute:
                return value / 0.06;

            case MassFlowUnit::TonnesPerHour:
                return value * 1000 / 3.6;

            case MassFlowUnit::PoundsPerDay:
                return value * 453.59237 / 86400;

            case MassFlowUnit::MegapoundsPerDay:
                return (value * 1e6) * 453.59237 / 86400;

            case MassFlowUnit::PoundsPerHour:
                return value * 453.59237 / 3600;

            case MassFlowUnit::MegapoundsPerHour:
                return (value * 1e6) * 453.59237 / 3600;

            case MassFlowUnit::PoundsPerMinute:
                return value * 453.59237 / 60;

            case MassFlowUnit::MegapoundsPerMinute:
                return (value * 1e6) * 453.59237 / 60;

            case MassFlowUnit::PoundsPerSecond:
                return value * 453.59237;

            case MassFlowUnit::MegapoundsPerSecond:
                return (value * 1e6) * 453.59237;

            case MassFlowUnit::TonnesPerDay:
                return value / 0.0864000;

            case MassFlowUnit::ShortTonsPerHour:
                return value * 907.18474 / 3.6;

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MassFlowUnit unit) const
        {
            switch (unit)
            {

            case MassFlowUnit::GramsPerSecond:
                return value_;

            case MassFlowUnit::NanogramsPerSecond:
                return (value_) / 1e-9;

            case MassFlowUnit::MicrogramsPerSecond:
                return (value_) / 1e-6;

            case MassFlowUnit::MilligramsPerSecond:
                return (value_) / 1e-3;

            case MassFlowUnit::CentigramsPerSecond:
                return (value_) / 1e-2;

            case MassFlowUnit::DecigramsPerSecond:
                return (value_) / 1e-1;

            case MassFlowUnit::DecagramsPerSecond:
                return (value_) / 1e1;

            case MassFlowUnit::HectogramsPerSecond:
                return (value_) / 1e2;

            case MassFlowUnit::KilogramsPerSecond:
                return (value_) / 1e3;

            case MassFlowUnit::GramsPerDay:
                return value_ * 86400;

            case MassFlowUnit::NanogramsPerDay:
                return (value_ * 86400) / 1e-9;

            case MassFlowUnit::MicrogramsPerDay:
                return (value_ * 86400) / 1e-6;

            case MassFlowUnit::MilligramsPerDay:
                return (value_ * 86400) / 1e-3;

            case MassFlowUnit::CentigramsPerDay:
                return (value_ * 86400) / 1e-2;

            case MassFlowUnit::DecigramsPerDay:
                return (value_ * 86400) / 1e-1;

            case MassFlowUnit::DecagramsPerDay:
                return (value_ * 86400) / 1e1;

            case MassFlowUnit::HectogramsPerDay:
                return (value_ * 86400) / 1e2;

            case MassFlowUnit::KilogramsPerDay:
                return (value_ * 86400) / 1e3;

            case MassFlowUnit::MegagramsPerDay:
                return (value_ * 86400) / 1e6;

            case MassFlowUnit::GramsPerHour:
                return value_ * 3600;

            case MassFlowUnit::KilogramsPerHour:
                return value_ * 3.6;

            case MassFlowUnit::KilogramsPerMinute:
                return value_ * 0.06;

            case MassFlowUnit::TonnesPerHour:
                return value_ * 3.6 / 1000;

            case MassFlowUnit::PoundsPerDay:
                return value_ * 86400 / 453.59237;

            case MassFlowUnit::MegapoundsPerDay:
                return (value_ * 86400 / 453.59237) / 1e6;

            case MassFlowUnit::PoundsPerHour:
                return value_ * 3600 / 453.59237;

            case MassFlowUnit::MegapoundsPerHour:
                return (value_ * 3600 / 453.59237) / 1e6;

            case MassFlowUnit::PoundsPerMinute:
                return value_ * 60 / 453.59237;

            case MassFlowUnit::MegapoundsPerMinute:
                return (value_ * 60 / 453.59237) / 1e6;

            case MassFlowUnit::PoundsPerSecond:
                return value_ / 453.59237;

            case MassFlowUnit::MegapoundsPerSecond:
                return (value_ / 453.59237) / 1e6;

            case MassFlowUnit::TonnesPerDay:
                return value_ * 0.0864000;

            case MassFlowUnit::ShortTonsPerHour:
                return value_ * 3.6 / 907.18474;

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        double value_;
    };
}
