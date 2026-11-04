
float10 FUN_00621aa0(float *param_1,float *param_2)

{
  return ABS((float10)((*param_1 + param_1[4]) - (param_2[4] + *param_2))) +
         ABS((float10)(param_1[5] + param_1[1]) - (float10)(param_2[5] + param_2[1])) +
         ABS((float10)(param_1[6] + param_1[2]) - (float10)(param_2[6] + param_2[2]));
}

