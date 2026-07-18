#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PowerUnit : std::uint16_t
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
            double value,
            PowerUnit unit = PowerUnit::Watts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Power operator+(Power other) const noexcept
        {
            return Power(value_ + other.value_);
        }

        [[nodiscard]] constexpr Power operator-(Power other) const noexcept
        {
            return Power(value_ - other.value_);
        }

        [[nodiscard]] constexpr Power operator*(double scalar) const noexcept
        {
            return Power(value_ * scalar);
        }

        [[nodiscard]] constexpr Power operator/(double scalar) const noexcept
        {
            return Power(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Power other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Power other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts() const
        {
            return convert_from_base(PowerUnit::Watts);
        }

        [[nodiscard]] static constexpr Power from_watts(double value)
        {
            return Power(value, PowerUnit::Watts);
        }


        [[nodiscard]] constexpr double femtowatts() const
        {
            return convert_from_base(PowerUnit::Femtowatts);
        }

        [[nodiscard]] static constexpr Power from_femtowatts(double value)
        {
            return Power(value, PowerUnit::Femtowatts);
        }


        [[nodiscard]] constexpr double picowatts() const
        {
            return convert_from_base(PowerUnit::Picowatts);
        }

        [[nodiscard]] static constexpr Power from_picowatts(double value)
        {
            return Power(value, PowerUnit::Picowatts);
        }


        [[nodiscard]] constexpr double nanowatts() const
        {
            return convert_from_base(PowerUnit::Nanowatts);
        }

        [[nodiscard]] static constexpr Power from_nanowatts(double value)
        {
            return Power(value, PowerUnit::Nanowatts);
        }


        [[nodiscard]] constexpr double microwatts() const
        {
            return convert_from_base(PowerUnit::Microwatts);
        }

        [[nodiscard]] static constexpr Power from_microwatts(double value)
        {
            return Power(value, PowerUnit::Microwatts);
        }


        [[nodiscard]] constexpr double milliwatts() const
        {
            return convert_from_base(PowerUnit::Milliwatts);
        }

        [[nodiscard]] static constexpr Power from_milliwatts(double value)
        {
            return Power(value, PowerUnit::Milliwatts);
        }


        [[nodiscard]] constexpr double deciwatts() const
        {
            return convert_from_base(PowerUnit::Deciwatts);
        }

        [[nodiscard]] static constexpr Power from_deciwatts(double value)
        {
            return Power(value, PowerUnit::Deciwatts);
        }


        [[nodiscard]] constexpr double decawatts() const
        {
            return convert_from_base(PowerUnit::Decawatts);
        }

        [[nodiscard]] static constexpr Power from_decawatts(double value)
        {
            return Power(value, PowerUnit::Decawatts);
        }


        [[nodiscard]] constexpr double kilowatts() const
        {
            return convert_from_base(PowerUnit::Kilowatts);
        }

        [[nodiscard]] static constexpr Power from_kilowatts(double value)
        {
            return Power(value, PowerUnit::Kilowatts);
        }


        [[nodiscard]] constexpr double megawatts() const
        {
            return convert_from_base(PowerUnit::Megawatts);
        }

        [[nodiscard]] static constexpr Power from_megawatts(double value)
        {
            return Power(value, PowerUnit::Megawatts);
        }


        [[nodiscard]] constexpr double gigawatts() const
        {
            return convert_from_base(PowerUnit::Gigawatts);
        }

        [[nodiscard]] static constexpr Power from_gigawatts(double value)
        {
            return Power(value, PowerUnit::Gigawatts);
        }


        [[nodiscard]] constexpr double terawatts() const
        {
            return convert_from_base(PowerUnit::Terawatts);
        }

        [[nodiscard]] static constexpr Power from_terawatts(double value)
        {
            return Power(value, PowerUnit::Terawatts);
        }


        [[nodiscard]] constexpr double petawatts() const
        {
            return convert_from_base(PowerUnit::Petawatts);
        }

        [[nodiscard]] static constexpr Power from_petawatts(double value)
        {
            return Power(value, PowerUnit::Petawatts);
        }


        [[nodiscard]] constexpr double mechanical_horsepower() const
        {
            return convert_from_base(PowerUnit::MechanicalHorsepower);
        }

        [[nodiscard]] static constexpr Power from_mechanical_horsepower(double value)
        {
            return Power(value, PowerUnit::MechanicalHorsepower);
        }


        [[nodiscard]] constexpr double metric_horsepower() const
        {
            return convert_from_base(PowerUnit::MetricHorsepower);
        }

        [[nodiscard]] static constexpr Power from_metric_horsepower(double value)
        {
            return Power(value, PowerUnit::MetricHorsepower);
        }


        [[nodiscard]] constexpr double electrical_horsepower() const
        {
            return convert_from_base(PowerUnit::ElectricalHorsepower);
        }

        [[nodiscard]] static constexpr Power from_electrical_horsepower(double value)
        {
            return Power(value, PowerUnit::ElectricalHorsepower);
        }


        [[nodiscard]] constexpr double boiler_horsepower() const
        {
            return convert_from_base(PowerUnit::BoilerHorsepower);
        }

        [[nodiscard]] static constexpr Power from_boiler_horsepower(double value)
        {
            return Power(value, PowerUnit::BoilerHorsepower);
        }


        [[nodiscard]] constexpr double hydraulic_horsepower() const
        {
            return convert_from_base(PowerUnit::HydraulicHorsepower);
        }

        [[nodiscard]] static constexpr Power from_hydraulic_horsepower(double value)
        {
            return Power(value, PowerUnit::HydraulicHorsepower);
        }


        [[nodiscard]] constexpr double british_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::BritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_british_thermal_units_per_hour(double value)
        {
            return Power(value, PowerUnit::BritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr double kilobritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::KilobritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_kilobritish_thermal_units_per_hour(double value)
        {
            return Power(value, PowerUnit::KilobritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr double megabritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::MegabritishThermalUnitsPerHour);
        }

        [[nodiscard]] static constexpr Power from_megabritish_thermal_units_per_hour(double value)
        {
            return Power(value, PowerUnit::MegabritishThermalUnitsPerHour);
        }


        [[nodiscard]] constexpr double joules_per_hour() const
        {
            return convert_from_base(PowerUnit::JoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_joules_per_hour(double value)
        {
            return Power(value, PowerUnit::JoulesPerHour);
        }


        [[nodiscard]] constexpr double millijoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MillijoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_millijoules_per_hour(double value)
        {
            return Power(value, PowerUnit::MillijoulesPerHour);
        }


        [[nodiscard]] constexpr double kilojoules_per_hour() const
        {
            return convert_from_base(PowerUnit::KilojoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_kilojoules_per_hour(double value)
        {
            return Power(value, PowerUnit::KilojoulesPerHour);
        }


        [[nodiscard]] constexpr double megajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MegajoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_megajoules_per_hour(double value)
        {
            return Power(value, PowerUnit::MegajoulesPerHour);
        }


        [[nodiscard]] constexpr double gigajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::GigajoulesPerHour);
        }

        [[nodiscard]] static constexpr Power from_gigajoules_per_hour(double value)
        {
            return Power(value, PowerUnit::GigajoulesPerHour);
        }


        [[nodiscard]] constexpr double tons_of_refrigeration() const
        {
            return convert_from_base(PowerUnit::TonsOfRefrigeration);
        }

        [[nodiscard]] static constexpr Power from_tons_of_refrigeration(double value)
        {
            return Power(value, PowerUnit::TonsOfRefrigeration);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PowerUnit unit)
        {
            switch (unit)
            {

            case PowerUnit::Watts:
                return value;

            case PowerUnit::Femtowatts:
                return (value * 1e-15);

            case PowerUnit::Picowatts:
                return (value * 1e-12);

            case PowerUnit::Nanowatts:
                return (value * 1e-9);

            case PowerUnit::Microwatts:
                return (value * 1e-6);

            case PowerUnit::Milliwatts:
                return (value * 1e-3);

            case PowerUnit::Deciwatts:
                return (value * 1e-1);

            case PowerUnit::Decawatts:
                return (value * 1e1);

            case PowerUnit::Kilowatts:
                return (value * 1e3);

            case PowerUnit::Megawatts:
                return (value * 1e6);

            case PowerUnit::Gigawatts:
                return (value * 1e9);

            case PowerUnit::Terawatts:
                return (value * 1e12);

            case PowerUnit::Petawatts:
                return (value * 1e15);

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
                return (value * 1e3) * 1055.05585262 / 3600;

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (value * 1e6) * 1055.05585262 / 3600;

            case PowerUnit::JoulesPerHour:
                return value / 3600;

            case PowerUnit::MillijoulesPerHour:
                return (value * 1e-3) / 3600;

            case PowerUnit::KilojoulesPerHour:
                return (value * 1e3) / 3600;

            case PowerUnit::MegajoulesPerHour:
                return (value * 1e6) / 3600;

            case PowerUnit::GigajoulesPerHour:
                return (value * 1e9) / 3600;

            case PowerUnit::TonsOfRefrigeration:
                return value * 3516.853;

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PowerUnit unit) const
        {
            switch (unit)
            {

            case PowerUnit::Watts:
                return value_;

            case PowerUnit::Femtowatts:
                return (value_) / 1e-15;

            case PowerUnit::Picowatts:
                return (value_) / 1e-12;

            case PowerUnit::Nanowatts:
                return (value_) / 1e-9;

            case PowerUnit::Microwatts:
                return (value_) / 1e-6;

            case PowerUnit::Milliwatts:
                return (value_) / 1e-3;

            case PowerUnit::Deciwatts:
                return (value_) / 1e-1;

            case PowerUnit::Decawatts:
                return (value_) / 1e1;

            case PowerUnit::Kilowatts:
                return (value_) / 1e3;

            case PowerUnit::Megawatts:
                return (value_) / 1e6;

            case PowerUnit::Gigawatts:
                return (value_) / 1e9;

            case PowerUnit::Terawatts:
                return (value_) / 1e12;

            case PowerUnit::Petawatts:
                return (value_) / 1e15;

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
                return (value_ * 3600 / 1055.05585262) / 1e3;

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (value_ * 3600 / 1055.05585262) / 1e6;

            case PowerUnit::JoulesPerHour:
                return value_ * 3600;

            case PowerUnit::MillijoulesPerHour:
                return (value_ * 3600) / 1e-3;

            case PowerUnit::KilojoulesPerHour:
                return (value_ * 3600) / 1e3;

            case PowerUnit::MegajoulesPerHour:
                return (value_ * 3600) / 1e6;

            case PowerUnit::GigajoulesPerHour:
                return (value_ * 3600) / 1e9;

            case PowerUnit::TonsOfRefrigeration:
                return value_ / 3516.853;

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        double value_;
    };
}
