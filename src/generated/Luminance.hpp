#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LuminanceUnit : std::uint8_t
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
            const un_scalar_t value,
            const LuminanceUnit unit = LuminanceUnit::CandelasPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Luminance operator+(const Luminance other) const noexcept
        {
            return Luminance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Luminance operator-(const Luminance other) const noexcept
        {
            return Luminance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Luminance operator*(const un_scalar_t scalar) const noexcept
        {
            return Luminance(value_ * scalar);
        }

        [[nodiscard]] constexpr Luminance operator/(const un_scalar_t scalar) const noexcept
        {
            return Luminance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Luminance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Luminance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t candelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::NanocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_nanocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::NanocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t microcandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MicrocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_microcandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MicrocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t millicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MillicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_millicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MillicandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t centicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CenticandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_centicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CenticandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t decicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::DecicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_decicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::DecicandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::KilocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_kilocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::KilocandelasPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t candelas_per_square_foot() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareFoot);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_foot(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t candelas_per_square_inch() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareInch);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_inch(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t nits() const
        {
            return convert_from_base(LuminanceUnit::Nits);
        }

        [[nodiscard]] static constexpr Luminance from_nits(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::Nits);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminanceUnit unit)
        {
            switch (unit)
            {

            case LuminanceUnit::CandelasPerSquareMeter:
                return value;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LuminanceUnit::CandelasPerSquareFoot:
                return value / 9.290304e-2;

            case LuminanceUnit::CandelasPerSquareInch:
                return value / 0.00064516;

            case LuminanceUnit::Nits:
                return value;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminanceUnit unit) const
        {
            switch (unit)
            {

            case LuminanceUnit::CandelasPerSquareMeter:
                return value_;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case LuminanceUnit::CandelasPerSquareFoot:
                return value_ * 9.290304e-2;

            case LuminanceUnit::CandelasPerSquareInch:
                return value_ * 0.00064516;

            case LuminanceUnit::Nits:
                return value_;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        un_scalar_t value_;
    };
}
