#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class VolumeConcentrationUnit : std::uint8_t
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
            const un_scalar_t value,
            const VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFractions)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit VolumeConcentration(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeConcentration operator+(const VolumeConcentration other) const noexcept
        {
            return VolumeConcentration(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumeConcentration operator-(const VolumeConcentration other) const noexcept
        {
            return VolumeConcentration(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumeConcentration operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumeConcentration operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeConcentration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const VolumeConcentration other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeConcentration other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_decimal_fractions(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecimalFractions);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t picoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicolitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanolitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicrolitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicrolitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MillilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MillilitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentilitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecilitersPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecilitersPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t liters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t picoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicolitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanolitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t microliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicrolitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicrolitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MillilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MillilitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentilitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecilitersPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecilitersPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(VolumeConcentrationUnit::Percent);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_percent(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::Percent);
        }


        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_thousand(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerThousand);
        }


        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_million(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerMillion);
        }


        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_billion(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerBillion);
        }


        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_trillion(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartsPerTrillion);
        }


        [[nodiscard]] static constexpr VolumeConcentration from_invalid()
        {
            return VolumeConcentration(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeConcentrationUnit unit)
        {
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return value;

            case VolumeConcentrationUnit::LitersPerLiter:
                return value;

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return value / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case VolumeConcentrationUnit::PartsPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeConcentrationUnit::PartsPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumeConcentrationUnit::PartsPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case VolumeConcentrationUnit::PartsPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeConcentrationUnit unit) const
        {
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return value_;

            case VolumeConcentrationUnit::LitersPerLiter:
                return value_;

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return value_ * static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::Percent:
                return value_ * static_cast<un_scalar_t>(1e2);

            case VolumeConcentrationUnit::PartsPerThousand:
                return value_ * static_cast<un_scalar_t>(1e3);

            case VolumeConcentrationUnit::PartsPerMillion:
                return value_ * static_cast<un_scalar_t>(1e6);

            case VolumeConcentrationUnit::PartsPerBillion:
                return value_ * static_cast<un_scalar_t>(1e9);

            case VolumeConcentrationUnit::PartsPerTrillion:
                return value_ * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        un_scalar_t value_;
    };
}
