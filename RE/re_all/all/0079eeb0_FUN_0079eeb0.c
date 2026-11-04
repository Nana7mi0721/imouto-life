
void FUN_0079eeb0(short *param_1,short *param_2,undefined4 param_3,int param_4,int param_5)

{
  short sVar1;
  
  if (param_4 < 1) {
    *param_1 = 0;
    *param_2 = 0;
    return;
  }
  sVar1 = FUN_007a2170(param_3,(uint)(byte)(&DAT_00837e14)[param_4] + param_5,8);
  *param_1 = sVar1;
  *param_2 = (short)param_4 - sVar1;
  return;
}

