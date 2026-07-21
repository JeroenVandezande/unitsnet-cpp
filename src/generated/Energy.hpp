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
    enum class EnergyUnit : std::uint8_t
    {
        Joule,
        Nanojoule,
        Microjoule,
        Millijoule,
        Kilojoule,
        Megajoule,
        Gigajoule,
        Terajoule,
        Petajoule,
        Calorie,
        Kilocalorie,
        Megacalorie,
        BritishThermalUnit,
        KilobritishThermalUnit,
        MegabritishThermalUnit,
        GigabritishThermalUnit,
        ElectronVolt,
        KiloelectronVolt,
        MegaelectronVolt,
        GigaelectronVolt,
        TeraelectronVolt,
        FootPound,
        Erg,
        WattHour,
        KilowattHour,
        MegawattHour,
        GigawattHour,
        TerawattHour,
        WattDay,
        KilowattDay,
        MegawattDay,
        GigawattDay,
        TerawattDay,
        ThermEc,
        DecathermEc,
        ThermUs,
        DecathermUs,
        ThermImperial,
        DecathermImperial,
        HorsepowerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Energy.</summary>
    class EnergyDto
    {
    public:
        constexpr EnergyDto() noexcept
            : value{}, unit(EnergyUnit::Joule)
        {
        }

        constexpr EnergyDto(
            const un_scalar_t value,
            const EnergyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        EnergyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr EnergyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<EnergyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Energy unit name.");
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
        [[nodiscard]] static EnergyDto from_json(const nlohmann::json& json)
        {
            return EnergyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The joule, symbol J, is a derived unit of energy, work, or amount of heat in the International System of Units. It is equal to the energy transferred (or work done) when applying a force of one newton through a distance of one metre (1 newton metre or N·m), or in passing an electric current of one ampere through a resistance of one ohm for one second. Many other units of energy are included. Please do not confuse this definition of the calorie with the one colloquially used by the food industry, the large calorie, which is equivalent to 1 kcal. Thermochemical definition of the calorie is used. For BTU, the IT definition is used.</summary>
    class Energy : public UnitsNetBase
    {
    public:
        constexpr explicit Energy(
            const un_scalar_t value,
            const EnergyUnit unit = EnergyUnit::Joule)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const EnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr EnergyDto to_dto(
            const EnergyUnit unit = EnergyUnit::Joule) const
        {
            return EnergyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Energy from_dto(const EnergyDto& dto)
        {
            return Energy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const EnergyUnit unit = EnergyUnit::Joule) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Energy from_json(const nlohmann::json& json)
        {
            return from_dto(EnergyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Energy operator+(const Energy& other) const noexcept
        {
            return Energy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Energy operator-(const Energy& other)const noexcept
        {
            return Energy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Energy operator*(const un_scalar_t scalar) const noexcept
        {
            return Energy(base_value() * scalar);
        }

        [[nodiscard]] constexpr Energy operator/(const un_scalar_t scalar) const noexcept
        {
            return Energy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Energy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Energy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Energy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules() const
        {
            return convert_from_base(EnergyUnit::Joule);
        }

        [[nodiscard]] static constexpr Energy from_joules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Joule);
        }

        [[nodiscard]] constexpr un_scalar_t nanojoules() const
        {
            return convert_from_base(EnergyUnit::Nanojoule);
        }

        [[nodiscard]] static constexpr Energy from_nanojoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Nanojoule);
        }

        [[nodiscard]] constexpr un_scalar_t microjoules() const
        {
            return convert_from_base(EnergyUnit::Microjoule);
        }

        [[nodiscard]] static constexpr Energy from_microjoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Microjoule);
        }

        [[nodiscard]] constexpr un_scalar_t millijoules() const
        {
            return convert_from_base(EnergyUnit::Millijoule);
        }

        [[nodiscard]] static constexpr Energy from_millijoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Millijoule);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules() const
        {
            return convert_from_base(EnergyUnit::Kilojoule);
        }

        [[nodiscard]] static constexpr Energy from_kilojoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Kilojoule);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules() const
        {
            return convert_from_base(EnergyUnit::Megajoule);
        }

        [[nodiscard]] static constexpr Energy from_megajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Megajoule);
        }

        [[nodiscard]] constexpr un_scalar_t gigajoules() const
        {
            return convert_from_base(EnergyUnit::Gigajoule);
        }

        [[nodiscard]] static constexpr Energy from_gigajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Gigajoule);
        }

        [[nodiscard]] constexpr un_scalar_t terajoules() const
        {
            return convert_from_base(EnergyUnit::Terajoule);
        }

        [[nodiscard]] static constexpr Energy from_terajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Terajoule);
        }

        [[nodiscard]] constexpr un_scalar_t petajoules() const
        {
            return convert_from_base(EnergyUnit::Petajoule);
        }

        [[nodiscard]] static constexpr Energy from_petajoules(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Petajoule);
        }

        [[nodiscard]] constexpr un_scalar_t calories() const
        {
            return convert_from_base(EnergyUnit::Calorie);
        }

        [[nodiscard]] static constexpr Energy from_calories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Calorie);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories() const
        {
            return convert_from_base(EnergyUnit::Kilocalorie);
        }

        [[nodiscard]] static constexpr Energy from_kilocalories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Kilocalorie);
        }

        [[nodiscard]] constexpr un_scalar_t megacalories() const
        {
            return convert_from_base(EnergyUnit::Megacalorie);
        }

        [[nodiscard]] static constexpr Energy from_megacalories(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Megacalorie);
        }

        [[nodiscard]] constexpr un_scalar_t british_thermal_units() const
        {
            return convert_from_base(EnergyUnit::BritishThermalUnit);
        }

        [[nodiscard]] static constexpr Energy from_british_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::BritishThermalUnit);
        }

        [[nodiscard]] constexpr un_scalar_t kilobritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::KilobritishThermalUnit);
        }

        [[nodiscard]] static constexpr Energy from_kilobritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilobritishThermalUnit);
        }

        [[nodiscard]] constexpr un_scalar_t megabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::MegabritishThermalUnit);
        }

        [[nodiscard]] static constexpr Energy from_megabritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegabritishThermalUnit);
        }

        [[nodiscard]] constexpr un_scalar_t gigabritish_thermal_units() const
        {
            return convert_from_base(EnergyUnit::GigabritishThermalUnit);
        }

        [[nodiscard]] static constexpr Energy from_gigabritish_thermal_units(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigabritishThermalUnit);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] constexpr un_scalar_t electron_volts() const
        {
            return convert_from_base(EnergyUnit::ElectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] static constexpr Energy from_electron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ElectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloelectron_volts() const
        {
            return convert_from_base(EnergyUnit::KiloelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] static constexpr Energy from_kiloelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KiloelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] constexpr un_scalar_t megaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::MegaelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] static constexpr Energy from_megaelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegaelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] constexpr un_scalar_t gigaelectron_volts() const
        {
            return convert_from_base(EnergyUnit::GigaelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] static constexpr Energy from_gigaelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigaelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] constexpr un_scalar_t teraelectron_volts() const
        {
            return convert_from_base(EnergyUnit::TeraelectronVolt);
        }

        /// <summary>In physics, an electronvolt (symbol eV, also written electron-volt and electron volt) is the measure of an amount of kinetic energy gained by a single electron accelerating from rest through an electric potential difference of one volt in vacuum. When used as a unit of energy, the numerical value of 1 eV in joules (symbol J) is equivalent to the numerical value of the charge of an electron in coulombs (symbol C). Under the 2019 redefinition of the SI base units, this sets 1 eV equal to the exact value 1.602176634×10−19 J.</summary>
        [[nodiscard]] static constexpr Energy from_teraelectron_volts(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TeraelectronVolt);
        }

        /// <summary>A pound-foot (lb⋅ft), abbreviated from pound-force foot (lbf · ft), is a unit of torque representing one pound of force acting at a perpendicular distance of one foot from a pivot point. Conversely one foot pound-force (ft · lbf) is the moment about an axis that applies one pound-force at a radius of one foot.</summary>
        [[nodiscard]] constexpr un_scalar_t foot_pounds() const
        {
            return convert_from_base(EnergyUnit::FootPound);
        }

        /// <summary>A pound-foot (lb⋅ft), abbreviated from pound-force foot (lbf · ft), is a unit of torque representing one pound of force acting at a perpendicular distance of one foot from a pivot point. Conversely one foot pound-force (ft · lbf) is the moment about an axis that applies one pound-force at a radius of one foot.</summary>
        [[nodiscard]] static constexpr Energy from_foot_pounds(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::FootPound);
        }

        /// <summary>The erg is a unit of energy equal to 10−7 joules (100 nJ). It originated in the Centimetre–gram–second system of units (CGS). It has the symbol erg. The erg is not an SI unit. Its name is derived from ergon (ἔργον), a Greek word meaning 'work' or 'task'.</summary>
        [[nodiscard]] constexpr un_scalar_t ergs() const
        {
            return convert_from_base(EnergyUnit::Erg);
        }

        /// <summary>The erg is a unit of energy equal to 10−7 joules (100 nJ). It originated in the Centimetre–gram–second system of units (CGS). It has the symbol erg. The erg is not an SI unit. Its name is derived from ergon (ἔργον), a Greek word meaning 'work' or 'task'.</summary>
        [[nodiscard]] static constexpr Energy from_ergs(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::Erg);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours() const
        {
            return convert_from_base(EnergyUnit::WattHour);
        }

        [[nodiscard]] static constexpr Energy from_watt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::WattHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours() const
        {
            return convert_from_base(EnergyUnit::KilowattHour);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilowattHour);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours() const
        {
            return convert_from_base(EnergyUnit::MegawattHour);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegawattHour);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours() const
        {
            return convert_from_base(EnergyUnit::GigawattHour);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigawattHour);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_hours() const
        {
            return convert_from_base(EnergyUnit::TerawattHour);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TerawattHour);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days() const
        {
            return convert_from_base(EnergyUnit::WattDay);
        }

        [[nodiscard]] static constexpr Energy from_watt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::WattDay);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days() const
        {
            return convert_from_base(EnergyUnit::KilowattDay);
        }

        [[nodiscard]] static constexpr Energy from_kilowatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::KilowattDay);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days() const
        {
            return convert_from_base(EnergyUnit::MegawattDay);
        }

        [[nodiscard]] static constexpr Energy from_megawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::MegawattDay);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days() const
        {
            return convert_from_base(EnergyUnit::GigawattDay);
        }

        [[nodiscard]] static constexpr Energy from_gigawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::GigawattDay);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days() const
        {
            return convert_from_base(EnergyUnit::TerawattDay);
        }

        [[nodiscard]] static constexpr Energy from_terawatt_days(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::TerawattDay);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t therms_ec() const
        {
            return convert_from_base(EnergyUnit::ThermEc);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_therms_ec(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermEc);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t decatherms_ec() const
        {
            return convert_from_base(EnergyUnit::DecathermEc);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_decatherms_ec(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermEc);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t therms_us() const
        {
            return convert_from_base(EnergyUnit::ThermUs);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_therms_us(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermUs);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t decatherms_us() const
        {
            return convert_from_base(EnergyUnit::DecathermUs);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_decatherms_us(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermUs);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t therms_imperial() const
        {
            return convert_from_base(EnergyUnit::ThermImperial);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_therms_imperial(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::ThermImperial);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] constexpr un_scalar_t decatherms_imperial() const
        {
            return convert_from_base(EnergyUnit::DecathermImperial);
        }

        /// <summary>The therm (symbol, thm) is a non-SI unit of heat energy equal to 100,000 British thermal units (BTU), and approximately 105 megajoules, 29.3 kilowatt-hours, 25,200 kilocalories and 25.2 thermies. One therm is the energy content of approximately 100 cubic feet (2.83 cubic metres) of natural gas at standard temperature and pressure. However, the BTU is not standardised worldwide, with slightly different values in the EU, UK, and United States, meaning that the energy content of the therm also varies by territory.</summary>
        [[nodiscard]] static constexpr Energy from_decatherms_imperial(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::DecathermImperial);
        }

        /// <summary>A horsepower-hour (symbol: hp⋅h) is an outdated unit of energy, not used in the International System of Units. The unit represents an amount of work a horse is supposed capable of delivering during an hour (1 horsepower integrated over a time interval of an hour).</summary>
        [[nodiscard]] constexpr un_scalar_t horsepower_hours() const
        {
            return convert_from_base(EnergyUnit::HorsepowerHour);
        }

        /// <summary>A horsepower-hour (symbol: hp⋅h) is an outdated unit of energy, not used in the International System of Units. The unit represents an amount of work a horse is supposed capable of delivering during an hour (1 horsepower integrated over a time interval of an hour).</summary>
        [[nodiscard]] static constexpr Energy from_horsepower_hours(const un_scalar_t value)
        {
            return Energy(value, EnergyUnit::HorsepowerHour);
        }

        [[nodiscard]] static constexpr Energy from_invalid()
        {
            return Energy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EnergyUnit unit)
        {
            switch (unit)
            {

            case EnergyUnit::Joule:
                return value;

            case EnergyUnit::Nanojoule:
                return (value * static_cast<un_scalar_t>(1e-9));

            case EnergyUnit::Microjoule:
                return (value * static_cast<un_scalar_t>(1e-6));

            case EnergyUnit::Millijoule:
                return (value * static_cast<un_scalar_t>(1e-3));

            case EnergyUnit::Kilojoule:
                return (value * static_cast<un_scalar_t>(1e3));

            case EnergyUnit::Megajoule:
                return (value * static_cast<un_scalar_t>(1e6));

            case EnergyUnit::Gigajoule:
                return (value * static_cast<un_scalar_t>(1e9));

            case EnergyUnit::Terajoule:
                return (value * static_cast<un_scalar_t>(1e12));

            case EnergyUnit::Petajoule:
                return (value * static_cast<un_scalar_t>(1e15));

            case EnergyUnit::Calorie:
                return value * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Kilocalorie:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Megacalorie:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.184);

            case EnergyUnit::BritishThermalUnit:
                return value * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::KilobritishThermalUnit:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::MegabritishThermalUnit:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::GigabritishThermalUnit:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::ElectronVolt:
                return value * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::KiloelectronVolt:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::MegaelectronVolt:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::GigaelectronVolt:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::TeraelectronVolt:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::FootPound:
                return value * static_cast<un_scalar_t>(1.3558179483314004);

            case EnergyUnit::Erg:
                return value * static_cast<un_scalar_t>(1e-7);

            case EnergyUnit::WattHour:
                return value * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattHour:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::MegawattHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::GigawattHour:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::TerawattHour:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::WattDay:
                return value * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattDay:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::MegawattDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::GigawattDay:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::TerawattDay:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::ThermEc:
                return value * static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::DecathermEc:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::ThermUs:
                return value * static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::DecathermUs:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::ThermImperial:
                return value * static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::DecathermImperial:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::HorsepowerHour:
                return value * static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case EnergyUnit::Joule:
                return base_value;

            case EnergyUnit::Nanojoule:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case EnergyUnit::Microjoule:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case EnergyUnit::Millijoule:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case EnergyUnit::Kilojoule:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::Megajoule:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::Gigajoule:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::Terajoule:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::Petajoule:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case EnergyUnit::Calorie:
                return base_value / static_cast<un_scalar_t>(4.184);

            case EnergyUnit::Kilocalorie:
                return (base_value / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::Megacalorie:
                return (base_value / static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::BritishThermalUnit:
                return base_value / static_cast<un_scalar_t>(1055.05585262);

            case EnergyUnit::KilobritishThermalUnit:
                return (base_value / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegabritishThermalUnit:
                return (base_value / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigabritishThermalUnit:
                return (base_value / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::ElectronVolt:
                return base_value / static_cast<un_scalar_t>(1.602176634e-19);

            case EnergyUnit::KiloelectronVolt:
                return (base_value / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegaelectronVolt:
                return (base_value / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigaelectronVolt:
                return (base_value / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TeraelectronVolt:
                return (base_value / static_cast<un_scalar_t>(1.602176634e-19)) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::FootPound:
                return base_value / static_cast<un_scalar_t>(1.3558179483314004);

            case EnergyUnit::Erg:
                return base_value / static_cast<un_scalar_t>(1e-7);

            case EnergyUnit::WattHour:
                return base_value / static_cast<un_scalar_t>(3600.0);

            case EnergyUnit::KilowattHour:
                return (base_value / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegawattHour:
                return (base_value / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigawattHour:
                return (base_value / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TerawattHour:
                return (base_value / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::WattDay:
                return base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0));

            case EnergyUnit::KilowattDay:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e3);

            case EnergyUnit::MegawattDay:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e6);

            case EnergyUnit::GigawattDay:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e9);

            case EnergyUnit::TerawattDay:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600.0))) / static_cast<un_scalar_t>(1e12);

            case EnergyUnit::ThermEc:
                return base_value / static_cast<un_scalar_t>(1.05505585262e8);

            case EnergyUnit::DecathermEc:
                return (base_value / static_cast<un_scalar_t>(1.05505585262e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::ThermUs:
                return base_value / static_cast<un_scalar_t>(1.054804e8);

            case EnergyUnit::DecathermUs:
                return (base_value / static_cast<un_scalar_t>(1.054804e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::ThermImperial:
                return base_value / static_cast<un_scalar_t>(1.05505585257348e8);

            case EnergyUnit::DecathermImperial:
                return (base_value / static_cast<un_scalar_t>(1.05505585257348e8)) / static_cast<un_scalar_t>(1e1);

            case EnergyUnit::HorsepowerHour:
                return base_value / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown Energy unit.");
        }

        un_scalar_t value_;
        EnergyUnit value_unit_type_;       
    };
}
