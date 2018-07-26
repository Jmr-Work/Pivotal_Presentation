/************************************************************************************************************************************/
/**	@fcn		void tw_set_pwm(PwmChannel channel, uint32_t value)
 *	@brief		set a PWM channel's output value
 *
 *  @example	tw_set_pwm(PWM2, 500) <- Set PWM2 to 50%
 *
 *  @param		[in]	(PwmChannel) channel	channel of PWM to use   (e.g. PWM Module0 Unit2 is 'PWM2')
 *  @param		[in]	(uint32_t)	 value		PWM value in percentage (e.g. 99.5% is 995)
 *
 *  @pre		channel requested is properly configured and ready for use
 *  @post		channel requested is set to value percentage for PWM output
 *
 *  @section	Assumptions
 *  			all input values are valid and correct
 */
/************************************************************************************************************************************/
void tw_set_pwm(PwmChannel channel, uint32_t value) {

	//Convert value(%) to Compare Value
	uint32_t cmpVal = (value*pwmPeriod) / 1000;								/* @eqn 	(in: 0 - 1000) -> (out: 0 - pwmPeriod)		*/

	//Select pwm channel
	uint32_t pwmOut = (channel==PWM2) ? PWM_OUT_2 : PWM_OUT_3;

	//Apply the value
    PWMPulseWidthSet(PWM0_BASE, pwmOut, cmpVal);							/* set both to 1.0ms pulses								*/

	return;
}