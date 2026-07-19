#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class Power : public UnitsNetBase
    {
    public:
        constexpr explicit Power(
            const un_scalar_t value,
            const PowerUnit unit = PowerUnit::Watts)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Power operator+(const Power& other) const noexcept
        {
            return Power(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Power operator-(const Power& other)const noexcept
        {
            return Power(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Power operator*(const un_scalar_t scalar) const noexcept
        {
            return Power(base_value() * scalar);
        }

        [[nodiscard]] constexpr Power operator/(const un_scalar_t scalar) const noexcept
        {
            return Power(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Power& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Power& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Power& other) const noexcept
        {
            return base_value() > other.base_value();
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

        /// <summary>Assuming the third CGPM (1901, CR 70) definition of standard gravity, gn = 9.80665 m/s2, is used to define the pound-force as well as the kilogram force, and the international avoirdupois pound (1959), one imperial horsepower is: 76.0402249 × 9.80665 kg⋅m2/s3</summary>
        [[nodiscard]] constexpr un_scalar_t mechanical_horsepower() const
        {
            return convert_from_base(PowerUnit::MechanicalHorsepower);
        }

        /// <summary>Assuming the third CGPM (1901, CR 70) definition of standard gravity, gn = 9.80665 m/s2, is used to define the pound-force as well as the kilogram force, and the international avoirdupois pound (1959), one imperial horsepower is: 76.0402249 × 9.80665 kg⋅m2/s3</summary>
        [[nodiscard]] static constexpr Power from_mechanical_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MechanicalHorsepower);
        }

        /// <summary>DIN 66036 defines one metric horsepower as the power to raise a mass of 75 kilograms against the Earth's gravitational force over a distance of one metre in one second:[18] 75 kg × 9.80665 m/s2 × 1 m / 1 s = 75 kgf⋅m/s = 1 PS. This is equivalent to 735.49875 W, or 98.6% of an imperial horsepower.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_horsepower() const
        {
            return convert_from_base(PowerUnit::MetricHorsepower);
        }

        /// <summary>DIN 66036 defines one metric horsepower as the power to raise a mass of 75 kilograms against the Earth's gravitational force over a distance of one metre in one second:[18] 75 kg × 9.80665 m/s2 × 1 m / 1 s = 75 kgf⋅m/s = 1 PS. This is equivalent to 735.49875 W, or 98.6% of an imperial horsepower.</summary>
        [[nodiscard]] static constexpr Power from_metric_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MetricHorsepower);
        }

        /// <summary>Nameplates on electrical motors show their power output, not the power input (the power delivered at the shaft, not the power consumed to drive the motor). This power output is ordinarily stated in watts or kilowatts. In the United States, the power output is stated in horsepower, which for this purpose is defined as exactly 746 W.</summary>
        [[nodiscard]] constexpr un_scalar_t electrical_horsepower() const
        {
            return convert_from_base(PowerUnit::ElectricalHorsepower);
        }

        /// <summary>Nameplates on electrical motors show their power output, not the power input (the power delivered at the shaft, not the power consumed to drive the motor). This power output is ordinarily stated in watts or kilowatts. In the United States, the power output is stated in horsepower, which for this purpose is defined as exactly 746 W.</summary>
        [[nodiscard]] static constexpr Power from_electrical_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::ElectricalHorsepower);
        }

        /// <summary>Boiler horsepower is a boiler's capacity to deliver steam to a steam engine and is not the same unit of power as the 550 ft lb/s definition. One boiler horsepower is equal to the thermal energy rate required to evaporate 34.5 pounds (15.6 kg) of fresh water at 212 °F (100 °C) in one hour.</summary>
        [[nodiscard]] constexpr un_scalar_t boiler_horsepower() const
        {
            return convert_from_base(PowerUnit::BoilerHorsepower);
        }

        /// <summary>Boiler horsepower is a boiler's capacity to deliver steam to a steam engine and is not the same unit of power as the 550 ft lb/s definition. One boiler horsepower is equal to the thermal energy rate required to evaporate 34.5 pounds (15.6 kg) of fresh water at 212 °F (100 °C) in one hour.</summary>
        [[nodiscard]] static constexpr Power from_boiler_horsepower(const un_scalar_t value)
        {
            return Power(value, PowerUnit::BoilerHorsepower);
        }

        /// <summary>Hydraulic horsepower can represent the power available within hydraulic machinery, power through the down-hole nozzle of a drilling rig, or can be used to estimate the mechanical power needed to generate a known hydraulic flow rate.</summary>
        [[nodiscard]] constexpr un_scalar_t hydraulic_horsepower() const
        {
            return convert_from_base(PowerUnit::HydraulicHorsepower);
        }

        /// <summary>Hydraulic horsepower can represent the power available within hydraulic machinery, power through the down-hole nozzle of a drilling rig, or can be used to estimate the mechanical power needed to generate a known hydraulic flow rate.</summary>
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

        [[nodiscard]] static constexpr Power from_invalid()
        {
            return Power(false);
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
                return value * static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665);

            case PowerUnit::MetricHorsepower:
                return value * static_cast<un_scalar_t>(75) * static_cast<un_scalar_t>(9.80665);

            case PowerUnit::ElectricalHorsepower:
                return value * static_cast<un_scalar_t>(746);

            case PowerUnit::BoilerHorsepower:
                return value * static_cast<un_scalar_t>(9812.5);

            case PowerUnit::HydraulicHorsepower:
                return value * static_cast<un_scalar_t>(745.69987158227022);

            case PowerUnit::BritishThermalUnitsPerHour:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::KilobritishThermalUnitsPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::JoulesPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case PowerUnit::MillijoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::KilojoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::MegajoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::GigajoulesPerHour:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::TonsOfRefrigeration:
                return value * static_cast<un_scalar_t>(3516.853);

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PowerUnit::Watts:
                return base_value;

            case PowerUnit::Femtowatts:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case PowerUnit::Picowatts:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case PowerUnit::Nanowatts:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case PowerUnit::Microwatts:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case PowerUnit::Milliwatts:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::Deciwatts:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case PowerUnit::Decawatts:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case PowerUnit::Kilowatts:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::Megawatts:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::Gigawatts:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::Terawatts:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case PowerUnit::Petawatts:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case PowerUnit::MechanicalHorsepower:
                return base_value / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665));

            case PowerUnit::MetricHorsepower:
                return base_value / (static_cast<un_scalar_t>(75) * static_cast<un_scalar_t>(9.80665));

            case PowerUnit::ElectricalHorsepower:
                return base_value / static_cast<un_scalar_t>(746);

            case PowerUnit::BoilerHorsepower:
                return base_value / static_cast<un_scalar_t>(9812.5);

            case PowerUnit::HydraulicHorsepower:
                return base_value / static_cast<un_scalar_t>(745.69987158227022);

            case PowerUnit::BritishThermalUnitsPerHour:
                return base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262);

            case PowerUnit::KilobritishThermalUnitsPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegabritishThermalUnitsPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::JoulesPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case PowerUnit::MillijoulesPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::KilojoulesPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegajoulesPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::GigajoulesPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::TonsOfRefrigeration:
                return base_value / static_cast<un_scalar_t>(3516.853);

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        un_scalar_t value_;
        PowerUnit value_unit_type_;       
    };
}
