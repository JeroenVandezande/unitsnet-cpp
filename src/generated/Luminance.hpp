#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LuminanceUnit : std::uint16_t
    {
        CandelasPerSquareMeter,
        NanocandelasPerSquareMeter,
        MicrocandelasPerSquareMeter,
        MillicandelasPerSquareMeter,
        CenticandelasPerSquareMeter,
        DecicandelasPerSquareMeter,
        KilocandelasPerSquareMeter,
        CandelasPerSquareFoot,
        CandelasPerSquareInch,
        Nits,
    };

    /// <summary></summary>
    class Luminance
    {
    public:
        constexpr explicit Luminance(
            double value,
            LuminanceUnit unit = LuminanceUnit::CandelasPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LuminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Luminance operator+(Luminance other) const noexcept
        {
            return Luminance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Luminance operator-(Luminance other) const noexcept
        {
            return Luminance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Luminance operator*(double scalar) const noexcept
        {
            return Luminance(value_ * scalar);
        }

        [[nodiscard]] constexpr Luminance operator/(double scalar) const noexcept
        {
            return Luminance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Luminance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Luminance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double candelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double nanocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::NanocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_nanocandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::NanocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double microcandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MicrocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_microcandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::MicrocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double millicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MillicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_millicandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::MillicandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double centicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CenticandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_centicandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::CenticandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double decicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::DecicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_decicandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::DecicandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double kilocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::KilocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_kilocandelas_per_square_meter(double value)
        {
            return Luminance(value, LuminanceUnit::KilocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr double candelas_per_square_foot() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareFoot);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_foot(double value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareFoot);
        }


        [[nodiscard]] constexpr double candelas_per_square_inch() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareInch);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_inch(double value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareInch);
        }


        [[nodiscard]] constexpr double nits() const
        {
            return convert_from_base(LuminanceUnit::Nits);
        }

        [[nodiscard]] static constexpr Luminance from_nits(double value)
        {
            return Luminance(value, LuminanceUnit::Nits);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LuminanceUnit unit)
        {
            switch (unit)
            {

            case LuminanceUnit::CandelasPerSquareMeter:
                return value;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (value * 1e-9);

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (value * 1e-6);

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (value * 1e-3);

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (value * 1e-2);

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (value * 1e-1);

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (value * 1e3);

            case LuminanceUnit::CandelasPerSquareFoot:
                return value / 9.290304e-2;

            case LuminanceUnit::CandelasPerSquareInch:
                return value / 0.00064516;

            case LuminanceUnit::Nits:
                return value;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LuminanceUnit unit) const
        {
            switch (unit)
            {

            case LuminanceUnit::CandelasPerSquareMeter:
                return value_;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (value_) / 1e-9;

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (value_) / 1e-6;

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (value_) / 1e-3;

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (value_) / 1e-2;

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (value_) / 1e-1;

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (value_) / 1e3;

            case LuminanceUnit::CandelasPerSquareFoot:
                return value_ * 9.290304e-2;

            case LuminanceUnit::CandelasPerSquareInch:
                return value_ * 0.00064516;

            case LuminanceUnit::Nits:
                return value_;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        double value_;
    };
}
