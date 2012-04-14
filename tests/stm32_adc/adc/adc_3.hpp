/*
 * adc_3.hpp
 *
 *  Created on: 03.04.2012
 *      Author: dhebbeker
 */

#ifndef XPCC_STM32__ADC3_HPP
#define XPCC_STM32__ADC3_HPP

#if !defined (STM32F4XX) && !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_XL) && !defined (STM32F10X_CL)
 #error "Please select first the target STM32F?XX device used in your application (in stm32f?xx.h file)"
#endif


#if defined (STM32F10X_HD) || defined (STM32F10X_XL)
#include <xpcc/architecture.hpp>

namespace xpcc
{
	namespace stm32
	{
		/**
		 * Analog/Digital-Converter module (ADC3).
		 *
		 * \author	Stephan Kugelmann, David Hebbeker
		 * \ingroup	stm32
		 * @todo add functionality for STM32F103
		 * This API is designed for STM32F103xF, STM32F103xG, STM32F405xx and 
		 * STM32F407xx.  
		 */
		class Adc3 : public Interface
		{
		public:

			/**
			 * Channels, which can be used with this ADC.
			 * 
			 * You can specify the channel by using a pin-name, like PIN_C0, an 
			 * internal sensor, like TEMPERATURE_SENSOR or just the plain 
			 * channel number, like CHANNEL_0. 
			 */
			enum Channels
			{
				PIN_A0 = 0,
				PIN_A1 = 1,
				PIN_A2 = 2,
				PIN_A3 = 3,
				PIN_C0 = 10,
				PIN_C1 = 11,
				PIN_C2 = 12,
				PIN_C3 = 13,
				// For ADC3
				PIN_F6 = 4,
				PIN_F7 = 5,
				PIN_F8 = 6,
				PIN_F9 = 7,
				PIN_F10 = 8,
#if defined(STM32F4XX)	// Actually STM32F405xx or STM32F407xx is meant!
				PIN_F3 = 9,
				PIN_F4 = 14,
				PIN_F5 = 15,
#endif
				#if defined(STM32F4XX)
				#define TEMP_REF_AVIALABLE (1)
				
				/**
				 * The half V_BAT voltage.
				 */
				VBAT = 18,
				
				#endif
				
#ifdef TEMP_REF_AVIALABLE
				/** Measure the ambient temperature of the device.
				 * 
				 * \li Supported temperature range: -40 to 125 C
				 * \li Precision: +-1.5 C
				 * 
				 * @see Reference manual (i.e. RM0090) for the formula for the
				 * 	calculation of the actual temperature.
				 * @note The TSVREFE bit must be set to enable the conversion of 
				 * 	this internal channel.
				 */
				TEMPERATURE_SENSOR = 16,

				/** Internal reference voltage.
				 * 
				 * @note The TSVREFE bit must be set to enable the conversion of 
				 * 	this internal channel.
				 */
				V_REFINT = 17,
#endif // TEMP_REF_AVIALABLE
				
				CHANNEL_0 = 0,
				CHANNEL_1 = 1,
				CHANNEL_2 = 2,
				CHANNEL_3 = 3,
				CHANNEL_4 = 4,
				CHANNEL_5 = 5,
				CHANNEL_6 = 6,
				CHANNEL_7 = 7,
				CHANNEL_8 = 8,
				CHANNEL_10= 10,
				CHANNEL_11 = 11,
				CHANNEL_12 = 12,
				CHANNEL_13 = 13,
#if defined(STM32F4XX)
				CHANNEL_9 = 9,
				CHANNEL_14 = 14,
				CHANNEL_15 = 15,
				CHANNEL_16 = 16,
				CHANNEL_17 = 17,
				CHANNEL_18 = 18
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				#endif
			};
			
			/**
			 * Programmable prescaler to divide the APB2 clock frequency, which 
			 * is used fot the analog circuitry (not the digital interface which
			 * is used for registers). 
			 */
			enum Prescaler
			{
				PRESCALER_2 = 0b00,	//!< PCLK2 divided by 2
				PRESCALER_4 = 0b01,	//!< PCLK2 divided by 4
				PRESCALER_6 = 0b10,	//!< PCLK2 divided by 6
				PRESCALER_8 = 0b11	//!< PCLK2 divided by 8
			};
			
