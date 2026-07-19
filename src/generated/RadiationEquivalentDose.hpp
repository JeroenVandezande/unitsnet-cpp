#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RadiationEquivalentDoseUnit : std::uint8_t
    {
        Sieverts,
        Nanosieverts,
        Microsieverts,
        Millisieverts,
        RoentgensEquivalentMan,
        MilliroentgensEquivalentMan,
    };

    /// <summary>Equivalent dose is a dose quantity representing the stochastic health effects of low levels of ionizing radiation on the human body which represents the probability of radiation-induced cancer and genetic damage.</summary>
    class RadiationEquivalentDose : public UnitsNetBase
    {
    public:
        constexpr explicit RadiationEquivalentDose(
            const un_scalar_t value,
            const RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sieverts)
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
           return "RadiationEquivalentDose"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return "Sieverts";

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return "Nanosieverts";

            case RadiationEquivalentDoseUnit::Microsieverts:
                return "Microsieverts";

            case RadiationEquivalentDoseUnit::Millisieverts:
                return "Millisieverts";

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return "RoentgensEquivalentMan";

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return "MilliroentgensEquivalentMan";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationEquivalentDoseUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator+(const RadiationEquivalentDose& other) const noexcept
        {
            return RadiationEquivalentDose(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator-(const RadiationEquivalentDose& other)const noexcept
        {
            return RadiationEquivalentDose(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(base_value() * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t sieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Sieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_sieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Sieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t nanosieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Nanosieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_nanosieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Nanosieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t microsieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Microsieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_microsieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Microsieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t millisieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Millisieverts);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_millisieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Millisieverts);
        }

        [[nodiscard]] constexpr un_scalar_t roentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_roentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }

        [[nodiscard]] constexpr un_scalar_t milliroentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_milliroentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_invalid()
        {
            return RadiationEquivalentDose(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationEquivalentDoseUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return value;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return value / static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationEquivalentDoseUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return base_value;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return base_value * static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        un_scalar_t value_;
        RadiationEquivalentDoseUnit value_unit_type_;       
    };
}
