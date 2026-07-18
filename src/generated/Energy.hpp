#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class EnergyUnit : std::uint16_t
    {
        Joules,
        Nanojoules,
        Microjoules,
        Millijoules,
        Kilojoules,
        Megajoules,
        Gigajoules,
        Terajoules,
        Petajoules,
        Calories,
        Kilocalories,
        Megacalories,
        BritishThermalUnits,
        KilobritishThermalUnits,
        MegabritishThermalUnits,
        GigabritishThermalUnits,
        ElectronVolts,
        KiloelectronVolts,
        MegaelectronVolts,
        GigaelectronVolts,
        TeraelectronVolts,
        FootPounds,
        Ergs,
        WattHours,
        KilowattHours,
        MegawattHours,
        GigawattHours,
        TerawattHours,
        WattDays,
        KilowattDays,
        MegawattDays,
        GigawattDays,
        TerawattDays,
        ThermsEc,
        DecathermsEc,
        ThermsUs,
        DecathermsUs,
        ThermsImperial,
        DecathermsImperial,
        HorsepowerHours,
    };

    /// <summary>The joule, symbol J, is a derived unit of energy, work, or amount of heat in the International System of Units. It is equal to the energy transferred (or work done) when applying a force of one newton through a distance of one metre (1 newton metre or N·m), or in passing an electric current of one ampere through a resistance of one ohm for one second. Many other units of energy are included. Please do not confuse this definition of the calorie with the one colloquially used by the food industry, the large calorie, which is equivalent to 1 kcal. Thermochemical definition of the calorie is used. For BTU, the IT definition is used.</summary>
    class Energy
    {
    public:
        constexpr explicit Energy(
            double value,
            EnergyUnit unit = EnergyUnit::Joules)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(EnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Energy operator+(Energy other) const noexcept
        {
            return Energy(value_ + other.value_);
        }

        [[nodiscard]] constexpr Energy operator-(Energy other) const noexcept
        {
            return Energy(value_ - other.value_);
        }

        [[nodiscard]] constexpr Energy operator*(double scalar) const noexcept
        {
            return Energy(value_ * scalar);
        }

        [[nodiscard]] constexpr Energy operator/(double scalar) const noexcept
        {
            return Energy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Energy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Energy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules() const
        {
            return convert_from_base(EnergyUnit::Joules);
        }

        [[nodiscard]] static constexpr Energy from_joules(double value)
        {
            return Energy(value, EnergyUnit::Joules);
        }


        [[nodiscard]] constexpr double nanojoules() const
        {
            return convert_from_base(EnergyUnit::Nanojoules);
        }

        [[nodiscard]] static constexpr Energy from_nanojoules(double value)
        {
            return Energy(value, EnergyUnit::Nanojoules);
        }


        [[nodiscard]] constexpr double microjoules() const
        {
            return convert_from_base(EnergyUnit::Microjoules);
        }

        [[nodiscard]] static constexpr Energy from_microjoules(double value)
        {
            return Energy(value, EnergyUnit::Microjoules);
        }


        [[nodiscard]] constexpr double millijoules() const
        {
            return convert_from_base(EnergyUnit::Millijoules);
        }

        [[nodiscard]] static constexpr Energy from_millijoules(double value)
        {
            return Energy(value, EnergyUnit::Millijoules);
        }


        [[nodiscard]] constexpr double kilojoules() const
        {
            return convert_from_base(EnergyUnit::Kilojoules);
        }

        [[nodiscard]] static constexpr Energy from_kilojoules(double value)
        {
            return Energy(value, EnergyUnit::Kilojoules);
        }


        [[nodiscard]] constexpr double megajoules() const
        {
            return convert_from_base(EnergyUnit::Megajoules);
        }

        [[nodiscard]] static constexpr Energy from_megajoules(double value)
        {
            return Energy(value, EnergyUnit::Megajoules);
        }


        [[nodiscard]] constexpr double gigajoules() const
        {
            return convert_from_base(EnergyUnit::Gigajoules);
        }

        [[nodiscard]] static constexpr Energy from_gigajoules(double value)
        {
            return Energy(value, EnergyUnit::Gigajoules);
        }


        [[nodiscard]] constexpr double terajoules() const
        {
            return convert_from_base(EnergyUnit::Terajoules);
        }

        [[nodiscard]] static constexpr Energy from_terajoules(double value)
        {
            return Energy(value, EnergyUnit::Terajoules);
        }


        [[nodiscard]] constexpr double petajoules() const
        {
            return convert_from_base(EnergyUnit::Petajoules);
        }

        [[nodiscard]] static constexpr Energy from_petajoules(double value)
        {
            return Energy(value, EnergyUnit::Petajoules);
        }


        [[nodiscard]] constexpr double calories() const
        {
            return convert_from_base(EnergyUnit::Calories);
        }

        [[nodiscard]] static constexpr Energy from_calories(double value)
        {
            return Energy(value, EnergyUnit::Calories);
        }


        [[nodiscard]] constexpr double kilocalories() const
        {
            return convert_from_base(EnergyUnit::Kilocalories);
        }

        [[nodiscard]] static constexpr Energy from_kilocalories(double value)
        {
            return Energy(value, EnergyUnit::Kilocalories);
        }


        [[nodiscard]] constexpr double megacalories() const
        {
            return convert_from_base(EnergyUnit::Megacalories);
        }

        [[nodiscard]] static constexpr Energy from_megacalories(double value)
        {
            return Energy(value, EnergyUnit::Megacalories);
        }


        [[nodiscard]] constexpr double british_thermal_units() const
        {
            return convert_from_base(EnergyUnit::BritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_british_thermal_units(double value)
        {
            return Energy(value, EnergyUnit::BritishThermalUnits);
        }


        [[nodiscard]] constexpr double kilobritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::KilobritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_kilobritish_thermal_units(double value)
        {
            return Energy(value, EnergyUnit::KilobritishThermalUnits);
        }


        [[nodiscard]] constexpr double megabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::MegabritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_megabritish_thermal_units(double value)
        {
            return Energy(value, EnergyUnit::MegabritishThermalUnits);
        }


        [[nodiscard]] constexpr double gigabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::GigabritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_gigabritish_thermal_units(double value)
        {
            return Energy(value, EnergyUnit::GigabritishThermalUnits);
        }


        [[nodiscard]] constexpr double electron_volts() const
        {
            return convert_from_base(EnergyUnit::ElectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_electron_volts(double value)
        {
            return Energy(value, EnergyUnit::ElectronVolts);
        }


        [[nodiscard]] constexpr double kiloelectron_volts() const
        {
            return convert_from_base(EnergyUnit::KiloelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_kiloelectron_volts(double value)
        {
            return Energy(value, EnergyUnit::KiloelectronVolts);
        }


        [[nodiscard]] constexpr double megaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::MegaelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_megaelectron_volts(double value)
        {
            return Energy(value, EnergyUnit::MegaelectronVolts);
        }


        [[nodiscard]] constexpr double gigaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::GigaelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_gigaelectron_volts(double value)
        {
            return Energy(value, EnergyUnit::GigaelectronVolts);
        }


        [[nodiscard]] constexpr double teraelectron_volts() const
        {
            return convert_from_base(EnergyUnit::TeraelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_teraelectron_volts(double value)
        {
            return Energy(value, EnergyUnit::TeraelectronVolts);
        }


        [[nodiscard]] constexpr double foot_pounds() const
        {
            return convert_from_base(EnergyUnit::FootPounds);
        }

        [[nodiscard]] static constexpr Energy from_foot_pounds(double value)
        {
            return Energy(value, EnergyUnit::FootPounds);
        }


        [[nodiscard]] constexpr double ergs() const
        {
            return convert_from_base(EnergyUnit::Ergs);
        }

        [[nodiscard]] static constexpr Energy from_ergs(double value)
        {
            return Energy(value, EnergyUnit::Ergs);
        }


        [[nodiscard]] constexpr double watt_hours() const
        {
            return convert_from_base(EnergyUnit::WattHours);
        }

        [[nodiscard]] static constexpr Energy from_watt_hours(double value)
        {
            return Energy(value, EnergyUnit::WattHours);
        }


        [[nodiscard]] constexpr double kilowatt_hours() const
        {
            return convert_from_base(EnergyUnit::KilowattHours);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_hours(double value)
        {
            return Energy(value, EnergyUnit::KilowattHours);
        }


        [[nodiscard]] constexpr double megawatt_hours() const
        {
            return convert_from_base(EnergyUnit::MegawattHours);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_hours(double value)
        {
            return Energy(value, EnergyUnit::MegawattHours);
        }


        [[nodiscard]] constexpr double gigawatt_hours() const
        {
            return convert_from_base(EnergyUnit::GigawattHours);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_hours(double value)
        {
            return Energy(value, EnergyUnit::GigawattHours);
        }


        [[nodiscard]] constexpr double terawatt_hours() const
        {
            return convert_from_base(EnergyUnit::TerawattHours);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_hours(double value)
        {
            return Energy(value, EnergyUnit::TerawattHours);
        }


        [[nodiscard]] constexpr double watt_days() const
        {
            return convert_from_base(EnergyUnit::WattDays);
        }

        [[nodiscard]] static constexpr Energy from_watt_days(double value)
        {
            return Energy(value, EnergyUnit::WattDays);
        }


        [[nodiscard]] constexpr double kilowatt_days() const
        {
            return convert_from_base(EnergyUnit::KilowattDays);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_days(double value)
        {
            return Energy(value, EnergyUnit::KilowattDays);
        }


        [[nodiscard]] constexpr double megawatt_days() const
        {
            return convert_from_base(EnergyUnit::MegawattDays);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_days(double value)
        {
            return Energy(value, EnergyUnit::MegawattDays);
        }


        [[nodiscard]] constexpr double gigawatt_days() const
        {
            return convert_from_base(EnergyUnit::GigawattDays);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_days(double value)
        {
            return Energy(value, EnergyUnit::GigawattDays);
        }


        [[nodiscard]] constexpr double terawatt_days() const
        {
            return convert_from_base(EnergyUnit::TerawattDays);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_days(double value)
        {
            return Energy(value, EnergyUnit::TerawattDays);
        }


        [[nodiscard]] constexpr double therms_ec() const
        {
            return convert_from_base(EnergyUnit::ThermsEc);
        }

        [[nodiscard]] static constexpr Energy from_therms_ec(double value)
        {
            return Energy(value, EnergyUnit::ThermsEc);
        }


        [[nodiscard]] constexpr double decatherms_ec() const
        {
            return convert_from_base(EnergyUnit::DecathermsEc);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_ec(double value)
        {
            return Energy(value, EnergyUnit::DecathermsEc);
        }


        [[nodiscard]] constexpr double therms_us() const
        {
            return convert_from_base(EnergyUnit::ThermsUs);
        }

        [[nodiscard]] static constexpr Energy from_therms_us(double value)
        {
            return Energy(value, EnergyUnit::ThermsUs);
        }


        [[nodiscard]] constexpr double decatherms_us() const
        {
            return convert_from_base(EnergyUnit::DecathermsUs);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_us(double value)
        {
            return Energy(value, EnergyUnit::DecathermsUs);
        }


        [[nodiscard]] constexpr double therms_imperial() const
        {
            return convert_from_base(EnergyUnit::ThermsImperial);
        }

        [[nodiscard]] static constexpr Energy from_therms_imperial(double value)
        {
            return Energy(value, EnergyUnit::ThermsImperial);
        }


        [[nodiscard]] constexpr double decatherms_imperial() const
        {
            return convert_from_base(EnergyUnit::DecathermsImperial);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_imperial(double value)
        {
            return Energy(value, EnergyUnit::DecathermsImperial);
        }


        [[nodiscard]] constexpr double horsepower_hours() const
        {
            return convert_from_base(EnergyUnit::HorsepowerHours);
        }

        [[nodiscard]] static constexpr Energy from_horsepower_hours(double value)
        {
            return Energy(value, EnergyUnit::HorsepowerHours);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, EnergyUnit unit)
        {
            switch (unit)
            {

            case EnergyUnit::Joules:
                return value;

            case EnergyUnit::Nanojoules:
                return (value * 1e-9);

            case EnergyUnit::Microjoules:
                return (value * 1e-6);

            case EnergyUnit::Millijoules:
                return (value * 1e-3);

            case EnergyUnit::Kilojoules:
                return (value * 1e3);

            case EnergyUnit::Megajoules:
                return (value * 1e6);

            case EnergyUnit::Gigajoules:
                return (value * 1e9);

            case EnergyUnit::Terajoules:
                return (value * 1e12);

            case EnergyUnit::Petajoules:
                return (value * 1e15);

            case EnergyUnit::Calories:
                return value * 4.184;

            case EnergyUnit::Kilocalories:
                return (value * 1e3) * 4.184;

            case EnergyUnit::Megacalories:
                return (value * 1e6) * 4.184;

            case EnergyUnit::BritishThermalUnits:
                return value * 1055.05585262;

            case EnergyUnit::KilobritishThermalUnits:
                return (value * 1e3) * 1055.05585262;

            case EnergyUnit::MegabritishThermalUnits:
                return (value * 1e6) * 1055.05585262;

            case EnergyUnit::GigabritishThermalUnits:
                return (value * 1e9) * 1055.05585262;

            case EnergyUnit::ElectronVolts:
                return value * 1.602176634e-19;

            case EnergyUnit::KiloelectronVolts:
                return (value * 1e3) * 1.602176634e-19;

            case EnergyUnit::MegaelectronVolts:
                return (value * 1e6) * 1.602176634e-19;

            case EnergyUnit::GigaelectronVolts:
                return (value * 1e9) * 1.602176634e-19;

            case EnergyUnit::TeraelectronVolts:
                return (value * 1e12) * 1.602176634e-19;

            case EnergyUnit::FootPounds:
                return value * 1.3558179483314004;

            case EnergyUnit::Ergs:
                return value * 1e-7;

            case EnergyUnit::WattHours:
                return value * 3600;

            case EnergyUnit::KilowattHours:
                return (value * 1e3) * 3600;

            case EnergyUnit::MegawattHours:
                return (value * 1e6) * 3600;

            case EnergyUnit::GigawattHours:
                return (value * 1e9) * 3600;

            case EnergyUnit::TerawattHours:
                return (value * 1e12) * 3600;

            case EnergyUnit::WattDays:
                return value * 24 * 3600;

            case EnergyUnit::KilowattDays:
                return (value * 1e3) * 24 * 3600;

            case EnergyUnit::MegawattDays:
                return (value * 1e6) * 24 * 3600;

            case EnergyUnit::GigawattDays:
                return (value * 1e9) * 24 * 3600;

            case EnergyUnit::TerawattDays:
                return (value * 1e12) * 24 * 3600;

            case EnergyUnit::ThermsEc:
                return value * 1.05505585262e8;

            case EnergyUnit::DecathermsEc:
                return (value * 1e1) * 1.05505585262e8;

            case EnergyUnit::ThermsUs:
                return value * 1.054804e8;

            case EnergyUnit::DecathermsUs:
                return (value * 1e1) * 1.054804e8;

            case EnergyUnit::ThermsImperial:
                return value * 1.05505585257348e8;

            case EnergyUnit::DecathermsImperial:
                return (value * 1e1) * 1.05505585257348e8;

            case EnergyUnit::HorsepowerHours:
                return value * 76.0402249 * 9.80665 * 3600;

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(EnergyUnit unit) const
        {
            switch (unit)
            {

            case EnergyUnit::Joules:
                return value_;

            case EnergyUnit::Nanojoules:
                return (value_) / 1e-9;

            case EnergyUnit::Microjoules:
                return (value_) / 1e-6;

            case EnergyUnit::Millijoules:
                return (value_) / 1e-3;

            case EnergyUnit::Kilojoules:
                return (value_) / 1e3;

            case EnergyUnit::Megajoules:
                return (value_) / 1e6;

            case EnergyUnit::Gigajoules:
                return (value_) / 1e9;

            case EnergyUnit::Terajoules:
                return (value_) / 1e12;

            case EnergyUnit::Petajoules:
                return (value_) / 1e15;

            case EnergyUnit::Calories:
                return value_ / 4.184;

            case EnergyUnit::Kilocalories:
                return (value_ / 4.184) / 1e3;

            case EnergyUnit::Megacalories:
                return (value_ / 4.184) / 1e6;

            case EnergyUnit::BritishThermalUnits:
                return value_ / 1055.05585262;

            case EnergyUnit::KilobritishThermalUnits:
                return (value_ / 1055.05585262) / 1e3;

            case EnergyUnit::MegabritishThermalUnits:
                return (value_ / 1055.05585262) / 1e6;

            case EnergyUnit::GigabritishThermalUnits:
                return (value_ / 1055.05585262) / 1e9;

            case EnergyUnit::ElectronVolts:
                return value_ / 1.602176634e-19;

            case EnergyUnit::KiloelectronVolts:
                return (value_ / 1.602176634e-19) / 1e3;

            case EnergyUnit::MegaelectronVolts:
                return (value_ / 1.602176634e-19) / 1e6;

            case EnergyUnit::GigaelectronVolts:
                return (value_ / 1.602176634e-19) / 1e9;

            case EnergyUnit::TeraelectronVolts:
                return (value_ / 1.602176634e-19) / 1e12;

            case EnergyUnit::FootPounds:
                return value_ / 1.3558179483314004;

            case EnergyUnit::Ergs:
                return value_ / 1e-7;

            case EnergyUnit::WattHours:
                return value_ / 3600;

            case EnergyUnit::KilowattHours:
                return (value_ / 3600) / 1e3;

            case EnergyUnit::MegawattHours:
                return (value_ / 3600) / 1e6;

            case EnergyUnit::GigawattHours:
                return (value_ / 3600) / 1e9;

            case EnergyUnit::TerawattHours:
                return (value_ / 3600) / 1e12;

            case EnergyUnit::WattDays:
                return value_ / (24 * 3600);

            case EnergyUnit::KilowattDays:
                return (value_ / (24 * 3600)) / 1e3;

            case EnergyUnit::MegawattDays:
                return (value_ / (24 * 3600)) / 1e6;

            case EnergyUnit::GigawattDays:
                return (value_ / (24 * 3600)) / 1e9;

            case EnergyUnit::TerawattDays:
                return (value_ / (24 * 3600)) / 1e12;

            case EnergyUnit::ThermsEc:
                return value_ / 1.05505585262e8;

            case EnergyUnit::DecathermsEc:
                return (value_ / 1.05505585262e8) / 1e1;

            case EnergyUnit::ThermsUs:
                return value_ / 1.054804e8;

            case EnergyUnit::DecathermsUs:
                return (value_ / 1.054804e8) / 1e1;

            case EnergyUnit::ThermsImperial:
                return value_ / 1.05505585257348e8;

            case EnergyUnit::DecathermsImperial:
                return (value_ / 1.05505585257348e8) / 1e1;

            case EnergyUnit::HorsepowerHours:
                return value_ / (76.0402249 * 9.80665 * 3600);

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        double value_;
    };
}