			/**
			 * Sampling time of the input voltage.
			 * 
			 * Total conversion time is T_con = Sampling time + 12 cycles
			 */
			enum SampleTime
			{
#if defined(STM32F4XX)
				CYCLES_3 	= 0b000,	//!< 3 ADCCLK cycles
				CYCLES_15 	= 0b001,	//!< 15 ADCCLK cycles
				CYCLES_28 	= 0b010,	//!< 28 ADCCLK cycles
				CYCLES_56 	= 0b011,	//!< 56 ADCCLK cycles
				CYCLES_84 	= 0b100,	//!< 84 ADCCLK cycles
				CYCLES_112 	= 0b101,	//!< 112 ADCCLK cycles
				CYCLES_144 	= 0b110,	//!< 144 ADCCLK cycles
				CYCLES_480 	= 0b111		//!< 480 ADCCLK cycles
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				CYCLES_2 	= 0b000,	//!< 1.5 ADCCLK cycles
				CYCLES_8 	= 0b001,	//!< 7.5 ADCCLK cycles
				CYCLES_14 	= 0b010,	//!< 13.5 ADCCLK cycles
				CYCLES_29 	= 0b011,	//!< 28.5 ADCCLK cycles
				CYCLES_42 	= 0b100,	//!< 41.5 ADCCLK cycles
				CYCLES_56 	= 0b101,	//!< 55.5 ADCCLK cycles
				CYCLES_72 	= 0b110,	//!< 71.5 ADCCLK cycles
				CYCLES_240 	= 0b111		//!< 239.5 ADCCLK cycles
#endif
			}; 

			/**
			 * Possible interrupts.
			 * 
			 * An interrupt can be produced on the end of conversion for regular
			 * and injected groups, when the analog watchdog status bit is set 
			 * and when the overrun status bit is set. 
			 */
			enum Interrupt
			{
				END_OF_CONVERSION_REGULAR	= ADC_SR_EOC,	//!< End of conversion of a regular group
				END_OF_CONVERSION_INJECTED	= ADC_SR_JEOC,	//!< End of conversion of an injected group
				ANALOG_WATCHDOG				= ADC_SR_AWD,	//!< Analog watchdog status bit is set
#if defined(STM32F4XX) 
				OVERRUN						= ADC_SR_OVR	//!< Overrun (if data are lost)
#endif
			};


		public:

#ifdef TEMP_REF_AVIALABLE
			static inline void
			enableTemperatureRefVMeasurement(void)
			{
#ifdef TMS32F4XX
				ADC3->CCR |= ADC_CCR_TSVREFE;
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				ADC3->CR2 |= ADC_CR2_TSVREFE;
#endif
			}

			static inline void
			disableTemperatureRefVMeasurement(void)
			{
#ifdef TMS32F4XX
				ADC3->CCR &= ~ADC_CCR_TSVREFE;
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				ADC3->CR2 &= ~ADC_CR2_TSVREFE;
#endif
			}
#endif

			/**
			 * Change the presentation of the ADC conversion result.
			 *
			 * @param enable Set to \c true to left adjust the result. 
			 * 	Otherwise, the result is right adjusted.
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 */
			static inline void
			setLeftAdjustResult(const bool enable)
			{
				if(enable)
					ADC3->CR2 |= ADC_CR2_ALIGN;
				else
					ADC3->CR2 &= ~ADC_CR2_ALIGN;			
			}

