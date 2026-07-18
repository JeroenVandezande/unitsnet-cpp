#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumeConcentrationUnit : std::uint16_t
    {
        DecimalFractions,
        LitersPerLiter,
        PicolitersPerLiter,
        NanolitersPerLiter,
        MicrolitersPerLiter,
        MillilitersPerLiter,
        CentilitersPerLiter,
        DecilitersPerLiter,
        LitersPerMilliliter,
        PicolitersPerMilliliter,
        NanolitersPerMilliliter,
        MicrolitersPerMilliliter,
        MillilitersPerMilliliter,
        CentilitersPerMilliliter,
        DecilitersPerMilliliter,
        Percent,
        PartsPerThousand,
        PartsPerMillion,
        PartsPerBillion,
        PartsPerTrillion,
    };

    /// <summary>The volume concentration (not to be confused with volume fraction) is defined as the volume of a constituent divided by the total volume of the mixture.</summary>
    class VolumeConcentration
    {
    public:
        constexpr explicit VolumeConcentration(
            double value,
            VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFractions)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumeConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeConcentration operator+(VolumeConcentration other) const noexcept
        {
            return VolumeConcentration(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumeConcentration operator-(VolumeConcentration other) const noexcept
        {
            return VolumeConcentration(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumeConcentration operator*(double scalar) const noexcept
        {
            return VolumeConcentration(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumeConcentration operator/(double scalar) const noexcept
        {
            return VolumeConcentration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VolumeConcentration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VolumeConcentration other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decimal_fractions() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_decimal_fractions(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecimalFractions);
        }


        [[nodiscard]] constexpr double liters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LitersPerLiter);
        }


        [[nodiscard]] constexpr double picoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicolitersPerLiter);
        }


        [[nodiscard]] constexpr double nanoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanolitersPerLiter);
        }


        [[nodiscard]] constexpr double microliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicrolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicrolitersPerLiter);
        }


        [[nodiscard]] constexpr double milliliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MillilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MillilitersPerLiter);
        }


        [[nodiscard]] constexpr double centiliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentilitersPerLiter);
        }


        [[nodiscard]] constexpr double deciliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_liter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecilitersPerLiter);
        }


        [[nodiscard]] constexpr double liters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LitersPerMilliliter);
        }


        [[nodiscard]] constexpr double picoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicolitersPerMilliliter);
        }


        [[nodiscard]] constexpr double nanoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanolitersPerMilliliter);
        }


        [[nodiscard]] constexpr double microliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicrolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicrolitersPerMilliliter);
        }


        [[nodiscard]] constexpr double milliliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MillilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MillilitersPerMilliliter);
        }


        [[nodiscard]] constexpr double centiliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentilitersPerMilliliter);
        }


        [[nodiscard]] constexpr double deciliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_milliliter(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecilitersPerMilliliter);
        }


        [[nodiscard]] constexpr double percent() const
        {
            return convert_from_base(VolumeConcentrationUnit::Percent);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_percent(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::Percent);
        }


        [[nodiscard]] constexpr double parts_per_thousand() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_thousand(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerThousand);
        }


        [[nodiscard]] constexpr double parts_per_million() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_million(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerMillion);
        }


        [[nodiscard]] constexpr double parts_per_billion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_billion(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerBillion);
        }


        [[nodiscard]] constexpr double parts_per_trillion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_trillion(double value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerTrillion);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumeConcentrationUnit unit)
        {
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return value;

            case VolumeConcentrationUnit::LitersPerLiter:
                return value;

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return (value * 1e-12);

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return (value * 1e-9);

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return (value * 1e-6);

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return (value * 1e-3);

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return (value * 1e-2);

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return (value * 1e-1);

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return value / 1e-3;

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return (value * 1e-12) / 1e-3;

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return (value * 1e-9) / 1e-3;

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return (value * 1e-6) / 1e-3;

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return (value * 1e-3) / 1e-3;

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return (value * 1e-2) / 1e-3;

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return (value * 1e-1) / 1e-3;

            case VolumeConcentrationUnit::Percent:
                return value / 1e2;

            case VolumeConcentrationUnit::PartsPerThousand:
                return value / 1e3;

            case VolumeConcentrationUnit::PartsPerMillion:
                return value / 1e6;

            case VolumeConcentrationUnit::PartsPerBillion:
                return value / 1e9;

            case VolumeConcentrationUnit::PartsPerTrillion:
                return value / 1e12;

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumeConcentrationUnit unit) const
        {
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return value_;

            case VolumeConcentrationUnit::LitersPerLiter:
                return value_;

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return (value_) / 1e-12;

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return (value_) / 1e-9;

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return (value_) / 1e-6;

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return (value_) / 1e-3;

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return (value_) / 1e-2;

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return (value_) / 1e-1;

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return value_ * 1e-3;

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return (value_ * 1e-3) / 1e-12;

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return (value_ * 1e-3) / 1e-9;

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return (value_ * 1e-3) / 1e-6;

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return (value_ * 1e-3) / 1e-3;

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return (value_ * 1e-3) / 1e-2;

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return (value_ * 1e-3) / 1e-1;

            case VolumeConcentrationUnit::Percent:
                return value_ * 1e2;

            case VolumeConcentrationUnit::PartsPerThousand:
                return value_ * 1e3;

            case VolumeConcentrationUnit::PartsPerMillion:
                return value_ * 1e6;

            case VolumeConcentrationUnit::PartsPerBillion:
                return value_ * 1e9;

            case VolumeConcentrationUnit::PartsPerTrillion:
                return value_ * 1e12;

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        double value_;
    };
}
