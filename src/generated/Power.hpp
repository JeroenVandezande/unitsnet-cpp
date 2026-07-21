#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PowerUnit : std::uint8_t
    {
        Watt,
        Femtowatt,
        Picowatt,
        Nanowatt,
        Microwatt,
        Milliwatt,
        Deciwatt,
        Decawatt,
        Kilowatt,
        Megawatt,
        Gigawatt,
        Terawatt,
        Petawatt,
        MechanicalHorsepower,
        MetricHorsepower,
        ElectricalHorsepower,
        BoilerHorsepower,
        HydraulicHorsepower,
        BritishThermalUnitPerHour,
        KilobritishThermalUnitPerHour,
        MegabritishThermalUnitPerHour,
        JoulePerHour,
        MillijoulePerHour,
        KilojoulePerHour,
        MegajoulePerHour,
        GigajoulePerHour,
        TonOfRefrigeration,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Power.</summary>
    class PowerDto
    {
    public:
        constexpr PowerDto() noexcept
            : value{}, unit(PowerUnit::Watt)
        {
        }

        constexpr PowerDto(
            const un_scalar_t value,
            const PowerUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PowerUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PowerUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PowerUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Power unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static PowerDto from_json(const nlohmann::json& json)
        {
            return PowerDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In physics, power is the rate of doing work. It is equivalent to an amount of energy consumed per unit time.</summary>
    class Power : public UnitsNetBase
    {
    public:
        constexpr explicit Power(
            const un_scalar_t value,
            const PowerUnit unit = PowerUnit::Watt)
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

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PowerDto to_dto(
            const PowerUnit unit = PowerUnit::Watt) const
        {
            return PowerDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Power from_dto(const PowerDto& dto)
        {
            return Power(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PowerUnit unit = PowerUnit::Watt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Power from_json(const nlohmann::json& json)
        {
            return from_dto(PowerDto::from_json(json));
        }
#endif
#endif

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
            return convert_from_base(PowerUnit::Watt);
        }

        [[nodiscard]] static constexpr Power from_watts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Watt);
        }

        [[nodiscard]] constexpr un_scalar_t femtowatts() const
        {
            return convert_from_base(PowerUnit::Femtowatt);
        }

        [[nodiscard]] static constexpr Power from_femtowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Femtowatt);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts() const
        {
            return convert_from_base(PowerUnit::Picowatt);
        }

        [[nodiscard]] static constexpr Power from_picowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Picowatt);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts() const
        {
            return convert_from_base(PowerUnit::Nanowatt);
        }

        [[nodiscard]] static constexpr Power from_nanowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Nanowatt);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts() const
        {
            return convert_from_base(PowerUnit::Microwatt);
        }

        [[nodiscard]] static constexpr Power from_microwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Microwatt);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts() const
        {
            return convert_from_base(PowerUnit::Milliwatt);
        }

        [[nodiscard]] static constexpr Power from_milliwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Milliwatt);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts() const
        {
            return convert_from_base(PowerUnit::Deciwatt);
        }

        [[nodiscard]] static constexpr Power from_deciwatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Deciwatt);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts() const
        {
            return convert_from_base(PowerUnit::Decawatt);
        }

        [[nodiscard]] static constexpr Power from_decawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Decawatt);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts() const
        {
            return convert_from_base(PowerUnit::Kilowatt);
        }

        [[nodiscard]] static constexpr Power from_kilowatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Kilowatt);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts() const
        {
            return convert_from_base(PowerUnit::Megawatt);
        }

        [[nodiscard]] static constexpr Power from_megawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Megawatt);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts() const
        {
            return convert_from_base(PowerUnit::Gigawatt);
        }

        [[nodiscard]] static constexpr Power from_gigawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Gigawatt);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts() const
        {
            return convert_from_base(PowerUnit::Terawatt);
        }

        [[nodiscard]] static constexpr Power from_terawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Terawatt);
        }

        [[nodiscard]] constexpr un_scalar_t petawatts() const
        {
            return convert_from_base(PowerUnit::Petawatt);
        }

        [[nodiscard]] static constexpr Power from_petawatts(const un_scalar_t value)
        {
            return Power(value, PowerUnit::Petawatt);
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
            return convert_from_base(PowerUnit::BritishThermalUnitPerHour);
        }

        [[nodiscard]] static constexpr Power from_british_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::BritishThermalUnitPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilobritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::KilobritishThermalUnitPerHour);
        }

        [[nodiscard]] static constexpr Power from_kilobritish_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::KilobritishThermalUnitPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megabritish_thermal_units_per_hour() const
        {
            return convert_from_base(PowerUnit::MegabritishThermalUnitPerHour);
        }

        [[nodiscard]] static constexpr Power from_megabritish_thermal_units_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MegabritishThermalUnitPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_hour() const
        {
            return convert_from_base(PowerUnit::JoulePerHour);
        }

        [[nodiscard]] static constexpr Power from_joules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::JoulePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t millijoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MillijoulePerHour);
        }

        [[nodiscard]] static constexpr Power from_millijoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MillijoulePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_hour() const
        {
            return convert_from_base(PowerUnit::KilojoulePerHour);
        }

        [[nodiscard]] static constexpr Power from_kilojoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::KilojoulePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::MegajoulePerHour);
        }

        [[nodiscard]] static constexpr Power from_megajoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::MegajoulePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t gigajoules_per_hour() const
        {
            return convert_from_base(PowerUnit::GigajoulePerHour);
        }

        [[nodiscard]] static constexpr Power from_gigajoules_per_hour(const un_scalar_t value)
        {
            return Power(value, PowerUnit::GigajoulePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t tons_of_refrigeration() const
        {
            return convert_from_base(PowerUnit::TonOfRefrigeration);
        }

        [[nodiscard]] static constexpr Power from_tons_of_refrigeration(const un_scalar_t value)
        {
            return Power(value, PowerUnit::TonOfRefrigeration);
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

            case PowerUnit::Watt:
                return value;

            case PowerUnit::Femtowatt:
                return (value * static_cast<un_scalar_t>(1e-15));

            case PowerUnit::Picowatt:
                return (value * static_cast<un_scalar_t>(1e-12));

            case PowerUnit::Nanowatt:
                return (value * static_cast<un_scalar_t>(1e-9));

            case PowerUnit::Microwatt:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PowerUnit::Milliwatt:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PowerUnit::Deciwatt:
                return (value * static_cast<un_scalar_t>(1e-1));

            case PowerUnit::Decawatt:
                return (value * static_cast<un_scalar_t>(1e1));

            case PowerUnit::Kilowatt:
                return (value * static_cast<un_scalar_t>(1e3));

            case PowerUnit::Megawatt:
                return (value * static_cast<un_scalar_t>(1e6));

            case PowerUnit::Gigawatt:
                return (value * static_cast<un_scalar_t>(1e9));

            case PowerUnit::Terawatt:
                return (value * static_cast<un_scalar_t>(1e12));

            case PowerUnit::Petawatt:
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

            case PowerUnit::BritishThermalUnitPerHour:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::KilobritishThermalUnitPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::MegabritishThermalUnitPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(3600);

            case PowerUnit::JoulePerHour:
                return value / static_cast<un_scalar_t>(3600);

            case PowerUnit::MillijoulePerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::KilojoulePerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::MegajoulePerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::GigajoulePerHour:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(3600);

            case PowerUnit::TonOfRefrigeration:
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

            case PowerUnit::Watt:
                return base_value;

            case PowerUnit::Femtowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case PowerUnit::Picowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case PowerUnit::Nanowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case PowerUnit::Microwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case PowerUnit::Milliwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::Deciwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case PowerUnit::Decawatt:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case PowerUnit::Kilowatt:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::Megawatt:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::Gigawatt:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::Terawatt:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case PowerUnit::Petawatt:
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

            case PowerUnit::BritishThermalUnitPerHour:
                return base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262);

            case PowerUnit::KilobritishThermalUnitPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegabritishThermalUnitPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::JoulePerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case PowerUnit::MillijoulePerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case PowerUnit::KilojoulePerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case PowerUnit::MegajoulePerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            case PowerUnit::GigajoulePerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e9);

            case PowerUnit::TonOfRefrigeration:
                return base_value / static_cast<un_scalar_t>(3516.853);

            }

            throw std::invalid_argument("Unknown Power unit.");
        }

        un_scalar_t value_;
        PowerUnit value_unit_type_;       
    };
}