			/**
			 * Analog channel selection.
			 * 
			 * This is for single conversion mode only! The number of channels
			 * will be set to 1, the channel selected and the corresponding pin
			 * will be set to analog input.
			 * 
			 * @param channel		The channel which shall be read.
			 * @param sampleTime	The sample time to sample the input voltage.
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 */
			static inline void
			setChannel(const Channels channel, const SampleTime sampleTime=static_cast<SampleTime> (0b000))
			{
				ADC3->SQR1 = 0;		// clear number of conversions in the sequence and set number of conversions to 1
				ADC3->SQR3 |= channel & 0b11111;

				if(static_cast<uint8_t>(channel) < 10)
					ADC3->SMPR2 |= sampleTime << (static_cast<uint8_t>(channel) * 3);
				else
					ADC3->SMPR1 |= sampleTime << ((static_cast<uint8_t>(channel)-10) * 3);

#if defined(STM32F4XX) 
				if(channel <4)
					GPIOA->MODER |= 0b11 << ((channel + 0) * 2);
				else if(channel <9)
					GPIOF->MODER |= 0b11 << ((channel + 2) * 2);
				else if(channel == 9)
					GPIOF->MODER |= 0b11 << ((channel - 6) * 2);
				else if(channel <14)
					GPIOC->MODER |= 0b11 << ((channel - 10) * 2);
				else if(channel <16)
					GPIOF->MODER |= 0b11 << ((channel - 10) * 2);
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				if(channel <4)
					GPIOA->CRL &= ~(0b1111 << ((channel + 0) * 4));
				else if(channel <6)
					GPIOF->CRL &= ~(0b1111 << ((channel + 2) * 4));
				else if(channel <9)
					GPIOF->CRH &= ~(0b1111 << ((channel - 6) * 4));
				else if(channel <14 && channel>9)
					GPIOC->CRL &= ~(0b1111 << ((channel - 10) * 4));;
#endif
			}

			/**
			 * \brief Enables free running mode
			 *
			 * The ADC will continously start conversions and provide the most
			 * recent result in the ADC register.
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 */
			static inline void
			enableFreeRunningMode(void)
			{
				ADC3->CR2 |= ADC_CR2_CONT;	// set to continuous mode
			}

			/**
			 * \brief Disables free running mode
			 *
			 * The ADC will do only one sample and stop. The result will be in 
			 * the ADC register.
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 */
			static inline void
			disableFreeRunningMode(void)
			{
				ADC3->CR2 &= ~ADC_CR2_CONT;		// set to single mode
			}

			/**
			 * Returns if the specified interrupt flag is set.
			 * 
			 * \return \c true if the flag is set
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 * @param flag The interrupt flag, which shall be checked.
			 */
			static inline bool
			isInterruptFlagSet(const Interrupt flag)
			{
				return ADC3->SR & flag;
			}

			/**
			 * Clears the specified interrupt flag.
			 *
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 * @param flag The interrupt flag, which shall be cleared.
			 */
			static inline void
			clearInterruptFlag(const Interrupt flag)
			{
				ADC3->SR &= ~flag;
			}

			/**
			 * Disables the ADC Conversion Complete Interrupt.
			 */
			static inline void
			disableInterrupt(const Interrupt interrupt)
			{
#if defined(STM32F4XX)
				NVIC_DisableIRQ(ADC_IRQn);
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				NVIC_DisableIRQ(ADC3_IRQn);
				#endif

				switch(interrupt)
				{
					case END_OF_CONVERSION_REGULAR:
						ADC3->CR1 &= ~ADC_CR1_EOCIE;
						break;
					case END_OF_CONVERSION_INJECTED:
						ADC3->CR1 &= ~ADC_CR1_JEOCIE;
						break;
					case ANALOG_WATCHDOG:
						ADC3->CR1 &= ~ADC_CR1_AWDIE;
						break;
#if defined(STM32F4XX)
					case OVERRUN:
						ADC3->CR1 &= ~ADC_CR1_OVRIE;
						break;
#endif
				}
			}

