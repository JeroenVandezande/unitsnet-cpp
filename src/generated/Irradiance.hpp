#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class IrradianceUnit : std::uint8_t
    {
        WattsPerSquareMeter,
        PicowattsPerSquareMeter,
        NanowattsPerSquareMeter,
        MicrowattsPerSquareMeter,
        MilliwattsPerSquareMeter,
        KilowattsPerSquareMeter,
        MegawattsPerSquareMeter,
        WattsPerSquareCentimeter,
        PicowattsPerSquareCentimeter,
        NanowattsPerSquareCentimeter,
        MicrowattsPerSquareCentimeter,
        MilliwattsPerSquareCentimeter,
        KilowattsPerSquareCentimeter,
        MegawattsPerSquareCentimeter,
    };

    /// <summary>Irradiance is the intensity of ultraviolet (UV) or visible light incident on a surface.</summary>
    class Irradiance
    {
    public:
        constexpr explicit Irradiance(
            const un_scalar_t value,
            const IrradianceUnit unit = IrradianceUnit::WattsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Irradiance(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const IrradianceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Irradiance operator+(const Irradiance other) const noexcept
        {
            return Irradiance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Irradiance operator-(const Irradiance other) const noexcept
        {
            return Irradiance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Irradiance operator*(const un_scalar_t scalar) const noexcept
        {
            return Irradiance(value_ * scalar);
        }

        [[nodiscard]] constexpr Irradiance operator/(const un_scalar_t scalar) const noexcept
        {
            return Irradiance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Irradiance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Irradiance other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Irradiance other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::WattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::WattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::PicowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::PicowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::NanowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::NanowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::KilowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::KilowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MegawattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MegawattsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::WattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::WattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::PicowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::PicowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::NanowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::NanowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::KilowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::KilowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MegawattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MegawattsPerSquareCentimeter);
        }


        [[nodiscard]] static constexpr Irradiance from_invalid()
        {
            return Irradiance(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IrradianceUnit unit)
        {
            switch (unit)
            {

            case IrradianceUnit::WattsPerSquareMeter:
                return value;

            case IrradianceUnit::PicowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case IrradianceUnit::NanowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case IrradianceUnit::MicrowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case IrradianceUnit::MilliwattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case IrradianceUnit::KilowattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case IrradianceUnit::MegawattsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case IrradianceUnit::WattsPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::PicowattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::NanowattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MicrowattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MilliwattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::KilowattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MegawattsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(10000);

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IrradianceUnit unit) const
        {
            switch (unit)
            {

            case IrradianceUnit::WattsPerSquareMeter:
                return value_;

            case IrradianceUnit::PicowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case IrradianceUnit::NanowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case IrradianceUnit::MicrowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case IrradianceUnit::MilliwattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case IrradianceUnit::KilowattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case IrradianceUnit::MegawattsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case IrradianceUnit::WattsPerSquareCentimeter:
                return value_ * static_cast<un_scalar_t>(0.0001);

            case IrradianceUnit::PicowattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-12);

            case IrradianceUnit::NanowattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-9);

            case IrradianceUnit::MicrowattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-6);

            case IrradianceUnit::MilliwattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-3);

            case IrradianceUnit::KilowattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e3);

            case IrradianceUnit::MegawattsPerSquareCentimeter:
                return (value_ * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        un_scalar_t value_;
    };
}
