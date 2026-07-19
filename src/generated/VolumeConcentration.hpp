#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class VolumeConcentration : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeConcentration(
            const un_scalar_t value,
            const VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFractions)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "VolumeConcentration"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return "DecimalFractions";

            case VolumeConcentrationUnit::LitersPerLiter:
                return "LitersPerLiter";

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return "PicolitersPerLiter";

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return "NanolitersPerLiter";

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return "MicrolitersPerLiter";

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return "MillilitersPerLiter";

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return "CentilitersPerLiter";

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return "DecilitersPerLiter";

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return "LitersPerMilliliter";

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return "PicolitersPerMilliliter";

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return "NanolitersPerMilliliter";

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return "MicrolitersPerMilliliter";

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return "MillilitersPerMilliliter";

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return "CentilitersPerMilliliter";

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return "DecilitersPerMilliliter";

            case VolumeConcentrationUnit::Percent:
                return "Percent";

            case VolumeConcentrationUnit::PartsPerThousand:
                return "PartsPerThousand";

            case VolumeConcentrationUnit::PartsPerMillion:
                return "PartsPerMillion";

            case VolumeConcentrationUnit::PartsPerBillion:
                return "PartsPerBillion";

            case VolumeConcentrationUnit::PartsPerTrillion:
                return "PartsPerTrillion";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeConcentration operator+(const VolumeConcentration& other) const noexcept
        {
            return VolumeConcentration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeConcentration operator-(const VolumeConcentration& other)const noexcept
        {
            return VolumeConcentration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeConcentration operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeConcentration operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeConcentration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeConcentration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeConcentration& other) const noexcept
        {
            return base_value() > other.base_value();
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
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFractions:
                return base_value;

            case VolumeConcentrationUnit::LitersPerLiter:
                return base_value;

            case VolumeConcentrationUnit::PicolitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanolitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicrolitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MillilitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentilitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DecilitersPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::LitersPerMilliliter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::PicolitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanolitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicrolitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MillilitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentilitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DecilitersPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case VolumeConcentrationUnit::PartsPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeConcentrationUnit::PartsPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumeConcentrationUnit::PartsPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case VolumeConcentrationUnit::PartsPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        un_scalar_t value_;
        VolumeConcentrationUnit value_unit_type_;       
    };
}