			/**
			 * Enables the ADC Conversion Complete Interrupt.
			 *
			 * You could catch the interrupt using this function:
			 * 	\code extern "C" void ADC_IRQHandler(void) \endcode
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 * @param priority Priority to set
			 * @note ADC1 and ADC2 interrupts are mapped onto the same interrupt
			 * 	vector. ADC3 interrupts are mapped onto a separate interrupt 
			 * 	vector.
			 */
			static inline void
			enableInterrupt(const Interrupt interrupt, const uint32_t priority)
			{
#if defined(STM32F4XX)
				// Set priority for the interrupt vector				
				NVIC_SetPriority(ADC_IRQn, priority);				
				// register IRQ at the NVIC
				NVIC_EnableIRQ(ADC_IRQn);
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				// Set priority for the interrupt vector
				NVIC_SetPriority(ADC3_IRQn, priority);
				// register IRQ at the NVIC
				NVIC_EnableIRQ(ADC3_IRQn);
#endif
				
				switch(interrupt)
				{
					case END_OF_CONVERSION_REGULAR:
						ADC3->CR1 |= ADC_CR1_EOCIE;
						break;
					case END_OF_CONVERSION_INJECTED:
						ADC3->CR1 |= ADC_CR1_JEOCIE;
						break;
					case ANALOG_WATCHDOG:
						ADC3->CR1 |= ADC_CR1_AWDIE;
						break;
#if defined(STM32F4XX)
					case OVERRUN:
						ADC3->CR1 |= ADC_CR1_OVRIE;
						break;
#endif
				}
			}

			/** 
			 * Select the frequency of the clock to the ADC. The clock is common
			 * for all the ADCs (ADC1, ADC2, ADC3) and all channels. 
			 * @pre The ADC clock must be started and the ADC switched on with 
			 * 	initialize()
			 * @param prescaler The prescaler specifies by which factor the 
			 * 	system clock will be divided.
			 */
			static inline void
			setPrescaler(const Prescaler prescaler)
			{
#if defined(STM32F4XX)
				ADC->CCR &= ~(0b11 << 17);				// Clear prescaler
				ADC->CCR |= prescaler << 17;		// set prescaler
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				RCC->CFGR &= ~(0b11 << 14);			// Clear prescaler
				RCC->CFGR |= prescaler << 14;		// set prescaler
#endif
			}

			/**
			 * Initialize and enable the A/D converter.
			 *
			 * Enables the ADC clock and switches on the ADC. The ADC clock
			 * prescaler will be set as well.
			 * @param prescaler The prescaler specifies by which factor the 
			 * 	system clock will be divided.
			 */
			static inline void
			initialize(Prescaler prescaler=PRESCALER_2)
			{
				// Initialize ADC
				RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;	// start ADC Clock
				ADC3->CR2 |= ADC_CR2_ADON;			// switch on ADC
				setPrescaler(prescaler);
			}

			/**
			 * Turns off the ADC and its clock.
			 */
			static inline void
			shutdownADC(void)
			{
				ADC3->CR2 &= ~(ADC_CR2_ADON);		// switch off ADC
				RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN; // stop ADC Clock
			}

			/**
			 * Start a new conversion or continuous conversions.
			 * @pre A ADC channel must be selected with setChannel()
			 * @post The result can be fetched with getValue()
			 */
			static inline void
			startConversion(void)
			{
#if defined(STM32F4XX)
				clearInterruptFlag(static_cast<Interrupt>(END_OF_CONVERSION_REGULAR | END_OF_CONVERSION_INJECTED | ANALOG_WATCHDOG | OVERRUN));
#elif defined (STM32F10X_LD) || defined (STM32F10X_LD_VL) || defined (STM32F10X_MD) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_HD_VL) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
				clearInterruptFlag(static_cast<Interrupt>(END_OF_CONVERSION_REGULAR | END_OF_CONVERSION_INJECTED | ANALOG_WATCHDOG));
#endif
				ADC3->CR2 |= ADC_CR2_SWSTART;	// starts single conversion for the regular group
			}

			/** 
			 * @return If the conversion is finished.
			 * @pre A conversion should have been stared with startConversion()
			 */
			static inline bool
			isConversionFinished(void)
			{
				return (ADC3->SR & ADC_SR_EOC);
			}

			/**
			 * @return The most recent 16bit result of the ADC conversion.
			 * @pre A conversion should have been stared with startConversion()
			 */
			static inline uint16_t
			getValue(void)
			{
				while(!isConversionFinished())
				{
					asm volatile("NOP");
				}
				return ADC3->DR & 0xFFFF;
			}
		};
	}

}


#endif // STM32F10X_HD || STM32F10X_XL
#endif /* XPCC_STM32__ADC3_HPP */