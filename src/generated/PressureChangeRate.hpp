#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PressureChangeRateUnit : std::uint16_t
    {
        PascalsPerSecond,
        KilopascalsPerSecond,
        MegapascalsPerSecond,
        PascalsPerMinute,
        KilopascalsPerMinute,
        MegapascalsPerMinute,
        MillimetersOfMercuryPerSecond,
        AtmospheresPerSecond,
        PoundsForcePerSquareInchPerSecond,
        KilopoundsForcePerSquareInchPerSecond,
        MegapoundsForcePerSquareInchPerSecond,
        PoundsForcePerSquareInchPerMinute,
        KilopoundsForcePerSquareInchPerMinute,
        MegapoundsForcePerSquareInchPerMinute,
        BarsPerSecond,
        MillibarsPerSecond,
        BarsPerMinute,
        MillibarsPerMinute,
    };

    /// <summary>Pressure change rate is the ratio of the pressure change to the time during which the change occurred (value of pressure changes per unit time).</summary>
    class PressureChangeRate
    {
    public:
        constexpr explicit PressureChangeRate(
            double value,
            PressureChangeRateUnit unit = PressureChangeRateUnit::PascalsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PressureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PressureChangeRate operator+(PressureChangeRate other) const noexcept
        {
            return PressureChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr PressureChangeRate operator-(PressureChangeRate other) const noexcept
        {
            return PressureChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr PressureChangeRate operator*(double scalar) const noexcept
        {
            return PressureChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr PressureChangeRate operator/(double scalar) const noexcept
        {
            return PressureChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(PressureChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(PressureChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double pascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalsPerSecond);
        }


        [[nodiscard]] constexpr double kilopascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalsPerSecond);
        }


        [[nodiscard]] constexpr double megapascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalsPerSecond);
        }


        [[nodiscard]] constexpr double pascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalsPerMinute);
        }


        [[nodiscard]] constexpr double kilopascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalsPerMinute);
        }


        [[nodiscard]] constexpr double megapascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalsPerMinute);
        }


        [[nodiscard]] constexpr double millimeters_of_mercury_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillimetersOfMercuryPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millimeters_of_mercury_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillimetersOfMercuryPerSecond);
        }


        [[nodiscard]] constexpr double atmospheres_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::AtmospheresPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_atmospheres_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::AtmospheresPerSecond);
        }


        [[nodiscard]] constexpr double pounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond);
        }


        [[nodiscard]] constexpr double megapounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond);
        }


        [[nodiscard]] constexpr double pounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute);
        }


        [[nodiscard]] constexpr double megapounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute);
        }


        [[nodiscard]] constexpr double bars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::BarsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarsPerSecond);
        }


        [[nodiscard]] constexpr double millibars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_second(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarsPerSecond);
        }


        [[nodiscard]] constexpr double bars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::BarsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarsPerMinute);
        }


        [[nodiscard]] constexpr double millibars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_minute(double value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarsPerMinute);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PressureChangeRateUnit unit)
        {
            switch (unit)
            {

            case PressureChangeRateUnit::PascalsPerSecond:
                return value;

            case PressureChangeRateUnit::KilopascalsPerSecond:
                return (value * 1e3);

            case PressureChangeRateUnit::MegapascalsPerSecond:
                return (value * 1e6);

            case PressureChangeRateUnit::PascalsPerMinute:
                return value / 60;

            case PressureChangeRateUnit::KilopascalsPerMinute:
                return (value * 1e3) / 60;

            case PressureChangeRateUnit::MegapascalsPerMinute:
                return (value * 1e6) / 60;

            case PressureChangeRateUnit::MillimetersOfMercuryPerSecond:
                return value * 133.322387415;

            case PressureChangeRateUnit::AtmospheresPerSecond:
                return value * 1.01325 * 1e5;

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond:
                return value * 4.4482216152605 / 0.00064516;

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond:
                return (value * 1e3) * 4.4482216152605 / 0.00064516;

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond:
                return (value * 1e6) * 4.4482216152605 / 0.00064516;

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute:
                return value * (4.4482216152605 / 0.00064516) / 60;

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute:
                return (value * 1e3) * (4.4482216152605 / 0.00064516) / 60;

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute:
                return (value * 1e6) * (4.4482216152605 / 0.00064516) / 60;

            case PressureChangeRateUnit::BarsPerSecond:
                return value * 1e5;

            case PressureChangeRateUnit::MillibarsPerSecond:
                return (value * 1e-3) * 1e5;

            case PressureChangeRateUnit::BarsPerMinute:
                return value * 1e5 / 60;

            case PressureChangeRateUnit::MillibarsPerMinute:
                return (value * 1e-3) * 1e5 / 60;

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PressureChangeRateUnit unit) const
        {
            switch (unit)
            {

            case PressureChangeRateUnit::PascalsPerSecond:
                return value_;

            case PressureChangeRateUnit::KilopascalsPerSecond:
                return (value_) / 1e3;

            case PressureChangeRateUnit::MegapascalsPerSecond:
                return (value_) / 1e6;

            case PressureChangeRateUnit::PascalsPerMinute:
                return value_ * 60;

            case PressureChangeRateUnit::KilopascalsPerMinute:
                return (value_ * 60) / 1e3;

            case PressureChangeRateUnit::MegapascalsPerMinute:
                return (value_ * 60) / 1e6;

            case PressureChangeRateUnit::MillimetersOfMercuryPerSecond:
                return value_ / 133.322387415;

            case PressureChangeRateUnit::AtmospheresPerSecond:
                return value_ / (1.01325 * 1e5);

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond:
                return value_ * 0.00064516 / 4.4482216152605;

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond:
                return (value_ * 0.00064516 / 4.4482216152605) / 1e3;

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond:
                return (value_ * 0.00064516 / 4.4482216152605) / 1e6;

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute:
                return value_ * 60 / (4.4482216152605 / 0.00064516);

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute:
                return (value_ * 60 / (4.4482216152605 / 0.00064516)) / 1e3;

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute:
                return (value_ * 60 / (4.4482216152605 / 0.00064516)) / 1e6;

            case PressureChangeRateUnit::BarsPerSecond:
                return value_ / 1e5;

            case PressureChangeRateUnit::MillibarsPerSecond:
                return (value_ / 1e5) / 1e-3;

            case PressureChangeRateUnit::BarsPerMinute:
                return value_ / 1e5 * 60;

            case PressureChangeRateUnit::MillibarsPerMinute:
                return (value_ / 1e5 * 60) / 1e-3;

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        double value_;
    };
}
