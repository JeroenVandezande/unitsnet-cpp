#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PowerDensityUnit : std::uint8_t
    {
        WattsPerCubicMeter,
        PicowattsPerCubicMeter,
        NanowattsPerCubicMeter,
        MicrowattsPerCubicMeter,
        MilliwattsPerCubicMeter,
        DeciwattsPerCubicMeter,
        DecawattsPerCubicMeter,
        KilowattsPerCubicMeter,
        MegawattsPerCubicMeter,
        GigawattsPerCubicMeter,
        TerawattsPerCubicMeter,
        WattsPerCubicInch,
        PicowattsPerCubicInch,
        NanowattsPerCubicInch,
        MicrowattsPerCubicInch,
        MilliwattsPerCubicInch,
        DeciwattsPerCubicInch,
        DecawattsPerCubicInch,
        KilowattsPerCubicInch,
        MegawattsPerCubicInch,
        GigawattsPerCubicInch,
        TerawattsPerCubicInch,
        WattsPerCubicFoot,
        PicowattsPerCubicFoot,
        NanowattsPerCubicFoot,
        MicrowattsPerCubicFoot,
        MilliwattsPerCubicFoot,
        DeciwattsPerCubicFoot,
        DecawattsPerCubicFoot,
        KilowattsPerCubicFoot,
        MegawattsPerCubicFoot,
        GigawattsPerCubicFoot,
        TerawattsPerCubicFoot,
        WattsPerLiter,
        PicowattsPerLiter,
        NanowattsPerLiter,
        MicrowattsPerLiter,
        MilliwattsPerLiter,
        DeciwattsPerLiter,
        DecawattsPerLiter,
        KilowattsPerLiter,
        MegawattsPerLiter,
        GigawattsPerLiter,
        TerawattsPerLiter,
        BtusPerSecondCubicInch,
        BtusPerSecondCubicFoot,
    };

    /// <summary>The amount of power in a volume.</summary>
    class PowerDensity
    {
    public:
        constexpr explicit PowerDensity(
            const un_scalar_t value,
            const PowerDensityUnit unit = PowerDensityUnit::WattsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PowerDensity operator+(const PowerDensity other) const noexcept
        {
            return PowerDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr PowerDensity operator-(const PowerDensity other) const noexcept
        {
            return PowerDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr PowerDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return PowerDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr PowerDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return PowerDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PowerDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const PowerDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_meter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_liter(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_second_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::BtusPerSecondCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_inch(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::BtusPerSecondCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_second_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::BtusPerSecondCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_foot(const un_scalar_t value)
        {
            return PowerDensity(value, PowerDensityUnit::BtusPerSecondCubicFoot);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerDensityUnit unit)
        {
            switch (unit)
            {

            case PowerDensityUnit::WattsPerCubicMeter:
                return value;

            case PowerDensityUnit::PicowattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case PowerDensityUnit::NanowattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case PowerDensityUnit::MicrowattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PowerDensityUnit::MilliwattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PowerDensityUnit::DeciwattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case PowerDensityUnit::DecawattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e1));

            case PowerDensityUnit::KilowattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case PowerDensityUnit::MegawattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case PowerDensityUnit::GigawattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case PowerDensityUnit::TerawattsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12));

            case PowerDensityUnit::WattsPerCubicInch:
                return value / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::PicowattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::NanowattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MicrowattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MilliwattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::DeciwattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::DecawattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::KilowattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::MegawattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::GigawattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::TerawattsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e12)) / static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::WattsPerCubicFoot:
                return value / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::PicowattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::NanowattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MicrowattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MilliwattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::DeciwattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::DecawattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::KilowattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::MegawattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::GigawattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::TerawattsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e12)) / static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::WattsPerLiter:
                return value * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::PicowattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::NanowattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MicrowattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MilliwattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::DeciwattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::DecawattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::KilowattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::MegawattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::GigawattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::TerawattsPerLiter:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::BtusPerSecondCubicInch:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case PowerDensityUnit::BtusPerSecondCubicFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerDensityUnit unit) const
        {
            switch (unit)
            {

            case PowerDensityUnit::WattsPerCubicMeter:
                return value_;

            case PowerDensityUnit::PicowattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattsPerCubicInch:
                return value_ * static_cast<un_scalar_t>(1.6387064e-5);

            case PowerDensityUnit::PicowattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattsPerCubicFoot:
                return value_ * static_cast<un_scalar_t>(0.028316846592);

            case PowerDensityUnit::PicowattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::WattsPerLiter:
                return value_ / static_cast<un_scalar_t>(1.0e3);

            case PowerDensityUnit::PicowattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-12);

            case PowerDensityUnit::NanowattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-9);

            case PowerDensityUnit::MicrowattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-6);

            case PowerDensityUnit::MilliwattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-3);

            case PowerDensityUnit::DeciwattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e-1);

            case PowerDensityUnit::DecawattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e1);

            case PowerDensityUnit::KilowattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e3);

            case PowerDensityUnit::MegawattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e6);

            case PowerDensityUnit::GigawattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e9);

            case PowerDensityUnit::TerawattsPerLiter:
                return (value_ / static_cast<un_scalar_t>(1.0e3)) / static_cast<un_scalar_t>(1e12);

            case PowerDensityUnit::BtusPerSecondCubicInch:
                return value_ / static_cast<un_scalar_t>(1055.05585262) * (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case PowerDensityUnit::BtusPerSecondCubicFoot:
                return value_ / static_cast<un_scalar_t>(1055.05585262) * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        un_scalar_t value_;
    };
}
