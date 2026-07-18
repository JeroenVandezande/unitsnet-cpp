#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class IrradianceUnit : std::uint16_t
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
            double value,
            IrradianceUnit unit = IrradianceUnit::WattsPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(IrradianceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Irradiance operator+(Irradiance other) const noexcept
        {
            return Irradiance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Irradiance operator-(Irradiance other) const noexcept
        {
            return Irradiance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Irradiance operator*(double scalar) const noexcept
        {
            return Irradiance(value_ * scalar);
        }

        [[nodiscard]] constexpr Irradiance operator/(double scalar) const noexcept
        {
            return Irradiance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Irradiance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Irradiance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::WattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::WattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double picowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::PicowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::PicowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double nanowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::NanowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::NanowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double microwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::KilowattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::KilowattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double megawatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MegawattsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_meter(double value)
        {
            return Irradiance(value, IrradianceUnit::MegawattsPerSquareMeter);
        }


        [[nodiscard]] constexpr double watts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::WattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::WattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double picowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::PicowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::PicowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double nanowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::NanowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::NanowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double microwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::KilowattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::KilowattsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double megawatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MegawattsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_centimeter(double value)
        {
            return Irradiance(value, IrradianceUnit::MegawattsPerSquareCentimeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, IrradianceUnit unit)
        {
            switch (unit)
            {

            case IrradianceUnit::WattsPerSquareMeter:
                return value;

            case IrradianceUnit::PicowattsPerSquareMeter:
                return (value * 1e-12);

            case IrradianceUnit::NanowattsPerSquareMeter:
                return (value * 1e-9);

            case IrradianceUnit::MicrowattsPerSquareMeter:
                return (value * 1e-6);

            case IrradianceUnit::MilliwattsPerSquareMeter:
                return (value * 1e-3);

            case IrradianceUnit::KilowattsPerSquareMeter:
                return (value * 1e3);

            case IrradianceUnit::MegawattsPerSquareMeter:
                return (value * 1e6);

            case IrradianceUnit::WattsPerSquareCentimeter:
                return value * 10000;

            case IrradianceUnit::PicowattsPerSquareCentimeter:
                return (value * 1e-12) * 10000;

            case IrradianceUnit::NanowattsPerSquareCentimeter:
                return (value * 1e-9) * 10000;

            case IrradianceUnit::MicrowattsPerSquareCentimeter:
                return (value * 1e-6) * 10000;

            case IrradianceUnit::MilliwattsPerSquareCentimeter:
                return (value * 1e-3) * 10000;

            case IrradianceUnit::KilowattsPerSquareCentimeter:
                return (value * 1e3) * 10000;

            case IrradianceUnit::MegawattsPerSquareCentimeter:
                return (value * 1e6) * 10000;

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(IrradianceUnit unit) const
        {
            switch (unit)
            {

            case IrradianceUnit::WattsPerSquareMeter:
                return value_;

            case IrradianceUnit::PicowattsPerSquareMeter:
                return (value_) / 1e-12;

            case IrradianceUnit::NanowattsPerSquareMeter:
                return (value_) / 1e-9;

            case IrradianceUnit::MicrowattsPerSquareMeter:
                return (value_) / 1e-6;

            case IrradianceUnit::MilliwattsPerSquareMeter:
                return (value_) / 1e-3;

            case IrradianceUnit::KilowattsPerSquareMeter:
                return (value_) / 1e3;

            case IrradianceUnit::MegawattsPerSquareMeter:
                return (value_) / 1e6;

            case IrradianceUnit::WattsPerSquareCentimeter:
                return value_ * 0.0001;

            case IrradianceUnit::PicowattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e-12;

            case IrradianceUnit::NanowattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e-9;

            case IrradianceUnit::MicrowattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e-6;

            case IrradianceUnit::MilliwattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e-3;

            case IrradianceUnit::KilowattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e3;

            case IrradianceUnit::MegawattsPerSquareCentimeter:
                return (value_ * 0.0001) / 1e6;

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        double value_;
    };
}
