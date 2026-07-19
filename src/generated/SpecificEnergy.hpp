#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpecificEnergyUnit : std::uint8_t
    {
        JoulesPerKilogram,
        KilojoulesPerKilogram,
        MegajoulesPerKilogram,
        MegajoulesPerTonne,
        CaloriesPerGram,
        KilocaloriesPerGram,
        WattHoursPerKilogram,
        KilowattHoursPerKilogram,
        MegawattHoursPerKilogram,
        GigawattHoursPerKilogram,
        WattDaysPerKilogram,
        KilowattDaysPerKilogram,
        MegawattDaysPerKilogram,
        GigawattDaysPerKilogram,
        TerawattDaysPerKilogram,
        WattDaysPerTonne,
        KilowattDaysPerTonne,
        MegawattDaysPerTonne,
        GigawattDaysPerTonne,
        TerawattDaysPerTonne,
        WattDaysPerShortTon,
        KilowattDaysPerShortTon,
        MegawattDaysPerShortTon,
        GigawattDaysPerShortTon,
        TerawattDaysPerShortTon,
        WattHoursPerPound,
        KilowattHoursPerPound,
        MegawattHoursPerPound,
        GigawattHoursPerPound,
        BtuPerPound,
    };

    /// <summary>The SpecificEnergy</summary>
    class SpecificEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificEnergy(
            const un_scalar_t value,
            const SpecificEnergyUnit unit = SpecificEnergyUnit::JoulesPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificEnergy operator+(const SpecificEnergy& other) const noexcept
        {
            return SpecificEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificEnergy operator-(const SpecificEnergy& other)const noexcept
        {
            return SpecificEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::JoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_joules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::JoulesPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilojoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilojoules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilojoulesPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulesPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulesPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulesPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::CaloriesPerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_calories_per_gram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::CaloriesPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilocaloriesPerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilocalories_per_gram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilocaloriesPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHoursPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHoursPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHoursPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHoursPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHoursPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHoursPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHoursPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHoursPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t btu_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::BtuPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_btu_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::BtuPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_invalid()
        {
            return SpecificEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificEnergyUnit unit)
        {
            switch (unit)
            {

            case SpecificEnergyUnit::JoulesPerKilogram:
                return value;

            case SpecificEnergyUnit::KilojoulesPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::MegajoulesPerKilogram:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEnergyUnit::MegajoulesPerTonne:
                return value * static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::CaloriesPerGram:
                return value * static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::KilocaloriesPerGram:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::WattHoursPerKilogram:
                return value * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::KilowattHoursPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::MegawattHoursPerKilogram:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::GigawattHoursPerKilogram:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::WattDaysPerKilogram:
                return value * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::KilowattDaysPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::MegawattDaysPerKilogram:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::GigawattDaysPerKilogram:
                return (value * static_cast<un_scalar_t>(1e9)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::TerawattDaysPerKilogram:
                return (value * static_cast<un_scalar_t>(1e12)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::WattDaysPerTonne:
                return value * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::KilowattDaysPerTonne:
                return (value * static_cast<un_scalar_t>(1e3)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::MegawattDaysPerTonne:
                return (value * static_cast<un_scalar_t>(1e6)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::GigawattDaysPerTonne:
                return (value * static_cast<un_scalar_t>(1e9)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::TerawattDaysPerTonne:
                return (value * static_cast<un_scalar_t>(1e12)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::WattDaysPerShortTon:
                return value * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::KilowattDaysPerShortTon:
                return (value * static_cast<un_scalar_t>(1e3)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::MegawattDaysPerShortTon:
                return (value * static_cast<un_scalar_t>(1e6)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::GigawattDaysPerShortTon:
                return (value * static_cast<un_scalar_t>(1e9)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::TerawattDaysPerShortTon:
                return (value * static_cast<un_scalar_t>(1e12)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::WattHoursPerPound:
                return value * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::KilowattHoursPerPound:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::MegawattHoursPerPound:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::GigawattHoursPerPound:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::BtuPerPound:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificEnergyUnit::JoulesPerKilogram:
                return base_value;

            case SpecificEnergyUnit::KilojoulesPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegajoulesPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::MegajoulesPerTonne:
                return base_value / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::CaloriesPerGram:
                return base_value / static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::KilocaloriesPerGram:
                return (base_value / static_cast<un_scalar_t>(4.184e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::WattHoursPerKilogram:
                return base_value / static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::KilowattHoursPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattHoursPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattHoursPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::WattDaysPerKilogram:
                return base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::KilowattDaysPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDaysPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDaysPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDaysPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattDaysPerTonne:
                return base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::KilowattDaysPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDaysPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDaysPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDaysPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattDaysPerShortTon:
                return base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::KilowattDaysPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDaysPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDaysPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDaysPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattHoursPerPound:
                return base_value / static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::KilowattHoursPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattHoursPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattHoursPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::BtuPerPound:
                return base_value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1055.05585262);

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        un_scalar_t value_;
        SpecificEnergyUnit value_unit_type_;       
    };
}
