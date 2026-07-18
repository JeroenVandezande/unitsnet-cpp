#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PowerDensityUnit : std::uint16_t
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
            double value,
            PowerDensityUnit unit = PowerDensityUnit::WattsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PowerDensity operator+(PowerDensity other) const noexcept
        {
            return PowerDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr PowerDensity operator-(PowerDensity other) const noexcept
        {
            return PowerDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr PowerDensity operator*(double scalar) const noexcept
        {
            return PowerDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr PowerDensity operator/(double scalar) const noexcept
        {
            return PowerDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(PowerDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(PowerDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double picowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double nanowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double microwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double milliwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double deciwatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double decawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilowatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double megawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double gigawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double terawatts_per_cubic_meter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicMeter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_meter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicMeter);
        }


        [[nodiscard]] constexpr double watts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicInch);
        }


        [[nodiscard]] constexpr double picowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicInch);
        }


        [[nodiscard]] constexpr double nanowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicInch);
        }


        [[nodiscard]] constexpr double microwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicInch);
        }


        [[nodiscard]] constexpr double milliwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicInch);
        }


        [[nodiscard]] constexpr double deciwatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicInch);
        }


        [[nodiscard]] constexpr double decawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicInch);
        }


        [[nodiscard]] constexpr double kilowatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicInch);
        }


        [[nodiscard]] constexpr double megawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicInch);
        }


        [[nodiscard]] constexpr double gigawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicInch);
        }


        [[nodiscard]] constexpr double terawatts_per_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicInch);
        }


        [[nodiscard]] constexpr double watts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double picowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double nanowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double microwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double milliwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double deciwatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double decawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double kilowatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double megawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double gigawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double terawatts_per_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerCubicFoot);
        }


        [[nodiscard]] constexpr double watts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::WattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_watts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::WattsPerLiter);
        }


        [[nodiscard]] constexpr double picowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::PicowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_picowatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::PicowattsPerLiter);
        }


        [[nodiscard]] constexpr double nanowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::NanowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_nanowatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::NanowattsPerLiter);
        }


        [[nodiscard]] constexpr double microwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MicrowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_microwatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MicrowattsPerLiter);
        }


        [[nodiscard]] constexpr double milliwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MilliwattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_milliwatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MilliwattsPerLiter);
        }


        [[nodiscard]] constexpr double deciwatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DeciwattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_deciwatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DeciwattsPerLiter);
        }


        [[nodiscard]] constexpr double decawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::DecawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_decawatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::DecawattsPerLiter);
        }


        [[nodiscard]] constexpr double kilowatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::KilowattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_kilowatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::KilowattsPerLiter);
        }


        [[nodiscard]] constexpr double megawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::MegawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_megawatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::MegawattsPerLiter);
        }


        [[nodiscard]] constexpr double gigawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::GigawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_gigawatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::GigawattsPerLiter);
        }


        [[nodiscard]] constexpr double terawatts_per_liter() const
        {
            return convert_from_base(PowerDensityUnit::TerawattsPerLiter);
        }

        [[nodiscard]] static constexpr PowerDensity from_terawatts_per_liter(double value)
        {
            return PowerDensity(value, PowerDensityUnit::TerawattsPerLiter);
        }


        [[nodiscard]] constexpr double btus_per_second_cubic_inch() const
        {
            return convert_from_base(PowerDensityUnit::BtusPerSecondCubicInch);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_inch(double value)
        {
            return PowerDensity(value, PowerDensityUnit::BtusPerSecondCubicInch);
        }


        [[nodiscard]] constexpr double btus_per_second_cubic_foot() const
        {
            return convert_from_base(PowerDensityUnit::BtusPerSecondCubicFoot);
        }

        [[nodiscard]] static constexpr PowerDensity from_btus_per_second_cubic_foot(double value)
        {
            return PowerDensity(value, PowerDensityUnit::BtusPerSecondCubicFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PowerDensityUnit unit)
        {
            switch (unit)
            {

            case PowerDensityUnit::WattsPerCubicMeter:
                return value;

            case PowerDensityUnit::PicowattsPerCubicMeter:
                return (value * 1e-12);

            case PowerDensityUnit::NanowattsPerCubicMeter:
                return (value * 1e-9);

            case PowerDensityUnit::MicrowattsPerCubicMeter:
                return (value * 1e-6);

            case PowerDensityUnit::MilliwattsPerCubicMeter:
                return (value * 1e-3);

            case PowerDensityUnit::DeciwattsPerCubicMeter:
                return (value * 1e-1);

            case PowerDensityUnit::DecawattsPerCubicMeter:
                return (value * 1e1);

            case PowerDensityUnit::KilowattsPerCubicMeter:
                return (value * 1e3);

            case PowerDensityUnit::MegawattsPerCubicMeter:
                return (value * 1e6);

            case PowerDensityUnit::GigawattsPerCubicMeter:
                return (value * 1e9);

            case PowerDensityUnit::TerawattsPerCubicMeter:
                return (value * 1e12);

            case PowerDensityUnit::WattsPerCubicInch:
                return value / 1.6387064e-5;

            case PowerDensityUnit::PicowattsPerCubicInch:
                return (value * 1e-12) / 1.6387064e-5;

            case PowerDensityUnit::NanowattsPerCubicInch:
                return (value * 1e-9) / 1.6387064e-5;

            case PowerDensityUnit::MicrowattsPerCubicInch:
                return (value * 1e-6) / 1.6387064e-5;

            case PowerDensityUnit::MilliwattsPerCubicInch:
                return (value * 1e-3) / 1.6387064e-5;

            case PowerDensityUnit::DeciwattsPerCubicInch:
                return (value * 1e-1) / 1.6387064e-5;

            case PowerDensityUnit::DecawattsPerCubicInch:
                return (value * 1e1) / 1.6387064e-5;

            case PowerDensityUnit::KilowattsPerCubicInch:
                return (value * 1e3) / 1.6387064e-5;

            case PowerDensityUnit::MegawattsPerCubicInch:
                return (value * 1e6) / 1.6387064e-5;

            case PowerDensityUnit::GigawattsPerCubicInch:
                return (value * 1e9) / 1.6387064e-5;

            case PowerDensityUnit::TerawattsPerCubicInch:
                return (value * 1e12) / 1.6387064e-5;

            case PowerDensityUnit::WattsPerCubicFoot:
                return value / 0.028316846592;

            case PowerDensityUnit::PicowattsPerCubicFoot:
                return (value * 1e-12) / 0.028316846592;

            case PowerDensityUnit::NanowattsPerCubicFoot:
                return (value * 1e-9) / 0.028316846592;

            case PowerDensityUnit::MicrowattsPerCubicFoot:
                return (value * 1e-6) / 0.028316846592;

            case PowerDensityUnit::MilliwattsPerCubicFoot:
                return (value * 1e-3) / 0.028316846592;

            case PowerDensityUnit::DeciwattsPerCubicFoot:
                return (value * 1e-1) / 0.028316846592;

            case PowerDensityUnit::DecawattsPerCubicFoot:
                return (value * 1e1) / 0.028316846592;

            case PowerDensityUnit::KilowattsPerCubicFoot:
                return (value * 1e3) / 0.028316846592;

            case PowerDensityUnit::MegawattsPerCubicFoot:
                return (value * 1e6) / 0.028316846592;

            case PowerDensityUnit::GigawattsPerCubicFoot:
                return (value * 1e9) / 0.028316846592;

            case PowerDensityUnit::TerawattsPerCubicFoot:
                return (value * 1e12) / 0.028316846592;

            case PowerDensityUnit::WattsPerLiter:
                return value * 1.0e3;

            case PowerDensityUnit::PicowattsPerLiter:
                return (value * 1e-12) * 1.0e3;

            case PowerDensityUnit::NanowattsPerLiter:
                return (value * 1e-9) * 1.0e3;

            case PowerDensityUnit::MicrowattsPerLiter:
                return (value * 1e-6) * 1.0e3;

            case PowerDensityUnit::MilliwattsPerLiter:
                return (value * 1e-3) * 1.0e3;

            case PowerDensityUnit::DeciwattsPerLiter:
                return (value * 1e-1) * 1.0e3;

            case PowerDensityUnit::DecawattsPerLiter:
                return (value * 1e1) * 1.0e3;

            case PowerDensityUnit::KilowattsPerLiter:
                return (value * 1e3) * 1.0e3;

            case PowerDensityUnit::MegawattsPerLiter:
                return (value * 1e6) * 1.0e3;

            case PowerDensityUnit::GigawattsPerLiter:
                return (value * 1e9) * 1.0e3;

            case PowerDensityUnit::TerawattsPerLiter:
                return (value * 1e12) * 1.0e3;

            case PowerDensityUnit::BtusPerSecondCubicInch:
                return value * 1055.05585262 / (2.54e-2 * 2.54e-2 * 2.54e-2);

            case PowerDensityUnit::BtusPerSecondCubicFoot:
                return value * 1055.05585262 / (0.3048 * 0.3048 * 0.3048);

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PowerDensityUnit unit) const
        {
            switch (unit)
            {

            case PowerDensityUnit::WattsPerCubicMeter:
                return value_;

            case PowerDensityUnit::PicowattsPerCubicMeter:
                return (value_) / 1e-12;

            case PowerDensityUnit::NanowattsPerCubicMeter:
                return (value_) / 1e-9;

            case PowerDensityUnit::MicrowattsPerCubicMeter:
                return (value_) / 1e-6;

            case PowerDensityUnit::MilliwattsPerCubicMeter:
                return (value_) / 1e-3;

            case PowerDensityUnit::DeciwattsPerCubicMeter:
                return (value_) / 1e-1;

            case PowerDensityUnit::DecawattsPerCubicMeter:
                return (value_) / 1e1;

            case PowerDensityUnit::KilowattsPerCubicMeter:
                return (value_) / 1e3;

            case PowerDensityUnit::MegawattsPerCubicMeter:
                return (value_) / 1e6;

            case PowerDensityUnit::GigawattsPerCubicMeter:
                return (value_) / 1e9;

            case PowerDensityUnit::TerawattsPerCubicMeter:
                return (value_) / 1e12;

            case PowerDensityUnit::WattsPerCubicInch:
                return value_ * 1.6387064e-5;

            case PowerDensityUnit::PicowattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e-12;

            case PowerDensityUnit::NanowattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e-9;

            case PowerDensityUnit::MicrowattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e-6;

            case PowerDensityUnit::MilliwattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e-3;

            case PowerDensityUnit::DeciwattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e-1;

            case PowerDensityUnit::DecawattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e1;

            case PowerDensityUnit::KilowattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e3;

            case PowerDensityUnit::MegawattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e6;

            case PowerDensityUnit::GigawattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e9;

            case PowerDensityUnit::TerawattsPerCubicInch:
                return (value_ * 1.6387064e-5) / 1e12;

            case PowerDensityUnit::WattsPerCubicFoot:
                return value_ * 0.028316846592;

            case PowerDensityUnit::PicowattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e-12;

            case PowerDensityUnit::NanowattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e-9;

            case PowerDensityUnit::MicrowattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e-6;

            case PowerDensityUnit::MilliwattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e-3;

            case PowerDensityUnit::DeciwattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e-1;

            case PowerDensityUnit::DecawattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e1;

            case PowerDensityUnit::KilowattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e3;

            case PowerDensityUnit::MegawattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e6;

            case PowerDensityUnit::GigawattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e9;

            case PowerDensityUnit::TerawattsPerCubicFoot:
                return (value_ * 0.028316846592) / 1e12;

            case PowerDensityUnit::WattsPerLiter:
                return value_ / 1.0e3;

            case PowerDensityUnit::PicowattsPerLiter:
                return (value_ / 1.0e3) / 1e-12;

            case PowerDensityUnit::NanowattsPerLiter:
                return (value_ / 1.0e3) / 1e-9;

            case PowerDensityUnit::MicrowattsPerLiter:
                return (value_ / 1.0e3) / 1e-6;

            case PowerDensityUnit::MilliwattsPerLiter:
                return (value_ / 1.0e3) / 1e-3;

            case PowerDensityUnit::DeciwattsPerLiter:
                return (value_ / 1.0e3) / 1e-1;

            case PowerDensityUnit::DecawattsPerLiter:
                return (value_ / 1.0e3) / 1e1;

            case PowerDensityUnit::KilowattsPerLiter:
                return (value_ / 1.0e3) / 1e3;

            case PowerDensityUnit::MegawattsPerLiter:
                return (value_ / 1.0e3) / 1e6;

            case PowerDensityUnit::GigawattsPerLiter:
                return (value_ / 1.0e3) / 1e9;

            case PowerDensityUnit::TerawattsPerLiter:
                return (value_ / 1.0e3) / 1e12;

            case PowerDensityUnit::BtusPerSecondCubicInch:
                return value_ / 1055.05585262 * (2.54e-2 * 2.54e-2 * 2.54e-2);

            case PowerDensityUnit::BtusPerSecondCubicFoot:
                return value_ / 1055.05585262 * (0.3048 * 0.3048 * 0.3048);

            }

            throw std::invalid_argument("Unknown PowerDensity unit.");
        }

        double value_;
    };
}
