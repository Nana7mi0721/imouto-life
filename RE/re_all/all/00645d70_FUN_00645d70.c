
float10 __thiscall FUN_00645d70(int param_1,float *param_2)

{
  return ((float10)*(float *)(param_1 + 0x128) * (float10)param_2[2] +
         (float10)*(float *)(param_1 + 0x108) * (float10)*param_2 +
         (float10)*(float *)(param_1 + 0x118) * (float10)param_2[1]) * (float10)param_2[2] +
         ((float10)*(float *)(param_1 + 0x100) * (float10)*param_2 +
         (float10)*(float *)(param_1 + 0x120) * (float10)param_2[2] +
         (float10)*(float *)(param_1 + 0x110) * (float10)param_2[1]) * (float10)*param_2 +
         ((float10)*(float *)(param_1 + 0x124) * (float10)param_2[2] +
         (float10)*(float *)(param_1 + 0x104) * (float10)*param_2 +
         (float10)*(float *)(param_1 + 0x114) * (float10)param_2[1]) * (float10)param_2[1];
}

