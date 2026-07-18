#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpecificEnergyUnit : std::uint16_t
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
    class SpecificEnergy
    {
    public:
        constexpr explicit SpecificEnergy(
            double value,
            SpecificEnergyUnit unit = SpecificEnergyUnit::JoulesPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpecificEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificEnergy operator+(SpecificEnergy other) const noexcept
        {
            return SpecificEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificEnergy operator-(SpecificEnergy other) const noexcept
        {
            return SpecificEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificEnergy operator*(double scalar) const noexcept
        {
            return SpecificEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificEnergy operator/(double scalar) const noexcept
        {
            return SpecificEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SpecificEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SpecificEnergy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::JoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_joules_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::JoulesPerKilogram);
        }


        [[nodiscard]] constexpr double kilojoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilojoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilojoules_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilojoulesPerKilogram);
        }


        [[nodiscard]] constexpr double megajoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulesPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulesPerKilogram);
        }


        [[nodiscard]] constexpr double megajoules_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulesPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulesPerTonne);
        }


        [[nodiscard]] constexpr double calories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::CaloriesPerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_calories_per_gram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::CaloriesPerGram);
        }


        [[nodiscard]] constexpr double kilocalories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilocaloriesPerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilocalories_per_gram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilocaloriesPerGram);
        }


        [[nodiscard]] constexpr double watt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHoursPerKilogram);
        }


        [[nodiscard]] constexpr double kilowatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHoursPerKilogram);
        }


        [[nodiscard]] constexpr double megawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHoursPerKilogram);
        }


        [[nodiscard]] constexpr double gigawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHoursPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHoursPerKilogram);
        }


        [[nodiscard]] constexpr double watt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerKilogram);
        }


        [[nodiscard]] constexpr double kilowatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerKilogram);
        }


        [[nodiscard]] constexpr double megawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerKilogram);
        }


        [[nodiscard]] constexpr double gigawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerKilogram);
        }


        [[nodiscard]] constexpr double terawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_kilogram(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerKilogram);
        }


        [[nodiscard]] constexpr double watt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerTonne);
        }


        [[nodiscard]] constexpr double kilowatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerTonne);
        }


        [[nodiscard]] constexpr double megawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerTonne);
        }


        [[nodiscard]] constexpr double gigawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerTonne);
        }


        [[nodiscard]] constexpr double terawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_tonne(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerTonne);
        }


        [[nodiscard]] constexpr double watt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_short_ton(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDaysPerShortTon);
        }


        [[nodiscard]] constexpr double kilowatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_short_ton(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDaysPerShortTon);
        }


        [[nodiscard]] constexpr double megawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_short_ton(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDaysPerShortTon);
        }


        [[nodiscard]] constexpr double gigawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_short_ton(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDaysPerShortTon);
        }


        [[nodiscard]] constexpr double terawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDaysPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_short_ton(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDaysPerShortTon);
        }


        [[nodiscard]] constexpr double watt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_pound(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHoursPerPound);
        }


        [[nodiscard]] constexpr double kilowatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_pound(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHoursPerPound);
        }


        [[nodiscard]] constexpr double megawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_pound(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHoursPerPound);
        }


        [[nodiscard]] constexpr double gigawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHoursPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_pound(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHoursPerPound);
        }


        [[nodiscard]] constexpr double btu_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::BtuPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_btu_per_pound(double value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::BtuPerPound);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpecificEnergyUnit unit)
        {
            switch (unit)
            {

            case SpecificEnergyUnit::JoulesPerKilogram:
                return value;

            case SpecificEnergyUnit::KilojoulesPerKilogram:
                return (value * 1e3);

            case SpecificEnergyUnit::MegajoulesPerKilogram:
                return (value * 1e6);

            case SpecificEnergyUnit::MegajoulesPerTonne:
                return value * 1e3;

            case SpecificEnergyUnit::CaloriesPerGram:
                return value * 4.184e3;

            case SpecificEnergyUnit::KilocaloriesPerGram:
                return (value * 1e3) * 4.184e3;

            case SpecificEnergyUnit::WattHoursPerKilogram:
                return value * 3.6e3;

            case SpecificEnergyUnit::KilowattHoursPerKilogram:
                return (value * 1e3) * 3.6e3;

            case SpecificEnergyUnit::MegawattHoursPerKilogram:
                return (value * 1e6) * 3.6e3;

            case SpecificEnergyUnit::GigawattHoursPerKilogram:
                return (value * 1e9) * 3.6e3;

            case SpecificEnergyUnit::WattDaysPerKilogram:
                return value * (24 * 3.6e3);

            case SpecificEnergyUnit::KilowattDaysPerKilogram:
                return (value * 1e3) * (24 * 3.6e3);

            case SpecificEnergyUnit::MegawattDaysPerKilogram:
                return (value * 1e6) * (24 * 3.6e3);

            case SpecificEnergyUnit::GigawattDaysPerKilogram:
                return (value * 1e9) * (24 * 3.6e3);

            case SpecificEnergyUnit::TerawattDaysPerKilogram:
                return (value * 1e12) * (24 * 3.6e3);

            case SpecificEnergyUnit::WattDaysPerTonne:
                return value * ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::KilowattDaysPerTonne:
                return (value * 1e3) * ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::MegawattDaysPerTonne:
                return (value * 1e6) * ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::GigawattDaysPerTonne:
                return (value * 1e9) * ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::TerawattDaysPerTonne:
                return (value * 1e12) * ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::WattDaysPerShortTon:
                return value * ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::KilowattDaysPerShortTon:
                return (value * 1e3) * ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::MegawattDaysPerShortTon:
                return (value * 1e6) * ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::GigawattDaysPerShortTon:
                return (value * 1e9) * ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::TerawattDaysPerShortTon:
                return (value * 1e12) * ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::WattHoursPerPound:
                return value * 7.93664e3;

            case SpecificEnergyUnit::KilowattHoursPerPound:
                return (value * 1e3) * 7.93664e3;

            case SpecificEnergyUnit::MegawattHoursPerPound:
                return (value * 1e6) * 7.93664e3;

            case SpecificEnergyUnit::GigawattHoursPerPound:
                return (value * 1e9) * 7.93664e3;

            case SpecificEnergyUnit::BtuPerPound:
                return value * 1055.05585262 / 0.45359237;

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpecificEnergyUnit unit) const
        {
            switch (unit)
            {

            case SpecificEnergyUnit::JoulesPerKilogram:
                return value_;

            case SpecificEnergyUnit::KilojoulesPerKilogram:
                return (value_) / 1e3;

            case SpecificEnergyUnit::MegajoulesPerKilogram:
                return (value_) / 1e6;

            case SpecificEnergyUnit::MegajoulesPerTonne:
                return value_ / 1e3;

            case SpecificEnergyUnit::CaloriesPerGram:
                return value_ / 4.184e3;

            case SpecificEnergyUnit::KilocaloriesPerGram:
                return (value_ / 4.184e3) / 1e3;

            case SpecificEnergyUnit::WattHoursPerKilogram:
                return value_ / 3.6e3;

            case SpecificEnergyUnit::KilowattHoursPerKilogram:
                return (value_ / 3.6e3) / 1e3;

            case SpecificEnergyUnit::MegawattHoursPerKilogram:
                return (value_ / 3.6e3) / 1e6;

            case SpecificEnergyUnit::GigawattHoursPerKilogram:
                return (value_ / 3.6e3) / 1e9;

            case SpecificEnergyUnit::WattDaysPerKilogram:
                return value_ / (24 * 3.6e3);

            case SpecificEnergyUnit::KilowattDaysPerKilogram:
                return (value_ / (24 * 3.6e3)) / 1e3;

            case SpecificEnergyUnit::MegawattDaysPerKilogram:
                return (value_ / (24 * 3.6e3)) / 1e6;

            case SpecificEnergyUnit::GigawattDaysPerKilogram:
                return (value_ / (24 * 3.6e3)) / 1e9;

            case SpecificEnergyUnit::TerawattDaysPerKilogram:
                return (value_ / (24 * 3.6e3)) / 1e12;

            case SpecificEnergyUnit::WattDaysPerTonne:
                return value_ / ((24 * 3.6e3) / 1e3);

            case SpecificEnergyUnit::KilowattDaysPerTonne:
                return (value_ / ((24 * 3.6e3) / 1e3)) / 1e3;

            case SpecificEnergyUnit::MegawattDaysPerTonne:
                return (value_ / ((24 * 3.6e3) / 1e3)) / 1e6;

            case SpecificEnergyUnit::GigawattDaysPerTonne:
                return (value_ / ((24 * 3.6e3) / 1e3)) / 1e9;

            case SpecificEnergyUnit::TerawattDaysPerTonne:
                return (value_ / ((24 * 3.6e3) / 1e3)) / 1e12;

            case SpecificEnergyUnit::WattDaysPerShortTon:
                return value_ / ((24 * 3.6e3) / 9.0718474e2);

            case SpecificEnergyUnit::KilowattDaysPerShortTon:
                return (value_ / ((24 * 3.6e3) / 9.0718474e2)) / 1e3;

            case SpecificEnergyUnit::MegawattDaysPerShortTon:
                return (value_ / ((24 * 3.6e3) / 9.0718474e2)) / 1e6;

            case SpecificEnergyUnit::GigawattDaysPerShortTon:
                return (value_ / ((24 * 3.6e3) / 9.0718474e2)) / 1e9;

            case SpecificEnergyUnit::TerawattDaysPerShortTon:
                return (value_ / ((24 * 3.6e3) / 9.0718474e2)) / 1e12;

            case SpecificEnergyUnit::WattHoursPerPound:
                return value_ / 7.93664e3;

            case SpecificEnergyUnit::KilowattHoursPerPound:
                return (value_ / 7.93664e3) / 1e3;

            case SpecificEnergyUnit::MegawattHoursPerPound:
                return (value_ / 7.93664e3) / 1e6;

            case SpecificEnergyUnit::GigawattHoursPerPound:
                return (value_ / 7.93664e3) / 1e9;

            case SpecificEnergyUnit::BtuPerPound:
                return value_ * 0.45359237 / 1055.05585262;

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        double value_;
    };
}
