#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class EnergyDensityUnit : std::uint16_t
    {
        JoulesPerCubicMeter,
        KilojoulesPerCubicMeter,
        MegajoulesPerCubicMeter,
        GigajoulesPerCubicMeter,
        TerajoulesPerCubicMeter,
        PetajoulesPerCubicMeter,
        WattHoursPerCubicMeter,
        KilowattHoursPerCubicMeter,
        MegawattHoursPerCubicMeter,
        GigawattHoursPerCubicMeter,
        TerawattHoursPerCubicMeter,
        PetawattHoursPerCubicMeter,
    };

    /// <summary></summary>
    class EnergyDensity
    {
    public:
        constexpr explicit EnergyDensity(
            double value,
            EnergyDensityUnit unit = EnergyDensityUnit::JoulesPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(EnergyDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr EnergyDensity operator+(EnergyDensity other) const noexcept
        {
            return EnergyDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr EnergyDensity operator-(EnergyDensity other) const noexcept
        {
            return EnergyDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr EnergyDensity operator*(double scalar) const noexcept
        {
            return EnergyDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr EnergyDensity operator/(double scalar) const noexcept
        {
            return EnergyDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(EnergyDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(EnergyDensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::JoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_joules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::JoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilojoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilojoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilojoules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilojoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double megajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megajoules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double gigajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigajoules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double terajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terajoules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double petajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petajoules_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr double watt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::WattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_watt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::WattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilowatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilowattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilowatt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilowattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr double megawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megawatt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr double gigawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigawatt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr double terawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terawatt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr double petawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petawatt_hours_per_cubic_meter(double value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetawattHoursPerCubicMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, EnergyDensityUnit unit)
        {
            switch (unit)
            {

            case EnergyDensityUnit::JoulesPerCubicMeter:
                return value;

            case EnergyDensityUnit::KilojoulesPerCubicMeter:
                return (value * 1e3);

            case EnergyDensityUnit::MegajoulesPerCubicMeter:
                return (value * 1e6);

            case EnergyDensityUnit::GigajoulesPerCubicMeter:
                return (value * 1e9);

            case EnergyDensityUnit::TerajoulesPerCubicMeter:
                return (value * 1e12);

            case EnergyDensityUnit::PetajoulesPerCubicMeter:
                return (value * 1e15);

            case EnergyDensityUnit::WattHoursPerCubicMeter:
                return value * 3.6e+3;

            case EnergyDensityUnit::KilowattHoursPerCubicMeter:
                return (value * 1e3) * 3.6e+3;

            case EnergyDensityUnit::MegawattHoursPerCubicMeter:
                return (value * 1e6) * 3.6e+3;

            case EnergyDensityUnit::GigawattHoursPerCubicMeter:
                return (value * 1e9) * 3.6e+3;

            case EnergyDensityUnit::TerawattHoursPerCubicMeter:
                return (value * 1e12) * 3.6e+3;

            case EnergyDensityUnit::PetawattHoursPerCubicMeter:
                return (value * 1e15) * 3.6e+3;

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(EnergyDensityUnit unit) const
        {
            switch (unit)
            {

            case EnergyDensityUnit::JoulesPerCubicMeter:
                return value_;

            case EnergyDensityUnit::KilojoulesPerCubicMeter:
                return (value_) / 1e3;

            case EnergyDensityUnit::MegajoulesPerCubicMeter:
                return (value_) / 1e6;

            case EnergyDensityUnit::GigajoulesPerCubicMeter:
                return (value_) / 1e9;

            case EnergyDensityUnit::TerajoulesPerCubicMeter:
                return (value_) / 1e12;

            case EnergyDensityUnit::PetajoulesPerCubicMeter:
                return (value_) / 1e15;

            case EnergyDensityUnit::WattHoursPerCubicMeter:
                return value_ / 3.6e+3;

            case EnergyDensityUnit::KilowattHoursPerCubicMeter:
                return (value_ / 3.6e+3) / 1e3;

            case EnergyDensityUnit::MegawattHoursPerCubicMeter:
                return (value_ / 3.6e+3) / 1e6;

            case EnergyDensityUnit::GigawattHoursPerCubicMeter:
                return (value_ / 3.6e+3) / 1e9;

            case EnergyDensityUnit::TerawattHoursPerCubicMeter:
                return (value_ / 3.6e+3) / 1e12;

            case EnergyDensityUnit::PetawattHoursPerCubicMeter:
                return (value_ / 3.6e+3) / 1e15;

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        double value_;
    };
}
