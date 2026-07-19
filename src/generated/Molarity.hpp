#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MolarityUnit : std::uint8_t
    {
        MolesPerCubicMeter,
        KilomolesPerCubicMeter,
        MolesPerLiter,
        FemtomolesPerLiter,
        PicomolesPerLiter,
        NanomolesPerLiter,
        MicromolesPerLiter,
        MillimolesPerLiter,
        CentimolesPerLiter,
        DecimolesPerLiter,
        PoundMolesPerCubicFoot,
    };

    /// <summary>Molar concentration, also called molarity, amount concentration or substance concentration, is a measure of the concentration of a solute in a solution, or of any chemical species, in terms of amount of substance in a given volume.</summary>
    class Molarity : public UnitsNetBase
    {
    public:
        constexpr explicit Molarity(
            const un_scalar_t value,
            const MolarityUnit unit = MolarityUnit::MolesPerCubicMeter)
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
           return "Molarity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case MolarityUnit::MolesPerCubicMeter:
                return "MolesPerCubicMeter";

            case MolarityUnit::KilomolesPerCubicMeter:
                return "KilomolesPerCubicMeter";

            case MolarityUnit::MolesPerLiter:
                return "MolesPerLiter";

            case MolarityUnit::FemtomolesPerLiter:
                return "FemtomolesPerLiter";

            case MolarityUnit::PicomolesPerLiter:
                return "PicomolesPerLiter";

            case MolarityUnit::NanomolesPerLiter:
                return "NanomolesPerLiter";

            case MolarityUnit::MicromolesPerLiter:
                return "MicromolesPerLiter";

            case MolarityUnit::MillimolesPerLiter:
                return "MillimolesPerLiter";

            case MolarityUnit::CentimolesPerLiter:
                return "CentimolesPerLiter";

            case MolarityUnit::DecimolesPerLiter:
                return "DecimolesPerLiter";

            case MolarityUnit::PoundMolesPerCubicFoot:
                return "PoundMolesPerCubicFoot";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Molarity operator+(const Molarity& other) const noexcept
        {
            return Molarity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Molarity operator-(const Molarity& other)const noexcept
        {
            return Molarity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Molarity operator*(const un_scalar_t scalar) const noexcept
        {
            return Molarity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Molarity operator/(const un_scalar_t scalar) const noexcept
        {
            return Molarity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Molarity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Molarity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Molarity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::MolesPerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_cubic_meter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MolesPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::KilomolesPerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_kilomoles_per_cubic_meter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::KilomolesPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t femtomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::FemtomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_femtomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::FemtomolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::PicomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_picomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::PicomolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::NanomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_nanomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::NanomolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t micromoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MicromolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_micromoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MicromolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t millimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MillimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_millimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MillimolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t centimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::CentimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_centimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::CentimolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t decimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::DecimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_decimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::DecimolesPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles_per_cubic_foot() const
        {
            return convert_from_base(MolarityUnit::PoundMolesPerCubicFoot);
        }

        [[nodiscard]] static constexpr Molarity from_pound_moles_per_cubic_foot(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::PoundMolesPerCubicFoot);
        }

        [[nodiscard]] static constexpr Molarity from_invalid()
        {
            return Molarity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarityUnit unit)
        {
            switch (unit)
            {

            case MolarityUnit::MolesPerCubicMeter:
                return value;

            case MolarityUnit::KilomolesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarityUnit::MolesPerLiter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::FemtomolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::PicomolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::NanomolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::MicromolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::MillimolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::CentimolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::DecimolesPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::PoundMolesPerCubicFoot:
                return value * static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarityUnit::MolesPerCubicMeter:
                return base_value;

            case MolarityUnit::KilomolesPerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarityUnit::MolesPerLiter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::FemtomolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-15);

            case MolarityUnit::PicomolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case MolarityUnit::NanomolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case MolarityUnit::MicromolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MolarityUnit::MillimolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::CentimolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case MolarityUnit::DecimolesPerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MolarityUnit::PoundMolesPerCubicFoot:
                return base_value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592));

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        un_scalar_t value_;
        MolarityUnit value_unit_type_;       
    };
}
