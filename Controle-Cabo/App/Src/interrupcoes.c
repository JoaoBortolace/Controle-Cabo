/* Interrupções externas --------------------------------------------------------*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
        switch (GPIO_Pin) {
                case OPTO_1_Pin:
                        if (HAL_GPIO_ReadPin(OPTO_2_GPIO_Port, OPTO_2_Pin) == OPTO_OFF) {
                                bobinaTick++;

                                if (bobinaTick > BOBINA_TICK_VOLTA) {
                                        bobinaTick = 0;
                                        carroTransversalAndar = true;

                                        OS_ERR err;
                                        OSFlagPost(
                                                (OS_FLAG_GRP *)&flagsGrp,
                                                (OS_FLAGS     )MOTOR_BOBINA_LIBERANDO,
                                                (OS_OPT       )OS_OPT_POST_FLAG_SET,
                                                (OS_ERR      *)&err
                                        );
                                }
                        }
                        break;

                case OPTO_2_Pin:
                        if (HAL_GPIO_ReadPin(OPTO_1_GPIO_Port, OPTO_1_Pin) == OPTO_OFF) {
                                bobinaTick--;

                                if (bobinaTick < -1*BOBINA_TICK_VOLTA) {
                                        bobinaTick = 0;
                                        carroTransversalAndar = true;

                                        OS_ERR err;
                                        OSFlagPost(
                                                (OS_FLAG_GRP *)&flagsGrp,
                                                (OS_FLAGS     )MOTOR_BOBINA_PUXANDO,
                                                (OS_OPT       )OS_OPT_POST_FLAG_SET,
                                                (OS_ERR      *)&err
                                        );
                                }
                        }
                        break;

                case OPTO_3_Pin:
                        carroTransversalTick++;

                        /* Assim que deu uma volta no eixo do carro transversal, mande o carro parar */
                        if (carroTransversalTick > CARRO_TRANSVERSAL_TICK_VOLTA) {
                                carroTransversalTick = 0;
                                carroTransversalAndar = false;
                        }
                        break;

                default:
                        __NOP();
                        break;
        }
}