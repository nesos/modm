modm_modules = [
    (r"modm/architecture.*", r"modm:architecture"),
    (r"modm/architecture/interface\.hpp", r"modm:architecture"),
    (r"modm/architecture/interface/accessor.*", r"modm:architecture:accessor"),
    (r"modm/architecture/interface/adc.*", r"modm:architecture:adc"),
    (r"modm/architecture/interface/assert.*", r"modm:architecture:assert"),
    (r"modm/architecture/interface/atomic.*", r"modm:architecture:atomic"),
    (r"modm/architecture/interface/block_device.*", r"modm:architecture:block.device"),
    (r"modm/architecture/interface/can.*", r"modm:architecture:can"),
    (r"modm/architecture/interface/clock.*", r"modm:architecture:clock"),
    (r"modm/architecture/interface/delay.*", r"modm:architecture:delay"),
    (r"modm/architecture/interface/gpio.*", r"modm:architecture:gpio"),
    (r"modm/architecture/interface/gpio_expander.*", r"modm:architecture:gpio.expander"),
    (r"modm/architecture/interface/i2c\.hpp", r"modm:architecture:i2c"),
    (r"modm/architecture/interface/i2c_device.*", r"modm:architecture:i2c.device"),
    (r"modm/architecture/interface/i2c_master.*", r"modm:architecture:i2c"),
    (r"modm/architecture/interface/i2c_transaction.*", r"modm:architecture:i2c"),
    (r"modm/architecture/interface/interrupt.*", r"modm:architecture:interrupt"),
    (r"modm/architecture/interface/memory.*", r"modm:architecture:memory"),
    (r"modm/architecture/interface/one_wire.*", r"modm:architecture:1-wire"),
    (r"modm/architecture/interface/register.*", r"modm:architecture:register"),
    (r"modm/architecture/interface/spi\.hpp", r"modm:architecture:spi"),
    (r"modm/architecture/interface/spi_device.*", r"modm:architecture:spi.device"),
    (r"modm/architecture/interface/spi_master.*", r"modm:architecture:spi"),
    (r"modm/architecture/interface/uart.*", r"modm:architecture:uart"),
    (r"modm/architecture/interface/unaligned.*", r"modm:architecture:unaligned"),
    (r"modm/communication/ros.*", r"modm:communication:ros"),
    (r"modm/communication/sab.*", r"modm:communication:sab"),
    (r"modm/communication/xpcc.*", r"modm:communication:xpcc"),
    (r"modm/container.*", r"modm:container"),
    (r"modm/debug.*", r"modm:debug"),
    (r"modm/driver/adc/ad7280a\.hpp", r"modm:driver:ad7280a"),
    (r"modm/driver/adc/ad7928\.hpp", r"modm:driver:ad7928"),
    (r"modm/driver/adc/adc_sampler\.hpp", r"modm:driver:adc_sampler"),
    (r"modm/driver/bus/bitbang_memory_interface\.hpp", r"modm:driver:memory_bus"),
    (r"modm/driver/bus/tft_memory_bus\.hpp", r"modm:driver:memory_bus"),
    (r"modm/driver/can/can_lawicel_formatter\.hpp", r"modm:driver:lawicel"),
    (r"modm/driver/can/mcp2515.*", r"modm:driver:mcp2515"),
    (r"modm/driver/color/tcs3414\.hpp", r"modm:driver:tcs3414"),
    (r"modm/driver/color/tcs3472\.hpp", r"modm:driver:tcs3472"),
    (r"modm/driver/display/ea_dog\.hpp", r"modm:driver:ea_dog"),
    (r"modm/driver/display/hd44780.*", r"modm:driver:hd44780"),
    (r"modm/driver/display/max7219matrix\.hpp", r"modm:driver:max7219"),
    (r"modm/driver/display/nokia5110\.hpp", r"modm:driver:nokia5110"),
    (r"modm/driver/display/parallel_tft\.hpp", r"modm:driver:parallel_tft_display"),
    (r"modm/driver/display/siemens_s65\.hpp", r"modm:driver:siemens_s65"),
    (r"modm/driver/display/siemens_s75\.hpp", r"modm:driver:siemens_s75"),
    (r"modm/driver/display/ssd1306\.hpp", r"modm:driver:ssd1306"),
    (r"modm/driver/display/st7.*", r"modm:driver:ea_dog"),
    (r"modm/driver/gpio/mcp23.*", r"modm:driver:mcp23x17"),
    (r"modm/driver/gpio/pca8574\.hpp", r"modm:driver:pca8574"),
    (r"modm/driver/gpio/pca9535\.hpp", r"modm:driver:pca9535"),
    (r"modm/driver/inertial/hmc58.*", r"modm:driver:hmc58x"),
    (r"modm/driver/inertial/hmc6343\.hpp", r"modm:driver:hmc6343"),
    (r"modm/driver/inertial/itg3200\.hpp", r"modm:driver:itg3200"),
    (r"modm/driver/inertial/l3gd20\.hpp", r"modm:driver:l3gd20"),
    (r"modm/driver/inertial/lis302dl\.hpp", r"modm:driver:lis302dl"),
    (r"modm/driver/inertial/lis3_transport\.hpp", r"modm:driver:lis3.transport"),
    (r"modm/driver/inertial/lis3dsh\.hpp", r"modm:driver:lis3dsh"),
    (r"modm/driver/inertial/lsm303a\.hpp", r"modm:driver:lsm303a"),
    (r"modm/driver/motion/adns9800.*", r"modm:driver:adns9800"),
    (r"modm/driver/motor/drv832x_spi\.hpp", r"modm:driver:drv832x_spi"),
    (r"modm/driver/position/vl53l0\.hpp", r"modm:driver:vl53l0"),
    (r"modm/driver/position/vl6180\.hpp", r"modm:driver:vl6180"),
    (r"modm/driver/pressure/ams5915\.hpp", r"modm:driver:ams5915"),
    (r"modm/driver/pressure/bme280.*", r"modm:driver:bme280"),
    (r"modm/driver/pressure/bmp085.*", r"modm:driver:bmp085"),
    (r"modm/driver/pressure/hclax\.hpp", r"modm:driver:hclax"),
    (r"modm/driver/pwm/max6966\.hpp", r"modm:driver:max6966"),
    (r"modm/driver/pwm/pca9685\.hpp", r"modm:driver:pca9685"),
    (r"modm/driver/pwm/ws2812b\.hpp", r"modm:driver:ws2812"),
    (r"modm/driver/radio/nrf24.*", r"modm:driver:nrf24"),
    (r"modm/driver/rtc/ds1302\.hpp", r"modm:driver:ds1302"),
    (r"modm/driver/storage/block_device_heap\.hpp", r"modm:driver:block.device:heap"),
    (r"modm/driver/storage/block_device_mirror\.hpp", r"modm:driver:block.device:mirror"),
    (r"modm/driver/storage/block_device_spiflash\.hpp", r"modm:driver:block.device:spi.flash"),
    (r"modm/driver/storage/fat\.hpp", r"modm:driver:fat"),
    (r"modm/driver/storage/i2c_eeprom\.hpp", r"modm:driver:i2c.eeprom"),
    (r"modm/driver/temperature/ds1631\.hpp", r"modm:driver:ds1631"),
    (r"modm/driver/temperature/ds18b20\.hpp", r"modm:driver:ds18b20"),
    (r"modm/driver/temperature/lm75\.hpp", r"modm:driver:lm75"),
    (r"modm/driver/temperature/ltc2984\.hpp", r"modm:driver:ltc2984"),
    (r"modm/driver/temperature/tmp102\.hpp", r"modm:driver:tmp102"),
    (r"modm/driver/temperature/tmp175\.hpp", r"modm:driver:tmp175"),
    (r"modm/driver/touch/ads7843\.hpp", r"modm:driver:ads7843"),
    (r"modm/driver/touch/ft6x06\.hpp", r"modm:driver:ft6x06"),
    (r"modm/driver/usb/ft245\.hpp", r"modm:driver:ft245"),
    (r"modm/io.*", r"modm:io"),
    (r"modm/math/filter.*", r"modm:math:filter"),
    (r"modm/math/geometry.*", r"modm:math:geometry"),
    (r"modm/math/interpolation.*", r"modm:math:interpolation"),
    (r"modm/math/lu_decomposition\.hpp", r"modm:math:matrix"),
    (r"modm/math/matrix\.hpp", r"modm:math:matrix"),
    (r"modm/math/saturated/saturated\.hpp", r"modm:math:saturated"),
    (r"modm/math/tolerance\.hpp", r"modm:math"),
    (r"modm/math/utils.*", r"modm:math:utils"),

    (r"modm/processing\.hpp", r"modm:processing"),
    (r"modm/processing/protothread.*", r"modm:processing:protothread"),
    (r"modm/processing/resumable.*", r"modm:processing:resumable"),
    (r"modm/processing/rtos.*", r"modm:processing:rtos"),
    (r"modm/processing/scheduler/scheduler\.hpp", r"modm:processing:scheduler"),
    (r"modm/processing/task\.hpp", r"modm:processing"),
    (r"modm/processing/timer.*", r"modm:processing:timer"),
    (r"modm/ui/animation.*", r"modm:ui:animation"),
    (r"modm/ui/button.*", r"modm:ui:button"),
    (r"modm/ui/color\.hpp", r"modm:ui:color"),
    (r"modm/ui/display.*", r"modm:ui:display"),
    (r"modm/ui/gui.*", r"modm:ui:gui"),
    (r"modm/ui/led.*", r"modm:ui:led"),
    (r"modm/ui/menu.*", r"modm:ui:menu"),
    (r"modm/ui/time/time\.hpp", r"modm:ui:time"),
    (r"modm/utils.*", r"modm:utils"),

    # All the platform modules
    (r"modm/platform\.hpp", r"modm:platform:core"),
    # As a last resort check the class names to get the platform modules
    (r"BitBangOneWireMaster", r"modm:platform:1-wire.bitbang"),
    (r"(Adc(\d))", r"modm:platform:adc:\2"),
    (r"(AdcInterrupt(\d))", r"modm:platform:adc:\2"),
    (r"(Can(\d))", r"modm:platform:can:\2"),
    (r"ClockControl", r"modm:platform:clock"),
    (r"SystemClock", r"modm:platform:clock"),
    (r"(Dma(\d))", r"modm:platform:dma:\2"),
    (r"Gpio\w*?[A-Z]\d{1,2}", r"modm:platform:gpio"),
    (r"BitBangI2cMaster", r"modm:platform:i2c.bitbang"),
    (r"(I2cMaster(\d))", r"modm:platform:i2c:\2"),
    (r"modm/platform/id/id\.hpp", r"modm:platform:id"),
    (r"RandomNumberGenerator", r"modm:platform:random"),
    (r"BitBangSpiMaster", r"modm:platform:spi.bitbang"),
    (r"(SpiMaster(\d))", r"modm:platform:spi:\2"),
    (r"(UartSpiMaster(\d))", r"modm:platform:uart.spi:\2"),
    (r"(Timer(\d{1,2}))", r"modm:platform:timer:\2"),
    (r"(Us?art(\d))", r"modm:platform:uart:\2"),
]

