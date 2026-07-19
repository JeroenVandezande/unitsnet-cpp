#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PowerUnit : std::uint8_t
    {
        Watts,
        Femtowatts,
        Picowatts,
        Nanowatts,
        Microwatts,
        Milliwatts,
        Deciwatts,
        Decawatts,
        Kilowatts,
        Megawatts,
        Gigawatts,
        Terawatts,
        Petawatts,
        MechanicalHorsepower,
        MetricHorsepower,
        ElectricalHorsepower,
        BoilerHorsepower,
        HydraulicHorsepower,
        BritishThermalUnitsPerHour,
        KilobritishThermalUnitsPerHour,
        MegabritishThermalUnitsPerHour,
        JoulesPerHour,
        MillijoulesPerHour,
        KilojoulesPerHour,
        MegajoulesPerHour,
        GigajoulesPerHour,
        TonsOfRefrigeration,
    };

    /// <summary>In physics, power is the rate of doing work. It is equivalent to an amount of energy consumed per unit time.</summary>
    class Power
    {
    public:
        constexpr explicit Power(
            const un_scalar_t value,
            const PowerUnit unit = PowerUnit::Watts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Power operator+(const Power other) const noexcept
        {
            return Power(value_ + other.value_);
        }

        [[nodiscard]] constexpr Power operator-(const Power other) const noexcept
        {
            return Power(value_ - other.value_);
        }

        [[nodiscard]] constexpr Power operator*(const un_scalar_t scalar) const noexcept
        {
            return Power(value_ * scalar);
        }

        [[nodiscard]] constexpr Power operator/(const un_scalar_t scalar) const noexcept
        {
            return Power(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Power other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Power other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t watts() const
        {
            return convert_from_base(PowerUnit::Watts);
        }

        [[nodiscard]] static constexpr Power from_watts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Watts);
        }


        [[nodiscard]] constexpr un_scalar_t femtowatts() const
        {
            return convert_from_base(PowerUnit::Femtowatts);
        }

        [[nodiscard]] static constexpr Power from_femtowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Femtowatts);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts() const
        {
            return convert_from_base(PowerUnit::Picowatts);
        }

        [[nodiscard]] static constexpr Power from_picowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Picowatts);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts() const
        {
            return convert_from_base(PowerUnit::Nanowatts);
        }

        [[nodiscard]] static constexpr Power from_nanowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Nanowatts);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts() const
        {
            return convert_from_base(PowerUnit::Microwatts);
        }

        [[nodiscard]] static constexpr Power from_microwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Microwatts);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts() const
        {
            return convert_from_base(PowerUnit::Milliwatts);
        }

        [[nodiscard]] static constexpr Power from_milliwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Milliwatts);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts() const
        {
            return convert_from_base(PowerUnit::Deciwatts);
        }

        [[nodiscard]] static constexpr Power from_deciwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Deciwatts);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts() const
        {
            return convert_from_base(PowerUnit::Decawatts);
        }

        [[nodiscard]] static constexpr Power from_decawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Decawatts);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts() const
        {
            return convert_from_base(PowerUnit::Kilowatts);
        }

        [[nodiscard]] static constexpr Power from_kilowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Kilowatts);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts() const
        {
            return convert_from_base(PowerUnit::Megawatts);
        }

        [[nodiscard]] static constexpr Power from_megawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Megawatts);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts() const
        {
            return convert_from_base(PowerUnit::Gigawatts);
        }

        [[nodiscard]] static constexpr Power from_gigawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Gigawatts);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts() const
        {
            return convert_from_base(PowerUnit::Terawatts);
        }

        [[nodiscard]] static constexpr Power from_terawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Terawatts);
        }


        [[nodiscard]] constexpr un_scalar_t petawatts() const
        {
            return convert_from_base(PowerUnit::Petawatts);
        }

        [[nodiscard]] static constexpr Power from_petawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Petawatts);
        }


        [[nodiscard]] constexpr un_scalar_t mechanical_horsepower() const
        {
            return convert_from_base(PowerUnit::MechanicalHorsepower);
        }

        [[nodiscard]] static constexpr Power from_mechanical_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MechanicalHorsepower);
        }


        [[nodiscard]] constexpr un_scalar_t metric_horsepower() const
        {
            return convert_from_base(PowerUnit::MetricHorsepower);
        }

        [[nodiscard]] static constexpr Power from_metric_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MetricHorsepower);
        }


        [[nodiscard]] constexpr un_scalar_t electrical_horsepower() const
        {
            return convert_from_base(PowerUnit::ElectricalHorsepower);
        }

        [[nodiscard]] static constexpr Power from_electrical_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::ElectricalHorsepower);
        }


        [[nodiscard]] constexpr un_scalar_t boiler_horsepower() const
        {
            return convert_from_base(PowerUnit::BoilerHorsepower);
        }

        [[nodiscard]] static constexpr Power from_boiler_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::BoilerHorsepower);
        }


        [[nodiscard]] constexpr un_scalar_t hydraulic_horsepower() const
        {
            return convert_from_base(PowerUnit::HydraulicHorsepower);
        }

        [[nodiscard]] static constexpr Power from_hydraulic_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::HydraulicHorsepower);
        }


        [[nodiscard]] constexpr un_scalar_t british_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::BritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_british_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::BritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilobritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::KilobritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_kilobritish_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::KilobritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t megabritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::MegabritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_megabritish_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MegabritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_hour() const
        {
            return convert_from_base(PowerUnit::JoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_joules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::JoulesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t millijoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MillijoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_millijoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MillijoulesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_hour() const
        {
            return convert_from_base(PowerUnit::KilojoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_kilojoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::KilojoulesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MegajoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_megajoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MegajoulesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t gigajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::GigajoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_gigajoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::GigajoulesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t tons_of_refrigeration() const
        {
            return convert_from_base(PowerUnit::TonsOfRefrigeration);
        }

        [[nodiscard]] static constexpr Power from_tons_of_refrigeration(const un_scalar_t value)
        {
            return Power(value, PowerUnit::TonsOfRefrigeration);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerUnit unit)
        {
            switch (unit)
            {

            case PowerUnit::Watts:
                return value;

            case PowerUnit::Femtowatts:
                return (value * static_cast<un_scalar_t>(1e-15));

            case PowerUnit::Picowatts:
                return (value * static_cast<un_scalar_t>(1e-12));

            case PowerUnit::Nanowatts:
                return (value * static_cast<un_scalar_t>(1e-9));

            case PowerUnit::Microwatts:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PowerUnit::Milliwatts:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PowerUnit::Deciwatts:
                return (value * static_cast<un_scalar_t>(1e-1));

            case PowerUnit::Decawatts:
                return (value * static_cast<un_scalar_t>(1e1));

            case PowerUnit::Kilowatts:
                return (value * static_cast<un_scalar_t>(1e3));

            case PowerUnit::Megawatts:
                return (value * static_cast<un_scalar_t>(1e6));

            case PowerUnit::Gigawatts:
                return (value * static_cast<un_scalar_t>(1e9));

            case PowerUnit::Terawatts:
                return (value * static_cast<un_scalar_t>(1e12));

            case PowerUnit::Petawatts:
                return (value * static_cast<un_scalar_t>(1e15));

            case PowerUnit::MechanicalHorsepower:
                return value * 76.0402249 * 9.80665;

            case PowerUnit::MetricHorsepower:
                return value * 75 * 9.80665;

            case PowerUnit::ElectricalHorsepower:
                return value * 746;

            case PowerUnit::BoilerHorsepower:
                return value * 9812.5;

            case PowerUnit::HydraulicHorsepower:
                return value * 745.69987158227022;

            case PowerUnit::BritishThermalUnitsPerHour:
                return value * 1055.05585262 / 3600;

            case PowerUnit::KilobritishThermalUnitsPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) * 1055.05585262 / 3600;

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) * 1055.05585262 / 3600;

            case PowerUnit::JoulesPerHour:
                return value / 3600;

            case PowerUnit::MillijoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / 3600;

            case PowerUnit::KilojoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / 3600;

            case PowerUnit::MegajoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / 3600;

            case PowerUnit::GigajoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e9)) / 3600;

            case PowerUnit::TonsOfRefrigeration:
                return value * 3516.853;

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerUnit unit) const
        {
            switch (unit)
            {

            case PowerUnit::Watts:
                return value_;

            case PowerUnit::Femtowatts:
                return (value_) / static_cast<un_scalar_t>(1e-15);

            case PowerUnit::Picowatts:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case PowerUnit::Nanowatts:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case PowerUnit::Microwatts:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case PowerUnit::Milliwatts:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::Deciwatts:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case PowerUnit::Decawatts:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case PowerUnit::Kilowatts:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::Megawatts:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::Gigawatts:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::Terawatts:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case PowerUnit::Petawatts:
                return (value_) / static_cast<un_scalar_t>(1e15);

            case PowerUnit::MechanicalHorsepower:
                return value_ / (76.0402249 * 9.80665);

            case PowerUnit::MetricHorsepower:
                return value_ / (75 * 9.80665);

            case PowerUnit::ElectricalHorsepower:
                return value_ / 746;

            case PowerUnit::BoilerHorsepower:
                return value_ / 9812.5;

            case PowerUnit::HydraulicHorsepower:
                return value_ / 745.69987158227022;

            case PowerUnit::BritishThermalUnitsPerHour:
                return value_ * 3600 / 1055.05585262;

            case PowerUnit::KilobritishThermalUnitsPerHour:
                return (value_ * 3600 / 1055.05585262) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (value_ * 3600 / 1055.05585262) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::JoulesPerHour:
                return value_ * 3600;

            case PowerUnit::MillijoulesPerHour:
                return (value_ * 3600) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::KilojoulesPerHour:
                return (value_ * 3600) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegajoulesPerHour:
                return (value_ * 3600) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::GigajoulesPerHour:
                return (value_ * 3600) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::TonsOfRefrigeration:
                return value_ / 3516.853;

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        un_scalar_t value_;
    };
}
