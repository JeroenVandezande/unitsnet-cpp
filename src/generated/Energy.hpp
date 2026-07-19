#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class EnergyUnit : std::uint8_t
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
            const un_scalar_t value,
            const EnergyUnit unit = EnergyUnit::Joules)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const EnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Energy operator+(const Energy other) const noexcept
        {
            return Energy(value_ + other.value_);
        }

        [[nodiscard]] constexpr Energy operator-(const Energy other) const noexcept
        {
            return Energy(value_ - other.value_);
        }

        [[nodiscard]] constexpr Energy operator*(const un_scalar_t scalar) const noexcept
        {
            return Energy(value_ * scalar);
        }

        [[nodiscard]] constexpr Energy operator/(const un_scalar_t scalar) const noexcept
        {
            return Energy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Energy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Energy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules() const
        {
            return convert_from_base(EnergyUnit::Joules);
        }

        [[nodiscard]] static constexpr Energy from_joules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Joules);
        }


        [[nodiscard]] constexpr un_scalar_t nanojoules() const
        {
            return convert_from_base(EnergyUnit::Nanojoules);
        }

        [[nodiscard]] static constexpr Energy from_nanojoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Nanojoules);
        }


        [[nodiscard]] constexpr un_scalar_t microjoules() const
        {
            return convert_from_base(EnergyUnit::Microjoules);
        }

        [[nodiscard]] static constexpr Energy from_microjoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Microjoules);
        }


        [[nodiscard]] constexpr un_scalar_t millijoules() const
        {
            return convert_from_base(EnergyUnit::Millijoules);
        }

        [[nodiscard]] static constexpr Energy from_millijoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Millijoules);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules() const
        {
            return convert_from_base(EnergyUnit::Kilojoules);
        }

        [[nodiscard]] static constexpr Energy from_kilojoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Kilojoules);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules() const
        {
            return convert_from_base(EnergyUnit::Megajoules);
        }

        [[nodiscard]] static constexpr Energy from_megajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Megajoules);
        }


        [[nodiscard]] constexpr un_scalar_t gigajoules() const
        {
            return convert_from_base(EnergyUnit::Gigajoules);
        }

        [[nodiscard]] static constexpr Energy from_gigajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Gigajoules);
        }


        [[nodiscard]] constexpr un_scalar_t terajoules() const
        {
            return convert_from_base(EnergyUnit::Terajoules);
        }

        [[nodiscard]] static constexpr Energy from_terajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Terajoules);
        }


        [[nodiscard]] constexpr un_scalar_t petajoules() const
        {
            return convert_from_base(EnergyUnit::Petajoules);
        }

        [[nodiscard]] static constexpr Energy from_petajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Petajoules);
        }


        [[nodiscard]] constexpr un_scalar_t calories() const
        {
            return convert_from_base(EnergyUnit::Calories);
        }

        [[nodiscard]] static constexpr Energy from_calories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Calories);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories() const
        {
            return convert_from_base(EnergyUnit::Kilocalories);
        }

        [[nodiscard]] static constexpr Energy from_kilocalories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Kilocalories);
        }


        [[nodiscard]] constexpr un_scalar_t megacalories() const
        {
            return convert_from_base(EnergyUnit::Megacalories);
        }

        [[nodiscard]] static constexpr Energy from_megacalories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Megacalories);
        }


        [[nodiscard]] constexpr un_scalar_t british_thermal_units() const
        {
            return convert_from_base(EnergyUnit::BritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_british_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::BritishThermalUnits);
        }


        [[nodiscard]] constexpr un_scalar_t kilobritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::KilobritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_kilobritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilobritishThermalUnits);
        }


        [[nodiscard]] constexpr un_scalar_t megabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::MegabritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_megabritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegabritishThermalUnits);
        }


        [[nodiscard]] constexpr un_scalar_t gigabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::GigabritishThermalUnits);
        }

        [[nodiscard]] static constexpr Energy from_gigabritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigabritishThermalUnits);
        }


        [[nodiscard]] constexpr un_scalar_t electron_volts() const
        {
            return convert_from_base(EnergyUnit::ElectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_electron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ElectronVolts);
        }


        [[nodiscard]] constexpr un_scalar_t kiloelectron_volts() const
        {
            return convert_from_base(EnergyUnit::KiloelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_kiloelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KiloelectronVolts);
        }


        [[nodiscard]] constexpr un_scalar_t megaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::MegaelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_megaelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegaelectronVolts);
        }


        [[nodiscard]] constexpr un_scalar_t gigaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::GigaelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_gigaelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigaelectronVolts);
        }


        [[nodiscard]] constexpr un_scalar_t teraelectron_volts() const
        {
            return convert_from_base(EnergyUnit::TeraelectronVolts);
        }

        [[nodiscard]] static constexpr Energy from_teraelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TeraelectronVolts);
        }


        [[nodiscard]] constexpr un_scalar_t foot_pounds() const
        {
            return convert_from_base(EnergyUnit::FootPounds);
        }

        [[nodiscard]] static constexpr Energy from_foot_pounds(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::FootPounds);
        }


        [[nodiscard]] constexpr un_scalar_t ergs() const
        {
            return convert_from_base(EnergyUnit::Ergs);
        }

        [[nodiscard]] static constexpr Energy from_ergs(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Ergs);
        }


        [[nodiscard]] constexpr un_scalar_t watt_hours() const
        {
            return convert_from_base(EnergyUnit::WattHours);
        }

        [[nodiscard]] static constexpr Energy from_watt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::WattHours);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatt_hours() const
        {
            return convert_from_base(EnergyUnit::KilowattHours);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilowattHours);
        }


        [[nodiscard]] constexpr un_scalar_t megawatt_hours() const
        {
            return convert_from_base(EnergyUnit::MegawattHours);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegawattHours);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatt_hours() const
        {
            return convert_from_base(EnergyUnit::GigawattHours);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigawattHours);
        }


        [[nodiscard]] constexpr un_scalar_t terawatt_hours() const
        {
            return convert_from_base(EnergyUnit::TerawattHours);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TerawattHours);
        }


        [[nodiscard]] constexpr un_scalar_t watt_days() const
        {
            return convert_from_base(EnergyUnit::WattDays);
        }

        [[nodiscard]] static constexpr Energy from_watt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::WattDays);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatt_days() const
        {
            return convert_from_base(EnergyUnit::KilowattDays);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilowattDays);
        }


        [[nodiscard]] constexpr un_scalar_t megawatt_days() const
        {
            return convert_from_base(EnergyUnit::MegawattDays);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegawattDays);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatt_days() const
        {
            return convert_from_base(EnergyUnit::GigawattDays);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigawattDays);
        }


        [[nodiscard]] constexpr un_scalar_t terawatt_days() const
        {
            return convert_from_base(EnergyUnit::TerawattDays);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TerawattDays);
        }


        [[nodiscard]] constexpr un_scalar_t therms_ec() const
        {
            return convert_from_base(EnergyUnit::ThermsEc);
        }

        [[nodiscard]] static constexpr Energy from_therms_ec(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermsEc);
        }


        [[nodiscard]] constexpr un_scalar_t decatherms_ec() const
        {
            return convert_from_base(EnergyUnit::DecathermsEc);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_ec(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermsEc);
        }


        [[nodiscard]] constexpr un_scalar_t therms_us() const
        {
            return convert_from_base(EnergyUnit::ThermsUs);
        }

        [[nodiscard]] static constexpr Energy from_therms_us(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermsUs);
        }


        [[nodiscard]] constexpr un_scalar_t decatherms_us() const
        {
            return convert_from_base(EnergyUnit::DecathermsUs);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_us(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermsUs);
        }


        [[nodiscard]] constexpr un_scalar_t therms_imperial() const
        {
            return convert_from_base(EnergyUnit::ThermsImperial);
        }

        [[nodiscard]] static constexpr Energy from_therms_imperial(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermsImperial);
        }


        [[nodiscard]] constexpr un_scalar_t decatherms_imperial() const
        {
            return convert_from_base(EnergyUnit::DecathermsImperial);
        }

        [[nodiscard]] static constexpr Energy from_decatherms_imperial(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermsImperial);
        }


        [[nodiscard]] constexpr un_scalar_t horsepower_hours() const
        {
            return convert_from_base(EnergyUnit::HorsepowerHours);
        }

        [[nodiscard]] static constexpr Energy from_horsepower_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::HorsepowerHours);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EnergyUnit unit)
        {
            switch (unit)
            {

            case EnergyUnit::Joules:
                return value;

            case EnergyUnit::Nanojoules:
                return (value * static_cast<un_scalar_t>(1e-9));

            case EnergyUnit::Microjoules:
                return (value * static_cast<un_scalar_t>(1e-6));

            case EnergyUnit::Millijoules:
                return (value * static_cast<un_scalar_t>(1e-3));

            case EnergyUnit::Kilojoules:
                return (value * static_cast<un_scalar_t>(1e3));

            case EnergyUnit::Megajoules:
                return (value * static_cast<un_scalar_t>(1e6));

            case EnergyUnit::Gigajoules:
                return (value * static_cast<un_scalar_t>(1e9));

            case EnergyUnit::Terajoules:
                return (value * static_cast<un_scalar_t>(1e12));

            case EnergyUnit::Petajoules:
                return (value * static_cast<un_scalar_t>(1e15));

            case EnergyUnit::Calories:
                return value * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Kilocalories:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Megacalories:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::BritishThermalUnits:
                return value * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::KilobritishThermalUnits:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::MegabritishThermalUnits:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::GigabritishThermalUnits:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::ElectronVolts:
                return value * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::KiloelectronVolts:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::MegaelectronVolts:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::GigaelectronVolts:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::TeraelectronVolts:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::FootPounds:
                return value * static_cast<un_scalar_t>(1.3558179483314004);

            case EnergyUnit::Ergs:
                return value * static_cast<un_scalar_t>(1e-7);

            case EnergyUnit::WattHours:
                return value * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattHours:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::MegawattHours:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::GigawattHours:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::TerawattHours:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::WattDays:
                return value * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattDays:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::MegawattDays:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::GigawattDays:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::TerawattDays:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::ThermsEc:
                return value * static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::DecathermsEc:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::ThermsUs:
                return value * static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::DecathermsUs:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::ThermsImperial:
                return value * static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::DecathermsImperial:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::HorsepowerHours:
                return value * static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EnergyUnit unit) const
        {
            switch (unit)
            {

            case EnergyUnit::Joules:
                return value_;

            case EnergyUnit::Nanojoules:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case EnergyUnit::Microjoules:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case EnergyUnit::Millijoules:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case EnergyUnit::Kilojoules:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::Megajoules:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::Gigajoules:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::Terajoules:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::Petajoules:
                return (value_) / static_cast<un_scalar_t>(1e15);

            case EnergyUnit::Calories:
                return value_ / static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Kilocalories:
                return (value_ / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::Megacalories:
                return (value_ / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::BritishThermalUnits:
                return value_ / static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::KilobritishThermalUnits:
                return (value_ / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegabritishThermalUnits:
                return (value_ / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigabritishThermalUnits:
                return (value_ / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::ElectronVolts:
                return value_ / static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::KiloelectronVolts:
                return (value_ / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegaelectronVolts:
                return (value_ / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigaelectronVolts:
                return (value_ / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TeraelectronVolts:
                return (value_ / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::FootPounds:
                return value_ / static_cast<un_scalar_t>(1.3558179483314004);

            case EnergyUnit::Ergs:
                return value_ / static_cast<un_scalar_t>(1e-7);

            case EnergyUnit::WattHours:
                return value_ / static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattHours:
                return (value_ / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegawattHours:
                return (value_ / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigawattHours:
                return (value_ / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TerawattHours:
                return (value_ / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::WattDays:
                return value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0));

            case EnergyUnit::KilowattDays:
                return (value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegawattDays:
                return (value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigawattDays:
                return (value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TerawattDays:
                return (value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::ThermsEc:
                return value_ / static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::DecathermsEc:
                return (value_ / static_cast<un_scalar_t>(1.05505585262e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::ThermsUs:
                return value_ / static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::DecathermsUs:
                return (value_ / static_cast<un_scalar_t>(1.054804e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::ThermsImperial:
                return value_ / static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::DecathermsImperial:
                return (value_ / static_cast<un_scalar_t>(1.05505585257348e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::HorsepowerHours:
                return value_ / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        un_scalar_t value_;
    };
}
